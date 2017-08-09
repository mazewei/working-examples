<?php
/**
 * @file
 * Template for logout button.
 *
 * Available variables
 * - $logout_url: url for logout button/link
 * - $logout_link_text: logout button/link text.
 */
?>
<div class="drop-down-login-container">
  <a href="<?php print $logout_url; ?>" class="btn btn-default">
    <?php print $logout_link_text; ?>
  </a>
</div>
