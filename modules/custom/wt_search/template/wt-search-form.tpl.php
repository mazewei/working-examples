<div id=filterblock" class="filterblock">
    <div class="filter-elements">
        <?php print render($form['search_field']); ?>
        <?php print render($form['journals']); ?>
        <?php print render($form['submit']); ?>
    </div>
    <div id="teaser-content" class="teaser-content">
        <?php foreach ($variables['pages'] as $key => $nodeValue): ?>
            <div class="col-md-4 col-xs-12">
                <?php print drupal_render(node_view($nodeValue, 'listen_teaser')); ?>
            </div>
        <?php endforeach; ?>
    </div>
</div>
