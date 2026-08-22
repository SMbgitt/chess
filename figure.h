#ifndef FIGURE_H
#define FIGURE_H
#include <stdio.h>
#include <string.h>

typedef enum{
    Pawn,
    Rook,
    Knight,
    Bishop,
    Queen,
    King,
    None
}Type;

typedef struct
{
    int x;
    int y;
}Position;

typedef struct{
    Type type;
    int team;
    Position pos;
    int value;
}Figure;

typedef struct{
    Figure square[8][8];
}Board;
#endif