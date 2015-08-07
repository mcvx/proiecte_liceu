function load_code(nume, versiune, s){
	var fisier = nume + '_' + versiune + ".cpp";
	$.ajax({
		type: 'GET',
		dataType: 'text',
		url: "content/aplicatii/"+fisier,
		success: function(raspuns){
			var content = '<pre name="code2" class="cpp">' + htmlEncode(raspuns) + '</pre>';
			var link = $("#program").offset().top - 105;
			
			$("#prog").html(content);
			dp.SyntaxHighlighter.HighlightAll('code2');
			if ($(window).scrollTop()!=link && s) $(window).scrollTo(link, 1000, {easing:'easeInCubic'});
		}
	});
}

function cod(obj, s){
	var nume = $(obj).parent().parent().find('h2').attr('info');
	var versiune = $(obj).attr('info');
	$(".prg span.text").removeClass('active');
	$(obj).addClass('active');
	load_code(nume, versiune, s);
}
	
$(document).ready(function(){

	$(".prg h2").click(function(){
		$(this).parent().hide();
		$(".prg").not($(this).parent()).show();
	});
	
	$(".prg span.text").click(function(){
		cod(this, 1);
	});
	
	cod($(".prg:nth-child(1) span.text:nth-of-type(1)"), 0);

});