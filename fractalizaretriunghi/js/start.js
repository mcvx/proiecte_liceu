function size(box){

	var maskHeight = $(document).height();
	var maskWidth = $(window).width();
	$('#mask').css({'width':maskWidth,'height':maskHeight});
		
	var winH = $(window).height();
	var winW = $(window).width();
	box.css('top',  winH/2 - box.height()/2);
	box.css('left', winW/2 - box.width()/2);
	
}

$(document).ready(function() { 
	
	size($('#start'));
	$('#mask').show();
	$('#start').show();
	
	$('#box').click(function(){
		$('#mask').slideUp(500);
		$('#start').slideUp(500);
	});
	
	$(window).resize(function(){
		size($('#start'));
	});
	
});