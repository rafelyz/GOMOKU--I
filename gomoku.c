#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include "designs.c"

char board[15][15];
const char PLAYER1 = 'X';
const char PLAYER2 = 'O';

void gotoxy(int x,int y) {
    printf("%c[%d;%df",0x1B,y,x);
}

void loading() {
    int i,j,l;
    gomo();
    printf(" \n\t\t\t\t\t\t WELCOME TO GOMOKU\n");
    printf(" \n\n\n\n\n\n\n\n\t\t\t\t\t\t Created by: \n\t\t\t\t\t\t Avignya Gautam \n\t\t\t\t\t\t Balram Sharma Kandel\n");
    printf(" \n\n\n\n\n\n\n\n\n\t\t\t\t\t\tPRESS ANY KEY TO CONTINUE\n");
    getch();
}

void ResetBoard() {
    int i, j; 
    for(i=0; i<15; i++) {
        for(j=0; j<15; j++) {
            board[i][j]= ' ';
        }
    }
}

void PrintBoard() {
    system("cls");
    gotoxy(72,0);
    printf("Current Board : \n");
    int i; 
    for(i=0; i<15; i++) {
        printf("\n\t\t\t\t\t\t|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|\n");
        printf("\t\t\t\t\t\t| %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c |",
               board[i][0], board[i][1], board[i][2], board[i][3], board[i][4], board[i][5], board[i][6],board[i][7],
               board[i][8], board[i][9], board[i][10], board[i][11],board[i][12],board[i][13],board[i][14]);
    }
    printf("\n\t\t\t\t\t\t|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|\n");
}


int CheckFreePlaces() {
    int free = 225;
    int i, j; 
    for(i=0; i<15; i++) {
        for(j=0; j<15; j++) {
            if (board[i][j] != ' ')
                free--;
        }
    }
    return free;
}

void Player1Move() {
    int x,y;
    do {
        printf("PLAYER 1:\nEnter the row(1-15):");
        scanf("%d",&x);
        printf("PLAYER 1:\nEnter the column(1-15):");
        scanf("%d",&y);
        x--; y--;
        if (board[x][y] != ' ') {
            printf("\n INVALID MOVE \n ");
        } else {
            board[x][y]= PLAYER1;
            break;
        }
    } while(board[x][y] != ' ');
}

void Player2Move() {
    int x,y;
    do {
        printf("PLAYER 2:\nEnter the row(1-15):");
        scanf("%d",&x);
        printf("PLAYER 2:\nEnter the column(1-15):");
        scanf("%d",&y);
        x--;
        y--;
        if (board[x][y] != ' ') {
            printf("\n INVALID MOVE \n ");
        } else {
            board[x][y]= PLAYER2;
            break;
        }
    } while(board[x][y] != ' ');
}

char CheckdaWinner() {
    int count = 1,i,j;
    for(i=0; i<15; i++) {
        for(j=0; j<14; j++) {
            if(board[i][j]==board[i][j+1] && board[i][j]!= ' ')
                count++;
            else
                count = 1;
            if (count == 5 )
                return board[i][j];
        }
    }
    return ' ';
}

void PrintdaWinner(char winner) {
    if (winner == PLAYER1) {
    	congrtas();
        printf("\n\t\t\t\t\t\t\t  Player 1, You Win 🙂 !");
        printf(" \n\n\n\n\n\n\n\n\n\t\t\t\t\t\tPRESS ANY KEY TO EXIT\n");
    getch();
    } else if(winner == PLAYER2) {
    	congrtas();
        printf("\n\t\t\t\t\t\t\t  Player 2, You Win 🙂 !");
        printf(" \n\n\n\n\n\n\n\n\n\t\t\t\t\t\tPRESS ANY KEY TO EXIT\n");
    getch();
    } else {
    	tie();
    getch();
    }
}

int main() {
    loading();
    char winner = ' ';
    ResetBoard();
    PrintBoard();
    while(winner == ' ' && CheckFreePlaces() != 0) {
        Player1Move();
        winner = CheckdaWinner();
        if (winner != ' ' || CheckFreePlaces() == 0) {
            break;
        }
        PrintBoard();
        Player2Move();
        winner = CheckdaWinner();
        if (winner != ' ' || CheckFreePlaces() == 0) {
            break;
        }
        PrintBoard();
    }
    PrintBoard();
    PrintdaWinner(winner);
    return 0;
}
