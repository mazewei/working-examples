<?php
/**
 * @file
 * profile2_current_25_04_2014.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function profile2_current_25_04_2014_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_default_profile2_type().
 */
function profile2_current_25_04_2014_default_profile2_type() {
  $items = array();
  $items['main'] = entity_import('profile2_type', '{
    "userCategory" : true,
    "userView" : true,
    "type" : "main",
    "label" : "Main profile",
    "weight" : "0",
    "data" : { "registration" : 1 },
    "rdf_mapping" : []
  }');
  return $items;
}
