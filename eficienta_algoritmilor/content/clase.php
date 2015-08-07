                    <link href='css/clase.css' rel='stylesheet' type='text/css'>
                    <link href='css/jquery.jqplot.css' rel='stylesheet' type='text/css'>
                    <link href='css/jquery.fancybox.css' rel='stylesheet' type='text/css'>
                    <link href='highlighter/SyntaxHighlighter.css' rel='stylesheet' type='text/css'/>
                    <script type='text/javascript' src='js/jquery.jqplot.min.js'></script>
                    <script type='text/javascript' src='js/jquery.fancybox.pack.js'></script>
		            <script type='text/javascript' src='highlighter/shCore.js'></script>
		            <script type='text/javascript' src='highlighter/shBrushCpp.js'></script>

                    <script>
                        $(document).ready(function() {
                        
			                $('.fancybox').fancybox();
			                
		                });
		            </script>
                    
                    <h1>Clase de eficienţă</h1>
                    
                    <table>
                        <thead>
                            <tr>
                                <th scope="col">Ordin</th>
                                <th scope="col">Denumire</th>
                                <th scope="col">Exemplu</th>
                            </tr>
	                    </thead>
	                    <tbody>
                            <tr>
                                <td>O(c)</td>
                                <td>constant</td>
                                <td><a class="fancybox fancybox.ajax" href="content/surse.php?cod=constant">Suma lui Gauss</a></td>
                            </tr>
                            <tr>
                                <td>O(log<sub>2</sub>n)</td>
                                <td>logaritmic</td>
                                <td><a class="fancybox fancybox.ajax" href="content/surse.php?cod=logaritmic">Căutarea binară</a></td>
                            </tr>
                            <tr>
                                <td>O(n)</td>
                                <td>liniar</td>
                                <td><a class="fancybox fancybox.ajax" href="content/surse.php?cod=liniar">Căutarea secvenţiala</a></td>
                            </tr>
                            <tr>
                                <td>O(n log<sub>2</sub>n)</td>
                                <td>supraliniar</td>
                                <td><a class="fancybox fancybox.ajax" href="content/surse.php?cod=supraliniar">Quick Sort</a></td>
                            </tr>
                            <tr>
                                <td>O(n<sup>2</sup>)</td>
                                <td>pătratic</td>
                                <td><a class="fancybox fancybox.ajax" href="content/surse.php?cod=patratic">Sortarea prin selecţie</a></td>
                            </tr>
                            <tr>
                                <td>O(n<sup>c</sup>)</td>
                                <td>polinomial</td>
                                <td><a class="fancybox fancybox.ajax" href="content/surse.php?cod=polinomial">Algoritmul Roy-Warshal</a></td>
                            </tr>
                            <tr>
                                <td>O(c<sup>n</sup>)</td>
                                <td>exponenţial</td>
                                <td><a class="fancybox fancybox.ajax" href="content/surse.php?cod=exponential">Generarea produsului cartezian a <span class="hgl red">n-1</span> mulţimi de <span class="hgl red">2</span> elemente</a></td>
                            </tr>
                            <tr>
                                <td>O(n!)</td>
                                <td>factorial</td>
                                <td><a class="fancybox fancybox.ajax" href="content/surse.php?cod=factorial">Generarea permutărilor unei mulţimi de cardinal <span class="hgl red">n</span></a></td>
                            </tr>
	                    </tbody>
                    </table>
                    <div id="grafic" style="height: 600px; width:94%; margin: 40px 3%;"></div>
                    <script>
                        var cnst = [], lg = [], lin = [], slin = [], sq = [], expn = [], fact = [];
                        
                        function factorial(n)
                        {
                            if (n > 0)
                                return n * factorial(n-1);
                            else
                                return 1;
                        }
                        
                        for (var i = 1; i < 30; i+=0.1)
                        {
                            cnst.push([i, 2]);
                        }
                        
                        for (var i = 1; i < 30; i+=0.1)
                        {
                            lg.push([i, Math.log(i) / Math.LN2]);
                        }
                        
                        for (var i = 1; i < 30; i+=0.1)
                        {
                            lin.push([i, i]);
                        }
                        
                        for (var i = 1; i < 30; i+=0.1)
                        {
                            slin.push([i, i * Math.log(i) / Math.LN2]);
                        }
                        
                        for (var i = 1; i < 12.4; i+=0.1)
                        {
                            sq.push([i, Math.pow(i, 2)]);
                        }
                        
                        for (var i = 1; i < 7.2; i+=0.1)
                        {
                            expn.push([i, Math.pow(2, i)]);
                        }
                        
                        for (var i = 1; i < 6; i+=1)
                        {
                            fact.push([i, factorial(i)]);
                        }
 
                        $.jqplot("grafic", [cnst, lg, lin, slin, sq, expn, fact],
                            {
                                seriesDefaults: {showMarker: false, fontSize: '22px'},
                                legend: {show: true},
                                title: "Rata de creştere",
                                series:[
                                    {label: "Constantă", color: "#00BFFF"}, 
                                    {label: "Logaritmică", color: "#CD3333"}, 
                                    {label: "Liniară", color: "#43CD80"}, 
                                    {label: "Supraliniară", color: "#FFD700"}, 
                                    {label: "Patratică", color: "#E066FF"}, 
                                    {label: "Exponentială", color: "#FFA500"},
                                    {label: "Factorială", color: "#000000"}
                                ]
                            }
                        );
                    </script>
