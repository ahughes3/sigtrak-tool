<?php
/**
 * @file
 * Views integration default settings.
 *
 * Stores default values for views. The view provides a list of ticket
 * nodes and is available at 'pm/tickets'
 */

/**
 * Implements hook_views_default_views().
 */
function pmticket_views_default_views() {
  $views = array();

  $view = new view();
  $view->name = 'pmticket_list';
  $view->description = '';
  $view->tag = 'pm';
  $view->base_table = 'node';
  $view->human_name = 'PM Ticket';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Errors';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'Project Management Ticket: access';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'pm_status' => 'pm_status',
    'pm_priority' => 'pm_priority',
    'pm_category' => 'pm_category',
    'pm_assigned' => 'pm_assigned',
    'edit_node' => 'edit_node',
    'delete_node' => 'edit_node',
  );
  $handler->display->display_options['style_options']['default'] = 'title';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'pm_status' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'pm_priority' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'pm_category' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'pm_assigned' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => ' ',
      'empty_column' => 1,
    ),
    'delete_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
  );
  $handler->display->display_options['style_options']['sticky'] = TRUE;
  $handler->display->display_options['style_options']['empty_table'] = TRUE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No Tickets match your search.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Ticket';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Status */
  $handler->display->display_options['fields']['pm_status']['id'] = 'pm_status';
  $handler->display->display_options['fields']['pm_status']['table'] = 'field_data_pm_status';
  $handler->display->display_options['fields']['pm_status']['field'] = 'pm_status';
  /* Field: Content: Priority */
  $handler->display->display_options['fields']['pm_priority']['id'] = 'pm_priority';
  $handler->display->display_options['fields']['pm_priority']['table'] = 'field_data_pm_priority';
  $handler->display->display_options['fields']['pm_priority']['field'] = 'pm_priority';
  /* Field: Content: Category */
  $handler->display->display_options['fields']['pm_category']['id'] = 'pm_category';
  $handler->display->display_options['fields']['pm_category']['table'] = 'field_data_pm_category';
  $handler->display->display_options['fields']['pm_category']['field'] = 'pm_category';
  /* Field: Content: Assigned to */
  $handler->display->display_options['fields']['pm_assigned']['id'] = 'pm_assigned';
  $handler->display->display_options['fields']['pm_assigned']['table'] = 'field_data_pm_assigned';
  $handler->display->display_options['fields']['pm_assigned']['field'] = 'pm_assigned';
  $handler->display->display_options['fields']['pm_assigned']['settings'] = array(
    'link' => 1,
  );
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Operations';
  /* Field: Content: Delete link */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
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
    'pmticket' => 'pmticket',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Ticket';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: Content: Category (pm_category) */
  $handler->display->display_options['filters']['pm_category_value']['id'] = 'pm_category_value';
  $handler->display->display_options['filters']['pm_category_value']['table'] = 'field_data_pm_category';
  $handler->display->display_options['filters']['pm_category_value']['field'] = 'pm_category_value';
  $handler->display->display_options['filters']['pm_category_value']['group'] = 1;
  $handler->display->display_options['filters']['pm_category_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['pm_category_value']['expose']['operator_id'] = 'pm_category_value_op';
  $handler->display->display_options['filters']['pm_category_value']['expose']['label'] = 'Category';
  $handler->display->display_options['filters']['pm_category_value']['expose']['operator'] = 'pm_category_value_op';
  $handler->display->display_options['filters']['pm_category_value']['expose']['identifier'] = 'pm_category_value';
  $handler->display->display_options['filters']['pm_category_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['pm_category_value']['reduce_duplicates'] = TRUE;
  /* Filter criterion: Content: Priority (pm_priority) */
  $handler->display->display_options['filters']['pm_priority_value']['id'] = 'pm_priority_value';
  $handler->display->display_options['filters']['pm_priority_value']['table'] = 'field_data_pm_priority';
  $handler->display->display_options['filters']['pm_priority_value']['field'] = 'pm_priority_value';
  $handler->display->display_options['filters']['pm_priority_value']['group'] = 1;
  $handler->display->display_options['filters']['pm_priority_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['pm_priority_value']['expose']['operator_id'] = 'pm_priority_value_op';
  $handler->display->display_options['filters']['pm_priority_value']['expose']['label'] = 'Priority';
  $handler->display->display_options['filters']['pm_priority_value']['expose']['operator'] = 'pm_priority_value_op';
  $handler->display->display_options['filters']['pm_priority_value']['expose']['identifier'] = 'pm_priority_value';
  $handler->display->display_options['filters']['pm_priority_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['pm_priority_value']['reduce_duplicates'] = TRUE;
  /* Filter criterion: Content: Status (pm_status) */
  $handler->display->display_options['filters']['pm_status_value']['id'] = 'pm_status_value';
  $handler->display->display_options['filters']['pm_status_value']['table'] = 'field_data_pm_status';
  $handler->display->display_options['filters']['pm_status_value']['field'] = 'pm_status_value';
  $handler->display->display_options['filters']['pm_status_value']['group'] = 1;
  $handler->display->display_options['filters']['pm_status_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['pm_status_value']['expose']['operator_id'] = 'pm_status_value_op';
  $handler->display->display_options['filters']['pm_status_value']['expose']['label'] = 'Status';
  $handler->display->display_options['filters']['pm_status_value']['expose']['operator'] = 'pm_status_value_op';
  $handler->display->display_options['filters']['pm_status_value']['expose']['identifier'] = 'pm_status_value';
  $handler->display->display_options['filters']['pm_status_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['pm_status_value']['reduce_duplicates'] = TRUE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'pm/errors';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Errors';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;

  $views[$view->name] = $view;

  return $views;
}
