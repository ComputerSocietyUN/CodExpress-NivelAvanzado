<h1>CodExpress — Nivel Avanzado (Algoritmos + Rendimiento)</h1>
<p><strong>Tiempo:</strong> 3 horas · <strong>Meta:</strong> completar <u>7 u 8 mini-retos</u> y, si te alcanza, una <u>app integrada (código 3900)</u> que reutilice tus propias implementaciones. Lenguajes: <strong>Python</strong>, <strong>Java</strong> o <strong>C++</strong> (solo librerías estándar).</p>

<h2>Flujo de trabajo (fork &amp; PR)</h2>
<ol>
  <li>Haz <em>fork</em> y clónalo.</li>
  <li>Usa un <strong>&lt;ALIAS&gt;</strong> sin espacios ni acentos (tu usuario de GitHub o <code>nombre-apellido</code> en minúsculas).</li>
  <li>Cada mini-reto va en un archivo con <strong>formato exacto</strong>: <code>&lt;CODIGO_RETO&gt;_&lt;ALIAS&gt;_v&lt;N&gt;.&lt;ext&gt;</code> (ej.: <code>3005_lina-rojas_v1.py</code> o <code>3005_lina-rojas_v1.cpp</code>).</li>
  <li>Si haces la app, crea <code>3900_&lt;ALIAS&gt;_app/</code> con <code>README.md</code> (cómo ejecutar), y si quieres <code>src/</code> y <code>requirements.txt</code>.</li>
  <li>Abre un Pull Request a <code>main</code> titulado: <strong>&lt;ALIAS&gt; — Entrega Nivel Avanzado</strong>.</li>
</ol>

<hr/>

<h2>Códigos (Nivel Avanzado)</h2>
<ul>
  <li><strong>Mini-retos:</strong> 3001–3008 (elige 7 u 8).</li>
  <li><strong>App integrada:</strong> 3900 (<em>Smart Routes &amp; Data</em>).</li>
</ul>
<p><strong>Nombre de archivo obligatorio:</strong> <code>&lt;CODIGO_RETO&gt;_&lt;ALIAS&gt;_v&lt;N&gt;.&lt;ext&gt;</code></p>

<hr/>

<h2>Mini-retos (entrega 7 u 8)</h2>
<p>Usa <strong>solo la librería estándar</strong>. Al final de cada archivo incluye, en comentarios, <strong>3 pruebas</strong> (entrada → salida esperada). La salida se compara <strong>literalmente</strong>. Indica en comentario la <strong>complejidad</strong> esperada de tu solución.</p>

<table>
  <thead>
    <tr><th>Código</th><th>Nombre</th><th>Requisitos técnicos y verificación</th><th>Entrada / Salida</th><th>Archivo</th><th>Docs útiles</th></tr>
  </thead>
  <tbody>
    <tr><td><strong>3001</strong></td><td>Sort Bench (O(n²) vs O(n log n))</td><td>Implementa <em>bubble</em> (o insertion) y <em>quicksort/mergesort</em> propios. Cuenta <code>comps</code> y <code>swaps</code> e imprime tiempo en ms. Verifica que ambos producen exactamente el mismo arreglo final. Genera los datos con <code>--seed</code> (reproducible). No uses <code>sort</code> de la librería.</td><td>Modo A: lista en stdin (N y N enteros). Modo B: <code>GEN N --seed=S</code>. Salida (dos líneas): <code>algo, comps=..., swaps=..., ms=...</code>.</td><td><code>3001_&lt;ALIAS&gt;_v1.(py|java|cpp)</code></td><td>Python: <a href="https://docs.python.org/3/library/time.html">time</a> · C++: <a href="https://en.cppreference.com/w/cpp/chrono">chrono</a> · Java: <a href="https://docs.oracle.com/javase/8/docs/api/java/lang/System.html#nanoTime--">nanoTime</a></td></tr>
    <tr><td><strong>3002</strong></td><td>Búsqueda binaria (izquierda)</td><td>En arreglo <strong>ordenado</strong>, responde Q consultas y devuelve el índice del <u>primer</u> elemento ≥ x (leftmost lower_bound). Si no existe, imprime −1. Evita overflow en Java/C++ usando <code>mid = l + (r-l)/2</code>. O(Q log N).</td><td>Entrada: <code>N</code>, línea con N enteros, <code>Q</code>, luego Q valores. Salida: Q líneas con índices.</td><td><code>3002_&lt;ALIAS&gt;_v1.(py|java|cpp)</code></td><td>C++: <a href="https://en.cppreference.com/w/cpp/algorithm/lower_bound">lower_bound</a> (referencia) · Py: <a href="https://docs.python.org/3/library/bisect.html">bisect</a> (no usar directamente)</td></tr>
    <tr><td><strong>3003</strong></td><td>BFS en grafo (ruta + niveles)</td><td>Grafo no dirigido con V hasta 10<sup>5</sup>, E hasta 2·10<sup>5</sup>. Imprime distancia mínima y la ruta <u>determinista</u> de <code>s</code> a <code>t</code> (vecinos explorados en orden ascendente de id). O(V+E) usando <code>deque</code>/<code>queue</code>.</td><td>Entrada: <code>V E</code>, E líneas <code>u v</code>, luego <code>s t</code>. Salida: <code>dist=K</code> y en la línea siguiente la ruta <code>u-&gt;...-&gt;t</code>; si no hay, <code>NO</code>.</td><td><code>3003_&lt;ALIAS&gt;_v1.(py|java|cpp)</code></td><td>Py: <a href="https://docs.python.org/3/library/collections.html#collections.deque">deque</a> · C++: <a href="https://en.cppreference.com/w/cpp/container/queue">queue</a></td></tr>
    <tr><td><strong>3004</strong></td><td>DFS: tiempos y topológico</td><td>Calcula <code>tin/tout</code> por vértice y detecta ciclo. Si no hay ciclos, imprime un orden <u>topológico</u>. Determinismo: itera vecinos en orden ascendente. En Python ajusta <code>recursionlimit</code> o haz DFS iterativo.</td><td>Entrada: <code>V E</code>, E líneas <code>u v</code> (dirigido). Salida: si hay ciclo, <code>CYCLE</code>. Si no, una línea: <code>topo: v1 v2 ...</code>.</td><td><code>3004_&lt;ALIAS&gt;_v1.(py|java|cpp)</code></td><td>Py: <a href="https://docs.python.org/3/library/sys.html">sys.setrecursionlimit</a> · C++: <a href="https://en.cppreference.com/w/cpp/container/vector">vector</a></td></tr>
    <tr><td><strong>3005</strong></td><td>Dijkstra (camino y distancias)</td><td>Peso positivo. Implementa con <code>priority_queue</code>/<code>heapq</code>. Distancias desde <code>s</code> y ruta exacta a <code>t</code>. O((V+E) log V). Si <code>t</code> es inalcanzable: <code>INF</code>. En caso de empate por distancia, desempata por id de predecesor menor (determinismo).</td><td>Entrada: <code>V E</code>, E líneas <code>u v w</code> (dirigido o no; se indicará 0/1 en primera línea), y <code>s t</code>. Salida: <code>dist[t]=X</code> y en la siguiente línea la ruta; o <code>INF</code>.</td><td><code>3005_&lt;ALIAS&gt;_v1.(py|java|cpp)</code></td><td>Py: <a href="https://docs.python.org/3/library/heapq.html">heapq</a> · Java: <a href="https://docs.oracle.com/javase/8/docs/api/java/util/PriorityQueue.html">PriorityQueue</a></td></tr>
    <tr><td><strong>3006</strong></td><td>WordCount top-k (streaming)</td><td>Lee texto por stdin, normaliza Unicode (NFKD), elimina signos, <code>casefold</code>. Calcula frecuencias en <strong>streaming</strong> (no cargues todo si es grande). Imprime top-k (k en la primera línea) con desempate lexicográfico ascendente. Determinista.</td><td>Entrada: primera línea <code>k</code>, luego texto libre hasta EOF. Salida: k líneas <code>palabra conteo</code>.</td><td><code>3006_&lt;ALIAS&gt;_v1.(py|java|cpp)</code></td><td>Py: <a href="https://docs.python.org/3/library/unicodedata.html">unicodedata</a> · <a href="https://docs.python.org/3/library/collections.html#collections.Counter">Counter</a> (o mapa propio)</td></tr>
    <tr><td><strong>3007</strong></td><td>BST (insert/find/delete + rango)</td><td>Árbol binario de búsqueda sin librerías balanceadas. Soporta <code>ADD x</code>, <code>DEL x</code>, <code>HAS x</code>, <code>PREV x</code>, <code>NEXT x</code>. Imprime <code>INORDER</code> al llamar <code>PRINT</code>. Implementa correctamente los 3 casos de borrado.</td><td>Entrada: múltiples comandos (uno por línea). Salida: respuestas a <code>HAS/PREV/NEXT/PRINT</code>.</td><td><code>3007_&lt;ALIAS&gt;_v1.(py|java|cpp)</code></td><td>C++: <a href="https://en.cppreference.com/w/cpp/language/pimpl">punteros</a> · Py: <a href="https://docs.python.org/3/tutorial/classes.html">clases</a></td></tr>
    <tr><td><strong>3008</strong></td><td>Heapsort + métricas</td><td>Implementa <em>binary heap</em> y <em>heapsort</em> ascendente. Cuenta <code>sift_up</code>/<code>sift_down</code> y compara con <code>n log n</code>. Prohíbido usar <code>sort</code> de la librería. Determinista.</td><td>Entrada: <code>N</code> y N enteros. Salida: una línea con el arreglo ordenado y otra con <code>sift_up=.. sift_down=..</code>.</td><td><code>3008_&lt;ALIAS&gt;_v1.(py|java|cpp)</code></td><td>Py: <a href="https://docs.python.org/3/library/heapq.html">heapq</a> (solo referencia) · C++: <a href="https://en.cppreference.com/w/cpp/container/vector">vector</a></td></tr>
  </tbody>
</table>

<h3>Requisitos mínimos por mini-reto</h3>
<ul>
  <li><strong>E/S exacta</strong> (la comparación es literal).</li>
  <li><strong>3 pruebas</strong> (entrada → salida) en comentarios al final del archivo.</li>
  <li><strong>Complejidad</strong> indicada en comentario (y que cumpla con los límites).</li>
  <li><strong>Solo librería estándar</strong>; nada de frameworks externos.</li>
  <li><strong>Nomenclatura exacta</strong> del archivo. Nombre incorrecto: −5%.</li>
</ul>

<hr/>

<h2>App integrada (3900) — Smart Routes &amp; Data</h2>
<table>
  <thead>
    <tr><th>Código</th><th>Debe reutilizar</th><th>Qué agrega</th><th>Entregables</th><th>Puntaje máx.</th></tr>
  </thead>
  <tbody>
    <tr><td><strong>3900</strong></td><td>3001, 3003, 3005, 3006, 3008</td><td>CLI que permite: (1) cargar/redimensionar grafos; (2) comparar ordenamientos (3001) en datasets generados con <code>--seed</code>; (3) rutas mínimas (3003/3005) con impresión de camino; (4) análisis de texto (3006) para logs. Incluye un comando <code>bench</code> que guarda resultados en un CSV/JSON.</td><td>Carpeta <code>3900_&lt;ALIAS&gt;_app/</code> con <code>README.md</code> (comandos), <code>src/</code>, y un archivo <code>benchmarks.(csv|json)</code> con al menos 3 corridas reproducibles.</td><td><strong>220</strong></td></tr>
  </tbody>
</table>
<ul>
  <li>Reutiliza tus funciones/clases: impórtalas o muévelas a <code>src/</code> sin reescribir.</li>
  <li>Incluye una tabla de tiempos con tamaños crecientes y semilla fija.</li>
  <li>Los recorridos de grafo deben ser deterministas (orden de vecinos).</li>
</ul>

<hr/>

<h2>Puntajes — Nivel Avanzado</h2>
<ul>
  <li><strong>Mini-reto (máx. 110 pts)</strong>: funciona y cumple complejidad (60%) · casos borde / 3 pruebas (20%) · claridad/estructura (10%) · defensa breve (10%).</li>
  <li><strong>App 3900 (máx. 220 pts)</strong>: integración real (50%) · diseño y cohesión (20%) · manejo de errores y CLI usable (20%) · README/benchmarks (10%).</li>
</ul>

<h3>Bonificaciones creativas (opcionales, suman — tope +120 pts por equipo)</h3>
<ul>
  <li><strong>Visualizador de rutas</strong> (GUI o TUI) para 3900: muestra nodos, aristas y el camino encontrado (Tkinter/Swing/Qt/curses): <strong>+40 pts</strong>.</li>
  <li><strong>Paralelización</strong> (multi-thread/Procesos) en algún módulo de 3900 (p. ej., generación de datasets o wordcount por <em>shards</em>): <strong>+25 pts</strong>.</li>
  <li><strong>Perfilado</strong> (reporte con <em>time/chrono</em> o contadores propios) comparando implementaciones y tamaños: <strong>+15 pts</strong>.</li>
  <li><strong>Reproducibilidad</strong>: script que corre 3 benches con la misma semilla y deja <code>benchmarks.json</code>/<code>.csv</code> con promedios y desvío: <strong>+10 pts</strong>.</li>
  <li><strong>Tests automatizados</strong> (unittest/JUnit/asserts) ≥8 casos: <strong>+10 pts</strong>.</li>
  <li><strong>Validadores</strong> de entrada (detectan formatos inválidos y reportan línea/causa): <strong>+10 pts</strong>.</li>
  <li><strong>Top-k eficiente</strong> en 3006 con <em>min-heap</em> + streaming (sin ordenar todo): <strong>+10 pts</strong>.</li>
</ul>

<hr/>

<h2>Anti-IA desde la consigna (verificación incorporada)</h2>
<ul>
  <li><strong>Determinismo</strong> en orden de vecinos, empates y formato exacto de salida (rutas, top-k, etc.).</li>
  <li><strong>Semillas obligatorias</strong> para generación de datos/bench (3001, 3900).</li>
  <li><strong>Complejidad exigida</strong> (rechazamos O(n²) donde no corresponda; se probará con tamaños “trampa”).</li>
  <li><strong>Edición en vivo (≤2 min)</strong> durante la defensa: se puede pedir cambiar el formato, tamaño o un criterio de desempate.</li>
</ul>

<hr/>

<h2>Checklist final</h2>
<ul>
  <li>7 u 8 mini-retos con nombres correctos: <code>300x_&lt;ALIAS&gt;_vN.(py|java|cpp)</code>.</li>
  <li>3 pruebas por archivo (en comentarios) y complejidad indicada.</li>
  <li>Si hiciste la app: <code>3900_&lt;ALIAS&gt;_app/</code> + <code>README.md</code> + <code>benchmarks.(csv|json)</code>.</li>
  <li>PR: <code>&lt;ALIAS&gt; — Entregas Nivel Avanzado</code>.</li>
</ul>

<h2>Documentación</h2>
<p>
  <a href="https://docs.python.org/3/">Python</a> ·
  <a href="https://docs.oracle.com/javase/8/docs/">Java</a> ·
  <a href="https://en.cppreference.com/w/">C++</a> ·
  <a href="https://docs.python.org/3/library/collections.html#collections.deque">deque (Py)</a> ·
  <a href="https://docs.python.org/3/library/heapq.html">heapq (Py)</a> ·
  <a href="https://docs.oracle.com/javase/8/docs/api/java/util/PriorityQueue.html">PriorityQueue (Java)</a> ·
  <a href="https://en.cppreference.com/w/cpp/container/priority_queue">priority_queue (C++)</a> ·
  <a href="https://docs.python.org/3/library/unicodedata.html">unicodedata</a>
</p>
