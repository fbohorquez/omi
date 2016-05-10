jQuery(document).ready(function($){$("a.paypal.xco").on("click.ppxco",function(e){$.getJSON("//www.pccomponentes.com/core/paypal/setEC").done(function(resp){if(resp.ACK=="Success"){window.location.href=resp.URL;}});});$("a.paypal.xcoarticle").on("click.ppxco",function(e){$("#cargando_paypal").css("display","inline");var id=parseInt($("input#id").val());if(id>0){var qty=parseInt($("input#qty").val());qty=qty==0?1:qty;$.post(url+"cart/addItem/stop/stop/id/"+id+"/qty/"+qty).done(function(resp){$.getJSON("//www.pccomponentes.com/core/paypal/setEC").done(function(resp){if(resp.ACK=="Success"){window.location.href=resp.URL;}else{//@todo
}}).fail(function(){//@todo
});}).fail(function(){//@todo
});}});$('#paypal-cart').on("click.ppxco",function(e){$.getJSON("//www.pccomponentes.com/core/paypal/setEC").done(function(resp){if(resp.ACK=="Success"){window.location.href=resp.URL;}else{//@todo
}}).fail(function(){//@todo
});});});