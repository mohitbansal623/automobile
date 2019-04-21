<?php

/**
 * @file
 * The primary PHP file for this theme.
 */

/**
 * @file
 * The primary PHP file for this theme.
 */

function tourister_bag_theme_preprocess_page(&$variables) {
  // $path = path_to_theme();
  // drupal_add_css($path . '/stylesheets/basic_layout.css');
  $theme_path = drupal_get_path('theme', 'tourister_bag_theme');
  $slick_lib = libraries_get_path('slick');
  drupal_add_js($slick_lib .'/slick/slick.min.js');
  drupal_add_css($slick_lib .'/slick/slick.css');
  drupal_add_css($slick_lib .'/slick/slick-theme.css');
  drupal_add_css($theme_path . '/css/display_products.css');
}

function tourister_bag_theme_preprocess_html(&$variables) {

}    

