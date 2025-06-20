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
}Figure;

typedef struct{
    Figure board[8][8];
}Board;
