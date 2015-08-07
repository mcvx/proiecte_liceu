function htmlEncode(value) {
	if (value) {
		return jQuery('<div />').text(value).html();
	}
	else {
		return '';
	}
}

function loadCpp(file, target) {
	$.ajax({
		type: 'GET',
		dataType: 'text',
		url: file,
		success: function(raspuns){
			var content = '<pre><code>' + htmlEncode(raspuns) + '</code></pre>';
			$(target).html(content);
			hljs.highlightBlock($(target).get(0));
		}
	});
}