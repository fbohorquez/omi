<div id="top-mobile-panel" >
<a href="" id="menu" onclick="menu_animate();return false;" ><i class="fa fa-bars"></i></a> 
<a href="<?= URL;?>" id="menu-logo" ><img src="http://omi.local/src/images/logo-mobile.png" height="60"></a>
</div>
<script>
   var isanimate = false;
   function menu_animate () {
      if (!isanimate) {
         $( '#menu-options' ).show().animate({ height: '208' }, 1000, function() {});
         $(".logo").animate({ top: '+=208' }, 1000, function() {});
      }
      else{
         $( '#menu-options' ).animate({ height: '0' }, 1000, function() { $( '#menu-options' ).hide() });
         $(".logo").animate({ top: '-=208' }, 1000, function() {});
      }
      isanimate = !isanimate;
   }
</script>
<?php template::navPanel (['id' => 'menu-options']);?>
