<?php

/**
 * @file
 * Font arrays and processing.
 */

/**
 * Get websafe font stack options.
 * Websafe font stacks source: http://cssfontstack.com/
 *  
 * @param $format
 */
function _safe_styler_get_websafe_font_options($format) {

  // Font options array with values containing full font stack formatted for CSS output
  $font_options_css = &drupal_static(__FUNCTION__, array());
  if (empty($font_options_css)) {
    $font_options_css = array(

      // Sans Serif
      'Sans Serif' => array(
        'Arial' => 'Arial, "Helvetica Neue", Helvetica, sans-serif',
        'Arial Black' => '"Arial Black", "Arial Bold", Gadget, sans-serif',
        'Arial Narrow' => '"Arial Narrow", Arial, sans-serif',
        'Arial Rounded MT Bold' => '"Arial Rounded MT Bold", "Helvetica Rounded", Arial, sans-serif',
        'Avant Garde' => '"Avant Garde", Avantgarde, "Century Gothic", CenturyGothic, "AppleGothic", sans-serif',
        'Calibri' => 'Calibri, Candara, Segoe, "Segoe UI", Optima, Arial, sans-serif',
        'Candara' => 'Candara, Calibri, Segoe, "Segoe UI", Optima, Arial, sans-serif',
        'Century Gothic' => '"Century Gothic", CenturyGothic, AppleGothic, sans-serif',
        'Franklin Gothic Medium' => '"Franklin Gothic Medium", "Franklin Gothic", "ITC Franklin Gothic", Arial, sans-serif',
        'Futura' => 'Futura, "Trebuchet MS", Arial, sans-serif',
        'Geneva' => 'Geneva, Tahoma, Verdana, sans-serif',
        'Gill Sans' => '"Gill Sans", "Gill Sans MT", Calibri, sans-serif',
        'Helvetica' => '"Helvetica Neue", Helvetica, Arial, sans-serif',
        'Impact' => 'Impact, Haettenschweiler, "Franklin Gothic Bold", Charcoal, "Helvetica Inserat", "Bitstream Vera Sans Bold", "Arial Black", sans serif',
        'Lucida Grande' => '"Lucida Grande", "Lucida Sans Unicode", "Lucida Sans", Geneva, Verdana, sans-serif',
        'Optima' => 'Optima, Segoe, "Segoe UI", Candara, Calibri, Arial, sans-serif',
        'Segoe UI' => '"Segoe UI", Frutiger, "Frutiger Linotype", "Dejavu Sans", "Helvetica Neue", Arial, sans-serif',
        'Tahoma' => 'Tahoma, Verdana, Segoe, sans-serif',
        'Trebuchet MS' => '"Trebuchet MS", "Lucida Grande", "Lucida Sans Unicode", "Lucida Sans", Tahoma, sans-serif',
        'Verdana' => 'Verdana, Geneva, sans-serif',
      ),
      // Serif
      'Serif' => array(
        'Baskerville' => 'Baskerville, "Baskerville Old Face", "Hoefler Text", Garamond, "Times New Roman", serif',
        'Big Caslon' => '"Big Caslon", "Book Antiqua", "Palatino Linotype", Georgia, serif',
        'Bodoni MT' => '"Bodoni MT", Didot, "Didot LT STD", "Hoefler Text", Garamond, "Times New Roman", serif',
        'Book Antiqua' => '"Book Antiqua", Palatino, "Palatino Linotype", "Palatino LT STD", Georgia, serif',
        'Calisto MT' => '"Calisto MT", "Bookman Old Style", Bookman, "Goudy Old Style", Garamond, "Hoefler Text", "Bitstream Charter", Georgia, serif',
        'Cambria' => 'Cambria, Georgia, serif',
        'Didot' => 'Didot, "Didot LT STD", "Hoefler Text", Garamond, "Times New Roman", serif',
        'Garamond' => 'Garamond, Baskerville, "Baskerville Old Face", "Hoefler Text", "Times New Roman", serif',
        'Georgia' => 'Georgia, Times, "Times New Roman", serif',
        'Goudy Old Style' => '"Goudy Old Style", Garamond, "Big Caslon", "Times New Roman", serif',
        'Hoefler Text' => '"Hoefler Text", "Baskerville old face", Garamond, "Times New Roman", serif',
        'Lucida Bright' => '"Lucida Bright", Georgia, serif',
        'Palatino' => 'Palatino, "Palatino Linotype", "Palatino LT STD", "Book Antiqua", Georgia, serif',
        'Perpetua' => 'Perpetua, Baskerville, "Big Caslon", "Palatino Linotype", Palatino, "URW Palladio L", "Nimbus Roman No9 L", serif',
        'Rockwell' => 'Rockwell, "Courier Bold", Courier, Georgia, Times, "Times New Roman", serif',
        'Rockwell Extra Bold' => '"Rockwell Extra Bold", "Rockwell Bold", monospace',
        'Times New Roman' => 'TimesNewRoman, "Times New Roman", Times, Baskerville, Georgia, serif',
      ),
      // Monospaced
      'Monospaced' => array(
        'Andale Mono' => '"Andale Mono", AndaleMono, monospace',
        'Consolas' => 'Consolas, monaco, monospace',
        'Courier New' => '"Courier New", Courier, "Lucida Sans Typewriter", "Lucida Typewriter", monospace',
        'Lucida Console' => '"Lucida Console", "Lucida Sans Typewriter", Monaco, "Bitstream Vera Sans Mono", monospace',
        'Lucida Sans Typewriter' => '"Lucida Sans Typewriter", "Lucida Console", Monaco, "Bitstream Vera Sans Mono", monospace',
        'Monaco' => 'Monaco, Consolas, "Lucida Console", monospace',
      ),
      // Fantasy
      'Fantasy' => array(
        'Copperplate' => 'Copperplate, "Copperplate Gothic Light", fantasy',
        'Papyrus' => 'Papyrus, fantasy',
      ),
      // Script
      'Script' => array(
        'Brush Script MT' => '"Brush Script MT", cursive',
      ),
    );
  }

  // Font options array with values containing full font stack but stripped of quote marks
  $font_options_clean = &drupal_static(__FUNCTION__ . '_clean', array());
  if (empty($font_options_clean)) {
    $font_options_clean = _safe_styler_rec_array_replace('"', '', $font_options_css);
  }

  // Font options array with values containing first font only and sample text
  $font_options_sample = &drupal_static(__FUNCTION__ . '_sample', array());
  if (empty($font_options_sample)) {
    $sample = ' - "The quick brown fox jumped over the lazy dog! 0123456789"';
    foreach ($font_options_css AS $font_optgroup_key=>$font_optgroup_val) {
      foreach ($font_optgroup_val AS $font_key=>$font_val) {
        $font_options_sample[$font_optgroup_key][$font_key] = $font_key . $sample;
      }
    }
  }

  switch ($format) {
    case 'css':
      return $font_options_css;
      break;
    
    case 'clean':
      return $font_options_clean;
      break;
    
    case 'sample':
    default:
      return $font_options_sample;
      break;
  }
}

/**
 * Return the websafe font stack value from nested array.
 *  
 * @param $key
 */
function _safe_styler_get_websafe_font_value($key) {
  $font_optgroups = _safe_styler_get_websafe_font_options('css');

  foreach($font_optgroups AS $fonts) {
    if (array_key_exists($key, $fonts)) {
      return $fonts[$key];
    }
  }
}

/**
 * Return the websafe font stack key from nested array.
 *  
 * @param $value
 */
function _safe_styler_get_websafe_font_key($value) {
  $font_optgroups = _safe_styler_get_websafe_font_options('css');

  foreach($font_optgroups AS $fonts) {
    return array_search($value, $fonts);
  }
}

/**
 * Search & replace inside recursive array.
 *  
 * @param $find
 * @param $replace
 * @param $array
 */
function _safe_styler_rec_array_replace($find, $replace, $array){ 
     
  if (!is_array($array)) { 
    return str_replace($find, $replace, $array);
  }
   
  $new_array = array();
   
  foreach ($array AS $key=>$value) {
    $new_array[$key] = _safe_styler_rec_array_replace($find, $replace, $value);
  }
   
  return $new_array;
}