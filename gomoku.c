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
void PrintdaWinner(char);
int CheckFreePlaces();
int m;
int n;

//  main body
int main()
{
    char winner = ' ';
    char mode;
    ResetBoard();
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
 Player2Move();
 //printf("player 2 last move %d %d ", m,n);
winner = CheckdaWinner();
if (winner != ' ' || CheckFreePlaces() == 0) 
 {
break;
}
PrintBoard();
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
    int i;
    printf("Current Board : \n");
    for(int i=0;i<15;i++){
    printf("\n|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|\n");
    printf("| %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c |",
    board[i][0], board[i][1], board[i][2], board[i][3], board[i][4], board[i][5], board[i][6],board[i][7],
  board[i][8], board[i][9], board[i][10], board[i][11],board[i][12],board[i][13],board[i][14]);// row 0
    }
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
//printf("m = %d \t",m);
// horizontal
for(i=0;i<15;i++)
    {
    if(board[m][i]==board[m][i+1] && board[m][i]!= ' ')
    count++;
  else count =1;
  if (count == 5 ){
  //  printf("count = %d \t ",count);
    return board[m][i];
  }
  
    }
//for vertical
//printf("n = %d \t",n);
count=1;
for(j=0;j<15;j++)
    {
    if(board[j][n]==board[j+1][n] && board[j][n]!=' ')
    count++;
  else count =1 ;
    if(count == 5 ){
    //  printf("count = %d \t",count);
      return board[j][n];
    }
    
    }
   //diagonals
   //for lft to rt dia row>column
   count =1;
   if (m>=n){
   for(j=0;(m-n)+j+1<=15;j++)
    {
    if(board[m-n+j][j]==board[m-n+j+1][j+1] && board[m-n+j][j]!=' ')
    count++;
  else count =1 ;
    if(count == 5 ){
    //  printf("count = %d \t",count);
      return board[m][n];
    }
}
}
//rt dia col>row
 count =1;
   if (m<n){
   for(j=0;(n-m)+j+1<15;j++)
    {
        
    if(board[j][n-m+j]==board[j+1][n-m+j+1] && board[j][n-m+j]!=' ')
    count++;
  else count =1 ;
    if(count == 5 ){
    //  printf("count = %d \t",count);
      return board[m][n];
    }
}
}
// rt to lft dia  row>=col
if(m>=n){
  
  count =1;
for (int j=0;(m+n)-j>0;j++){
   if((m+n)-j>15){
        continue;
    }
    if (j+1>15){
        break;
    }
  if(board[j][m+n-j]==board[j+1][m+n-j-1] && board[j][m+n-j]!=' ')
    count++;
  else count =1 ;
    if(count == 5 ){
     printf("count = %d \t",count);
      return board[m][n];
    }
}}
// rt to lft dia  row<col
if(m<n){
  count =1;
  for (int j=0;(m+n)-j>0;j++){
    if((m+n)-j>15){
        continue;
    }
    if (j+1>15){
        break;
    }
  if(board[m+n-j][j]==board[m+n-j-1][j+1] && board[m+n-j][j]!=' ')
    count++;
  else count =1 ;
    if(count == 5 ){
    //  printf("count = %d \t",count);
      return board[m][n];
    }
      }

} 
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