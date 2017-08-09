<?php ?>  
    <h2 class="contact">Kontakt</h2>
    <div class="col-xs-12 col-sm-6">
        <?php print render ($form['name']); ?>
        <?php print render ($form['mail']); ?>
        <?php print render ($form['subject']); ?>
    </div>
    <div class="col-xs-12 col-sm-6">
        <?php print render ($form['message']); ?>

    </div>
    <div class="col-xs-12">
        <?php print render ($form['actions']['submit']); ?>
    </div>
<?php print render ($form['form_build_id']); ?>
<?php print render ($form['form_token']); ?>
<?php print render ($form['form_id']); ?>
