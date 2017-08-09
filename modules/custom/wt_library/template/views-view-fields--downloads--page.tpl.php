<?php
//kpr($variables);
//kpr($variables['items']);
?> 
<div class="wt-library">
    <?php if (!empty ($variables['items'])): ?>
      <div class="library-item">
          <div class="col-md-1 col-sm-12 col-xs-12 type-container">
              <div class="library-type">
                  <?php print $variables['items']->content['type']; ?>
              </div>
          </div>
          <div class="library-image col-xs-12 col-sm-5 col-md-3 col-lg-2">
              <img src="<?php print $variables['items']->content['image'] ?>" class="img img-responsive" />
          </div>
          <div class="library-body col-xs-12 col-sm-7 col-md-8 col-lg-10">
              <div class="metainfo">
                  <?php if ($variables['items']->type == 'heft'): ?>
                    <?php print $variables['items']->content['journalTitle']; ?> <?php print $variables['items']->content['number']; ?> | <?php print $variables['items']->content['year']; ?>
                  <?php elseif ($variables['items']->type == 'artikel'): ?>
                    <?php print $variables['items']->content['authors']; ?>
                  <?php endif; ?>
              </div>
              <h2 class="media-heading">
                  <?php print $variables['items']->content['title']; ?>
              </h2>
              <?php if ($variables['items']->type == 'artikel'): ?>
                <div class="subtitle">
                    <?php print $variables['items']->content['subtitle']; ?>
                </div>
              <?php else: ?>
                <?php print t ('Editor') . ': '; ?><?php print $variables['items']->content['authors']; ?>
                <div class="isbn">
                    <?php if (isset ($variables['items']->content['isbn'])): ?>
                      ISBN: <?php print $variables['items']->content['isbn']; ?> | 
                    <?php endif; ?>
                    <?php if (isset ($variables['items']->content['issn'])): ?>
                      ISSN: <?php print $variables['items']->content['issn']; ?>
                    <?php endif; ?>
                </div>
              <?php endif; ?>

              <?php print truncate_utf8 ($variables['items']->content['description'], 350, TRUE, TRUE, 3); ?>
              <div class="keywords-journal">
                  <b>
                      <?php print t ('Keywords') . ': '; ?>
                  </b>
                  <?php print $variables['items']->content['keywords']; ?>
              </div>
              <div class="add-to-cart-element">

                  <div class="subscribe-journal">
                      <a class="btn btn-default btn-download" target="_new" href="<?php print $variables['items']->content['download']['url']; ?>">
                          <?php print t ('download for free'); ?>
                      </a>
                  </div>
                   <?php print render ($variables['items']->addToCartField); ?>
              </div>  


          </div>
      </div>
    <?php else: ?>
      <h3><?php print t ('no content, you could by some <a href="!url">here</a>', array('!url' => url ('<front>', array('absolute' => TRUE)))); ?></h3>
    <?php endif; ?>

</div>