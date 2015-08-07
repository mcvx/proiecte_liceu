$(document).ready(function(){
	var content = $("#container");
	var folder = 'otto';
    	var link;
      	
	function afisare(adr){
		content.hide().load(adr).fadeIn(1000);
	}

	afisare('general/constructie.html');

	$("#motor a").click(function(e){
		e.preventDefault();
		var motor = $(this).html();
		if (motor != $("#motor .first").html()) {
			var text = $(this).find('li').text();
			if (text == "Motorul Otto") folder = "otto";
			else if (text == "Motorul Diesel") folder = "diesel";
			afisare(folder + '/' + $("#meniu .first").attr("href"));
			var aux = $("#motor .first").html();
			$("#motor .first").html(motor);
			$(".second").html(aux);
		}
	})

	$("#meniu a:not(.general)").click(function(e){
		e.preventDefault();
   		link = folder + '/' + $(this).attr("href");
  		afisare(link);
	});

	$("#meniu .general").click(function(e){
		e.preventDefault();
   		link = $(this).attr("href");
  		afisare(link);
	});
});