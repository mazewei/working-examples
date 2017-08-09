<?php
$refContent = $elements['#node']->field_artikelreferenz['und'];
//kpr($refContent);
foreach ($refContent as $refKey => $refValue) {
  $refWNode = entity_metadata_wrapper ('node', $refValue['node']);
  if ($refWNode->field_herausgeber_autor->value ()) {
    foreach ($refWNode->field_herausgeber_autor->value () as $authorKey => $authorValue) {
      $authors[] = $authorValue->name;
    }
  }
  $artikelRef[] = array(
    'title' => $refWNode->title->value (),
    'subtitle' => $refWNode->field_untertitel->value (),
    'nid' => $refWNode->nid->value (),
    'author' => implode (', ', $authors),
  );
  unset ($authors);
}

$downloadUrl = array(
  'url' => file_create_url ($elements['#node']->field_pdf_online['und'][0]['uri']),
  'fileName' => $elements['#node']->field_pdf_online['und'][0]['filename'],
);

//wrap the node
$wNode = entity_metadata_wrapper ('node', $node);

//check if journal is subscribable
if ($wNode->field_ref_zeitschrift->field_sub_possible->value () == 1) {
  $subscribable = $wNode->field_ref_zeitschrift->field_sub_possible->value ();
}
else {
  $subscribable = FALSE;
}

//build editor links
$editorArray = $wNode->field_herausgeber_autor->value ();
foreach ($editorArray as $key => $value) {
  $editor[] = l ($value->name, url ('suche', array('absolute' => TRUE)), array('query' =>
    array('search' => $value->name)
      )
  );
}
$printableEditor = implode (' | ', $editor);

//build author links
$authorArray = $wNode->field_author->value ();
foreach ($authorArray as $authorKey => $authorValue) {
  $author[] = l ($authorValue->name, url ('suche', array('absolute' => TRUE)), array('query' =>
    array('search' => $authorValue->name)
      )
  );
}
$printableAuthor = implode (' | ', $author);

//build keyword links
$keywordArray = $wNode->field_keywords->value ();
foreach ($keywordArray as $key => $value) {

  $keywords[] = l ($value->name, url ('suche', array('absolute' => TRUE)), array('query' =>
    array('search' => $value->name)
      )
  );
}

$printableKeywords = implode (' | ', $keywords);

//get shortname
if ($wNode->field_ref_zeitschrift->field_short_name->value ()) {
  $journalTitle = $wNode->field_ref_zeitschrift->field_short_name->value ();
}
else {
  $journalTitle = $wNode->field_ref_zeitschrift->name->value ();
}
?>

<div id="node-heft-detail-page">
    <div class="cover-image col-md-4">
        <?php
        print theme_image_style (array(
          'style_name' => 'listen_teaser_bild',
          'path' => $elements['#node']->field_coverbild['und'][0]['uri'],
          'attributes' => array(
            'class' => 'img img-responsive wt-full-node-img')));
        ?>
        <div class="add-to-cart-element">
            <?php print render ($elements['field_heft']) ?>

            <?php if ($subscribable == TRUE): ?>
              <div class="subscribe-journal">
                  <?php
                  print l (t ('Subscribe !title', array('!title' => $journalTitle)), url ('eform/submit/abo-bestellen', array('absolute' => TRUE)), array('attributes' => array('class' => 'btn btn-default btn-subscribe')), array('query' =>
                    array('field_sub_product' => $wNode->field_ref_zeitschrift->tid->value ())));
                  ?>
              </div>
            <?php endif; ?>
        </div>  

    </div>

    <div class="journal-content col-md-8">
        <p class="metainfo">
            <?php print $wNode->field_ref_zeitschrift->name->value (); ?> <?php print $wNode->field_heftnummer->value (); ?> | <?php print $wNode->field_jahr->name->value (); ?>
        </p>
        <h1>
            <?php print $wNode->title->value (); ?>
        </h1>
        <div class="subtitle">
            <?php print $wNode->field_untertitel->value (); ?>
        </div>

        <?php if (isset ($printableEditor)): ?>
          <div class="editor-journal">
              <?php print t ('Editor') . ': '; ?><?php print $printableEditor; ?>
          </div>
        <?php endif; ?>
        <?php if (isset ($printableAuthor)): ?>
          <div class="editor-journal">
              <?php print t ('Author') . ': '; ?><?php print $printableAuthor; ?>
          </div>
        <?php endif; ?>
        <div class="sub-info">
            <p class="sub-info-pages">
                <?php if ($wNode->field_isbn_issn->value ()): ?>
                  <?php print t ('ISBN '); ?>
                  <?php print $wNode->field_isbn_issn->value (); ?>
                  <?php print ' | '; ?>
                <?php endif; ?>
                <?php if ($wNode->field_issn->value ()): ?>
                  <?php print t ('ISSN '); ?>
                  <?php print $wNode->field_issn->value (); ?>
                  <?php print ' | '; ?>
                <?php endif; ?>
                <?php print $wNode->field_anzahl_seiten->value (); ?> <?php print t ('Pages'); ?>
            </p>
            <p>

            </p>
        </div>
        <div class="description">
            <?php print $wNode->field_heft_editorial->value ()['safe_value']; ?>
        </div>

        <div class="keywords-journal">
            <b><?php print t ('Keywords') . ': '; ?></b><?php print $printableKeywords; ?>
        </div>
    </div>
    <div class="bottom-content col-xs-12">
        <?php if (isset ($artikelRef)): ?>
          <h3 class="uppercase"><?php print t ('Content'); ?></h3>
          <ul class="list-unstyled">
              <?php foreach ($artikelRef as $refKey => $refValue): ?>
                <li class="journal-content">
                    <div class="journal-headline">
                        <a class="" href="<?php print url ('node/' . $refValue['nid'], array('absolute' => TRUE)); ?>">
                            <?php print $refValue['title']; ?>
                        </a>
                    </div>
                    <div class="journal-subheadline">
                        <?php print $refValue['subtitle']; ?>
                    </div>
                    <div class="author">
                        <?php print $refValue['author']; ?>
                    </div>
                </li>

              <?php endforeach; ?>
          </ul>
        <?php endif; ?>
    </div>
</div>
