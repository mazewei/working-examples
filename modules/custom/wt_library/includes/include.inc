<?php

class freeLibraryItem {

  function __construct ($node) {

    $this->node = $node;
    $this->wNode = entity_metadata_wrapper ('node', $node);
    $this->content = self::getFreeLibraryItemcontent ();
  }

    private function getFreeLibraryItemcontent () {

    if ($this->wNode->type->value () == wtMailVariables::EBOOK_NODE_TYPE) {
      $text = $this->wNode->field_heft_editorial->value ()['safe_value'];
      $image = image_style_url ('listen_teaser_bild', $this->wNode->field_coverbild->value () ['uri']);
      if ($this->wNode->field_anzahl_seiten->value ()) {
        $pages = $this->wNode->field_anzahl_seiten->value ();
      }

      if ($this->wNode->field_ref_zeitschrift->value ()) {
        $journalTitle = $this->wNode->field_ref_zeitschrift->name->value ();
      }

      if ($this->wNode->field_jahr->value ()) {
        $year = $this->wNode->field_jahr->name->value ();
      }

      if ($this->wNode->field_heftnummer->value ()) {
        $number = $this->wNode->field_heftnummer->value ();
      }

      if ($this->wNode->field_isbn_issn->value ()) {
        $isbn = $this->wNode->field_isbn_issn->value ();
      }

      if ($this->wNode->field_issn->value ()) {
        $issn = $this->wNode->field_issn->value ();
      }

      if ($this->wNode->field_heft->value ()) {
        foreach ($this->wNode->field_heft->value () as $fileKey => $fileValue) {

          $wProduct = entity_metadata_wrapper ('commerce_product', $fileValue);
          if ($wProduct->field_pdf->value ()) {
            $file = array(
              'url' => file_create_url ($wProduct->field_pdf->value ()['uri']),
              'title' => $wProduct->field_pdf->value () ['filename'],
            );
          }
        }
      }
    }
    elseif ($this->wNode->type->value () == wtMailVariables::ARTICLE_NODE_TYPE) {
      $text = $this->wNode->field_abstract->value ()['safe_value'];
      if ($this->wNode->field_heftreferenz->value ()) {
        $image = image_style_url ('listen_teaser_bild', $this->wNode->field_heftreferenz->field_coverbild->value ()['uri']);
        $journalRef = $this->wNode->field_heftreferenz->title->value ();
      }
      if ($this->wNode->field_erste_seite->value ()) {
        $firstPage = $this->wNode->field_erste_seite->value ();
      }

      if ($this->wNode->field_letzte_seite->value ()) {
        $lastPage = $this->wNode->field_letzte_seite->value ();
      }

      if (isset ($firstPage) && isset ($lastPage)) {
        $pages = $lastPage - $firstPage;
      }

      if ($this->wNode->field_heftreferenz->field_ref_zeitschrift->value ()) {
        $journalTitle = $this->wNode->field_heftreferenz->field_ref_zeitschrift->name->value ();
      }

      if ($this->wNode->field_heftreferenz->field_jahr->value ()) {
        $year = $this->wNode->field_heftreferenz->field_jahr->name->value ();
      }

      if ($this->wNode->field_heftreferenz->field_heftnummer->value ()) {
        $number = $this->wNode->field_heftreferenz->field_heftnummer->value ();
      }

      if ($this->wNode->field_untertitel->value ()) {
        $subtitle = $this->wNode->field_untertitel->value ();
      }

      if ($this->wNode->field_artikel->value ()) {
          if($this->wNode->field_artikel->field_pdf->value ()) {
            $file = array(
              'url' => file_create_url ($this->wNode->field_artikel->field_pdf->value ()['uri']),
              'title' => $this->wNode->field_artikel->field_pdf->value ()['filename'],
            );
          }
      }
    }

    if ($this->wNode->field_herausgeber_autor->value ()) {
      foreach ($this->wNode->field_herausgeber_autor->value () as $authorKey => $authorValue) {
        $authorArray[] = $authorValue->name;
      }
      $authors = implode ($authorArray, ', ');
    }

    if ($this->wNode->field_keywords->value ()) {
      foreach ($this->wNode->field_keywords->value () as $keywordsKey => $keywordsValue) {
        $keywordsArray[] = $keywordsValue->name;
      }
      $keywords = implode ($keywordsArray, ' | ');
    }

    $libraryItem = array(
      'title' => $this->wNode->title->value (),
      'type' => $this->wNode->type->value (),
      'subtitle' => $subtitle,
      'pages' => $pages,
      'description' => $text,
      'image' => $image,
      'authors' => $authors,
      'keywords' => $keywords,
      'journalTitle' => $journalTitle,
      'number' => $number,
      'year' => $year,
      'isbn' => $isbn,
      'issn' => $issn,
      'file' => $file,
      'download' => array(
        'url' => file_create_url ($this->wNode->field_pdf_online->value ()['uri']),
        'filename' => $this->wNode->field_pdf_online->value ()['filename'],
      ),
    );

    return $libraryItem;
  }

}

class wtLibrary {

  function __construct ($lineItem) {
    $wLineItem = entity_metadata_wrapper ('commerce_line_item', $lineItem);

    $this->wLineItem = $wLineItem;
    $this->wProduct = entity_metadata_wrapper ('commerce_product', $wLineItem->commerce_product->value ());
    $this->type = self::getType ();
    $this->node = self::getLibraryItemNode ();
    $this->file = self::getFile ();
  }

  private function getType () {

    $type = $this->wProduct->type->value ();
    return $type;
  }

  private function getFile () {

    $file = array(
      'file' => file_create_url ($this->wProduct->field_pdf->value ()['uri']),
      'title' => $this->wProduct->field_pdf->value () ['filename'],
    );

    return $file;
  }

  private function getLibraryItemNode () {

    $query = db_select ('node', 'n');
    $query->fields ('n', array('nid'));
    if ($this->type == wtMailVariables::EBOOK_NODE_TYPE) {
      $query->condition ('type', wtMailVariables::EBOOK_NODE_TYPE, '=');
      $query->join ('field_data_field_heft', 'heft', 'heft.entity_id=n.nid');
      $query->condition ('heft.field_heft_product_id', $this->wProduct->product_id->value (), '=');
    }
    elseif ($this->type == wtMailVariables::ARTICLE_NODE_TYPE) {
      $query->condition ('type', wtMailVariables::ARTICLE_NODE_TYPE, '=');
      $query->join ('field_data_field_artikel', 'article', 'article.entity_id=n.nid');
      $query->condition ('article.field_artikel_product_id', $this->wProduct->product_id->value (), '=');
    }
    $query->condition ('status', 1, '=');

    $result = $query->execute ()->fetchAllKeyed (0, 0);
//    kpr($result);

    if (!empty ($result)) {

      $node = node_load (reset ($result));
      $wNode = entity_metadata_wrapper ('node', $node);

      if ($wNode->type->value () == wtMailVariables::EBOOK_NODE_TYPE) {

        $text = $wNode->field_heft_editorial->value ()['safe_value'];
        $image = image_style_url ('listen_teaser_bild', $wNode->field_coverbild->value () ['uri']);
        if ($wNode->field_anzahl_seiten->value ()) {
          $pages = $wNode->field_anzahl_seiten->value ();
        }

        if ($wNode->field_ref_zeitschrift->value ()) {
          $journalTitle = $wNode->field_ref_zeitschrift->name->value ();
        }

        if ($wNode->field_jahr->value ()) {
          $year = $wNode->field_jahr->name->value ();
        }

        if ($wNode->field_heftnummer->value ()) {
          $number = $wNode->field_heftnummer->value ();
        }

        if ($wNode->field_isbn_issn->value ()) {
          $isbn = $wNode->field_isbn_issn->value ();
        }

        if ($wNode->field_issn->value ()) {
          $issn = $wNode->field_issn->value ();
        }
      }
      elseif ($wNode->type->value () == wtMailVariables::ARTICLE_NODE_TYPE) {
        $text = $wNode->field_abstract->value ()['safe_value'];
        if ($wNode->field_heftreferenz->value ()) {
          $image = image_style_url ('listen_teaser_bild', $wNode->field_heftreferenz->field_coverbild->value ()['uri']);
          $journalRef = $wNode->field_heftreferenz->title->value ();
        }
        if ($wNode->field_erste_seite->value ()) {
          $firstPage = $wNode->field_erste_seite->value ();
        }

        if ($wNode->field_letzte_seite->value ()) {
          $lastPage = $wNode->field_letzte_seite->value ();
        }

        if (isset ($firstPage) && isset ($lastPage)) {
          $pages = $lastPage - $firstPage;
        }

        if ($wNode->field_heftreferenz->field_ref_zeitschrift->value ()) {
          $journalTitle = $wNode->field_heftreferenz->field_ref_zeitschrift->name->value ();
        }

        if ($wNode->field_heftreferenz->field_jahr->value ()) {
          $year = $wNode->field_heftreferenz->field_jahr->name->value ();
        }

        if ($wNode->field_heftreferenz->field_heftnummer->value ()) {
          $number = $wNode->field_heftreferenz->field_heftnummer->value ();
        }
      }

      if ($wNode->field_untertitel->value ()) {
        $subtitle = $wNode->field_untertitel->value ();
      }

      if ($wNode->field_herausgeber_autor->value ()) {
        foreach ($wNode->field_herausgeber_autor->value () as $authorKey => $authorValue) {
          $authorArray[] = $authorValue->name;
        }
        $authors = implode ($authorArray, ', ');
      }

      if ($wNode->field_keywords->value ()) {
        foreach ($wNode->field_keywords->value () as $keywordsKey => $keywordsValue) {
          $keywordsArray[] = $keywordsValue->name;
        }
        $keywords = implode ($keywordsArray, ' | ');
      }

      $libraryItem = array(
        'title' => $wNode->title->value (),
        'subtitle' => $subtitle,
        'pages' => $pages,
        'description' => $text,
        'image' => $image,
        'authors' => $authors,
        'keywords' => $keywords,
        'journalTitle' => $journalTitle,
        'number' => $number,
        'year' => $year,
        'isbn' => $isbn,
        'issn' => $issn,
      );
    }

    return $libraryItem;
  }

}
