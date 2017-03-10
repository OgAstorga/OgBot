const uttIA = require('../index.js');

// Input
const lastMove = { x: 0, y: 3 };
const board = "xxx.oxoo..o.ox.xx...ox.x.o.o.x.x....xxoxox.o.ooxox.x...x...o..ooooxxx.o..x...ooxx";

// Clalc move
const answer = uttIA.play(lastMove.y, lastMove.x, board);

// Print it
console.log('lastMove');
console.log(answer.lastMove);

console.log('board');
console.log(answer.board.match(/.{9}/g).join('\n'));
