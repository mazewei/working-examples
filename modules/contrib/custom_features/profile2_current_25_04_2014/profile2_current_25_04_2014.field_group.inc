<?php
/**
 * @file
 * profile2_current_25_04_2014.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function profile2_current_25_04_2014_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_center2|profile2|main|default';
  $field_group->group_name = 'group_center2';
  $field_group->entity_type = 'profile2';
  $field_group->bundle = 'main';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_rechnungsadresse';
  $field_group->data = array(
    'label' => 'Center',
    'weight' => '11',
    'children' => array(
      0 => 'field_sl_delivery_billingaddress',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Center',
      'instance_settings' => array(
        'classes' => 'group-center field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_center2|profile2|main|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_center2|profile2|main|form';
  $field_group->group_name = 'group_center2';
  $field_group->entity_type = 'profile2';
  $field_group->bundle = 'main';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_zusatzfelder';
  $field_group->data = array(
    'label' => 'Center',
    'weight' => '27',
    'children' => array(
      0 => 'field_sl_favorite_stiegl',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Center',
      'instance_settings' => array(
        'required_fields' => 0,
        'id' => '',
        'classes' => 'group-center field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_center2|profile2|main|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_center3|profile2|main|default';
  $field_group->group_name = 'group_center3';
  $field_group->entity_type = 'profile2';
  $field_group->bundle = 'main';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_zusatzfelder';
  $field_group->data = array(
    'label' => 'Center',
    'weight' => '5',
    'children' => array(
      0 => 'field_sl_favorite_stiegl',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Center',
      'instance_settings' => array(
        'classes' => 'group-center field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_center3|profile2|main|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_center3|profile2|main|form';
  $field_group->group_name = 'group_center3';
  $field_group->entity_type = 'profile2';
  $field_group->bundle = 'main';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_zusatzfelder';
  $field_group->data = array(
    'label' => 'Center',
    'weight' => '30',
    'children' => array(
      0 => 'field_sl_socialmedia',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Center',
      'instance_settings' => array(
        'required_fields' => 0,
        'id' => '',
        'classes' => 'group-center field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_center3|profile2|main|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_center4|profile2|main|default';
  $field_group->group_name = 'group_center4';
  $field_group->entity_type = 'profile2';
  $field_group->bundle = 'main';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_zusatzfelder';
  $field_group->data = array(
    'label' => 'Center',
    'weight' => '10',
    'children' => array(
      0 => 'field_sl_socialmedia',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Center',
      'instance_settings' => array(
        'classes' => 'group-center field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_center4|profile2|main|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_center|profile2|main|default';
  $field_group->group_name = 'group_center';
  $field_group->entity_type = 'profile2';
  $field_group->bundle = 'main';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_personenangaben';
  $field_group->data = array(
    'label' => 'Center',
    'weight' => '8',
    'children' => array(
      0 => 'field_sl_phone',
      1 => 'field_sl_favorite_beer',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Center',
      'instance_settings' => array(
        'required_fields' => 0,
        'id' => '',
        'classes' => 'group-center field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_center|profile2|main|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_center|profile2|main|form';
  $field_group->group_name = 'group_center';
  $field_group->entity_type = 'profile2';
  $field_group->bundle = 'main';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_personenangaben';
  $field_group->data = array(
    'label' => 'Center',
    'weight' => '20',
    'children' => array(
      0 => 'field_sl_phone',
      1 => 'field_sl_favorite_beer',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Center',
      'instance_settings' => array(
        'required_fields' => 0,
        'id' => '',
        'classes' => 'group-center field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_center|profile2|main|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_left2|profile2|main|default';
  $field_group->group_name = 'group_left2';
  $field_group->entity_type = 'profile2';
  $field_group->bundle = 'main';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_rechnungsadresse';
  $field_group->data = array(
    'label' => 'Left',
    'weight' => '12',
    'children' => array(
      0 => 'field_sl_deliveryaddress',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Left',
      'instance_settings' => array(
        'classes' => 'group-left field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_left2|profile2|main|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_left2|profile2|main|form';
  $field_group->group_name = 'group_left2';
  $field_group->entity_type = 'profile2';
  $field_group->bundle = 'main';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_zusatzfelder';
  $field_group->data = array(
    'label' => 'Left',
    'weight' => '28',
    'children' => array(
      0 => 'field_sl_favorite_bowl',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Left',
      'instance_settings' => array(
        'required_fields' => 0,
        'id' => '',
        'classes' => 'group-left field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_left2|profile2|main|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_left3|profile2|main|default';
  $field_group->group_name = 'group_left3';
  $field_group->entity_type = 'profile2';
  $field_group->bundle = 'main';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_zusatzfelder';
  $field_group->data = array(
    'label' => 'Left',
    'weight' => '6',
    'children' => array(
      0 => 'field_sl_favorite_bowl',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Left',
      'instance_settings' => array(
        'classes' => 'group-left field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_left3|profile2|main|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_left|profile2|main|default';
  $field_group->group_name = 'group_left';
  $field_group->entity_type = 'profile2';
  $field_group->bundle = 'main';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_personenangaben';
  $field_group->data = array(
    'label' => 'Left',
    'weight' => '9',
    'children' => array(
      0 => 'field_sl_birth_date',
      1 => 'field_sl_newsletter_subs',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Left',
      'instance_settings' => array(
        'required_fields' => 0,
        'id' => '',
        'classes' => 'group-left field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_left|profile2|main|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_left|profile2|main|form';
  $field_group->group_name = 'group_left';
  $field_group->entity_type = 'profile2';
  $field_group->bundle = 'main';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_personenangaben';
  $field_group->data = array(
    'label' => 'Left',
    'weight' => '21',
    'children' => array(
      0 => 'field_sl_birth_date',
      1 => 'field_sl_newsletter_subs',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Left',
      'instance_settings' => array(
        'required_fields' => 0,
        'id' => '',
        'classes' => 'group-left field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_left|profile2|main|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_personenangaben|profile2|main|default';
  $field_group->group_name = 'group_personenangaben';
  $field_group->entity_type = 'profile2';
  $field_group->bundle = 'main';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Personenangaben',
    'weight' => '0',
    'children' => array(
      0 => 'group_right',
      1 => 'group_center',
      2 => 'group_left',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-personenangaben field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_personenangaben|profile2|main|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_personenangaben|profile2|main|form';
  $field_group->group_name = 'group_personenangaben';
  $field_group->entity_type = 'profile2';
  $field_group->bundle = 'main';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Personenangaben',
    'weight' => '1',
    'children' => array(
      0 => 'group_right',
      1 => 'group_center',
      2 => 'group_left',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'description' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'classes' => '',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $export['group_personenangaben|profile2|main|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_rechnungsadresse|profile2|main|default';
  $field_group->group_name = 'group_rechnungsadresse';
  $field_group->entity_type = 'profile2';
  $field_group->bundle = 'main';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Rechnungsadresse',
    'weight' => '1',
    'children' => array(
      0 => 'group_right2',
      1 => 'group_left2',
      2 => 'group_center2',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Rechnungsadresse',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => 'group-rechnungsadresse field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_rechnungsadresse|profile2|main|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_rechnungsadresse|profile2|main|form';
  $field_group->group_name = 'group_rechnungsadresse';
  $field_group->entity_type = 'profile2';
  $field_group->bundle = 'main';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Adresse',
    'weight' => '2',
    'children' => array(
      0 => 'field_sl_address',
      1 => 'field_sl_deliveryaddress',
      2 => 'field_sl_delivery_billingaddress',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'description' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'classes' => '',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $export['group_rechnungsadresse|profile2|main|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_right2|profile2|main|default';
  $field_group->group_name = 'group_right2';
  $field_group->entity_type = 'profile2';
  $field_group->bundle = 'main';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_rechnungsadresse';
  $field_group->data = array(
    'label' => 'Right',
    'weight' => '10',
    'children' => array(
      0 => 'field_sl_address',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Right',
      'instance_settings' => array(
        'classes' => 'group-right field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_right2|profile2|main|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_right2|profile2|main|form';
  $field_group->group_name = 'group_right2';
  $field_group->entity_type = 'profile2';
  $field_group->bundle = 'main';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_zusatzfelder';
  $field_group->data = array(
    'label' => 'Right',
    'weight' => '26',
    'children' => array(
      0 => 'field_sl_favorite_drink',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Right',
      'instance_settings' => array(
        'required_fields' => 0,
        'id' => '',
        'classes' => 'group-right field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_right2|profile2|main|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_right3|profile2|main|default';
  $field_group->group_name = 'group_right3';
  $field_group->entity_type = 'profile2';
  $field_group->bundle = 'main';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_zusatzfelder';
  $field_group->data = array(
    'label' => 'Right',
    'weight' => '4',
    'children' => array(
      0 => 'field_sl_favorite_drink',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Right',
      'instance_settings' => array(
        'classes' => 'group-right field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_right3|profile2|main|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_right3|profile2|main|form';
  $field_group->group_name = 'group_right3';
  $field_group->entity_type = 'profile2';
  $field_group->bundle = 'main';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_zusatzfelder';
  $field_group->data = array(
    'label' => 'Right',
    'weight' => '29',
    'children' => array(
      0 => 'field_sl_interest',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Right',
      'instance_settings' => array(
        'required_fields' => 0,
        'id' => '',
        'classes' => 'group-right field-group-div clear',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_right3|profile2|main|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_right4|profile2|main|default';
  $field_group->group_name = 'group_right4';
  $field_group->entity_type = 'profile2';
  $field_group->bundle = 'main';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_zusatzfelder';
  $field_group->data = array(
    'label' => 'Right',
    'weight' => '9',
    'children' => array(
      0 => 'field_sl_interest',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Right',
      'instance_settings' => array(
        'classes' => 'group-right field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_right4|profile2|main|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_right|profile2|main|default';
  $field_group->group_name = 'group_right';
  $field_group->entity_type = 'profile2';
  $field_group->bundle = 'main';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_personenangaben';
  $field_group->data = array(
    'label' => 'Right',
    'weight' => '7',
    'children' => array(
      0 => 'field_sl_salutation',
      1 => 'field_sl_firstname',
      2 => 'field_sl_lastname',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Right',
      'instance_settings' => array(
        'required_fields' => 0,
        'id' => '',
        'classes' => 'group-right field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_right|profile2|main|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_right|profile2|main|form';
  $field_group->group_name = 'group_right';
  $field_group->entity_type = 'profile2';
  $field_group->bundle = 'main';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_personenangaben';
  $field_group->data = array(
    'label' => 'Right',
    'weight' => '19',
    'children' => array(
      0 => 'field_sl_salutation',
      1 => 'field_sl_firstname',
      2 => 'field_sl_lastname',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Right',
      'instance_settings' => array(
        'required_fields' => 0,
        'id' => '',
        'classes' => 'group-right field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_right|profile2|main|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_zusatzfelder|profile2|main|default';
  $field_group->group_name = 'group_zusatzfelder';
  $field_group->entity_type = 'profile2';
  $field_group->bundle = 'main';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Eingabe der Zusatzfelder',
    'weight' => '2',
    'children' => array(
      0 => 'group_right3',
      1 => 'group_center3',
      2 => 'group_left3',
      3 => 'group_right4',
      4 => 'group_center4',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Eingabe der Zusatzfelder',
      'instance_settings' => array(
        'classes' => 'group-zusatzfelder field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_zusatzfelder|profile2|main|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_zusatzfelder|profile2|main|form';
  $field_group->group_name = 'group_zusatzfelder';
  $field_group->entity_type = 'profile2';
  $field_group->bundle = 'main';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Eingabe der Zusatzfelder +',
    'weight' => '3',
    'children' => array(
      0 => 'group_right2',
      1 => 'group_center2',
      2 => 'group_left2',
      3 => 'group_right3',
      4 => 'group_center3',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Eingabe der Zusatzfelder +',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-zusatzfelder',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_zusatzfelder|profile2|main|form'] = $field_group;

  return $export;
}
