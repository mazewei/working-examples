<?php
?>

<div class="wt-about">
    <div class="programm-teaser-content col-xs-12 col-sm-6">
        <blockquote class="blockquote">
            <?php print $about_wt['description']; ?>
        </blockquote>
    </div>
    <div class="cover-image hidden-xs col-sm-6">
        <img src="<?php print $about_wt['image']; ?>" class="img-responsive img-thumbnail"/>
    </div>

</div>
<?php foreach ($wt_publications as $pubKey => $pubValue): ?>

  <div class="programm-teaser thumbnail col-xs-12">
      <div class="cover-image hidden-xs col-sm-4">
          <img src="<?php print $pubValue['image']; ?>" class="img-responsive img-thumbnail"/>
      </div>
      <div class="programm-teaser-content col-xs-12 col-sm-8">
          <h2><?php print $pubValue['title']; ?><br /><small><?php print $pubValue['subtitle']; ?></small></h2>
          <blockquote class="blockquote">
              <?php print $pubValue['description']; ?>
          </blockquote>
          <p>
              <i class="labeled contact"></i>
              <?php print $pubValue['contact']; ?>  
          </p>
          <p>
              <i class="labeled url"></i>
              <a href="<?php print $pubValue['web']; ?>"><?php print t ('Homepage'); ?></a>
          </p>
          <p>
              <i class="labeled media-data"></i>
              <a href="<?php print $pubValue['mediadata']; ?>"><?php print t ('Media data'); ?></a>
          </p>

      </div>
  </div>
<?php endforeach; ?>



