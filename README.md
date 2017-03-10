# uttt-ia

Artificial intelligence that plays Ultimate tic tac toe.

## Installing
```
npm install uttt-ia
```

## Testing
```
npm test
```

## Data formatting
The Super tic tac toe board is represented by a 9x9 character matrix where each cell can have either `'o'`, `'x'` or `'.'` as its representation.
`'o'` means player 1
`'x'` means player 2
`'.'` means that the cell is not taken

All moves are represented by a line with two integers integers separated by one space.
`{row} {column}`

The first one is the row of the board and the second one represents the column of the board. both row and column are 0-indexed.
