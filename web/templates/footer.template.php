<?php
if (!isset($param['no-margin-top'])): ?>
<div style="height:40px;">
</div>
<?php endif;?>
<div id="footer">
   <div class="clear"></div>
   <div id="footer-content">
      <div id="footer-links">
         <a href="<?= URL;?>sobre-omi">Sobre OMI</a>
         <a href="<?= URL;?>contacto">Contacto</a>
         <a href="<?= URL;?>licencia">Licencia</a>
      </div>
      <div id="logos-list">
         <img src="<?= URL;?>src/images/gplv3.svg"/>
         <img src="<?= URL;?>src/images/cc.svg"/>
         <div id="copyleft"><img src="<?= URL;?>src/images/copyleft.svg"/> <span>2015 OMI.</span></div>
      </div>
   </div>
</div>
<script src="//code.jquery.com/jquery-1.11.3.min.js"></script>
</body>
</html>
