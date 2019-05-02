<?php

/**
 * @file
 * accessories_commerce.features.inc
 */

/**
 * Implements hook_commerce_product_default_types().
 */
function accessories_commerce_commerce_product_default_types() {
  $items = array(
    'accessories' => array(
      'type' => 'accessories',
      'name' => 'Accessories',
      'description' => '',
      'help' => '',
      'revision' => 1,
    ),
  );
  return $items;
}
