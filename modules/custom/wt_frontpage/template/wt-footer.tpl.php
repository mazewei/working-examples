<?php 
//    kpr($variables);
?>

<div class="white">
    <img src="<?php print $variables['logo']; ?>" />
    <div class="caption">
        <h3 class="white">
            <?php print $variables['name']; ?>
            <br />
            <span class="smaller"><?php print $variables['additional_name']; ?></span>
        </h3>
        <p class="white small-margin"><?php print $variables['street']; ?></p>
        <p class="white small-margin"><?php print $variables['city']; ?></p>
        <p class="white small-margin"><label><?php print t('Phone');?>:</label> <?php print $variables['phone']; ?></p>
        <p class="white small-margin"><label><?php print t('Fax');?>:</label> <?php print $variables['fax']; ?></p>
    </div>
</div>


