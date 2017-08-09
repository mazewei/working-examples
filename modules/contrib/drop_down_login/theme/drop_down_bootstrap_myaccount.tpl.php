<?php
/**
 * @file
 * Template for myaccount dropdown.
 *
 * Available variables
 * - $myaccount_text: drop down myaccount button/link text
 * - $myaccount_url: url for myaccount button/link
 * - $myaccount_links: myaccount drop down additional links
 * sorted by weight.
 */
?>
<div class="dropdown">
  <?php if (!empty($profile_image)): ?>
    <a class="dropdown-toggle my-account" href="<?php print $myaccount_url; ?>" id="dropdownMenu1" data-toggle="dropdown">
      <img class="profile-pic" src="<?php print $profile_image?>" alt="<?php print t('Profile picture')?>">
    </a>
  <?php else: ?>
    <a href="<?php print $myaccount_url; ?>" class="btn btn-default dropdown-toggle my-account" type="button" id="dropdownMenu1" data-toggle="dropdown">
      <?php print $myaccount_text; ?>
    </a>
  <?php endif; ?>
  <ul class="dropdown-menu" aria-labelledby="dropdownMenu1">
      <li>
        <a href="<?php print url('user');?>">
            <div>
              <strong><?php print $account->name; ?></strong>
            </div>
            <span><?php print t('View profile');?></span>
        </a>
      </li>
      <?php if (!empty($myaccount_links)): ?>
      <?php foreach ($myaccount_links as $item): ?>
        <li>
          <?php print l($item['menu']['menu_name'], $item['menu']['menu_url']); ?>
        </li>
      <?php endforeach; ?>
      <?php endif; ?>
      <li>
        <?php print l(t('Log out'), 'user/logout'); ?>
      </li>
    </ul>
</div>
