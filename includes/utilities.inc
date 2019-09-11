<?php
module_load_include('inc', 'bibutils', 'includes/utilities');
/**
 * @file
 * Class BibutilsExtra
 *
 * Extends the default BibUtils class, adds extra mappings and methods needed to export more formats
 *
 */
class BibutilsExtra extends Bibutils {

  /**
   * @inheritDoc
   */
  public static function Convert($src, $src_format, $dest, $dest_format) {
    $command = self::GetCommand($src_format, $dest_format);
    if ($command) {
      module_invoke_all('preprocess_bibutils_convert', $src, $src_format, $dest_format);
      list($exit_status, $output) = self::Execute($command, $src, $dest);
      if ($exit_status !== FALSE) {
        $results = module_invoke_all('postprocess_bibutils_convert', $src, $src_format, $dest, $dest_format);
        // No post process function returned false.
        return !in_array(FALSE, $results, TRUE);
      }
      else {
        drupal_set_message(filter_xss($output), 'warning');
      }
    }
    return FALSE;
  }

  /**
   * @inheritDoc
   */
  protected static function getConversionTable() {
    $base = parent::getConversionTable();
    return array_merge($base, array(
      'MODS' => array(
        'RIS' => array(
          'type' => 'callable',
          'callable' => 'RIS::transformFile',
        ),
        'EndNote' => array(
          'type' => 'shell',
          'command' => escapeshellcmd(format_string('!command -i unicode', array(
            '!command' => variable_get('bibutils_xml2end_path', '/usr/bin/xml2end'),
          ))),
        ),
        'BibTeX' => array(
          'type' => 'shell',
          'command' => escapeshellcmd(format_string('!command -i unicode', array(
            '!command' => variable_get('bibutils_xml2end_path', '/usr/bin/xml2bib'),
          ))),
        ),
      )
    ));
  }

  /**
   * @inheritDoc
   */
  protected static function GetCommand($src_format, $dest_format) {
    $conversion_table = self::getConversionTable();
    $conversion = isset($conversion_table[$src_format]) ? $conversion_table[$src_format] : array();
    if (isset($conversion[$dest_format])) {
      return $conversion[$dest_format];
    }
    return FALSE;
  }
}
