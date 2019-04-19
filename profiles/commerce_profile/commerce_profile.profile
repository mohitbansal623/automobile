<?php

/**
 * @file
 * File with custom installation tasks.
 */

 /**
  * Implements hook_form_FORM_ID_alter() for install_configure_form().
  *
  * Allows the profile to alter the site configuration form.
  */
function system_form_install_configure_form_alter(&$form, $form_state) {
  // Add new option at configure site form. If checkbox will be selected, we
  // enable custom module, which sends usage statistics.
  if (!function_exists("system_form_install_configure_form_alter")) {
    $form['site_information']['site_name']['#default_value'] = 'brainstorm_profile';
  }
  $form['additional_settings'] = array(
    '#type' => 'fieldset',
    '#title' => st('Additional settings'),
    '#collapsible' => FALSE,
  );
  $form['additional_settings']['send_message'] = array(
    '#type' => 'checkbox',
    '#title' => 'Send info to developers team',
    '#description' => st('Send reports to developers. We use anonymous data about your site (URL and site-name) to fix issues and ensure great user experience.'),
    '#default_value' => TRUE,
  );

  $form['#submit'][] = 'system_form_install_configure_form_custom_submit';
}

/**
 * Function system_form_install_configure_form_custom_submit().
 */
function system_form_install_configure_form_custom_submit($form, &$form_state) {
  if ($form_state['values']['send_message']) {
    if (!module_exists('profile_stat_sender')) {
      module_enable(array('profile_stat_sender'), FALSE);
    }
  }
}

/**
 * Implements hook_install_tasks().
 */
function commerce_profile_install_tasks($install_state) {
  return array(
    'commerce_profile_batch_task' => array(
      'display_name' => 'Commerce profile specific tasks',
      'display' => TRUE,
      'type' => 'batch',
      'function' => 'commerce_profile_batch',
    ),
  );
}

/**
 * Unites all custom tasks into a batch.
 */
function commerce_profile_batch() {
  $batch = array(
    'operations' => array(
      array(
        'commerce_profile_public_files_copy',
        array(),
      ),
      array(
        'commerce_profile_enable_custom_modules',
        array(),
      ),
      array(
        'commerce_profile_simplenews_turning',
        array(),
      ),
      array(
        'commerce_profile_enable_paypal_payment_method',
        array(),
      ),
    ),
    'finished' => 'commerce_profile_batch_finished',
    'title' => t('Commerce Profile specific tasks'),
    'init_message' => t('Starting...'),
    'progress_message' => t('Completed @current out of @total.'),
    'error_message' => t('Errors occured during profile installation.'),
  );

  return $batch;
}

if (!function_exists("system_form_alter")) {

  /**
   * Implements hook_form_FORM_ID_alter().
   *
   * Select the current install profile by default.
   */
  function system_form_install_select_profile_form_alter(&$form, $form_state) {
    foreach ($form['profile'] as $profile_name => $profile_data) {
      $form['profile'][$profile_name]['#value'] = 'commerce_profile';
    }
  }

}

/**
 * Our custom task. Copy public files for default theme.
 */
function commerce_profile_public_files_copy($context) {
  $profile_root = DRUPAL_ROOT . '/profiles/commerce_profile';
  $source = $profile_root . '/public/adaptivetheme';
  $res = DRUPAL_ROOT . '/sites/default/files/adaptivetheme';
  _commerce_profile_recurse_copy($source, $res);
  $source = $profile_root . '/images/icon_commerce_profile.png';
  $res = DRUPAL_ROOT . '/sites/default/files/icon_commerce_profile.png';
  copy($source, $res);
  $source = $profile_root . '/images/blog-1.jpg';
  $res = DRUPAL_ROOT . '/sites/default/files/blog-1.jpg';
  copy($source, $res);
  $source = $profile_root . '/images/plastic-cards.png';
  $res = DRUPAL_ROOT . '/sites/default/files/plastic-cards.png';
  copy($source, $res);
  $source = $profile_root . '/images/avatar_default.jpg';
  $res = DRUPAL_ROOT . '/sites/default/files/avatar_default.jpg';
  copy($source, $res);

  $context['message'] = t('Copied public files for default theme');
}

/**
 * Copy a file, or recursively copy a folder and its contents.
 *
 * @arg string $source
 *  Absolute path to copied file or directory.
 * @arg string $destination
 *  Absolute path to directory where file will be copied to.
 */
function _commerce_profile_recurse_copy($source, $destination) {
  // Simple copy for a file.
  if (is_file($source)) {
    return copy($source, $destination);
  }

  // Make destination directory.
  if (!is_dir($destination)) {
    mkdir($destination);
  }

  // Loop through the folder.
  $dir = dir($source);
  while ($entry = $dir->read()) {
    // Skip pointers.
    if ($entry == '.' || $entry == '..') {
      continue;
    }

    // Deep copy directories.
    _commerce_profile_recurse_copy("$source/$entry", "$destination/$entry");
  }

  // Clean up.
  $dir->close();
  return TRUE;
}

/**
 * Enable custom modules.
 */
function commerce_profile_enable_custom_modules($context) {
  $modules = array(
    'custom_nodes',
    'menu_links',
    'block_settings',
  );
  module_enable($modules);

  $context['message'] = t("Enabled custom moudles");
}

/**
 * Simplenews turning.
 */
function commerce_profile_simplenews_turning($context) {
  $values = array(
    'tid' => 1,
    'name' => 'NEWSLETTER SUBSCRIBE',
    'description' => '',
    'weight' => 0,
    'new_account' => 'none',
    'opt_inout' => 'double',
    'block' => 1,
    'format' => 'plain',
    'priority' => 3,
    'receipt' => 0,
    'from_name' => 'Commerce profile',
    'from_address' => 'ecommerce@post.com',
    'email_subject' => '[[simplenews-category:name]] [node:title]',
    'hyperlinks' => 0,
    'submit' => 'Save',
    'delete' => 'Delete',
    'op' => 'Save',
  );
  $category = (object) $values;
  $term = new stdClass();
  $term->tid = $values['tid'];
  $term->vocabulary_machine_name = 'newsletter';
  $term->vid = taxonomy_vocabulary_machine_name_load('newsletter')->vid;
  $term->name = $values['name'];
  $term->description = $values['description'];
  $term->weight = $values['weight'];
  taxonomy_term_save($term);
  simplenews_category_save($category);
  variable_set('simplenews_block_r_1', 0);
  variable_set('simplenews_block_l_1', 0);
  variable_set('simplenews_block_m_1', '');

  $context['message'] = 'Created newsletter';
}

/**
 * Enable paypal payment method.
 */
function commerce_profile_enable_paypal_payment_method($context) {
  $rule = rules_config_load('commerce_payment_paypal_wps');
  $rule->active = 1;
  $rule->save();

  $context['message'] = t('Enabled Paypal payment method');
}

/**
 * Batch finish callback.
 */
function commerce_profile_batch_finished($success, $results, $operations) {
  if ($success) {
    drupal_set_message(t('All custom tasks were successfully completed.'));
  }
  else {
    drupal_set_message(t('There were errors during custom tasks completion', 'error'));
  }
}
