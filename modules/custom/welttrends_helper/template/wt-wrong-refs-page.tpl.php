<?php
//kpr ($variables);
?>


<div id="wrong-refs">
    <table class="table">
        <thead>
            <tr>
                <th>pid</th>
                <th>type</th>
                <th>sku</th>
                <th>product name</th>
                <th>nid</th>
                <th>page</th>
                <th>edit</th>
            </tr>
        </thead>
        <tbody>
            <?php foreach ($variables['items'] as $rowKey => $rowValue): ?>
              <tr>
                  <td rowspan="<?php print $rowValue['count'];?>"><?php print $rowValue['pid']; ?></td>
                  <td rowspan="<?php print $rowValue['count'];?>"><?php print $rowValue['type']; ?></td>
                  <td rowspan="<?php print $rowValue['count'];?>"><?php print $rowValue['sku']; ?></td>
                  <td rowspan="<?php print $rowValue['count'];?>"><?php print $rowValue['product_title']; ?></td>
                  <?php foreach ($rowValue['nodes'] as $nodeKey => $nodeValue): ?>
                    <td><?php print $nodeValue['nid']; ?></td>
                    <td><?php print $nodeValue['title']; ?></td>
                    <td><a href="<?php print url ('node/' . $nodeValue['nid'] . '/edit', array('absolute' => TRUE)); ?>"><?php print t ('Edit'); ?></a></td>
                  </tr>
                  <?php endforeach; ?>
              

            <?php endforeach; ?>
        </tbody>

    </table>


</div>