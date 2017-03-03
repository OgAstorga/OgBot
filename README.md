# Og Bot

Artificial intelligence that plays Ultimate tic tac toe.

It already beats me :'(

## Compiling
```
g++ *.cpp -o ai
```

## Data formatting
The Super tic tac toe board is represented by a 9x9 character matrix where each cell can have either `'o'`, `'x'` or `'.'` as its representation.
`'o'` means player 1
`'x'` means player 2
`'.'` means that the cell is not taken

All moves are represented by a line with two integers integers separated by one space.
`{row} {column}`

The first one is the row of the board and the second one represents the column of the board. both row and column are 0-indexed.

## Input
Og Bot receives one line indicating what was the last move of the oponent.
`-1, -1` means that Og Bot makes the first move.

The following 9 lines are a 9x9 character matrix that represents the board just after the last move of the opponent.

## Output
Og Bot will print the following to stdout
on the first line the coordinates of its move

The following 9 lines are a 9x9 character matrix that represents the board just after Og Bot made its move.

## Example run
```
./ai
< 3 0
< xxx .ox oo.
< .o. ox. xx.
< ..o x.x .o.

< o.x .x. ...
< xxo xox .o.
< oox ox. x..

< .x. ..o ..o
< ooo xxx .o.
< .x. ..o oxx

> 1 8
> xxx .ox oo.
> .o. ox. xxx
> ..o x.x .o.

> o.x .x. ...
> xxo xox .o.
> oox ox. x..

> .x. ..o ..o
> ooo xxx .o.
> .x. ..o oxx
```
