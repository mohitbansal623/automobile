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

  // kpr($variables);
  drupal_add_css($theme_path . '/css/display_products.css');
}

function tourister_bag_theme_preprocess_html(&$variables) {
    //kpr($variables['page']['#children']);
    global $user;
    $user_info = user_load($user->uid);
    if (in_array('Agent', $user->roles)) {
        $variables['page']['#children'] = str_replace('col-xs-12 col-sm-6 col-md-6 col-lg-4', 'col-xs-12 col-sm-6 col-md-6 col-lg-4 agent_role', $variables['page']['#children']);
        
    }
    
    $variables['page']['#children'] = str_replace('Out of stock</button>', 'Out of stock</button><div class="advance_booking">Advance Booking<a href="/node/add/advance-booking">Click here</a></div>', $variables['page']['#children']);
    
    
    if (isset($user_info->field_select_category['und'][0]['value'])) {
      $user_role = $user_info->field_select_category['und'][0]['value'];
      if ($user_role == 'buyer') {
          if (in_array('page-checkout', $variables['classes_array']) && in_array('logged-in', $variables['classes_array'])) {
              
              $variables['page']['#children'] = str_replace('class="customer_profile_billing', 'class="customer_profile_billing hide_billing_box', $variables['page']['#children'] );
          }
      }
    }
    if (in_array('administrator', $user->roles)) {
        
        
    }
    
//     if (in_array('page-user-orders', $variables['classes_array']) && in_array('page-user-orders-', $variables['classes_array']))
//     $variables['page']['#children'] = str_replace('<div class="site-footer">','<div class="bank-details container">
// <p><strong>Bank Details:  </strong><strong>Name:</strong> AU SMALL FINANCE BANK, <strong>A/C Name:</strong> Shri Prasanna Industrial Services<strong>, A/C No:</strong> 1821236817620968, <strong>IFSC Code:</strong> AUBL0002368,  <strong>Branch:</strong> Gondia Fulchur road </p>
// </div><div class="company-name-sign container"><p class="name">SHRI PRASANNA INDUSTRIAL SERVICES</p><p class="signature"><img src="https://jnbag.in/sites/all/themes/sub/tourister_bag_theme/sign.png" style="width:100px;"></p><p class="signature">Sign</p></div></div><div class="messages"><p class="material-received-message">Material Received in Good Condition, If any problem please write here <a href="/content/contact-us">Contact Us</a></p><p class="computer-message">This is computer generated invoice</p></div><div class="print-button container"><button class="print">Print</button></div><div class="site-footer">', $variables['page']['#children']);
   
//    // Adding class to Tax for display taxes seperately    
//    $variables['page']['#children'] = str_replace('class="component-type-tax', 'class="all-taxes component-type-tax', $variables['page']['#children']);
}    

