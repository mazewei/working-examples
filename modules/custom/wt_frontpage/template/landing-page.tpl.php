<?php
//dpm($pageContent);
?>

<div class="container">
    <div id="myCarousel" class="carousel slide">  
        <div class="carousel-inner">
            <?php foreach ($pageContent as $pageKey => $pageValue): ?>
              <?php if ($pageKey == 0): ?>
                <div class="item active">
                  <?php else: ?>
                    <div class="item">
                      <?php endif; ?>
                      <img src="http://lorempixel.com/output/city-q-c-1200-300-5.jpg" alt="Slide1">
                      <div class="container">
                          <div class="carousel-caption">
                              <h2><span><?php print $pageValue->title; ?></span></h2>
                              <div class="slide-caption"><?php print truncate_utf8 ($pageValue->editorial, 200, TRUE, TRUE, 3); ?></div>
                              <p><a class="btn btn-danger" href="<?php print(url ($pageValue->url, array('absolute' => TRUE))); ?>">Read More <i class="fa fa-angle-double-right"></i></a>
                              </p></div>
                      </div>
                  </div>
                <?php endforeach; ?>

            </div>
            <!-- Controls -->
            <a class="left carousel-control" href="#myCarousel" data-slide="prev"><span class="control-left"></span></a>
            <a class="right carousel-control" href="#myCarousel" data-slide="next"><span class="control-right"></span></a>  
        </div>

        <div class="bestseller">
            <?php $block = module_invoke ('wt_frontpage', 'block_view', 'bestseller'); ?>
            <h1 class="page-header-front">
                <?php print render ($block['subject']); ?>
            </h1>
            <?php print render ($block['content']); ?>
        </div>
    </div>

