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

  // Font options array formatted for CSS output
  $font_options_css = &drupal_static(__FUNCTION__, array());
  if (empty($font_options_css)) {
    $font_options_css = array(

      // Sans Serif
      'Sans Serif' => array(
        'arial'                   => 'Arial, "Helvetica Neue", Helvetica, sans-serif',
        'arial-black'             => '"Arial Black", "Arial Bold", Gadget, sans-serif',
        'arial-narrow'            => '"Arial Narrow", Arial, sans-serif',
        'arial-rounded-mt-bold'   => '"Arial Rounded MT Bold", "Helvetica Rounded", Arial, sans-serif',
        'avant-garde'             => '"Avant Garde", Avantgarde, "Century Gothic", CenturyGothic, "AppleGothic", sans-serif',
        'calibri'                 => 'Calibri, Candara, Segoe, "Segoe UI", Optima, Arial, sans-serif',
        'candara'                 => 'Candara, Calibri, Segoe, "Segoe UI", Optima, Arial, sans-serif',
        'century-gothic'          => '"Century Gothic", CenturyGothic, AppleGothic, sans-serif',
        'franklin-gothic-medium'  => '"Franklin Gothic Medium", "Franklin Gothic", "ITC Franklin Gothic", Arial, sans-serif',
        'futura'                  => 'Futura, "Trebuchet MS", Arial, sans-serif',
        'geneva'                  => 'Geneva, Tahoma, Verdana, sans-serif',
        'gill-sans'               => '"Gill Sans", "Gill Sans MT", Calibri, sans-serif',
        'helvetica'               => '"Helvetica Neue", Helvetica, Arial, sans-serif',
        'impact'                  => 'Impact, Haettenschweiler, "Franklin Gothic Bold", Charcoal, "Helvetica Inserat", "Bitstream Vera Sans Bold", "Arial Black", sans serif',
        'lucida-grande'           => '"Lucida Grande", "Lucida Sans Unicode", "Lucida Sans", Geneva, Verdana, sans-serif',
        'optima'                  => 'Optima, Segoe, "Segoe UI", Candara, Calibri, Arial, sans-serif',
        'segoe-ui'                => '"Segoe UI", Frutiger, "Frutiger Linotype", "Dejavu Sans", "Helvetica Neue", Arial, sans-serif',
        'tahoma'                  => 'Tahoma, Verdana, Segoe, sans-serif',
        'trebuchet-ms'            => '"Trebuchet MS", "Lucida Grande", "Lucida Sans Unicode", "Lucida Sans", Tahoma, sans-serif',
        'verdana'                 => 'Verdana, Geneva, sans-serif',
      ),
      // Serif
      'Serif' => array(
        'baskerville'             => 'Baskerville, "Baskerville Old Face", "Hoefler Text", Garamond, "Times New Roman", serif',
        'big-caslon'              => '"Big Caslon", "Book Antiqua", "Palatino Linotype", Georgia, serif',
        'bodoni-mt'               => '"Bodoni MT", Didot, "Didot LT STD", "Hoefler Text", Garamond, "Times New Roman", serif',
        'book-antiqua'            => '"Book Antiqua", Palatino, "Palatino Linotype", "Palatino LT STD", Georgia, serif',
        'calisto-mt'              => '"Calisto MT", "Bookman Old Style", Bookman, "Goudy Old Style", Garamond, "Hoefler Text", "Bitstream Charter", Georgia, serif',
        'cambria'                 => 'Cambria, Georgia, serif',
        'didot'                   => 'Didot, "Didot LT STD", "Hoefler Text", Garamond, "Times New Roman", serif',
        'garamond'                => 'Garamond, Baskerville, "Baskerville Old Face", "Hoefler Text", "Times New Roman", serif',
        'georgia'                 => 'Georgia, Times, "Times New Roman", serif',
        'goudy-old-style'         => '"Goudy Old Style", Garamond, "Big Caslon", "Times New Roman", serif',
        'hoefler-text'            => '"Hoefler Text", "Baskerville old face", Garamond, "Times New Roman", serif',
        'lucida-bright'           => '"Lucida Bright", Georgia, serif',
        'palatino'                => 'Palatino, "Palatino Linotype", "Palatino LT STD", "Book Antiqua", Georgia, serif',
        'perpetua'                => 'Perpetua, Baskerville, "Big Caslon", "Palatino Linotype", Palatino, "URW Palladio L", "Nimbus Roman No9 L", serif',
        'rockwell'                => 'Rockwell, "Courier Bold", Courier, Georgia, Times, "Times New Roman", serif',
        'rockwell-extra-bold'     => '"Rockwell Extra Bold", "Rockwell Bold", monospace',
        'times-new-roman'         => '"Times New Roman", TimesNewRoman, Times, Baskerville, Georgia, serif',
      ),
      // Monospaced
      'Monospaced' => array(
        'andale-mono'             => '"Andale Mono", AndaleMono, monospace',
        'consolas'                => 'Consolas, monaco, monospace',
        'courier-new'             => '"Courier New", Courier, "Lucida Sans Typewriter", "Lucida Typewriter", monospace',
        'lucida-console'          => '"Lucida Console", "Lucida Sans Typewriter", Monaco, "Bitstream Vera Sans Mono", monospace',
        'lucida-sans-typewriter'  => '"Lucida Sans Typewriter", "Lucida Console", Monaco, "Bitstream Vera Sans Mono", monospace',
        'monaco'                  => 'Monaco, Consolas, "Lucida Console", monospace',
      ),
      // Fantasy
      'Fantasy' => array(
        'copperplate'             => 'Copperplate, "Copperplate Gothic Light", fantasy',
        'papyrus'                 => 'Papyrus, fantasy',
      ),
      // Script
      'Script' => array(
        'brush-script-mt'         => '"Brush Script MT", cursive',
      ),
    );
  }

  // Font options array with quotes stripped
  $font_options_clean = &drupal_static(__FUNCTION__ . '_clean', array());
  if (empty($font_options_clean)) {
    $font_options_clean = _safe_styler_rec_array_replace('"', '', $font_options_css);
  }

  // Font options array with only the first font in stack, stripped of quotes
  $font_options_sample = &drupal_static(__FUNCTION__ . '_first', array());
  if (empty($font_options_sample)) {
    foreach ($font_options_css AS $font_optgroup_key=>$font_optgroup_val) {
      foreach ($font_optgroup_val AS $font_key=>$font_val) {
        $fonts_in_stack = explode(',', $font_val);
        $first_font = trim($fonts_in_stack[0], ' "');
        $font_options_sample[$font_optgroup_key][$font_key] = $first_font;
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
    
    case 'first-only':
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