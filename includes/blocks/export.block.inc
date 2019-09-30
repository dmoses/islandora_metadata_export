<?php

function citation_exporter_extra_format_options($format, $format_options) {
  return $format;
}
/**
 * Implements hook_block_configure().
 */
function citation_exporter_extra_block_configure($delta = '') {
  // allow the user to enable / disable certain exports
  $form = array();
  $formats = citation_exporter_extra_get_export_formats();
  $formats = array_map('citation_exporter_extra_format_options', array_keys($formats), $formats);
  if ($delta == 'islandora_export_formats') {
    $form['#attached']['css'] = array(
      drupal_get_path('module', 'citation_exporter_extra') . '/css/export.block.css',
    );
    $form['islandora_export_formats_available_options'] = array(
      '#type' => 'checkboxes',
      '#options' => drupal_map_assoc($formats),
      '#title' => t('Choose the downloadable formats for objects exposing this block.'),
      '#default_value' => variable_get('islandora_export_formats_available_options', array()),
    );
  }
  return $form;
}

/**
 * Implements hook_block_info().
 */
function citation_exporter_extra_block_info() {
  $blocks['islandora_export_formats'] = array(
    // The name that will appear in the block list.
    'info' => t('Islandora Metadata Export'),
    // Default setting.
    'visibility' => BLOCK_VISIBILITY_LISTED,
    'pages' => 'islandora/object/*',
    'cache' => DRUPAL_NO_CACHE,
  );
  return $blocks;
}

/**
 * Implements hook_block_view().
 *
 * @throws \Exception
 */
function citation_exporter_extra_block_view($delta = '') {
  $block = array();
  If ($delta == 'islandora_export_formats') {
    $object = menu_get_object('islandora_object', 2);
    if ($object &&  $object->getDatastream('MODS') !== FALSE) {
      $block['subject'] = t('Export Object');
      $block['content'] =  theme('islandora_export_available_formats', array('object' => $object));
    }
  }

  return $block;
}

/**
 * Implements hook_block_save().
 */
function citation_exporter_extra_block_save($delta = '', $edit = []) {
  If ($delta == 'islandora_export_formats') {
    variable_set('islandora_export_formats_available_options', $edit['islandora_export_formats_available_options']);
  }
}
