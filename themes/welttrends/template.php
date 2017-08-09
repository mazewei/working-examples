<?php

/**
 * @file
 * The primary PHP file for this theme.
 */

function welttrends_preprocess_node(&$vars) {
    if ($vars['view_mode'] == 'listen_teaser') {
        $vars['theme_hook_suggestions'][] = 'node__listen_teaser';
    }
    if ($vars['view_mode'] == 'frontpage_teaser') {
        $vars['theme_hook_suggestions'][] = 'node__frontpage_teaser';
        
    }
    if ($vars['view_mode'] == 'programm_teaser') {
        $vars['theme_hook_suggestions'][] = 'node__programm_teaser';
    }
    if ($vars['view_mode'] == 'search_result_full') {
        $vars['theme_hook_suggestions'][] = 'node__search_result_full';
    }
    if ($vars['view_mode'] == 'full_text_search') {
        $vars['theme_hook_suggestions'][] = 'node__full_text_search';
    }
}


function welttrends_button($variables) {
  $element = $variables['element'];
  $element['#attributes']['type'] = 'submit';
  element_set_attributes($element, array('id', 'name', 'value'));

  $element['#attributes']['class'][] = 'form-' . $element['#button_type'];
  if (!empty($element['#attributes']['disabled'])) {
    $element['#attributes']['class'][] = 'form-button-disabled';
  }

  return '<input' . drupal_attributes($element['#attributes']) . ' />';
}
