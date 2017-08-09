<?php
$wNode = entity_metadata_wrapper ('node', $elements['#node']);

//$refContent = $elements['#node']->field_artikelreferenz['und'];
////kpr($refContent);
//foreach ($refContent as $refKey => $refValue) {
//  $refWNode = entity_metadata_wrapper ('node', $refValue['node']);
//  if ($refWNode->field_herausgeber_autor->value ()) {
//    foreach ($refWNode->field_herausgeber_autor->value () as $authorKey => $authorValue) {
//      $authors[] = $authorValue->name;
//    }
//  }
//  $artikelRef[] = array(
//    'title' => $refWNode->title->value (),
//    'subtitle' => $refWNode->field_untertitel->value (),
//    'nid' => $refWNode->nid->value (),
//    'author' => implode (', ', $authors),
//  );
//  unset ($authors);
//}
//
//$downloadUrl = array(
//  'url' => file_create_url ($elements['#node']->field_pdf_online['und'][0]['uri']),
//  'fileName' => $elements['#node']->field_pdf_online['und'][0]['filename'],
//);
//
////wrap the node
//$wNode = entity_metadata_wrapper ('node', $node);
//
////check if journal is subscribable
//if ($wNode->field_ref_zeitschrift->field_sub_possible->value () == 1) {
//  $subscribable = $wNode->field_ref_zeitschrift->field_sub_possible->value ();
//}
//else {
//  $subscribable = FALSE;
//}
//
////build editor links
//$editorArray = $wNode->field_herausgeber_autor->value ();
//foreach ($editorArray as $key => $value) {
//  $editor[] = l ($value->name, url ('journals', array('absolute' => TRUE)), array('query' =>
//    array('search' => $value->name)
//      )
//  );
//}
//$printableEditor = implode (' | ', $editor);
//
////build author links
//$authorArray = $wNode->field_author->value ();
//foreach ($authorArray as $authorKey => $authorValue) {
//  $author[] = l ($authorValue->name, url ('journals', array('absolute' => TRUE)), array('query' =>
//    array('search' => $authorValue->name)
//      )
//  );
//}
//$printableAuthor = implode (' | ', $author);
//
////build keyword links
//$keywordArray = $wNode->field_keywords->value ();
//foreach ($keywordArray as $key => $value) {
//
//  $keywords[] = l ($value->name, url ('journals', array('absolute' => TRUE)), array('query' =>
//    array('search' => $value->name)
//      )
//  );
//}
//
//$printableKeywords = implode (' | ', $keywords);
//
//get shortname
if ($wNode->type->value () == 'heft') {
  if ($wNode->field_ref_zeitschrift->field_short_name->value ()) {
    $journalTitle = $wNode->field_ref_zeitschrift->field_short_name->value ();
  }
  else {
    $journalTitle = $wNode->field_ref_zeitschrift->name->value ();
  }
}
if ($wNode->type->value () == 'artikel') {

  //build page numbers
  if ($wNode->field_erste_seite->value ()) {
    $firstPage = $wNode->field_erste_seite->value ();
  }

  if ($wNode->field_letzte_seite->value ()) {
    $lastPage = $wNode->field_letzte_seite->value ();
  }

  if (isset ($firstPage) && isset ($lastPage)) {
    $pages = $lastPage - $firstPage + 1;
  }

//get the human readable price
  $price = commerce_currency_format ($elements['product:commerce_price']['#items'][0]['amount'], $elements['product:commerce_price']['#items'][0]['currency_code']);


//build author links
  $editorArray = $wNode->field_herausgeber_autor->value ();
  foreach ($editorArray as $key => $value) {

    $editorCount += strlen ($value->name);

    if ($editorCount <= 60) {
      $editor[] = l ($value->name, url ('suche', array('absolute' => TRUE)), array('query' =>
        array('search' => $value->name)
          )
      );
    }
  }
  $printableEditor = implode (', ', $editor);
}
?>

<div id="node-heft-detail-page" class="fulltext-search">
    <?php if ($wNode->type->value () == 'heft'): ?>

      <div class="thumbnail">
          <div class="teaser-image">
              <a class="teaser-link" href="<?php print url ('node/' . $node->nid, array('absolute' => TRUE)); ?>">
                  <?php print theme_image_style (array('style_name' => 'listen_teaser_bild', 'path' => $wNode->field_coverbild->value ()['uri'], 'attributes' => array('class' => 'img img-responsive wt-teaser-img'))); ?>
              </a>    
          </div>

          <div class="caption">
              <p class="metainfo-fulltext-search">
                  <?php print $journalTitle; ?> <?php print $wNode->field_heftnummer->value (); ?> | <?php print $wNode->field_jahr->name->value (); ?>
              </p>
              <h2 class="teaser-headline-fulltext-search">
                  <a class="teaser-link" href="<?php print url ('node/' . $node->nid, array('absolute' => TRUE)); ?>">
                      <?php print truncate_utf8 ($wNode->title->value (), 45, FALSE, TRUE, 3); ?>
                  </a>
              </h2>

              <div class="sub-info">

                  <a class="teaser-link" href="<?php print url ('node/' . $node->nid, array('absolute' => TRUE)); ?>">
                      <?php print t ('...read more'); ?>
                  </a>
              </div>
              <div class="add-to-cart-element" style="height:80px;">
                  <?php print render ($elements['field_heft']) ?>
              </div>         
          </div>
      </div>

    <?php elseif ($wNode->type->value () == 'artikel'): ?>
      <div class="thumbnail">
          <div class="teaser-image">
              <a class="teaser-link" href="<?php print url ('node/' . $node->nid, array('absolute' => TRUE)); ?>">
                  <?php print theme_image_style (array('style_name' => 'listen_teaser_bild', 'path' => $wNode->field_coverbild->value ()['uri'], 'attributes' => array('class' => 'img img-responsive wt-teaser-img'))); ?>
              </a>    
          </div>

          <div class="caption">
              <div class="metainfo-fulltext-search">
                  <?php print $printableEditor; ?>
              </div>
              <h2 class="teaser-headline-fulltext-search">
                  <a class="teaser-link" href="<?php print url ('node/' . $node->nid, array('absolute' => TRUE)); ?>">
                      <?php print truncate_utf8 ($wNode->title->value (), 40, FALSE, TRUE, 3); ?>
                  </a>
              </h2>
              <div class="sub-info">

                  <a class="teaser-link" href="<?php print url ('node/' . $node->nid, array('absolute' => TRUE)); ?>">
                      <?php print t ('...read more'); ?>
                  </a>
              </div>
              <div class="add-to-cart-element" style="height:80px;">
                  <div class="info-teaser">
                      <?php print $pages; ?> <?php print t ('Pages'); ?><?php print t ('&nbsp;|&nbsp;'); ?>
                      <?php print t ('PDF'); ?> <?php print $price; ?>
                  </div>
                  <?php print render ($elements['field_artikel']) ?>
              </div>         
          </div>
      </div>
    <?php endif; ?>

</div>
