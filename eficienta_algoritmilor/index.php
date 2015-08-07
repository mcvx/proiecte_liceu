<?php
    $exemplu = "";
    $page = "";
    if (isset($_GET['exemplu']))
        $exemplu = $_GET['exemplu'];
    else {
        $page = "info";
        if (isset($_GET['page']))
            $page = $_GET['page'];
    }
?>

<!DOCTYPE html>
<html>

	<head>

<?php include('includes/head.php'); ?>

	</head>

	<body>	

<?php include('includes/header.php'); ?>

		<div id="content" class="group">
            <section id="left">
                <div id="logo">
                    <h1>Eficienta algoritmilor</h1>
                </div>
                <nav>
                    <ul class="group">
                        <span class="auxText"></span>
                        <li <?php if ($page == "info") echo "class=\"active\""; ?> >
                            <a href="index.php?page=info" title="In ce consta analiza eficientei algoritmilor?">
                                <span data-icon="g" class="icon"></span>
                                <span class="text">In ce consta analiza eficientei algoritmilor?</span>
                            </a>
                        </li>
                        <li <?php if ($page == "masura") echo "class=\"active\""; ?> >
                            <a href="index.php?page=masura" title="Cum se poate măsura eficienţa algoritmilor?">
                                <span data-icon="g" class="icon"></span>
                                <span class="text">Cum se poate masura eficienta algoritmilor?</span>
                            </a>
                        </li>
                        <li <?php if ($page == "clase") echo "class=\"active\""; ?> >
                            <a href="index.php?page=clase" title="Clase de eficienta">
                                <span data-icon="g" class="icon"></span>
                                <span class="text">Clase de eficienta</span>
                            </a>
                        </li>
                        <li>
                            <a href="#" title="Exemple">
                                <span data-icon="g" class="icon"></span>
                                <span class="text">Exemple</span>
                            </a>
                            <ul <?php if (empty($exemplu)) echo "style=\"display: none;\""; ?> >
                                <li <?php if ($exemplu == "constant") echo "class=\"active\""; ?> >
                                    <a href="index.php?exemplu=constant" title="Constant">
                                        <span data-icon="A" class="icon"></span>
                                        <span class="text">Constant</span>
                                    </a>
                                </li>
                                <li <?php if ($exemplu == "logaritmic") echo "class=\"active\""; ?> >
                                    <a href="index.php?exemplu=logaritmic" title="Logaritmic">
                                        <span data-icon="A" class="icon"></span>
                                        <span class="text">Logaritmic</span>
                                    </a>
                                </li>
                                <li <?php if ($exemplu == "liniar") echo "class=\"active\""; ?> >
                                    <a href="index.php?exemplu=liniar" title="Liniar">
                                        <span data-icon="A" class="icon"></span>
                                        <span class="text">Liniar</span>
                                    </a>
                                </li>
                                <li <?php if ($exemplu == "supraliniar") echo "class=\"active\""; ?> >
                                    <a href="index.php?exemplu=supraliniar" title="Supraliniar">
                                        <span data-icon="A" class="icon"></span>
                                        <span class="text">Supraliniar</span>
                                    </a>
                                </li>
                                <li <?php if ($exemplu == "patratic") echo "class=\"active\""; ?> >
                                    <a href="index.php?exemplu=patratic" title="Patratic">
                                        <span data-icon="A" class="icon"></span>
                                        <span class="text">Patratic</span>
                                    </a>
                                </li>
                                <li <?php if ($exemplu == "polinomial") echo "class=\"active\""; ?> >
                                    <a href="index.php?exemplu=polinomial" title="Polinomial">
                                        <span data-icon="A" class="icon"></span>
                                        <span class="text">Polinomial</span>
                                    </a>
                                </li>
                                <li <?php if ($exemplu == "exponential") echo "class=\"active\""; ?> >
                                    <a href="index.php?exemplu=exponential" title="Exponential">
                                        <span data-icon="A" class="icon"></span>
                                        <span class="text">Exponential</span>
                                    </a>
                                </li>
                                <li <?php if ($exemplu == "factorial") echo "class=\"active\""; ?> >
                                    <a href="index.php?exemplu=factorial" title="Factorial">
                                        <span data-icon="A" class="icon"></span>
                                        <span class="text">Factorial</span>
                                    </a>
                                </li>
                            </ul>
                        </li>
                        <li <?php if ($page == "test") echo "class=\"active\""; ?> >
                            <a href="index.php?page=test" title="Test de verificare">
                                <span data-icon="g" class="icon"></span>
                                <span class="text">Test de verificare</span>
                            </a>
                        </li>
                    </ul>
                </nav>
            </section>
            <section id="right">
                <section class="content-box">
                
<?php

    if (!empty($exemplu))
        require "content/exemplu.php";
    else
        require "content/" . $page . ".php";     
?>
                
                </section>
            </section>
		</div>

<?php include('includes/footer.php'); ?>

	</body>
	
</html>
