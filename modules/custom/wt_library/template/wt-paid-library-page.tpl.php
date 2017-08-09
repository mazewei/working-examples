<?php ?>

<div id="wt-library">
    <?php if (!empty ($variables['items'])): ?>
      <ul class="library-list">
          <?php foreach ($variables['items'] as $nodeKey => $nodeValue): ?>
            <li class="library-item">
                <div class="col-md-1 col-sm-12 col-xs-12 type-container">
                    <div class="library-type">
                        <?php print $nodeValue->type; ?>
                    </div>
                </div>
                <div class="library-image col-xs-12 col-sm-5 col-md-3 col-lg-2">
                    <img src="<?php print $nodeValue->node['image'] ?>" class="img img-responsive" />
                </div>
                <div class="library-body col-xs-12 col-sm-7 col-md-8 col-lg-10">
                    <div class="metainfo">
                        <?php if ($nodeValue->type == 'heft'): ?>
                          <?php print $nodeValue->node['journalTitle']; ?> <?php print $nodeValue->node['number']; ?> | <?php print $nodeValue->node['year']; ?>
                        <?php elseif ($nodeValue->type == 'artikel'): ?>
                          <?php print $nodeValue->node['authors']; ?>
                        <?php endif; ?>
                    </div>
                    <h2 class="media-heading">
                        <?php print $nodeValue->node['title']; ?>
                    </h2>
                    <?php if ($nodeValue->type == 'artikel'): ?>
                      <div class="subtitle">
                          <?php print $nodeValue->node['subtitle']; ?>
                      </div>
                    <?php else: ?>
                      <?php print t ('Editor') . ': '; ?><?php print $nodeValue->node['authors']; ?>
                      <div class="isbn">
                          <?php if (isset ($nodeValue->node['isbn'])): ?>
                            ISBN: <?php print $nodeValue->node['isbn']; ?> | 
                          <?php endif; ?>
                          <?php if (isset ($nodeValue->node['issn'])): ?>
                            ISSN: <?php print $nodeValue->node['issn']; ?>
                          <?php endif; ?>
                      </div>
                    <?php endif; ?>

                    <?php print truncate_utf8 ($nodeValue->node['description'], 350, TRUE, TRUE, 3); ?>
                    <div class="keywords-journal">
                        <b>
                            <?php print t ('Keywords') . ': '; ?>
                        </b>
                        <?php print $nodeValue->node['keywords']; ?>
                    </div>
                     <div class="subscribe-journal">
                      <a class="btn btn-default btn-download" target="_new" href="<?php print $nodeValue->file['file']; ?>">
                          <?php print t ('download'); ?>
                      </a>
                  </div>
                 
                </div>
            </li>
          <?php endforeach; ?>
      </ul>
    <?php else: ?>
      <h3><?php print t ('no content, you could by some <a href="!url">here</a>', array('!url' => url ('<front>', array('absolute' => TRUE)))); ?></h3>
    <?php endif; ?>

</div>