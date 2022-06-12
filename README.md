<h1>Game-Of-Life
<h2>Rules of Program</h2>
The universe of the Game of Life is an infinite, two-dimensional orthogonal grid of square cells, each of which is in one of two possible states, live or dead (or populated and unpopulated, respectively). Every cell interacts with its eight neighbours, which are the cells that are horizontally, vertically, or diagonally adjacent. At each step in time, the following transitions occur:

  <p>Any live cell with fewer than two live neighbours dies, as if by underpopulation.</p>
  <p>Any live cell with two or three live neighbours lives on to the next generation.</p>
  <p>Any live cell with more than three live neighbours dies, as if by overpopulation.</p>
  <p>Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.</p>
<p>These rules, which compare the behavior of the automaton to real life, can be condensed into the following:</p>

  <p>Any live cell with two or three live neighbours survives.</p>
  <p>Any dead cell with three live neighbours becomes a live cell.</p>
  <p>All other live cells die in the next generation. Similarly, all other dead cells stay dead.</p>
<p>The initial pattern constitutes the seed of the system. The first generation is created by applying the above rules simultaneously to every cell in the seed, live or dead; births and deaths occur simultaneously, and the discrete moment at which this happens is sometimes called a tick.[nb 1] Each generation is a pure function of the preceding one. The rules continue to be applied repeatedly to create further generations.</p>
  <h2>Manual of Program</h2>
  <p>git clone https://github.com/raminafandi/Game_of_Life_DT.git
  <p>cd GameofLifeStep5</p>
  <p>mkdir build</p>
  <p>cd build</p>
  <p>cmake ../</p>
  <p>make</p>
  <p>make docs - for creating doxygen</p>
  <p>make dist - for compressing source</p>
  <p>make cover_html - for showing coverage report</p>
  <p>./GameOfLifeStep5 - for running program</p>
  <p>./unit_testing - for running unit tests</p>


