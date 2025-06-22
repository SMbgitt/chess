#include <stdio.h>
#include "header.h"

void transmit(Position *pos1, Position* pos2, Board* board){
    board->square[pos2->x][pos2->y] = board->square[pos1->x][pos1->y];
    setPos(&board->square[pos2->x][pos2->y], pos2);
    board->square[pos1->x][pos1->y] = (Figure){None,0,pos1};
    setValue(&board->square[pos1->x][pos1->y],0);
}
void fillBoard(Board* board){
    int i;
    for(i=0;i<2;i++){
        board->square[7*i][0] = (Figure){Rook,i, (7*i,0)};
        setValue(&board->square[7*i][0],4);
        board->square[7*i][1] = (Figure){Knight,i,(7*i,1)};
        setValue(&board->square[7*i][1],3);
        board->square[7*i][2] = (Figure){Bishop,i,(7*i,2)};
        setValue(&board->square[7*i][2],2);
        board->square[7*i][3] = (Figure){Queen,i,(7*i,3)};
        setValue(&board->square[7*i][3],5);
        board->square[7*i][4] = (Figure){King,i,(7*i,4)};
        setValue(&board->square[7*i][4],6);
        board->square[7*i][5] = (Figure){Bishop,i,(7*i,5)};
        setValue(&board->square[7*i][5],2);
        board->square[7*i][6] = (Figure){Knight,i,(7*i,6)};
        setValue(&board->square[7*i][6],3);
        board->square[7*i][7] = (Figure){Rook,i,(7*i,7)};
        setValue(&board->square[7*i][7],4);
    }
    for(i=2;i<6;i++){
        for(int j=0;j<8;j++){
            board->square[i][j] = (Figure){None,0,(i,j),0};
        }
    }
    for(i=0;i<8;i++){
        board->square[1][i] = (Figure){Pawn,0,(1,i)};
        setValue(&board->square[1][i],1);
        board->square[6][i] = (Figure){Pawn,1,(6,i)};
        setValue(&board->square[6][i],1);
    }
}
void checkingMove(Figure n, Position xy){
    
}
Position getPos(Figure* n){
    return n->pos;
}
void setPos(Figure* n, Position* pos){
        n->pos = *pos;
}
Type getType(Figure* n){
    return n->type;
}
void setType(Figure* n, Type* t){
    n->type = t;
}
int getTeam(Figure *n){
    return n->team;
}
void setTeam(Figure *n, int team){
    n->team = team;
}
int getValue(Figure *n){
    return n->value;
}
void setValue(Figure *n, int val){
    n->value = val;
}
void printBoard(Board* board){
    int i,j;

    static const char *pieces[2][7] = {{
        "*",    // NONE
        "♙",    // PAWN
        "♗",    // BISHOP
        "♘",    // KNIGHT
        "♖",    // ROOK
        "♕",    // QUEEN
        "♔"     // KING
    },
    {
        "-",    // NONE
        "♟",    // PAWN
        "♝",    // BISHOP
        "♞",    // KNIGHT
        "♜",    // ROOK
        "♛",    // QUEEN
        "♚"     // KING
    }};
    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            printf("%s ",pieces[getTeam(&board->square[i][j])][getValue(&board->square[i][j])]);
        }
        printf("\n");
    }
}
void initEmptyBoard(Board *board) {
    if (!board) {
        printf("Error: NULL board passed to initEmptyBoard!\n");
        return;
    }

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            Position pos = {i,j};
            board->square[i][j].type = None;
            board->square[i][j].team = -1;
            board->square[i][j].value = 0;
            board->square[i][j].pos = pos;
        }
    }
}