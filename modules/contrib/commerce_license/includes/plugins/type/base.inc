<?php

/**
 * @file
 * Abstract and interface plugin implementation.
 */

/**
 * Provide a separate Exception so it can be caught separately.
 */
class CommerceLicenseException extends Exception { }

/**
 * Ensures basic required behavior for a license.
 *
 * EntityBundlePluginProvideFieldsInterface also mandates a fields() method.
 */
interface CommerceLicenseInterface extends EntityBundlePluginProvideFieldsInterface {

  /**
   * Returns an html representation of the access details.
   *
   * The information contained within should be the required minimum
   * for the customer to access the resource he purchased the rights to.
   *
   * If the customer purchased a file license, this method would output
   * the link to that file.
   * If the customer purchased a software subscription and the service
   * returned access credentials, this method would return those
   * access credentials.
   *
   * @return
   *   An html string with the access details.
   */
  public function accessDetails();

  /**
   * Returns whether a license is configurable.
   *
   * Configurable licenses are editable by the customer, either through
   * the add to cart form (via Inline Entity Form) or through a checkout pane.
   *
   * The output of this method determines whether form(), formValidate()
   * and formSubmit() will be called.
   *
   * @return
   *   TRUE if the license is configurable, FALSE otherwise.
   */
  public function isConfigurable();

  /**
   * Provides the license form.
   *
   * @param $form
   *   The license form. Might be embedded in another form through
   *   Inline Entity Form.
   * @param $form_state
   *   The form state of the complete form.
   *   Always use drupal_array_get_nested_value() instead of accessing
   *   $form_state['values'] directly.
   */
  public function form(&$form, &$form_state);

  /**
   * Validates the license form.
   *
   * @param $form
   *   The license form. Might be embedded in another form through
   *   Inline Entity Form, so form['#parents'] needs to be taken into account
   *   when fetching values and setting errors.
   * @param $form_state
   *   The form state of the complete form.
   *   Always use drupal_array_get_nested_value() instead of accessing
   *   $form_state['values'] directly.
   */
  public function formValidate($form, &$form_state);

  /**
   * Submits the license form.
   *
   * @param $form
   *   The license form. Might be embedded in another form through
   *   Inline Entity Form, so form['#parents'] needs to be taken into account
   *   when fetching values and setting errors.
   * @param $form_state
   *   The form state of the complete form.
   *   Always use drupal_array_get_nested_value() instead of accessing
   *   $form_state['values'] directly.
   */
  public function formSubmit(&$form, $form_state);

  /**
   * Returns the html message to be shown to the customer on checkout complete.
   *
   * Called by the commerce_license_complete checkout pane.
   *
   * @return
   *   The html message to be shown to the customer.
   */
  public function checkoutCompletionMessage();

}

/**
 * Marks a license as synchronizable with a remote service.
 *
 * All synchronizable licenses are queued when the order has been paid, and
 * then processed by Advanced queue.
 */
interface CommerceLicenseSynchronizableInterface {

  /**
   * Perform synchronization.
   *
   * @return
   *   TRUE if the synchronization was successful, FALSE otherwise.
   */
  public function synchronize();

}

/**
 * License base class.
 *
 * Remote license types should inherit CommerceLicenseRemoteBase instead.
 */
abstract class CommerceLicenseBase extends Entity implements CommerceLicenseInterface, EntityBundlePluginValidableInterface {

  /**
   * The license id.
   *
   * @var integer
   */
  public $license_id;

  /**
   * The license type (bundle).
   *
   * @var string
   */
  public $type;

  /**
   * The uid of the license owner.
   *
   * @var integer
   */
  public $uid;

  /**
   * The product_id of the licensed product.
   *
   * @var integer
   */
  public $product_id;

  /**
   * The license status.
   *
   * @var integer
   */
  public $status = COMMERCE_LICENSE_CREATED;

  /**
   * The date (unix timestamp) when the license was granted.
   *
   * @var integer
   */
  public $granted = 0;

  /**
   * The date (unix timestamp) when the license expires. 0 for never.
   *
   * @var integer
   */
  public $expires = 0;

  /**
   * License metadata wrapper.
   *
   * @var EntityDrupalWrapper
   */
  public $wrapper;

  /**
   * Constructor.
   *
   * @see Entity::__construct()
   */
  public function __construct(array $values = array(), $entityType = NULL) {
    parent::__construct($values, 'commerce_license');
    $this->wrapper = entity_metadata_wrapper($this->entityType, $this);
  }

  /**
   * Implements EntityBundlePluginProvideFieldsInterface::fields().
   */
  static function fields() {
    return array();
  }

  /**
   * Implements CommerceLicenseInterface::accessDetails().
   */
  public function accessDetails() {}

  /**
   * Implements CommerceLicenseInterface::isConfigurable().
   */
  public function isConfigurable() {
    return FALSE;
  }

  /**
   * Implements CommerceLicenseInterface::form().
   */
  public function form(&$form, &$form_state) {
    field_attach_form('commerce_license', $this, $form, $form_state, LANGUAGE_NONE);
  }

  /**
   * Implements CommerceLicenseInterface::formValidate().
   */
  public function formValidate($form, &$form_state) {
    field_attach_form_validate('commerce_license', $this, $form, $form_state);
  }

  /**
   * Implements CommerceLicenseInterface::formSubmit().
   */
  public function formSubmit(&$form, $form_state) {
    field_attach_submit('commerce_license', $this, $form, $form_state);
  }

  /**
   * Implements CommerceLicenseInterface::checkoutCompletionMessage().
   */
  public function checkoutCompletionMessage() {}

  /**
   * Overrides Entity::save().
   */
  public function save() {
    $granted = FALSE;
    if (!empty($this->license_id)) {
      $this->original = entity_load_unchanged('commerce_license', $this->license_id);
      if ($this->status > $this->original->status && $this->status == COMMERCE_LICENSE_ACTIVE) {
        // The license was updated, and its status was changed to active.
        $granted = TRUE;
      }
    }
    elseif (empty($this->license_id) && $this->status == COMMERCE_LICENSE_ACTIVE) {
      // The license was created with an active status.
      $granted = TRUE;
    }

    if ($granted) {
      // The license was just activated, set the granted timestamp.
      $this->granted = REQUEST_TIME;
      // Calculate the expiration timestamp.
      $duration = $this->wrapper->product->commerce_license_duration->value();
      if ($duration > 0) {
        $this->expires = REQUEST_TIME + $duration;
      }
    }

    parent::save();
  }

  /**
   * Implements EntityBundlePluginValidableInterface::isValid().
   */
  public static function isValid() {
    return TRUE;
  }
}

/**
 * Remote license base class.
 */
abstract class CommerceLicenseRemoteBase extends CommerceLicenseBase implements CommerceLicenseSynchronizableInterface {

  /**
   * Constructor.
   *
   * @see Entity::__construct()
   */
  public function __construct(array $values = array(), $entityType = NULL) {
    parent::__construct($values, $entityType);

    // Initialize the sync status.
    // The [LANGUAGE_NONE][0]['value'] = 0; default is then added automatically.
    if (!isset($this->sync_status)) {
      $this->sync_status = array();
    }
  }

  /**
   * Implements EntityBundlePluginProvideFieldsInterface::fields().
   */
  static function fields() {
    $fields = parent::fields();
    $fields['sync_status']['field'] = array(
      'type' => 'list_integer',
      'cardinality' => 1,
      'settings' => array(
        'allowed_values' => array(
          0 => t('N/A'),
          COMMERCE_LICENSE_NEEDS_SYNC => t('Needs synchronization'),
          COMMERCE_LICENSE_SYNCED =>  t('Synchronized'),
          COMMERCE_LICENSE_SYNC_FAILED => t('Synchronization failed'),
        ),
      ),
    );
    $fields['sync_status']['instance'] = array(
      'label' => t('Synchronization status'),
      'required' => TRUE,
      'widget' => array(
        'type' => 'options_select',
      ),
    );

    return $fields;
  }

  /**
   * Overrides CommerceLicenseBase::form().
   */
  public function form(&$form, &$form_state) {
    parent::form($form, $form_state);
    // The sync status should not be editable by the customer.
    $form['sync_status']['#access'] = FALSE;
  }

  /**
   * Implements CommerceLicenseSynchronizableInterface::synchronize().
   */
  public function synchronize() {
    return TRUE;
  }

  /**
   * Overrides CommerceLicenseBase::checkoutCompletionMessage().
   */
  public function checkoutCompletionMessage() {
    $message = '';
    $sync_status = $this->wrapper->sync_status->value();
    switch ($sync_status) {
      case COMMERCE_LICENSE_NEEDS_SYNC:
        $message = t("Please wait while we're contacting the remote service...");
        break;
      case COMMERCE_LICENSE_SYNCED:
        $message = 'Your license has been successfully created: <br />';
        $message .= $this->accessDetails();
        break;
      case COMMERCE_LICENSE_SYNC_FAILED:
        $message = t('Oops... We were unable to generate your credentials.');
        break;
    }

    return $message;
  }

  /**
   * Overrides CommerceLicenseBase::isValid().
   */
  public static function isValid() {
    $valid = parent::isValid();
    // Remote license types can't be used without the advancedqueue module.
    return $valid && module_exists('advancedqueue');
  }
}

/**
 * Broken implementation of a type plugin.
 * Used as a fallback when the actual type plugin can't be loaded.
 */
class CommerceLicenseBroken extends CommerceLicenseBase {

  /**
   * Throw an exception.
   */
  public function __construct($values = array(), $entityType = NULL) {
    throw new CommerceLicenseException('Attempted to instantiate a broken license type plugin');
  }

  /**
   * Implements EntityBundlePluginValidableInterface::isValid().
   */
  public static function isValid() {
    return FALSE;
  }
}
