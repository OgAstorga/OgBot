const http = require('http');
const url = require('url');
const querystring = require('querystring');

const utttIA = require('./index');

http.createServer((req, res) => {
  const { query } = url.parse(req.url, true);

  let ans;
  try {
    ans = utttIA.play(+query.lastrow, +query.lastcol, query.board);
  } catch (err) {
    res.writeHead(500, { 'Content-Type': 'application/json' });
    console.error(err);
    res.write(JSON.stringify({
      message: err.message
    }));
    return res.end();
  }

  res.writeHead(200, {
    'Access-Control-Allow-Origin': '*',
    'Access-Control-Allow-Methods': 'GET',
    'Access-Control-Allow-Headers': 'Content-Type',
    'Content-Type': 'application/json'
  });
  res.write(JSON.stringify(ans));
  res.end();
}).listen(8001);
