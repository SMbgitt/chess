#include <stdio.h>
#include "figure.c"
void transmit(Position pos1, Position pos2, Board* board);
void fillBoard(Board* board);
void checkingMove(Figure n, Position xy);
Position getPos(Figure* n);
void setPos(Figure* n, Position pos);
Type getType(Figure* n);
void setType(Figure* n, Type t);
int getTeam(Figure *n);
void setTeam(Figure *n, int t);
int getValue(Figure *n);
void setValue(Figure *n, int value);
void printBoard(Board* board);
void initEmptyBoard(Board* board);