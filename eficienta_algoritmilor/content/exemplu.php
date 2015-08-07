		            <link href='highlighter/SyntaxHighlighter.css' rel='stylesheet' type='text/css'/>
		            <script type="text/javascript" src="highlighter/shCore.js"></script>
		            <script type="text/javascript" src="highlighter/shBrushCpp.js"></script>
		            
		            <h1><?php echo file_get_contents("content/exemple/" . $exemplu . "/titlu.txt"); ?></h1>
		            
		            <h2>Enunţ</h2>
		            <p class="text" style="margin: 0 10px 20px 10px;"><?php echo file_get_contents("content/exemple/" . $exemplu . "/enunt.txt"); ?></p>
		            
		            <h2 style="margin-bottom: 0px;">Implementare</h2>
		            <pre name="code" class="cpp"><?php echo htmlentities(file_get_contents("content/exemple/" . $exemplu . "/implementare.txt")); ?></pre>
		            
		            <h2 style="margin-top: 20px;">Calculul ordinului de complexitate</h2>
		            <p class="text" style="margin: 0 10px 20px 10px;"> <?php echo file_get_contents("content/exemple/" . $exemplu . "/complexitate.txt"); ?></p>
		            
		            <script>
		                dp.SyntaxHighlighter.HighlightAll('code');
	                </script>
		            
