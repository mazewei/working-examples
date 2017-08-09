<?php
$wNode = entity_metadata_wrapper ('node', $node);
if ($wNode->field_erste_seite->value ()) {
  $startPage = $wNode->field_erste_seite->value ();
}
if ($wNode->field_letzte_seite->value ()) {
  $pages = $wNode->field_letzte_seite->value () - $startPage;
}

if ($wNode->field_heftreferenz->field_ref_zeitschrift->field_sub_possible->value () == 1) {
  $subscribable = $wNode->field_heftreferenz->field_ref_zeitschrift->field_sub_possible->value ();
}
else {
  $subscribable = FALSE;
}

//get shortname
if ($wNode->field_heftreferenz->field_ref_zeitschrift->field_short_name->value ()) {
  $journalTitle = $wNode->field_heftreferenz->field_ref_zeitschrift->field_short_name->value ();
}
else {
  $journalTitle = $wNode->field_heftreferenz->field_ref_zeitschrift->name->value ();
}

//get the human readable price
$price = commerce_currency_format ($elements['product:commerce_price']['#items'][0]['amount'], $elements['product:commerce_price']['#items'][0]['currency_code']);

//build author links
$editorArray = $elements['#node']->field_herausgeber_autor['und'];
foreach ($editorArray as $key => $value) {
//  $editor[] = $value['taxonomy_term']->name;
  $editor[] = l ($value['taxonomy_term']->name, url ('e-papers', array('absolute' => TRUE)), array('query' =>
    array('search' => $value['taxonomy_term']->name)
      )
  );
}
$printableEditor = implode (', ', $editor);

//build keyword links
$keywordArray = $elements['#node']->field_keywords['und'];
foreach ($keywordArray as $key => $value) {
//  $keywords[] = $value['taxonomy_term']->name;
  $keywords[] = l ($value['taxonomy_term']->name, url ('journals', array('absolute' => TRUE)), array('query' =>
    array('search' => $value['taxonomy_term']->name)
      )
  );
}
$printableKeywords = implode (' | ', $keywords);

//add to cart field for journal
$content = node_view ($wNode->field_heftreferenz->value (), 'full');
$fieldOutput = $content['field_heft'];

//kpr ($wNode->field_heftreferenz->field_ref_zeitschrift->tid->value ());
?>
<div id="node-article-detail-page">
    <div class="journal-content col-md-8">

        <h1>
            <?php print $wNode->title->value (); ?>
        </h1>
        <div class="subtitle">
            <?php print $wNode->field_untertitel->value (); ?>
        </div>

        <div class="sub-info">
            <p class="sub-info-pages">
                <?php if (!empty ($pages)): ?>
                  <?php print $pages; ?> <?php print t ('Pages'); ?> | <?php print t ('Author') . ': '; ?><?php print $printableEditor; ?>
                <?php endif; ?>
            </p>
        </div>
        <div class="description">
            <?php print $wNode->field_abstract->value ()['safe_value']; ?>
        </div>

        <div class="keywords-journal">
            <b><?php print t ('Keywords') . ': '; ?></b><?php print $printableKeywords; ?>
        </div>
        <div class="add-to-cart-element-small">
            <div class="article-price">
                <p>
                    <?php print t ('PDF: '); ?><?php print $price; ?>
                </p>
            </div>
            <?php print render ($elements['field_artikel']) ?>
            <?php if ($subscribable == TRUE): ?>

            <?php endif; ?>
        </div>    
    </div>
    <div class="cover-image col-md-4">
        <div class="subtitle-left">
            <?php print t ('Come out'); ?>
        </div>
        <a href="<?php print url ('node/' . $wNode->field_heftreferenz->nid->value (), array('absolute' => TRUE)) ?>">
            <?php
            print theme_image_style (array(
              'style_name' => 'listen_teaser_bild',
              'path' => $wNode->field_heftreferenz->field_coverbild->value ()['uri'],
              'attributes' => array(
                'class' => 'img img-responsive wt-full-node-img')));
            ?>
        </a>
        <div class="metainfo-article">
            <?php print $journalTitle; ?> 
            <?php print $wNode->field_heftreferenz->field_heftnummer->value (); ?> | 
            <?php print $wNode->field_heftreferenz->field_jahr->name->value (); ?>
            <div class="journal-title-article">
                <a href="<?php print url ('node/' . $wNode->field_heftreferenz->nid->value (), array('absolute' => TRUE)) ?>">
                    <?php print $wNode->field_heftreferenz->title->value (); ?>
                </a>
            </div>
            <?php print $wNode->field_heftreferenz->field_anzahl_seiten->value (); ?> <?php print t ('Pages'); ?>


        </div>
        <div class="add-to-cart-element">
            <?php print render ($fieldOutput); ?>
            <?php if ($subscribable == TRUE): ?>
              <div class="subscribe-journal">
                  <?php
                  print l (t ('Subscribe !title', array(
                    '!title' => $journalTitle)), url ('eform/submit/abo-bestellen', array('absolute' => TRUE)), array('attributes' =>
                    array('class' => 'btn btn-default btn-subscribe')), array('query' => array(
                      'field_sub_product' => $wNode->field_heftreferenz->field_ref_zeitschrift->tid->value ())));
                  ?>
              </div>
            <?php endif; ?>
        </div> 


    </div>
</div>








