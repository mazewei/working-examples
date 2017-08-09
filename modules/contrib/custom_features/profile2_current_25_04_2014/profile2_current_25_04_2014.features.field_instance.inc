<?php
/**
 * @file
 * profile2_current_25_04_2014.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function profile2_current_25_04_2014_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'profile2-main-field_no_register'
  $field_instances['profile2-main-field_no_register'] = array(
    'bundle' => 'main',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => 'Wenn sie nicht registriert werden wollen bitte hier ankreuzen',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 16,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'profile2',
    'fences_wrapper' => 'div',
    'field_name' => 'field_no_register',
    'label' => 'ich möchte nicht registriert werden',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 1,
      ),
      'type' => 'options_onoff',
      'weight' => 0,
    ),
  );

  // Exported field_instance: 'profile2-main-field_sl_address'
  $field_instances['profile2-main-field_sl_address'] = array(
    'bundle' => 'main',
    'default_value' => array(
      0 => array(
        'element_key' => 'profile2|main|field_sl_address|und|0',
        'thoroughfare' => '',
        'premise' => '',
        'postal_code' => '',
        'locality' => '',
        'country' => 'DE',
        'first_name' => '',
        'last_name' => '',
      ),
    ),
    'deleted' => 0,
    'description' => 'Teilnahme am Gewinnspiel nur für österreichische Benutzer',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'addressfield',
        'settings' => array(
          'format_handlers' => array(
            0 => 'address',
          ),
          'use_widget_handlers' => 1,
        ),
        'type' => 'addressfield_default',
        'weight' => 11,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'profile2',
    'fences_wrapper' => 'div',
    'field_name' => 'field_sl_address',
    'label' => 'Adresse',
    'required' => 1,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'addressfield',
      'settings' => array(
        'available_countries' => array(),
        'format_handlers' => array(
          'address' => 'address',
          'phone' => 0,
          'address-hide-country' => 0,
          'organisation' => 0,
          'name-oneline' => 0,
          'name-full' => 0,
        ),
      ),
      'type' => 'addressfield_standard',
      'weight' => 16,
    ),
  );

  // Exported field_instance: 'profile2-main-field_sl_delivery_billingaddress'
  $field_instances['profile2-main-field_sl_delivery_billingaddress'] = array(
    'bundle' => 'main',
    'default_value' => array(
      0 => array(
        'value' => 1,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 12,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'profile2',
    'fences_wrapper' => 'div',
    'field_name' => 'field_sl_delivery_billingaddress',
    'label' => 'Lieferadresse = Rechnungsadresse?',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 1,
      ),
      'type' => 'options_onoff',
      'weight' => 17,
    ),
  );

  // Exported field_instance: 'profile2-main-field_sl_deliveryaddress'
  $field_instances['profile2-main-field_sl_deliveryaddress'] = array(
    'bundle' => 'main',
    'default_value' => array(
      0 => array(
        'element_key' => 'profile2|main|field_sl_deliveryaddress|und|0',
        'thoroughfare' => '',
        'premise' => '',
        'postal_code' => '',
        'locality' => '',
        'country' => 'DE',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'addressfield',
        'settings' => array(
          'format_handlers' => array(
            0 => 'address',
          ),
          'use_widget_handlers' => 1,
        ),
        'type' => 'addressfield_default',
        'weight' => 13,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'profile2',
    'fences_wrapper' => 'div',
    'field_name' => 'field_sl_deliveryaddress',
    'label' => 'Lieferadresse',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'addressfield',
      'settings' => array(
        'available_countries' => array(),
        'format_handlers' => array(
          'address' => 'address',
          'name-full' => 'name-full',
          'phone' => 0,
          'address-hide-country' => 0,
          'organisation' => 0,
          'name-oneline' => 0,
        ),
      ),
      'type' => 'addressfield_standard',
      'weight' => 19,
    ),
  );

  // Exported field_instance: 'profile2-main-field_sl_firstname'
  $field_instances['profile2-main-field_sl_firstname'] = array(
    'bundle' => 'main',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 2,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'profile2',
    'fences_wrapper' => 'div',
    'field_name' => 'field_sl_firstname',
    'label' => 'Vorname',
    'placeholder' => '',
    'required' => 1,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'linkit' => array(
        'enable' => 0,
        'insert_plugin' => '',
      ),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 8,
    ),
  );

  // Exported field_instance: 'profile2-main-field_sl_lastname'
  $field_instances['profile2-main-field_sl_lastname'] = array(
    'bundle' => 'main',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 3,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'profile2',
    'fences_wrapper' => 'div',
    'field_name' => 'field_sl_lastname',
    'label' => 'Nachname',
    'placeholder' => '',
    'required' => 1,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'linkit' => array(
        'enable' => 0,
        'insert_plugin' => '',
      ),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 9,
    ),
  );

  // Exported field_instance: 'profile2-main-field_sl_newsletter_subs'
  $field_instances['profile2-main-field_sl_newsletter_subs'] = array(
    'bundle' => 'main',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 4,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'profile2',
    'fences_wrapper' => 'div',
    'field_name' => 'field_sl_newsletter_subs',
    'label' => 'Newsletter',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 0,
      ),
      'type' => 'options_onoff',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'profile2-main-field_sl_phone'
  $field_instances['profile2-main-field_sl_phone'] = array(
    'bundle' => 'main',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'für Rückfragen zur Bestellung',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 4,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'profile2',
    'fences_wrapper' => 'div',
    'field_name' => 'field_sl_phone',
    'label' => 'Telefon',
    'placeholder' => '',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'linkit' => array(
        'enable' => 0,
        'insert_plugin' => '',
      ),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 19,
    ),
  );

  // Exported field_instance: 'profile2-main-field_sl_salutation'
  $field_instances['profile2-main-field_sl_salutation'] = array(
    'bundle' => 'main',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 1,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'profile2',
    'fences_wrapper' => 'div',
    'field_name' => 'field_sl_salutation',
    'label' => 'Anrede',
    'required' => 1,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => '',
      ),
      'type' => 'options_select',
      'weight' => 7,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Adresse');
  t('Anrede');
  t('Lieferadresse');
  t('Lieferadresse = Rechnungsadresse?');
  t('Nachname');
  t('Newsletter');
  t('Teilnahme am Gewinnspiel nur für österreichische Benutzer');
  t('Telefon');
  t('Vorname');
  t('Wenn sie nicht registriert werden wollen bitte hier ankreuzen');
  t('für Rückfragen zur Bestellung');
  t('ich möchte nicht registriert werden');

  return $field_instances;
}
