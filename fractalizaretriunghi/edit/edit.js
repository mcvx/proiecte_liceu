function edit(id){
	var artcl = $('#' + id).find('article');
	var content = $(artcl).html();
	if ($('section article textarea').index('textarea')==-1) {
		$.ajax({
			type: 'GET',
			url: "content/"+id+".txt",
			beforeSend: function(){
				$(artcl).html('Loading...');
			},
			success: function(raspuns){
				var content = corectare(raspuns);
				$(artcl).html("<textarea>"+content+"</textarea>");
				$("textarea").tabby();
			}
		});
	}
}
	
function save(id){
	var txta = $('#' + id).find('textarea');
	var content = $(txta).val();
	content = encodeURIComponent(content);
	if (!content) content = "Empty";
	if ($('#' + id + ' textarea').index('textarea')>=0) {
		$(txta).remove();
		$.ajax({
			type: 'POST',
			url: "edit/edit.php",
			data: "file="+id+"&content="+content,
			beforeSend: function(){
				$("#" + id).find('article').html('Loading...');
			},
			success: function(){
				_load(id);
			}
		});
	}
}
	
$(document).ready(function(){

	$("article").click(function(){
		var id = $(this).parent().attr('id');
		edit(id);
	});
	
	$(".ribbon").click(function(){
		var id = $(this).parent().attr('id');
		save(id);
	});

});