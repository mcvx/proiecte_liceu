                    <h1>Cum se poate măsura eficienţa algoritmilor?</h1>
                    
                    <p class="text">Măsurarea experimentală a timpului consumat de un algoritm introduce o dependenţă de hardware şi software, cum ar fi computerul pe care se rulează algoritmul, sistemul de operare, limbajul de programare folosit - lucruri care nu ţin de calitatea intrinsecă a algoritmului. De aceea, vom prefera o estimare matematică a numărului de operaţii efectuate de algoritm în detrimentul calculării timpului exact.</p>
                    <p class="text"><span class="hgl red">Ordinul de complexitate</span> reprezintă numărul de operaţii efectuate de un algoritm în cel mai defavorabil caz. În general, complexitatea este exprimată folosind notația <span class="hgl blue">big O</span>, notație ce reține doar termenul care crește cel mai repede odată cu creșterea lui n, deoarece acest termen are impactul cel mai mare asupra timpului de execuție al implementărilor algoritmului, ceilalți termeni devenind neglijabili pentru valori mari ale lui n. De exemplu, dacă un algoritm se execută în <span class="hgl red">2<sup>n</sup> + n<sup>5</sup> + 8</span> unități de timp, atunci complexitatea lui în timp este <span class="hgl red">O(2<sup>n</sup>)</span>.</span>
                    <p class="text"><span class="hgl blue">Operaţie elementară</span> = operaţie al cărei timp de execuţie nu depinde de valorile operanzilor (timpul de execuţie pentru a calcula 1 + 2 nu diferă de timpul de execuţie pentru 12433 + 4567)</p>
                    
                    <p class="text" style="margin: 0;"><span class="hgl red">Operaţii elementare:</span></p>
                    <ul>
                        <li class="text">atribuire</li>
                        <li class="text">operaţii aritmetice</li>
                        <li class="text">operaţii logice</li>
                        <li class="text">comparaţii</li>
                    </ul>
                    
                    <p class="text" style="margin-bottom: 0;"><span class="hgl blue">Etapele analizei eficienţei în raport cu timpul de execuţie sunt:</span></p>
                    <ol>
                        <li class="text">Identificarea dimensiunii problemei</li>
                        <li class="text">Identificarea operaţiei dominante</li>
                        <li class="text">Determinarea numarului de execuţii ale operaţiei dominante</li>
                        <li class="text">Dacă timpul de execuţie depinde de proprietăţile datelor de intrare atunci se analizează:
                            <ul>
                                <li><span class="hgl red">Cel mai defavorabil caz:</span> analiza cea mai frecventă; furnizează o <span class="hgl blue">margine superioară</span> pentru timpul de execuţie</li>
                                <li><span class="hgl red">Cel mai favorabil caz:</span> analiza cea mai puţin frecventă; reprezintă o <span class="hgl blue">margine inferioară</span> a timpului de execuţie</li>
                                <li><span class="hgl red">Caz mediu:</span> <span class="hgl blue">timp mediu</span> de execuţie; se bazează pe cunoaşterea distribuţiei de probabilitate a datelor de intrare</li>
                            <ul>
                        </li>
                    </ol>
