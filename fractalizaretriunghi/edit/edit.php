<?php

	$file = "../content/".$_POST['file'].".txt";
	$content = $_POST['content'];

	$handler = fopen($file, "w");
	fwrite($handler, $content);
	
	fclose($handler);
	
?>
