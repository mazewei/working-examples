<?php
kpr($vars);
?>
<div id="wt-library">
    <?php if (!empty ($variables['items'])): ?>
      <ul class="library-list">
          <?php foreach ($variables['items'] as $nodeKey => $nodeValue): ?>
            <li class="library-item">
                <div class="col-md-1 col-sm-12 col-xs-12 type-container">
                    <div class="library-type">
                        <?php print $nodeValue->content['type']; ?>
                    </div>
                </div>
                <div class="library-image col-md-3 col-sm-12">
                    <img src="<?php print $nodeValue->content['image'] ?>" class="img img-responsive" />
                </div>
                <div class="library-body col-md-8 col-xs-12">
                    <div class="metainfo">
                        <?php if ($nodeValue->type == 'heft'): ?>
                          <?php print $nodeValue->content['journalTitle']; ?> <?php print $nodeValue->content['number']; ?> | <?php print $nodeValue->content['year']; ?>
                        <?php elseif ($nodeValue->type == 'artikel'): ?>
                          <?php print $nodeValue->content['authors']; ?>
                        <?php endif; ?>
                    </div>
                    <h2 class="media-heading">
                        <?php print $nodeValue->content['title']; ?>
                    </h2>
                    <?php if ($nodeValue->type == 'artikel'): ?>
                      <div class="subtitle">
                          <?php print $nodeValue->content['subtitle']; ?>
                      </div>
                    <?php else: ?>
                      <?php print t ('Editor') . ': '; ?><?php print $nodeValue->content['authors']; ?>
                      <div class="isbn">
                          <?php if (isset ($nodeValue->content['isbn'])): ?>
                            ISBN: <?php print $nodeValue->content['isbn']; ?> | 
                          <?php endif; ?>
                          <?php if (isset ($nodeValue->content['issn'])): ?>
                            ISSN: <?php print $nodeValue->content['issn']; ?>
                          <?php endif; ?>
                      </div>
                    <?php endif; ?>

                    <?php print truncate_utf8 ($nodeValue->content['description'], 350, TRUE, TRUE, 3); ?>
                    <div class="keywords-journal">
                        <b>
                            <?php print t ('Keywords') . ': '; ?>
                        </b>
                        <?php print $nodeValue->content['keywords']; ?>
                    </div>
                    <p>
                        <a target="_new" href="<?php print $nodeValue->content['download']['url']; ?>">
                            <?php print t ('download %title', array('%title' => $nodeValue->content['download']['filename'])); ?>
                        </a>
                    </p>
                    <div class="add-to-cart-element">
                        <?php print render ($nodeValue->addToCartField); ?>
                    </div>  
                </div>
            </li>
          <?php endforeach; ?>
      </ul>
    <?php else: ?>
      <h3><?php print t ('no content, you could by some <a href="!url">here</a>', array('!url' => url ('<front>', array('absolute' => TRUE)))); ?></h3>
    <?php endif; ?>

</div>
