<?php

/**
 * @file
 * feature_all_accessories_view.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function feature_all_accessories_view_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'accessories';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Accessories';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Accessories';
  $handler->display->display_options['css_class'] = 'container';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'input_required' => 0,
      'text_input_required' => array(
        'text_input_required' => array(
          'value' => 'Select any filter and click on Apply to see results',
          'format' => 'filtered_html',
        ),
      ),
      'allow_secondary' => 0,
      'secondary_label' => 'Advanced options',
      'secondary_collapse_override' => '0',
    ),
    'field_select_parts_tid' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => FALSE,
        'bef_collapsible' => 0,
        'autosubmit' => 0,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
            1 => 'vocabulary',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
  );
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'views_bootstrap_thumbnail_plugin_style';
  $handler->display->display_options['style_options']['columns_horizontal'] = '-1';
  $handler->display->display_options['style_options']['columns_vertical'] = '4';
  $handler->display->display_options['style_options']['columns_xs'] = '12';
  $handler->display->display_options['style_options']['columns_sm'] = '6';
  $handler->display->display_options['style_options']['columns_md'] = '4';
  $handler->display->display_options['style_options']['columns_lg'] = '3';
  $handler->display->display_options['style_options']['column_class'] = 'item';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<h4>Check out the list of accessories and filter them out according to your choice. </h4>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No results found.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Relationship: Content: Referenced products */
  $handler->display->display_options['relationships']['field_select_product_product_id']['id'] = 'field_select_product_product_id';
  $handler->display->display_options['relationships']['field_select_product_product_id']['table'] = 'field_data_field_select_product';
  $handler->display->display_options['relationships']['field_select_product_product_id']['field'] = 'field_select_product_product_id';
  /* Field: Commerce Product: Image */
  $handler->display->display_options['fields']['field_accessories_image']['id'] = 'field_accessories_image';
  $handler->display->display_options['fields']['field_accessories_image']['table'] = 'field_data_field_accessories_image';
  $handler->display->display_options['fields']['field_accessories_image']['field'] = 'field_accessories_image';
  $handler->display->display_options['fields']['field_accessories_image']['relationship'] = 'field_select_product_product_id';
  $handler->display->display_options['fields']['field_accessories_image']['label'] = '';
  $handler->display->display_options['fields']['field_accessories_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_accessories_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_accessories_image']['settings'] = array(
    'image_style' => 'medium',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Commerce Product: Price */
  $handler->display->display_options['fields']['commerce_price']['id'] = 'commerce_price';
  $handler->display->display_options['fields']['commerce_price']['table'] = 'field_data_commerce_price';
  $handler->display->display_options['fields']['commerce_price']['field'] = 'commerce_price';
  $handler->display->display_options['fields']['commerce_price']['relationship'] = 'field_select_product_product_id';
  $handler->display->display_options['fields']['commerce_price']['label'] = '';
  $handler->display->display_options['fields']['commerce_price']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['commerce_price']['click_sort_column'] = 'amount';
  $handler->display->display_options['fields']['commerce_price']['settings'] = array(
    'calculation' => '0',
  );
  /* Field: Commerce Product: Add to Cart form */
  $handler->display->display_options['fields']['add_to_cart_form']['id'] = 'add_to_cart_form';
  $handler->display->display_options['fields']['add_to_cart_form']['table'] = 'views_entity_commerce_product';
  $handler->display->display_options['fields']['add_to_cart_form']['field'] = 'add_to_cart_form';
  $handler->display->display_options['fields']['add_to_cart_form']['relationship'] = 'field_select_product_product_id';
  $handler->display->display_options['fields']['add_to_cart_form']['label'] = '';
  $handler->display->display_options['fields']['add_to_cart_form']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['add_to_cart_form']['show_quantity'] = 0;
  $handler->display->display_options['fields']['add_to_cart_form']['default_quantity'] = '1';
  $handler->display->display_options['fields']['add_to_cart_form']['combine'] = 1;
  $handler->display->display_options['fields']['add_to_cart_form']['display_path'] = 0;
  $handler->display->display_options['fields']['add_to_cart_form']['line_item_type'] = 0;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'add_accessories' => 'add_accessories',
  );
  /* Filter criterion: Commerce Product: Select Parts (field_select_parts) */
  $handler->display->display_options['filters']['field_select_parts_tid']['id'] = 'field_select_parts_tid';
  $handler->display->display_options['filters']['field_select_parts_tid']['table'] = 'field_data_field_select_parts';
  $handler->display->display_options['filters']['field_select_parts_tid']['field'] = 'field_select_parts_tid';
  $handler->display->display_options['filters']['field_select_parts_tid']['relationship'] = 'field_select_product_product_id';
  $handler->display->display_options['filters']['field_select_parts_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_select_parts_tid']['expose']['operator_id'] = 'field_select_parts_tid_op';
  $handler->display->display_options['filters']['field_select_parts_tid']['expose']['label'] = 'Select Parts';
  $handler->display->display_options['filters']['field_select_parts_tid']['expose']['operator'] = 'field_select_parts_tid_op';
  $handler->display->display_options['filters']['field_select_parts_tid']['expose']['identifier'] = 'field_select_parts_tid';
  $handler->display->display_options['filters']['field_select_parts_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_select_parts_tid']['vocabulary'] = 'parts';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['enabled'] = FALSE;
  $handler->display->display_options['path'] = 'accessories';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Accessories';
  $handler->display->display_options['block_description'] = 'Accessories';
  $export['accessories'] = $view;

  return $export;
}
