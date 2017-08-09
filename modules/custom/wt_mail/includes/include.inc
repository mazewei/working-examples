<?php

class MailService {

  function __construct ($type, $order, $path = '') {

    $this->type = $type;
    $this->order = $order;
    $this->wOrder = self::getWrappedOrder ();
    $this->entityType = self::getEntityType ();
    $this->bounce = variable_get ('bounce_email', '');
    $this->from = variable_get ('from_email', '');
    $this->bcc = variable_get ('bcc_email', '');
    $this->to = self::getRecipient ();
    if (!empty ($path)) {
      $this->downloadLinks = self::createDownloadPathsForPdfs ($path);
    }
    $this->body = self::getBody ();
    $this->subject = self::getSubject ();
    $this->attachment = self::getAttachments ();
  }

  private function getEntityType () {
    if ($this->wOrder->value ()->entityform_id) {
      $entityType = 'entityform';
    }
    else {
      $entityType = 'order';
    }

    return $entityType;
  }

  private function getWrappedOrder () {

    if ($this->order->type == wtMailVariables::SUBSCRIPTION_FORM_TYPE) {
      $wOrder = entity_metadata_wrapper ('entityform', $this->order);
    }
    else {
      $wOrder = entity_metadata_wrapper ('commerce_order', $this->order);
    }
    return $wOrder;
  }

  private function createDownloadPathsForPdfs ($path) {

    $files = scandir ('public://' . $path);
    unset ($files[0]);
    unset ($files[1]);

    $links = '';
    foreach ($files as $fileKey => $fileValue) {
      $links .= '<p>' . l ($fileValue, file_create_url ('public://' . $path . '/' . $fileValue)) . '</p>';
    }

    return $links;
  }

  private function getAttachments () {
    if ($this->type == wtMailVariables::ORDER_CONFIRM_EMAIL) {
      $attachments = _commerce_billy_mail_get_attachments ($this->order);
      
      return $attachments;
    } else {
      return FALSE;
    }
  }

  private function getRecipient () {
    if ($this->type == wtMailVariables::ORDER_DELIVER_PRINT_EMAIL) {
      $recipient = variable_get ('print_info_email', '');
    }
    elseif ($this->type == wtMailVariables::SUBSCRIPTION_CONFIRM_EMAIL) {
      $recipient = $this->wOrder->field_subscription_email->value ();
    }
    else {
      $recipient = $this->wOrder->mail->value ();
    }
    return $recipient;
  }

  private function getSubject () {

    if ($this->type == wtMailVariables::ORDER_CONFIRM_EMAIL) {
      $subjectText = variable_get ('order_confirmation_email_subject', '');
      $subject = t ($subjectText, array('!date' => format_date (time (), 'short')));
    }
    elseif ($this->type == wtMailVariables::PDF_DELIVERY_EMAIL) {
      $subjectText = variable_get ('pdf_delivery_email_subject', '');
      $subject = t ($subjectText, array('!date' => format_date (time (), 'short')));
    }
    
    elseif ($this->type == wtMailVariables::ORDER_DELIVER_PRINT_EMAIL) {
      $subjectText = variable_get ('print_delivery_notice_email_subject', '');
      $subject = t ($subjectText, array('!date' => format_date (time (), 'short')));
    }
    elseif ($this->type == wtMailVariables::SUBSCRIPTION_CONFIRM_EMAIL) {
      $subjectText = variable_get ('subscription_confirmation_email_subject', '');
      $subject = t ($subjectText, array('!abo' => $this->wOrder->field_sub_product->value ()->name, '!date' => format_date (time (), 'short')));
    }

    return $subject;
  }

  private function getBody () {

    if ($this->entityType == 'order') {
      if ($this->wOrder->commerce_customer_shipping->field_sl_salutation->value () == 'herr') {
        $sex = t (' geehrter ');
      }
      else {
        $sex = t (' geehrte ');
      }
    }
    elseif ($this->entityType == 'entityform') {

      if ($this->wOrder->field_sl_salutation->value () == 'herr') {
        $sex = t (' geehrter ');
      }
      else {
        $sex = t (' geehrte ');
      }
    }

    if ($this->type == wtMailVariables::ORDER_CONFIRM_EMAIL) {
      $mailTextVariable = variable_get ('order_confirmation_email_text', '');
      $mailText = t ($mailTextVariable, array(
        '!sex' => $sex,
        '!salutation' => ucfirst ($this->wOrder->commerce_customer_shipping->field_sl_salutation->value ()),
        '!fullname' => $this->wOrder->commerce_customer_shipping->commerce_customer_address->name_line->value (),
        '!date' => format_date (time (), 'short'),
        '!enddate' => format_date (time () + wtMailVariables::DOWNLOAD_URL_VALID_UNTIL, 'short'),
          )
      );
      $mailFooter = variable_get ('email_footer', '');
      $body = $mailText . '<br />' . $mailFooter;
    }
    elseif ($this->type == wtMailVariables::PDF_DELIVERY_EMAIL) {

      $mailTextVariable = variable_get ('pdf_delivery_email_text', '');
      $mailText = t ($mailTextVariable, array(
        '!sex' => $sex,
        '!salutation' => ucfirst ($this->wOrder->commerce_customer_shipping->field_sl_salutation->value ()),
        '!fullname' => $this->wOrder->commerce_customer_shipping->commerce_customer_address->name_line->value (),
        '!date' => format_date (time (), 'short'),
        '!enddate' => format_date (time () + wtMailVariables::DOWNLOAD_URL_VALID_UNTIL, 'short'),
        '!url' => $this->downloadLinks,
          )
      );

      $mailFooter = variable_get ('email_footer', '');
      $body = $mailText . '<br />' . $mailFooter;
    }
    elseif ($this->type == wtMailVariables::ORDER_DELIVER_PRINT_EMAIL) {

      $products = self::getPrintProducts ();

      $mailTextVariable = variable_get ('print_delivery_email_text', '');
      $mailText = t ($mailTextVariable, array(
        '!print' => '<ul>' . $products . '</ul>',
        '!fullname' => $this->wOrder->commerce_customer_shipping->commerce_customer_address->name_line->value (),
        '!street' => $this->wOrder->commerce_customer_shipping->commerce_customer_address->thoroughfare->value (),
        '!zip' => $this->wOrder->commerce_customer_shipping->commerce_customer_address->postal_code->value (),
        '!city' => $this->wOrder->commerce_customer_shipping->commerce_customer_address->locality->value (),
        '!company' => $this->wOrder->commerce_customer_shipping->commerce_customer_address->organisation_name->value () ? $this->wOrder->commerce_customer_shipping->commerce_customer_address->organisation_name->value () : '',
        '!invoice_fullname' => $this->wOrder->commerce_customer_billing->commerce_customer_address->name_line->value (),
        '!invoice_street' => $this->wOrder->commerce_customer_billing->commerce_customer_address->thoroughfare->value (),
        '!invoice_zip' => $this->wOrder->commerce_customer_billing->commerce_customer_address->postal_code->value (),
        '!invoice_city' => $this->wOrder->commerce_customer_billing->commerce_customer_address->locality->value (),
        '!invoice_company' => $this->wOrder->commerce_customer_billing->commerce_customer_address->organisation_name->value () ? $this->wOrder->commerce_customer_billing->commerce_customer_address->organisation_name->value () : '',
          )
      );

      $body = $mailText;
    }
    elseif ($this->type == wtMailVariables::SUBSCRIPTION_CONFIRM_EMAIL) {

      $mailTextVariable = variable_get ('subscription_confirmation_email_text', '');
      $mailText = t ($mailTextVariable, array(
        '!sex' => $sex,
        '!salutation' => ucfirst ($this->wOrder->field_sl_salutation->value ()),
        '!fullname' => $this->wOrder->field_sl_firstname->value () . ' ' . $this->wOrder->field_sl_lastname->value (),
        '!date' => format_date (time (), 'short'),
        '!sub_start' => format_date ($this->wOrder->field_starttermin->value (), 'short'),
        '!sub_number' => $this->wOrder->field_abo_id->value (),
          )
      );

      $mailFooter = variable_get ('email_footer', '');
      $body = $mailText . '<br />' . $mailFooter;
    }

    return $body;
  }

  private function getPrintProducts () {

    $printProducts = '';
    foreach ($this->wOrder->commerce_line_items->value () as $lineItemKey => $lineItemValue) {
      if ($lineItemValue->type == 'product') {
        $wLineItem = entity_metadata_wrapper ('commerce_line_item', $lineItemValue);
        if ($wLineItem->commerce_product->field_typ->value () == wtMailVariables::PRINT_PRODUCT_TYPE) {
          $printProducts .= '<li>' . $wLineItem->commerce_product->title->value () . '</li>';
        }
      }
    }
    return $printProducts;
  }

  public static function orderContainsPrint ($order) {
    $wOrder = entity_metadata_wrapper ('commerce_order', $order);
    foreach ($wOrder->commerce_line_items->value () as $lineItemKey => $lineItemValue) {
      if ($lineItemValue->type == 'product') {
        $wLineItem = entity_metadata_wrapper ('commerce_line_item', $lineItemValue);
        if ($wLineItem->commerce_product->field_typ->value () == 'print') {
          return TRUE;
        }
      }
    }

    return FALSE;
  }

  public static function orderContainsPdfFile ($order) {

    $wOrder = entity_metadata_wrapper ('commerce_order', $order);

    if ($wOrder->commerce_line_items->value ()) {
      foreach ($wOrder->commerce_line_items->value () as $lineItemKey => $lineItemValue) {
        if ($lineItemValue->type == 'product') {
          $wLineItem = entity_metadata_wrapper ('commerce_line_item', $lineItemValue);
          if ($wLineItem->commerce_product->field_typ->value () == wtMailVariables::EBOOK_PRODUCT_TYPE) {
            $fid[] = $wLineItem->commerce_product->field_pdf->value () ['fid'];
          }
        }
      }
      $path = self::copyFilesToDestination ($fid);
      return $path;
    }

    return FALSE;
  }

  public static function copyFilesToDestination ($fid) {

    if (isset ($fid)) {

      if (!isset ($path)) {
        //TODO comment out
        $path = self::generateRandomPath ();
//        $path = 'xITvcsf1dc';
      }

      if (!is_dir ('public://' . $path)) {
        self::makeDir ('public://' . $path);
      }

      foreach ($fid as $fidKey => $fidValue) {
        $file = file_load ($fidValue);
        copy ($file->uri, 'public://' . $path . '/' . $file->filename);
      }
    }
    return $path;
  }

  private static function makeDir ($path) {
    return is_dir ($path) || mkdir ($path);
  }

  private static function generateRandomPath ($length = 10) {
    // $chars - String aller erlaubten Zahlen
    $chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
    // Funktionsstart
    srand ((double) microtime () * 1000000);
    $i = 0; // Counter auf null
    $path = '';
    while ($i < $length) { // Schleife solange $i kleiner $length
      // Holen eines zufälligen Zeichens
      $num = rand () % strlen ($chars);
      // Ausf&uuml;hren von substr zum wählen eines Zeichens
      $tmp = substr ($chars, $num, 1);
      // Anhängen des Zeichens
      $path = $path . $tmp;
      // $i++ um den Counter um eins zu erhöhen
      $i++;
    }
    // Schleife wird beendet und
    // $pass (Zufallsstring) zurück gegeben
    return $path;
  }

}

//generate mails in sendable format and attach files
class wtMailSendService {

  public static function sendWtMails ($mail, $myModule) {
    
    $my_mail_token = $mail->type;
//    $from = $mail->from;
    $message = array(
      'id' => $myModule . '_' . $my_mail_token,
      'to' => $mail->to,
      'subject' => $mail->subject,
      'body' => $mail->body,
      'headers' => array(
        'Content-Type' => 'text/html; charset=UTF-8;',
        'From' => $mail->from,
        'Sender' => $mail->from,
        'Return-Path' => $mail->bounce,
        'Bcc' => $mail->bcc,
      ),
    );
    if ($mail->attachment != FALSE) {
      $message['params'] = array(
        'attachments' => $mail->attachment,
      );
    }
    
    $messageToSend = array(
      'message' => $message,
      'token' => $my_mail_token,
    );

    return $messageToSend;
  }

}
