<?php
/**
 * @file
 * Template for login dropd down.
 *
 * Available variables
 * - $login_form (array): renderable login form array
 * - $login_url: url for login button/link
 * - $login_link_text: logout button/link text.
 */
?>
<div class="dropdown">
  <a href="<?php print $login_url; ?>" class="btn btn-default dropdown-toggle" id="dropdownMenu1" data-toggle="dropdown">
    <?php print $login_link_text; ?>
  </a>
  <div class="dropdown-menu" aria-labelledby="dropdownMenu1">
    <?php if(!empty($login_form)):?>
      <?php print render($login_form); ?>
    <?php endif; ?>
  </div>
</div>
