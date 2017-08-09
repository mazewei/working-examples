<?php
//node wrappen for easy displaying the content
$wNode = entity_metadata_wrapper ('node', $node);
//kpr($wNode->value());

if ($wNode->field_ref_zeitschrift->field_short_name->value ()) {
  $journalTitle = $wNode->field_ref_zeitschrift->field_short_name->value ();
}
else {
  $journalTitle = $wNode->field_ref_zeitschrift->name->value ();
}
?>
<div id="wt-standard-teaser">
    <div class="thumbnail">
        <div class="teaser-image">
            <a class="teaser-link" href="<?php print url ('node/' . $node->nid, array('absolute' => TRUE)); ?>">
                <?php print theme_image_style (array('style_name' => 'listen_teaser_bild', 'path' => $wNode->field_coverbild->value ()['uri'], 'attributes' => array('class' => 'img img-responsive wt-teaser-img'))); ?>
            </a>    
        </div>
        <div class="caption">
            <p class="metainfo">
                <?php print $journalTitle; ?> <?php print $wNode->field_heftnummer->value (); ?> | <?php print $wNode->field_jahr->name->value (); ?>
            </p>
            <h2 class="teaser-headline">
                <a class="teaser-link" href="<?php print url ('node/' . $node->nid, array('absolute' => TRUE)); ?>">
                    <?php print truncate_utf8 ($wNode->title->value (), 45, FALSE, TRUE, 3); ?>
                </a>
            </h2>

            <div class="sub-info">
                <p class="sub-info-pages">
                    <?php print $wNode->field_anzahl_seiten->value (); ?> <?php print t ('Pages'); ?>
                </p>
                <a class="teaser-link" href="<?php print url ('node/' . $node->nid, array('absolute' => TRUE)); ?>">
                    <?php print t ('...read more'); ?>
                </a>
            </div>
            <div class="add-to-cart-element">
                <?php print render ($elements['field_heft']) ?>
            </div>         
        </div>
    </div>
</div>
