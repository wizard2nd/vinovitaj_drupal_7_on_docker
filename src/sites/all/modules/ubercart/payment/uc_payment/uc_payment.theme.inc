<?php

/**
 * @file
 * Theme functions for the uc_payment module.
 */

/**
 * Generates markup for payment totals.
 *
 * @ingroup themeable
 */
function theme_uc_payment_totals($variables) {
  $order = $variables['order'];
  $line_items = uc_order_load_line_items_display($order);

  $output = '<table>';

  foreach ($line_items as $line) {
    if (!empty($line['title'])) {
      $output .= '<tr><td class="title">' . filter_xss($line['title']) . ':</td>'
        . '<td class="price">' . theme('uc_price', array('price' => $line['amount'])) . '</td></tr>';
    }
  }

  $output .= '</table>';

  return $output;
}
