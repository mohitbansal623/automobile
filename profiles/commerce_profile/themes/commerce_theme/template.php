<?php

/**
 * @file
 * Process theme data.
 *
 * Use this file to run your theme specific implimentations of theme functions,
 * such preprocess, process, alters, and theme function overrides.
 *
 * Preprocess and process functions are used to modify or create variables for
 * templates and theme functions. They are a common theming tool in Drupal, often
 * used as an alternative to directly editing or adding code to templates. Its
 * worth spending some time to learn more about these functions - they are a
 * powerful way to easily modify the output of any template variable.
 *
 * Preprocess and Process Functions SEE: http://drupal.org/node/254940#variables-processor
 * 1. Rename each function and instance of "adaptivetheme_subtheme" to match
 *    your subthemes name, e.g. if your theme name is "footheme" then the function
 *    name will be "footheme_preprocess_hook". Tip - you can search/replace
 *    on "adaptivetheme_subtheme".
 * 2. Uncomment the required function to use.
 */

/**
 * Preprocess variables for the html template.
 */
/* -- Delete this line to enable.
function adaptivetheme_subtheme_preprocess_html(&$vars) {
  global $theme_key;

  // Two examples of adding custom classes to the body.

  // Add a body class for the active theme name.
  // $vars['classes_array'][] = drupal_html_class($theme_key);

  // Browser/platform sniff - adds body classes such as ipad, webkit, chrome etc.
  // $vars['classes_array'][] = css_browser_selector();

}
// */


/**
 * Process variables for the html template.
 */
/* -- Delete this line if you want to use this function
function adaptivetheme_subtheme_process_html(&$vars) {
}
// */

/**
 * Override or insert variables for the page templates.
 */
/* -- Delete this line if you want to use these functions
function adaptivetheme_subtheme_preprocess_page(&$vars) {
}
function adaptivetheme_subtheme_process_page(&$vars) {
}
// */


/**
 * Override or insert variables into the node templates.
 */
/* -- Delete this line if you want to use these functions
function adaptivetheme_subtheme_preprocess_node(&$vars) {
}
function adaptivetheme_subtheme_process_node(&$vars) {
}
// */


/**
 * Override or insert variables into the comment templates.
 */
/* -- Delete this line if you want to use these functions
function adaptivetheme_subtheme_preprocess_comment(&$vars) {
}
function adaptivetheme_subtheme_process_comment(&$vars) {
}
// */


/**
 * Override or insert variables into the block templates.
 */
/* -- Delete this line if you want to use these functions
function adaptivetheme_subtheme_preprocess_block(&$vars) {
}
function adaptivetheme_subtheme_process_block(&$vars) {
}
// */

/**
 * Override or insert variables into the node template.
 */

/**
 * Create a jCarousel on product page, turn on teaser's templates, change post information on a blog pages.]\
 *
 * @param array $vars.
 */
function commerce_theme_preprocess_node(&$vars) {
  if ($vars['view_mode'] == 'full' && node_is_page($vars['node'])) {
    $vars['classes_array'][] = 'node-full';
  }
  $node_type_suggestion_key = array_search('node__' . $vars['type'], $vars['theme_hook_suggestions']);
  if ($node_type_suggestion_key !== FALSE) {
    array_splice($vars['theme_hook_suggestions'], $node_type_suggestion_key + 1, 0, array('node__' . $vars['type'] . '__' . $vars['view_mode']));
  }
  if ($vars['type'] == 'blog') {
    $vars['submitted'] = commerce_theme_own_submitting($vars['name'], $vars['date'], $vars['created']);
  }
}

/**
 * Change output post information.
 * @param string $name.
 * @param int $datetime.
 * @param int $created.
 * @param boolean $short.
 *
 * @return string $return_text.
 */
function commerce_theme_own_submitting($name, $datetime, $created, $short = TRUE) {
  if ($short) {
    $datetime = '<time datetime="' . $datetime . '" pubdate="pubdate">' . date('d/m/Y', $created) . '</time>';
  }
  else {
    $datetime = '<time datetime="' . $datetime . '" pubdate="pubdate">' . date('d/m/Y - G:i', $created) . '</time>';
  }
  // Build the submitted variable used by default in node templates
  $return_text = t('Submitted !datetime by !username',
    array(
      '!username' => $name,
      '!datetime' => $datetime,
    )
  );
  return $return_text;
}

/**
 * Change output post information on a blog page.
 *
 * @param array $vars.
 */
function commerce_theme_preprocess_comment(&$vars) {
  if ($vars['elements']['#node']->type == 'blog') {
    $vars['submitted'] = commerce_theme_own_submitting($vars['author'], $vars['rdf_template_variable_attributes_array']['created']['content'], $vars['elements']['#comment']->created, FALSE);
  }
}

/**
 * Disable default message 'No front page content has been created yet.' on empty front page.
 *
 * @param array $vars.
 */
function commerce_theme_preprocess_page(&$vars) {
  if (drupal_is_front_page()) {
    unset($vars['page']['content']['system_main']['default_message']);
    drupal_set_title('');
  }
}

/**
 * Disable field 'Username' title on a front page.
 * @param array $variables.
 *
 * @return string $result.
 */
function commerce_theme_lt_username_title($variables) {
  switch ($variables['form_id']) {
    case 'user_login':
      // Label text for the username field on the /user/login page.
      return t('Username or e-mail address');
    case 'user_login_block':
      // Label text for the username field when shown in a block.
      $result = '';
      return $result;
  }
}

/**
 * Disable field 'Password' .title on a front page.
 * @param array $variables.
 *
 * @return string $result.
 */
function commerce_theme_lt_password_title($variables) {
  // Label text for the password field.
  switch ($variables['form_id']) {
    case 'user_login':
      return t('Password');
    case 'user_login_block':
      // Label text for the password field when shown in a block.
      $result = '';
      return $result;
  }
}

/**
 * Preprocesses the wrapping HTML.
 *
 * @param array &$vars.
 * Template variables.
 */
function commerce_theme_preprocess_html(&$vars) {
  // Setup IE meta tag to force IE rendering mode.
  $meta_ie_render_engine = array(
    '#type' => 'html_tag',
    '#tag' => 'meta',
    '#attributes' => array(
      'content' =>  'IE=edge,chrome=1',
      'http-equiv' => 'X-UA-Compatible',
    )
  );
  // Add header meta tag for IE to head.
  drupal_add_html_head($meta_ie_render_engine, 'meta_ie_render_engine');
}

/**
 * Implements hook_block_view_alter().
 * @param array $data.
 * @param array $block.
 */
function commerce_theme_block_view_alter(&$data, $block) {
  if ($block->delta == 'breadcrumb' && arg(0) == 'search') {   
    $new_data = substr($data['content'], 0, 125);
    $new_data .= substr($data['content'], 192);
    $data['content'] = $new_data;
  }
}

/**
 * Implements hook_preprocess_field().
 * @param array $variables.
 */
function commerce_theme_preprocess_field(&$variables) {
  if ($variables['element']['#field_name'] == 'field_view' && $variables['element']['#entity_type'] == 'commerce_product') {
    $i = 0;
    $detect = mobile_detect_get_object();
    $items = $variables['items'];
    foreach ($items as $delta => $item) {
      $path = file_create_url($item['#item']['uri']);
      if (isset($item['#image_style'])) {
        theme('image_style', array('style_name' => $item['#image_style'], 'path' => $item['#item']['uri']));
        $path = image_style_url($item['#image_style'], $item['#item']['uri']);
      }
      $array[$i] = '<div class="slideshow-preview ' . $i . '"><img src="' . $path . '"></div>';
      $i = $i + 1;
    }
    if ($detect->isMobile() && !$detect->isTablet()) {
      $options = array(
        'scroll' => 1,
        'vertical' => FALSE,
        'skin' => 'tango',
        'visible' => 1,
      );
    }
    elseif (!$detect->isMobile() && $detect->isTablet()) {
      $options = array(
        'scroll' => 1,
        'vertical' => FALSE,
        'skin' => 'tango',
        'visible' => 4,
      );
    }
    else {
      $options = array(
        'scroll' => 1,
        'vertical' => TRUE,
        'skin' => 'tango',
        'visible' => 3,
      );
    }
    $variables['array'] = $array;
    $variables['options'] = $options;
  }
}

