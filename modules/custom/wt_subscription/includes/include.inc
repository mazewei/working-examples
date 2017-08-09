<?php

class wtSubscriptionEmail {

  function __construct ($subscription, $preparation) {

    $this->wEntity = $subscription;
    $this->type = wtMailVariables::SUBSCRIPTION_DELIVERY_EMAIL;
    
    $this->subscriptionType = self::getSubscriptionType ();
    $this->preparation = $preparation;
    
    $this->path = self::getSubscriptionPath ();
    $this->productTitle = self::getSubscriptionTitle ();
    $this->productNid = self::getSubscriptionNid ();
    $this->productSubscriptionMailNid = self::getSubscriptionMailNid();

    $this->to = $this->wEntity->field_subscription_email->value ();
    $this->subject = self::getSubscriptionSubject ();
    $this->body = self::getSubscriptionBody ();
    $this->bounce = variable_get ('bounce_email', '');
    $this->from = variable_get ('from_email', '');
    $this->bcc = variable_get ('bcc_email', '');
  }
  
  private function getSubscriptionMailNid() {
    $query = db_select('node', 'n');
    $query->fields('n', array('nid'));
    $query->join('field_data_field_delivered_product', 'delivered_product', 'n.nid=delivered_product.entity_id');
    $query->condition('delivered_product.field_delivered_product_target_id', $this->productNid,'=');
    
    $result = $query->execute()->fetchField();
    if(isset($result)) {
      return $result;
    }
  }

  private function getSubscriptionType () {

    $type = array(
      'tid' => $this->wEntity->field_sub_product->value ()->tid,
      'term' => $this->wEntity->field_sub_product->value ()->name,
    );

    return $type;
  }

  private function getSubscriptionSubject () {
    $subjectText = variable_get ('subscription_delivery_email_subject', '');
    $subject = t ($subjectText, array('!abo' => $this->wEntity->field_sub_product->value ()->name, '!date' => format_date (time (), 'short')));

    return $subject;
  }

  private function getSubscriptionBody () {

    if ($this->wEntity->field_sl_salutation->value () == 'herr') {
      $sex = t (' geehrter ');
    }
    else {
      $sex = t (' geehrte ');
    }

    $mailTextVariable = variable_get ('subscription_delivery_email_text', '');
    $mailText = t ($mailTextVariable, array(
      '!sex' => $sex,
      '!salutation' => ucfirst ($this->wEntity->field_sl_salutation->value ()),
      '!fullname' => $this->wEntity->field_sl_firstname->value () . ' ' . $this->wEntity->field_sl_lastname->value (),
      '!sub_start' => format_date ($this->wEntity->field_starttermin->value (), 'short'),
      '!sub_number' => $this->wEntity->field_abo_id->value (),
      '!url' => l (t('Download !title', array('!title' => $this->productTitle)), url('sites/default/files/' . $this->path, array('absolute' => TRUE))),
        )
    );
    $mailFooter = variable_get ('email_footer', '');
    $body = $mailText . '<br />' . $mailFooter;

    return $body;
  }

  private function getSubscriptionPath () {

    foreach ($this->preparation as $prepKey => $prepValue) {
      if ($prepValue->status == 1) {
        
        if ($prepValue->tid == $this->subscriptionType['tid']) {
          return $prepValue->path;
        }
        else {
          $path = FALSE;
        }
      }
    }
  }

  private function getSubscriptionTitle () {

    foreach ($this->preparation as $prepKey => $prepValue) {
      if ($prepValue->status == 1) {
        
        if ($prepValue->tid == $this->subscriptionType['tid']) {
          return $prepValue->product['title'];
        }
        else {
          $path = FALSE;
        }
      }
    }
  }

  private function getSubscriptionNid () {

    foreach ($this->preparation as $prepKey => $prepValue) {
      if ($prepValue->status == 1) {
        
        if ($prepValue->tid == $this->subscriptionType['tid']) {
          return $prepValue->product['nid'];
        }
        else {
          $path = FALSE;
        }
      }
    }
  }
}

class wtSubscriptionPrepare {

  function __construct ($tid, $name) {
    $this->tid = $tid;
    $this->name = $name;
    $this->product = self::getLastEdition ();
    $this->status = self::getDeliveryStatus ();
    if ($this->status == 1) {
      $this->path = self::generatePath ();
    }
  }

  private function getLastEdition () {

    $query = db_select ('node', 'n');
    $query->fields ('n', array('nid'));
    $query->condition ('type', wtMailVariables::EBOOK_NODE_TYPE, '=');
    $query->join ('field_data_field_ref_zeitschrift', 'journal_ref', 'n.nid=journal_ref.entity_id');
    $query->condition ('journal_ref.field_ref_zeitschrift_target_id', $this->tid, '=');
    $query->range (0, 1);
    $query->orderBy ('n.created', 'DESC');
    $result = $query->execute ()->fetchAllKeyed (0, 0);

    if (isset ($result)) {
      $node = node_load (reset ($result));
      $wNode = entity_metadata_wrapper ('node', $node);
      $lastEdition['nid'] = $wNode->nid->value ();
      $lastEdition['title'] = $wNode->title->value ();
      foreach ($wNode->field_heft->value () as $productKey => $productValue) {
        $wProduct = entity_metadata_wrapper ('commerce_product', $productValue);
        if ($wProduct->field_typ->value ()) {
          if ($wProduct->field_typ->value () == wtMailVariables::EBOOK_PRODUCT_TYPE) {
            $lastEdition['fid'] = $wProduct->field_pdf->value ()['fid'];
            $lastEdition['filename'] = $wProduct->field_pdf->value ()['filename'];
          }
        }
      }
    }

    return $lastEdition;
  }

  //check if the product is allready delivered
  private function getDeliveryStatus () {

    $query = db_select ('node', 'n');
    $query->fields ('n', array());
    $query->condition ('type', wtMailVariables::SUBSCRIPTION_DELIVERY_NODE_TYPE, '=');
    $query->join ('field_data_field_delivered_product', 'product', 'n.nid=product.entity_id');
    $query->condition ('product.field_delivered_product_target_id', $this->product['nid'], '=');

    $result = $query->execute ()->fetchAllKeyed (0, 0);
    if (!empty ($result)) {

      $status = 0;
    }
    else {
      $status = 1;
    }

    return $status;
  }

  public function generatePath () {
    //TODO comment out
//    $path = 'test/' . $this->product['filename'];
    $path = MailService::copyFilesToDestination(array($this->product['fid'])) . '/' . $this->product['filename'];

    return $path;
  }

}
