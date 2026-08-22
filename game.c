#include "game.h"
#include "header.h"
void restart(Board* board){
    initEmptyBoard(board);
    fillBoard(board);
}
int gamefinish(Board* board){
    return 0;
}
void game(){    //Пока кривая ходовка, главная задумка x-изначальная позиция фигуры, y-конечная позиция фигуры
    Board board;
    Position x;
    Position y;
    restart(&board);
    printBoard(&board);
    int temp = 0;
    char pl[4] = {};
    while(gamefinish(&board) != 1){
        if(temp%2==0){
            printf("\nWhite's move, choose your piece: ");
            scanf(" %c%c", &pl[0],&pl[1]);
            temp++;
            
        }else{
            printf("\nBlack's move, choose your piece: ");
            scanf(" %c%c", &pl[0],&pl[1]);
            temp--;
        }
        printf("Where should we put your piece: ");
        scanf(" %c%c", &pl[2],&pl[3]);
        printf("%d %d -> %d %d", (int)pl[1]-49,(int)pl[0]-97,(int)pl[3]-49,(int)pl[2]-97);
        setPosxy(&x,(int)pl[1]-49,(int)pl[0]-97);
        setPosxy(&y,(int)pl[3]-49,(int)pl[2]-97);
        if(checkingMove(board.square[x.x][x.y], y, board) == 1){
            transmit(&x,&y,&board);
        }else{
            printf("This move coudn't be done!");
            temp++; //Отмена смены хода
        }
        printBoard(&board);
    }
}
void menu(){
    int c;
    printf("Choose:\n1)Start match on one pc\n2)Start match in one network\n3)Quit\n");
    scanf("%d",&c);
    switch (c)
    {
    case 1:
        game();
        break;
    case 2:
        printf("Now is not done(");
        break;
    case 3:
        printf("Thank you for game!");
        break;
    default:
        break;
    }
}