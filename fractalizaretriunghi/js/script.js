	click = 0;
	
function htmlEncode(value){
	if (value) {
		return jQuery('<div />').text(value).html();
	}
	else {
		return '';
	}
}
	
function isAlpha(xStr){
	var regEx = /^[a-zA-Z0-9\-]+$/;
	return xStr.match(regEx);
}

function corectare(html){
	var content = htmlEncode(html);
	var p, q, r, tag, tag_s, k;
	do {
		p = html.indexOf("<");
		q = html.indexOf(">");
		while (q<p) if(q!=-1) q = html.slice(q+1).indexOf(">") + q + 1; else break;
		if (html.slice(p+1).indexOf("<")==-1 && p!=-1) r = html.length + 1;
		else r = html.slice(p+1).indexOf("<") + p + 1;
		if (p<r && q<r && p<q && p!=-1 && q!=-1){
			tag = html.slice(p, q+1);
			tag_s = "</" + tag.slice(1, tag.indexOf(' ')) + ">";
			k = html.lastIndexOf(tag_s);
			if (tag == "<br/>") k = 0;
			if (k != -1){
				if (tag.slice(1, tag.indexOf(' ')) == "script")
					content = content.replace(htmlEncode(html.slice(q+1, k)), html.slice(q+1, k));
				content = content.replace(htmlEncode(tag), tag);
				content = content.replace(htmlEncode(tag_s), tag_s);
				html = html.replace(tag, '');
				html = html.replace(tag_s, '');
			}
			else html = html.slice(q+1);
		}
		else html = html.slice(p+1);
	} while (r!=-1);
	return content;
}
	
function _load(id){
	var trg = '#' + id + ' article';
	$.ajax({
		type: 'GET',
		dataType: 'text',
		url: "content/"+id+".html",
		beforeSend: function() {
			$(trg).html('Loading...');
		},
		success: function(raspuns){
			var content = corectare(raspuns);
			if (content) $(trg).html(content);
			else $(trg).html("Empty");
		}
	});
}
	
function activ(index){
	$("nav ul a li").removeClass('active');
	$("nav ul a:nth-child("+(index)+") li").addClass('active');
}

$(document).ready(function(){
	
	$("nav ul a").click(function(){
		var hrf = $(this).attr('href');
		var link = $(hrf).offset().top - 105;
		click = 1;
		activ($("nav ul a").index(this)+1);
		$(window).scrollTo(link, 1000, {easing:'easeInCubic', onAfter: function(){window.setTimeout(function(){click = 0;}, 10);}});
		return false;
	});
	
	$(window).scroll(function(){
		if(!click) {
			$("nav ul a").each(function(index){
				var href = $(this).attr('href');
				if (($(window).scrollTop()+$(window).height()/3) >= $(href).offset().top - 105) activ(index+1);
			});
			
		}
	});

	$(".btt").click(function(){
		$(window).scrollTo(0, 1000, {easing:'easeInCubic'});
	});
	
	_load('metoda');
	_load('tema');
	_load('algoritm');
	_load('subprograme');
	_load('eficienta');
	_load('program');
	
});
