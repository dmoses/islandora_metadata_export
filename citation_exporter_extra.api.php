<?php
/**
 * @file
 * Hooks provided by the Citation Exporter module.
 */

/**
 * Implements hook_TYPE_alter
 * Returns a list of available formats to download as an array that can be modified by other modules
 *  return array(
 *    TYPE => array (
 *      url => URL of the resource that will process the download
 *      title => (optional) title attribute that will be added to the URL
 *    )
 *  )
 *
 *
 * @param $formats
 *
 * @return array array of formats, this will be displayed in the block configuration file, this DOES not defines commands for menu item callbacks
 */
function hook_mods_download_format_alter(&$formats) {
  $formats = array_merge($formats, array(
    'BibTex' => array(
      'url' => 'islandora/object/[fedora:pid]/download_mods_as_bibtext',
      'title' => "Compatible with Zotero"
    ),
    'EndNote' => array(
      'url' => 'islandora/object/[fedora:pid]/download_mods_as_endnote',
      'title' => "Compatible with EndNote"
    ),
    'MARC' => array(
      'url' => 'islandora/object/[fedora:pid]/download_mods_as_marc'
    ),
    'MARCXML' => array(
      'url' => 'islandora/object/[fedora:pid]/download_mods_as_marcxml',
      'title' => 'Compatible with XML viewers'
    ),
    'MODS' => array(
      'url' => 'islandora/object/[fedora:pid]/datastream/MODS/download',
      'title' => 'Compatible with XML viewers'
    ),
    'DublinCore' => array(
      'url' => 'islandora/object/[fedora:pid]/datastream/DC/download',
      'title' => 'Compatible with XML viewers'
    ),
    'RIS' => array(
      'url' => 'islandora/object/[fedora:pid]/download_mods_as_ris',
      'title' => "Compatible with EndNote, Refworks, Zotero, and Reference Manager"
    ),
    //'JSON',
    'JSON-LD' => array(
      'url' => 'islandora/object/[fedora:pid]/download_mods_as_jsond',
      'title' => 'Compatible with Zotero'
    ),
  ));

  return $formats;
}
