#include<stdio.h>
#include <ctype.h>
//required consts and board
char board[15][15];
const char PLAYER1 = 'X';
const char BOT = 'O';
const char PLAYER2 = '0';
// declared functions
void ResetBoard();
void PrintBoard();
void Player1Move();
void Player2Move();
void BotMove();
char CheckdaWinner();
void PrintdaWinner(char winner);
int CheckFreePlaces();
int m;
int n;

//  main body
int main()
{
    char winner = ' ';
    char mode;
    ResetBoard();
    printf("Single Player / Multiplayer [S/M] ");
    mode = getchar(); 
    toupper(mode);
    while(winner = ' ' && CheckFreePlaces()!=0){
      Player1:
Player1Move();
//printf("player 1 last move %d %d ", m,n);
winner = CheckdaWinner();
if (winner != ' ' || CheckFreePlaces() == 0) 
            {
            break;
            }
            PrintBoard();

            if(mode == 'S') {
                goto singlee;}
                else {
                    goto multii;
                }
singlee:
BotMove();
winner = CheckdaWinner();
if (winner != ' ' || CheckFreePlaces() == 0) 
 {
break;
}
PrintBoard();
goto Player1;
 
 multii:
 Player2Move();
 //printf("player 2 last move %d %d ", m,n);
winner = CheckdaWinner();
if (winner != ' ' || CheckFreePlaces() == 0) 
 {
break;
}
PrintBoard();
goto Player1;
    }

PrintBoard();
PrintdaWinner(winner);
    return 0;
}



//RESET THE BOARD

void ResetBoard(){
for(int i=0;i<15;i++){
    for(int j=0;j<15;j++)
    {
    board[i][j]= ' ';
    }
}}



//PRINTING THE BOARD
void PrintBoard(){
printf("\n|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|\n");
    printf("| %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c |",
    board[0][0], board[0][1], board[0][2], board[0][3], board[0][4], board[0][5], board[0][6],board[0][7],
  board[0][8], board[0][9], board[0][10], board[0][11],board[0][12],board[0][13],board[0][14]);// row 0

   printf("\n|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|\n");

   printf("| %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c |",
    board[1][0], board[1][1], board[1][2], board[1][3], board[1][4], board[1][5], board[1][6],board[1][7],
  board[1][8], board[1][9], board[1][10], board[1][11],board[1][12],board[1][13],board[1][14]);// row 1

   printf("\n|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|\n");
   printf("| %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c |",
    board[2][0], board[2][1], board[2][2], board[2][3], board[2][4], board[2][5], board[2][6],board[2][7],
  board[2][8], board[2][9], board[2][10], board[2][11],board[2][12],board[2][13],board[2][14]);// row 2

   printf("\n|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|\n");
   printf("| %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c |",
    board[3][0], board[3][1], board[3][2], board[3][3], board[3][4], board[3][5], board[3][6],board[3][7],
  board[3][8], board[3][9], board[3][10], board[3][11],board[3][12],board[3][13],board[3][14]);// row 3

   printf("\n|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|\n");
   printf("| %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c |",
    board[4][0], board[4][1], board[4][2], board[4][3], board[4][4], board[4][5], board[4][6],board[4][7],
  board[4][8], board[4][9], board[4][10], board[4][11],board[4][12],board[4][13],board[4][14]);

   printf("\n|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|\n");
   printf("| %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c |",
    board[5][0], board[5][1], board[5][2], board[5][3], board[5][4], board[5][5], board[5][6],board[5][7],
  board[5][8], board[5][9], board[5][10], board[5][11],board[5][12],board[5][13],board[5][14]);

   printf("\n|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|\n");
   printf("| %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c |",
    board[6][0], board[6][1], board[6][2], board[6][3], board[6][4], board[6][5], board[6][6],board[6][7],
  board[6][8], board[6][9], board[6][10], board[6][11],board[6][12],board[6][13],board[6][14]);

   printf("\n|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|\n");
   printf("| %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c |",
    board[7][0], board[7][1], board[7][2], board[7][3], board[7][4], board[7][5], board[7][6],board[7][7],
  board[7][8], board[7][9], board[7][10], board[7][11],board[7][12],board[7][13],board[7][14]);

   printf("\n|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|\n");
   printf("| %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c |",
    board[8][0], board[8][1], board[8][2], board[8][3], board[8][4], board[8][5], board[8][6],board[8][7],
  board[8][8], board[8][9], board[8][10], board[8][11],board[8][12],board[8][13],board[8][14]);

   printf("\n|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|\n");
   printf("| %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c |",
    board[9][0], board[9][1], board[9][2], board[9][3], board[9][4], board[9][5], board[9][6],board[9][7],
  board[9][8], board[9][9], board[9][10], board[9][11],board[9][12],board[9][13],board[9][14]);

   printf("\n|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|\n");
   printf("| %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c |",
    board[10][0], board[10][1], board[10][2], board[10][3], board[10][4], board[10][5], board[10][6],board[10][7],
  board[10][8], board[10][9], board[10][10], board[10][11],board[10][12],board[10][13],board[10][14]);

   printf("\n|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|\n");
   printf("| %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c |",
    board[11][0], board[11][1], board[11][2], board[11][3], board[11][4], board[11][5], board[11][6],board[11][7],
  board[11][8], board[11][9], board[11][10], board[11][11],board[11][12],board[11][13],board[11][14]);

   printf("\n|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|\n");
   printf("| %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c |",
    board[12][0], board[12][1], board[12][2], board[12][3], board[12][4], board[12][5], board[12][6],board[12][7],
  board[12][8], board[12][9], board[12][10], board[12][11],board[12][12],board[12][13],board[12][14]);

   printf("\n|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|\n");
   printf("| %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c |",
    board[13][0], board[13][1], board[13][2], board[13][3], board[13][4], board[13][5], board[13][6],board[13][7],
  board[13][8], board[13][9], board[13][10], board[13][11],board[13][12],board[13][13],board[13][14]);

   printf("\n|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|\n");
   printf("| %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c |",
    board[14][0], board[14][1], board[14][2], board[14][3], board[14][4], board[14][5], board[14][6],board[14][7],
  board[14][8], board[14][9], board[14][10], board[14][11],board[14][12],board[14][13],board[14][14]);

   printf("\n|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|\n");
}

//FREE SPACES CHECK
int CheckFreePlaces(){
    int free=225;
    for(int i=0;i<15;i++){
    for(int j=0;j<15;j++)
    {
        if (board[i][j] != ' ' )
        free--;
    }
    return free;
}}


// PLAYING MOVES 

//PLAYER 1
void Player1Move(){
    int x,y;
    do{
    printf("PLAYER 1:\nEnter the row(1-15):");
    scanf("%d",&x);
    printf("PLAYER 1:\nEnter the column(1-15):");
    scanf("%d",&y);
    x--; y--;
if (board[x][y] != ' ' ){
printf("\n INVALID MOVE \n ");
}
else {
board[x][y]= PLAYER1;
m = x;
n = y;
break;
}

    }while(board[x][y] != ' ');
}
// Player 2
void Player2Move(){
   int x,y;
    do{
    printf("PLAYER 2:\nEnter the row(1-15):");
    scanf("%d",&x);
    printf("PLAYER 2:\nEnter the column(1-15):");
    scanf("%d",&y);
    x--;
    y--;
if (board[x][y] != ' ' ){
printf("\n INVALID MOVE \n ");
}
else {
board[x][y]= PLAYER2;
m = x;
n = y;
break;
}

    }while(board[x][y] != ' ');
 
}
//BOT 
void BotMove(){
}



// check winning positions
char CheckdaWinner(){
int count=1,i,j;
printf("m = %d \t",m);
// horizontal
for(i=0;i<15;i++)
    {
    if(board[m][i]==board[m][i+1] && board[m][i]!= ' ')
    count++;
  else count =1;
  if (count == 5 ){
    printf("count = %d \t ",count);
    return board[m][i];
  }
  
    }
    

//for vertical
printf("n = %d \t",n);
count=1;
for(j=0;j<15;j++)
    {
    if(board[j][n]==board[j+1][n] && board[j][n]!=' ')
    count++;
  else count =1 ;
    if(count == 5 ){
      printf("count = %d \t",count);
      return board[j][n];
    }
    
    }
    
    
   //diagonals
   count =1;
   return ' ';
}


//printing winner
void PrintdaWinner(char winner)
{
  if (winner == PLAYER1){
printf("\n Player 1 You Win :) !");
}

else if(winner == BOT){
    printf("\n Player 1 You Lose :( ");
  
} 
else if(winner==PLAYER2)
{
printf("\n Player 2 You Win :) !");
}
else
printf(" \nTie");
}