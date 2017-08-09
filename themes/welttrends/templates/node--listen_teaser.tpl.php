<?php
$wNode = entity_metadata_wrapper ('node', $node);

//build page numbers
if ($wNode->field_erste_seite->value ()) {
  $firstPage = $wNode->field_erste_seite->value ();
}

if ($wNode->field_letzte_seite->value ()) {
  $lastPage = $wNode->field_letzte_seite->value ();
}

if (isset ($firstPage) && isset ($lastPage)) {
  $pages = $lastPage - $firstPage +1;
}

//build keyword links
if ($wNode->field_keywords->value ()) {
  foreach ($wNode->field_keywords->value () as $keywordsKey => $keywordsValue) {
    $keywordsArray[] = l ($keywordsValue->name, url ('suche', array('absolute' => TRUE)), array('query' =>
      array('search' => $keywordsValue->name)
        )
    );
  }
  $keywords = implode ($keywordsArray, ' | ');
}

if ($wNode->field_heftreferenz->field_ref_zeitschrift->field_short_name->value ()) {
  $journalTitle = $wNode->field_heftreferenz->field_ref_zeitschrift->field_short_name->value ();
}
else {
  $journalTitle = $wNode->field_heftreferenz->field_ref_zeitschrift->name->value ();
}

//get the human readable price
$price = commerce_currency_format ($elements['product:commerce_price']['#items'][0]['amount'], $elements['product:commerce_price']['#items'][0]['currency_code']);

//build editor links
$editorArray = $elements['#node']->field_herausgeber_autor['und'];
$editorCount = 0;
foreach ($editorArray as $key => $value) {
  $editorCount += strlen ($value['taxonomy_term']->name);

  if ($editorCount <= 70) {
    $editor[] = l ($value['taxonomy_term']->name, url ('suche', array('absolute' => TRUE)), array('query' =>
      array('search' => $value['taxonomy_term']->name)
        )
    );
  }
}
$printableEditor = implode (' | ', $editor);
?>


<div class="thumbnail">
    <div class="caption">
        <div class="author">
            <?php print $printableEditor; ?>
        </div>
        <h2 class="teaser-headline">
            <a class="teaser-link" href="<?php print url ('node/' . $node->nid, array('absolute' => TRUE)); ?>">
                <?php print truncate_utf8 ($wNode->title->value (), 50, FALSE, TRUE, 3); ?>
            </a>
        </h2>
        <div class="subtitle">
            <?php print truncate_utf8 ($wNode->field_untertitel->value (), 60, FALSE, TRUE, 3); ?>
        </div>
        <p class="metainfo">
            <?php print t ('Come out' . ': '); ?>
            <b>
                <i>
                    <a href="<?php print url('node/' . $wNode->field_heftreferenz->nid->value (), array('absolute' => TRUE));?>">
                        <?php print $wNode->field_heftreferenz->title->value (); ?>
                    </a>
                </i>
            </b> 
            (<?php print $journalTitle; ?> 
            <?php print $wNode->field_heftreferenz->field_heftnummer->value (); ?> | 
            <?php print $wNode->field_heftreferenz->field_jahr->name->value (); ?>)
        </p>


        <div class="sub-info">
            <?php print t ('Keywords') . ':&nbsp;'; ?> <?php print $keywords; ?>
        </div>
        <div class="add-to-cart-element">
            <div class="info-teaser">
                <?php print $pages; ?> <?php print t ('Pages'); ?><?php print t ('&nbsp;|&nbsp;'); ?>
                <?php print t ('PDF'); ?> <?php print $price; ?>
            </div>
            <?php print render ($elements['field_artikel']) ?>
        </div>         
    </div>
</div>
