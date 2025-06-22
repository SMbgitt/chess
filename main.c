#include <stdio.h>
#include "header.h"

void main(){
    Board board;
    initEmptyBoard(&board);
    fillBoard(&board);
    printBoard(&board);
}