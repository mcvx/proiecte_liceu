$(document).ready(function() {

    var normalWidth, navMargin, $scrollingDiv;
    $scrollingDiv = $("#logo");
    normalWidth = parseInt($("nav > ul > li > a > span.text").css("width"), 10);
    navMargin = $scrollingDiv.offset().top;
    
    $("nav > ul > li > a").hover(
        function() {
            var spanText = $(this).find("> span.text");
            var width = $(".auxText").html(spanText.text()).width();
            if (width > normalWidth)
                spanText.stop().animate({width: width + "px"}, 500);
        },
        function() {
            var spanText = $(this).find("> span.text");
            if (spanText.css("width") != normalWidth)
                spanText.stop().animate({width: normalWidth + "px"}, 500);
        }
    );
	
	/*$(window).scroll(function() {
	    var scroll = $(window).scrollTop();
	    if (scroll > navMargin)
		    $scrollingDiv.stop().css({"marginTop": (scroll - navMargin) + "px"});
		else
		    $scrollingDiv.stop().css({"marginTop": "0px"});
	});*/
	
	$("nav > ul > li > ul").parent().find("> a").click(function(e) {
	    e.preventDefault();
	    var ul = $(this).parent().find("ul");
	    if (ul.is(":visible"))
            ul.stop().slideUp(500);
        else
            ul.stop().slideDown(500);
    });

});
