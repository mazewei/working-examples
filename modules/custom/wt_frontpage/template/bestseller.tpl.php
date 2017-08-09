<?php
//kpr ($variables);
?>
<?php foreach ($variables['teaser'] as $teaserKey => $teaserValue): ?>
  <div class="col-md-3 col-xs-12 wt-standard-teaser">
      <?php $node = node_view ($teaserValue, 'frontpage_teaser'); ?>
      <?php print drupal_render ($node); ?>
  </div>
<?php endforeach; ?>




