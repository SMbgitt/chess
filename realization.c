#include <stdio.h>
#include "header.h"

void transmit(Position pos1, Position pos2, Board* board){

}
void fillBoard(Board* board){
    int i;
    for(i=0;i<2;i++){
        board->board[1][i] = (Figure){Rook,i,(7,0)};
    }
    for(i=0;i<8;i++){
        board->board[1][i] = (Figure){Pawn,0,(1,i)};
        board->board[1][i] = (Figure){Pawn,1,(6,i)};
    }
}
void checkingMove(Figure n, Position xy){

}
Position getPos(Figure* n){

}
void setPos(Figure* n, Position pos){

}
Type getType(Figure* n){

}
void setType(Figure* n, Type t){

}
int getTeam(Figure *n){

}
void setTeam(Figure *n){

}