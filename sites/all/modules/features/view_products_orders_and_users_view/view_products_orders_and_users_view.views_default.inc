<?php

/**
 * @file
 * view_products_orders_and_users_view.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function view_products_orders_and_users_view_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'my_products';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'commerce_product';
  $view->human_name = 'My Products';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'My Products';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    5 => '5',
    3 => '3',
    4 => '4',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No results found.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Relationship: Commerce Product: Creator */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'commerce_product';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['required'] = TRUE;
  /* Field: Commerce Product: SKU */
  $handler->display->display_options['fields']['sku']['id'] = 'sku';
  $handler->display->display_options['fields']['sku']['table'] = 'commerce_product';
  $handler->display->display_options['fields']['sku']['field'] = 'sku';
  $handler->display->display_options['fields']['sku']['link_to_product'] = 0;
  /* Field: Commerce Product: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'commerce_product';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['link_to_product'] = 0;
  /* Field: Commerce Product: Image */
  $handler->display->display_options['fields']['field_accessories_image']['id'] = 'field_accessories_image';
  $handler->display->display_options['fields']['field_accessories_image']['table'] = 'field_data_field_accessories_image';
  $handler->display->display_options['fields']['field_accessories_image']['field'] = 'field_accessories_image';
  $handler->display->display_options['fields']['field_accessories_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_accessories_image']['settings'] = array(
    'image_style' => 'medium',
    'image_link' => '',
  );
  /* Field: Commerce Product: Select Vehicle */
  $handler->display->display_options['fields']['field_select_vehicle']['id'] = 'field_select_vehicle';
  $handler->display->display_options['fields']['field_select_vehicle']['table'] = 'field_data_field_select_vehicle';
  $handler->display->display_options['fields']['field_select_vehicle']['field'] = 'field_select_vehicle';
  $handler->display->display_options['fields']['field_select_vehicle']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Commerce Product: Select Parts */
  $handler->display->display_options['fields']['field_select_parts']['id'] = 'field_select_parts';
  $handler->display->display_options['fields']['field_select_parts']['table'] = 'field_data_field_select_parts';
  $handler->display->display_options['fields']['field_select_parts']['field'] = 'field_select_parts';
  $handler->display->display_options['fields']['field_select_parts']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Commerce Product: Product Price */
  $handler->display->display_options['fields']['field_product_price']['id'] = 'field_product_price';
  $handler->display->display_options['fields']['field_product_price']['table'] = 'field_data_field_product_price';
  $handler->display->display_options['fields']['field_product_price']['field'] = 'field_product_price';
  $handler->display->display_options['fields']['field_product_price']['click_sort_column'] = 'amount';
  $handler->display->display_options['fields']['field_product_price']['settings'] = array(
    'calculation' => FALSE,
  );
  /* Field: Commerce Product: Created date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'commerce_product';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'long';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: Commerce Product: Edit link */
  $handler->display->display_options['fields']['edit_product']['id'] = 'edit_product';
  $handler->display->display_options['fields']['edit_product']['table'] = 'commerce_product';
  $handler->display->display_options['fields']['edit_product']['field'] = 'edit_product';
  $handler->display->display_options['fields']['edit_product']['text'] = 'Edit';
  /* Filter criterion: User: Current */
  $handler->display->display_options['filters']['uid_current']['id'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['table'] = 'users';
  $handler->display->display_options['filters']['uid_current']['field'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['relationship'] = 'uid';
  $handler->display->display_options['filters']['uid_current']['value'] = '1';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: User: Current */
  $handler->display->display_options['filters']['uid_current']['id'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['table'] = 'users';
  $handler->display->display_options['filters']['uid_current']['field'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['relationship'] = 'uid';
  $handler->display->display_options['filters']['uid_current']['value'] = '1';
  $handler->display->display_options['filters']['uid_current']['group'] = 1;
  /* Filter criterion: Commerce Product: SKU */
  $handler->display->display_options['filters']['sku']['id'] = 'sku';
  $handler->display->display_options['filters']['sku']['table'] = 'commerce_product';
  $handler->display->display_options['filters']['sku']['field'] = 'sku';
  $handler->display->display_options['filters']['sku']['group'] = 1;
  $handler->display->display_options['filters']['sku']['exposed'] = TRUE;
  $handler->display->display_options['filters']['sku']['expose']['operator_id'] = 'sku_op';
  $handler->display->display_options['filters']['sku']['expose']['label'] = 'SKU';
  $handler->display->display_options['filters']['sku']['expose']['operator'] = 'sku_op';
  $handler->display->display_options['filters']['sku']['expose']['identifier'] = 'sku';
  $handler->display->display_options['filters']['sku']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  /* Filter criterion: Commerce Product: Select Vehicle (field_select_vehicle) */
  $handler->display->display_options['filters']['field_select_vehicle_tid']['id'] = 'field_select_vehicle_tid';
  $handler->display->display_options['filters']['field_select_vehicle_tid']['table'] = 'field_data_field_select_vehicle';
  $handler->display->display_options['filters']['field_select_vehicle_tid']['field'] = 'field_select_vehicle_tid';
  $handler->display->display_options['filters']['field_select_vehicle_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_select_vehicle_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_select_vehicle_tid']['expose']['operator_id'] = 'field_select_vehicle_tid_op';
  $handler->display->display_options['filters']['field_select_vehicle_tid']['expose']['label'] = 'Select Vehicle';
  $handler->display->display_options['filters']['field_select_vehicle_tid']['expose']['operator'] = 'field_select_vehicle_tid_op';
  $handler->display->display_options['filters']['field_select_vehicle_tid']['expose']['identifier'] = 'field_select_vehicle_tid';
  $handler->display->display_options['filters']['field_select_vehicle_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_select_vehicle_tid']['vocabulary'] = 'vehicles';
  /* Filter criterion: Commerce Product: Select Parts (field_select_parts) */
  $handler->display->display_options['filters']['field_select_parts_tid']['id'] = 'field_select_parts_tid';
  $handler->display->display_options['filters']['field_select_parts_tid']['table'] = 'field_data_field_select_parts';
  $handler->display->display_options['filters']['field_select_parts_tid']['field'] = 'field_select_parts_tid';
  $handler->display->display_options['filters']['field_select_parts_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_select_parts_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_select_parts_tid']['expose']['operator_id'] = 'field_select_parts_tid_op';
  $handler->display->display_options['filters']['field_select_parts_tid']['expose']['label'] = 'Select Parts';
  $handler->display->display_options['filters']['field_select_parts_tid']['expose']['operator'] = 'field_select_parts_tid_op';
  $handler->display->display_options['filters']['field_select_parts_tid']['expose']['identifier'] = 'field_select_parts_tid';
  $handler->display->display_options['filters']['field_select_parts_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_select_parts_tid']['vocabulary'] = 'parts';
  $handler->display->display_options['path'] = 'my-products';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Commerce Product: SKU */
  $handler->display->display_options['fields']['sku']['id'] = 'sku';
  $handler->display->display_options['fields']['sku']['table'] = 'commerce_product';
  $handler->display->display_options['fields']['sku']['field'] = 'sku';
  $handler->display->display_options['fields']['sku']['link_to_product'] = 0;
  /* Field: Commerce Product: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'commerce_product';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['link_to_product'] = 0;
  /* Field: Commerce Product: Image */
  $handler->display->display_options['fields']['field_accessories_image']['id'] = 'field_accessories_image';
  $handler->display->display_options['fields']['field_accessories_image']['table'] = 'field_data_field_accessories_image';
  $handler->display->display_options['fields']['field_accessories_image']['field'] = 'field_accessories_image';
  $handler->display->display_options['fields']['field_accessories_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_accessories_image']['settings'] = array(
    'image_style' => 'medium',
    'image_link' => '',
  );
  /* Field: Commerce Product: Select Vehicle */
  $handler->display->display_options['fields']['field_select_vehicle']['id'] = 'field_select_vehicle';
  $handler->display->display_options['fields']['field_select_vehicle']['table'] = 'field_data_field_select_vehicle';
  $handler->display->display_options['fields']['field_select_vehicle']['field'] = 'field_select_vehicle';
  $handler->display->display_options['fields']['field_select_vehicle']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Commerce Product: Select Parts */
  $handler->display->display_options['fields']['field_select_parts']['id'] = 'field_select_parts';
  $handler->display->display_options['fields']['field_select_parts']['table'] = 'field_data_field_select_parts';
  $handler->display->display_options['fields']['field_select_parts']['field'] = 'field_select_parts';
  $handler->display->display_options['fields']['field_select_parts']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Commerce Product: Product Price */
  $handler->display->display_options['fields']['field_product_price']['id'] = 'field_product_price';
  $handler->display->display_options['fields']['field_product_price']['table'] = 'field_data_field_product_price';
  $handler->display->display_options['fields']['field_product_price']['field'] = 'field_product_price';
  $handler->display->display_options['fields']['field_product_price']['click_sort_column'] = 'amount';
  $handler->display->display_options['fields']['field_product_price']['settings'] = array(
    'calculation' => FALSE,
  );
  /* Field: Commerce Product: Price */
  $handler->display->display_options['fields']['commerce_price']['id'] = 'commerce_price';
  $handler->display->display_options['fields']['commerce_price']['table'] = 'field_data_commerce_price';
  $handler->display->display_options['fields']['commerce_price']['field'] = 'commerce_price';
  $handler->display->display_options['fields']['commerce_price']['click_sort_column'] = 'amount';
  $handler->display->display_options['fields']['commerce_price']['settings'] = array(
    'calculation' => '0',
  );
  /* Field: Commerce Product: Created date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'commerce_product';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'long';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: Commerce Product: Edit link */
  $handler->display->display_options['fields']['edit_product']['id'] = 'edit_product';
  $handler->display->display_options['fields']['edit_product']['table'] = 'commerce_product';
  $handler->display->display_options['fields']['edit_product']['field'] = 'edit_product';
  $handler->display->display_options['fields']['edit_product']['text'] = 'Edit';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Commerce Product: Created date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'commerce_product';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Commerce Product: SKU */
  $handler->display->display_options['filters']['sku']['id'] = 'sku';
  $handler->display->display_options['filters']['sku']['table'] = 'commerce_product';
  $handler->display->display_options['filters']['sku']['field'] = 'sku';
  $handler->display->display_options['filters']['sku']['group'] = 1;
  $handler->display->display_options['filters']['sku']['exposed'] = TRUE;
  $handler->display->display_options['filters']['sku']['expose']['operator_id'] = 'sku_op';
  $handler->display->display_options['filters']['sku']['expose']['label'] = 'SKU';
  $handler->display->display_options['filters']['sku']['expose']['operator'] = 'sku_op';
  $handler->display->display_options['filters']['sku']['expose']['identifier'] = 'sku';
  $handler->display->display_options['filters']['sku']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  /* Filter criterion: Commerce Product: Select Parts (field_select_parts) */
  $handler->display->display_options['filters']['field_select_parts_tid']['id'] = 'field_select_parts_tid';
  $handler->display->display_options['filters']['field_select_parts_tid']['table'] = 'field_data_field_select_parts';
  $handler->display->display_options['filters']['field_select_parts_tid']['field'] = 'field_select_parts_tid';
  $handler->display->display_options['filters']['field_select_parts_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_select_parts_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_select_parts_tid']['expose']['operator_id'] = 'field_select_parts_tid_op';
  $handler->display->display_options['filters']['field_select_parts_tid']['expose']['label'] = 'Select Parts';
  $handler->display->display_options['filters']['field_select_parts_tid']['expose']['operator'] = 'field_select_parts_tid_op';
  $handler->display->display_options['filters']['field_select_parts_tid']['expose']['identifier'] = 'field_select_parts_tid';
  $handler->display->display_options['filters']['field_select_parts_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_select_parts_tid']['vocabulary'] = 'parts';
  /* Filter criterion: Commerce Product: Select Vehicle (field_select_vehicle) */
  $handler->display->display_options['filters']['field_select_vehicle_tid']['id'] = 'field_select_vehicle_tid';
  $handler->display->display_options['filters']['field_select_vehicle_tid']['table'] = 'field_data_field_select_vehicle';
  $handler->display->display_options['filters']['field_select_vehicle_tid']['field'] = 'field_select_vehicle_tid';
  $handler->display->display_options['filters']['field_select_vehicle_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_select_vehicle_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_select_vehicle_tid']['expose']['operator_id'] = 'field_select_vehicle_tid_op';
  $handler->display->display_options['filters']['field_select_vehicle_tid']['expose']['label'] = 'Select Vehicle';
  $handler->display->display_options['filters']['field_select_vehicle_tid']['expose']['operator'] = 'field_select_vehicle_tid_op';
  $handler->display->display_options['filters']['field_select_vehicle_tid']['expose']['identifier'] = 'field_select_vehicle_tid';
  $handler->display->display_options['filters']['field_select_vehicle_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_select_vehicle_tid']['vocabulary'] = 'vehicles';
  $handler->display->display_options['path'] = 'view-all-products';
  $export['my_products'] = $view;

  $view = new view();
  $view->name = 'show_all_users';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'Show All Users';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Show All Users';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    5 => '5',
    3 => '3',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Field: User: Roles */
  $handler->display->display_options['fields']['rid']['id'] = 'rid';
  $handler->display->display_options['fields']['rid']['table'] = 'users_roles';
  $handler->display->display_options['fields']['rid']['field'] = 'rid';
  /* Field: User: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['link_to_user'] = '0';
  /* Field: User: Mobile Number */
  $handler->display->display_options['fields']['field_mobile_number']['id'] = 'field_mobile_number';
  $handler->display->display_options['fields']['field_mobile_number']['table'] = 'field_data_field_mobile_number';
  $handler->display->display_options['fields']['field_mobile_number']['field'] = 'field_mobile_number';
  /* Sort criterion: User: Created date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'users';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: User: Roles */
  $handler->display->display_options['filters']['rid']['id'] = 'rid';
  $handler->display->display_options['filters']['rid']['table'] = 'users_roles';
  $handler->display->display_options['filters']['rid']['field'] = 'rid';
  $handler->display->display_options['filters']['rid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['rid']['expose']['operator_id'] = 'rid_op';
  $handler->display->display_options['filters']['rid']['expose']['label'] = 'Roles';
  $handler->display->display_options['filters']['rid']['expose']['operator'] = 'rid_op';
  $handler->display->display_options['filters']['rid']['expose']['identifier'] = 'rid';
  $handler->display->display_options['filters']['rid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  /* Filter criterion: User: E-mail */
  $handler->display->display_options['filters']['mail']['id'] = 'mail';
  $handler->display->display_options['filters']['mail']['table'] = 'users';
  $handler->display->display_options['filters']['mail']['field'] = 'mail';
  $handler->display->display_options['filters']['mail']['exposed'] = TRUE;
  $handler->display->display_options['filters']['mail']['expose']['operator_id'] = 'mail_op';
  $handler->display->display_options['filters']['mail']['expose']['label'] = 'E-mail';
  $handler->display->display_options['filters']['mail']['expose']['operator'] = 'mail_op';
  $handler->display->display_options['filters']['mail']['expose']['identifier'] = 'mail';
  $handler->display->display_options['filters']['mail']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'show-all-users';
  $export['show_all_users'] = $view;

  $view = new view();
  $view->name = 'view_all_orders';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'commerce_order';
  $view->human_name = 'View All Orders';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'View All Orders';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Field: Commerce Order: Created date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'long';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: Commerce Order: Order ID */
  $handler->display->display_options['fields']['order_id']['id'] = 'order_id';
  $handler->display->display_options['fields']['order_id']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['order_id']['field'] = 'order_id';
  /* Field: Commerce Order: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['render_as_link'] = 0;
  /* Field: Commerce Order: Billing information */
  $handler->display->display_options['fields']['commerce_customer_billing']['id'] = 'commerce_customer_billing';
  $handler->display->display_options['fields']['commerce_customer_billing']['table'] = 'field_data_commerce_customer_billing';
  $handler->display->display_options['fields']['commerce_customer_billing']['field'] = 'commerce_customer_billing';
  /* Field: Commerce Order: Order total */
  $handler->display->display_options['fields']['commerce_order_total']['id'] = 'commerce_order_total';
  $handler->display->display_options['fields']['commerce_order_total']['table'] = 'field_data_commerce_order_total';
  $handler->display->display_options['fields']['commerce_order_total']['field'] = 'commerce_order_total';
  $handler->display->display_options['fields']['commerce_order_total']['click_sort_column'] = 'amount';
  $handler->display->display_options['fields']['commerce_order_total']['settings'] = array(
    'calculation' => FALSE,
  );
  /* Field: Commerce Order: Order state */
  $handler->display->display_options['fields']['state']['id'] = 'state';
  $handler->display->display_options['fields']['state']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['state']['field'] = 'state';
  /* Field: Commerce Order: Edit link */
  $handler->display->display_options['fields']['edit_order']['id'] = 'edit_order';
  $handler->display->display_options['fields']['edit_order']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['edit_order']['field'] = 'edit_order';
  $handler->display->display_options['fields']['edit_order']['text'] = 'Edit';
  /* Field: Commerce Order: Delete link */
  $handler->display->display_options['fields']['delete_order']['id'] = 'delete_order';
  $handler->display->display_options['fields']['delete_order']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['delete_order']['field'] = 'delete_order';
  $handler->display->display_options['fields']['delete_order']['text'] = 'Delete';
  /* Sort criterion: Commerce Order: Created date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'commerce_order';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No results found.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['path'] = 'view-all-orders';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No results found.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Commerce Order: Created date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'long';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: Commerce Order: Order ID */
  $handler->display->display_options['fields']['order_id']['id'] = 'order_id';
  $handler->display->display_options['fields']['order_id']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['order_id']['field'] = 'order_id';
  /* Field: Commerce Order: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['render_as_link'] = 0;
  /* Field: Commerce Order: Billing information */
  $handler->display->display_options['fields']['commerce_customer_billing']['id'] = 'commerce_customer_billing';
  $handler->display->display_options['fields']['commerce_customer_billing']['table'] = 'field_data_commerce_customer_billing';
  $handler->display->display_options['fields']['commerce_customer_billing']['field'] = 'commerce_customer_billing';
  /* Field: Commerce Order: Order total */
  $handler->display->display_options['fields']['commerce_order_total']['id'] = 'commerce_order_total';
  $handler->display->display_options['fields']['commerce_order_total']['table'] = 'field_data_commerce_order_total';
  $handler->display->display_options['fields']['commerce_order_total']['field'] = 'commerce_order_total';
  $handler->display->display_options['fields']['commerce_order_total']['click_sort_column'] = 'amount';
  $handler->display->display_options['fields']['commerce_order_total']['settings'] = array(
    'calculation' => FALSE,
  );
  /* Field: Commerce Order: Order state */
  $handler->display->display_options['fields']['state']['id'] = 'state';
  $handler->display->display_options['fields']['state']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['state']['field'] = 'state';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Commerce Order: Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'commerce_order';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['path'] = 'view-my-orders';
  $export['view_all_orders'] = $view;

  return $export;
}
