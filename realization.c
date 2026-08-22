#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void transmit(Position *pos1, Position* pos2, Board* board){    //Перестановка фигур с позиции pos1 в позицию pos2
    board->square[pos2->x][pos2->y] = board->square[pos1->x][pos1->y];
    setPos(&board->square[pos2->x][pos2->y], pos2);
    board->square[pos1->x][pos1->y] = (Figure){None,0,pos1->x};
    setValue(&board->square[pos1->x][pos1->y],0);
}
void fillBoard(Board* board){   //Заполнение шахматной доски по базовой структуре
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
int checkingMove(Figure n, Position xy, Board board){   //Проверка правильности хода
    if(xy.x < 0 || xy.x > 7 || xy.y < 0 || xy.y > 7){   //вне поля
        return 0;
    }else if (n.team == board.square[xy.x][xy.y].team) //Пытаемся побить свою фигуру
    {
        return 0;
    }
    else if (n.type == Pawn)
    {
            int dx = xy.x - n.pos.x;      // движение по вертикали
        int dy = abs(xy.y - n.pos.y); // движение по горизонтали
        int sign = (n.team == 0) ? 1 : -1;  // белые: +1, чёрные: -1
        int startRow = (n.team == 0) ? 1 : 6;
        
        // НЕПРАВИЛЬНЫЙ ход, если:
        if (
            // 1. Движение назад
            dx * sign < 0 ||

            // 2. Слишком далеко по вертикали
            dx > 2 ||

            // 3. По горизонтали сдвинулась больше чем на 1
            dy > 1 ||

            // 4. Ход на 2 клетки, но не с начальной позиции
            (dx == 2 && n.pos.x != startRow) ||

            // 5. Ход на 2 клетки, но по горизонтали сдвинулась
            (dx == 2 && dy != 0) ||

            // 6. Обычный ход на 1, но по горизонтали сдвинулась
            (dx == 1 && dy != 0 && board.square[xy.x][xy.y].team == -1) ||

            // 7. Рубка (dy == 1), но нет врага
            (dy == 1 && board.square[xy.x][xy.y].team == n.team) ||

            // 8. Рубка (dy == 1), но пустая клетка
            (dy == 1 && board.square[xy.x][xy.y].team == -1) ||

            // 9. Просто шаг вперёд, но клетка занята
            (dx == 1 && dy == 0 && board.square[xy.x][xy.y].team != -1)
        ) {
        return 0;  // неправильный ход
    }
    }
    
    return 1;
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
void setType(Figure* n, Type t){
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
void setPosxy(Position *p,int x, int y){
    p->x = x;
    p->y = y;
}
void printBoard(Board* board){
    int i,j;

    static const char *pieces[2][7] = {{
        "*",    // value 0 - пусто (белые) - хотя белые пустые не бывают
        "♙",    // value 1 - пешка белая
        "♗",    // value 2 - слон белый
        "♘",    // value 3 - конь белый
        "♖",    // value 4 - ладья белая
        "♕",    // value 5 - ферзь белый
        "♔"     // value 6 - король белый
    },
    {
        "-",    // value 0 - пусто (чёрные)
        "♟",    // value 1 - пешка чёрная
        "♝",    // value 2 - слон чёрный
        "♞",    // value 3 - конь чёрный
        "♜",    // value 4 - ладья чёрная
        "♛",    // value 5 - ферзь чёрный
        "♚"     // value 6 - король чёрный
    }};
    printf("\n");
    for(i=0;i<8;i++){
        printf("%d ", i+1);
        for(j=0;j<8;j++){
            printf("%s ",pieces[getTeam(&board->square[i][j])][getValue(&board->square[i][j])]);
        }
        printf("\n");
    }
    printf("  a b c d e f g h\n");
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