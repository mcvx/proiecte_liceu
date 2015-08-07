<?php

    $exemplu = $_GET['cod'];
    
?>
		            
		            <pre name="code" class="cpp"><?php echo htmlentities(file_get_contents("exemple/" . $exemplu . "/implementare.txt")); ?></pre>

		            <script>
		                dp.SyntaxHighlighter.HighlightAll('code');
	                </script>
		            
