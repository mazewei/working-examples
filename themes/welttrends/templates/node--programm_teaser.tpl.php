<?php ?>
<div class="programm-teaser thumbnail col-xs-12">

    <div class="cover-image hidden-xs col-sm-4">
        <?php print render($elements['field_coverbild']); ?>
    </div>
    <div class="programm-teaser-content col-xs-12 col-sm-8">
        <h2><?php print render($node->title); ?></h2>
        <h3><?php print render($elements['field_untertitel']); ?></h3>
        <?php print render($elements['field_body']); ?>
        <?php print render($elements['field_e_mail']); ?>
        <?php print render($elements['field_mediadaten']); ?>
    </div>

</div>
