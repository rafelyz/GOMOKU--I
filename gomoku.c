#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "design.c"


#define PLAYER1 'X'
#define PLAYER2 '0'
//required consts and board
char board[15][15];
char current_player = PLAYER1;
int m,n;


//Loading Screen
void loading(){
	int i,j,l;
	gomo();
	printf(" \n\t\t\t\t\t\t WELCOME TO GOMOKU\n");
	printf(" \n\n\n\n\n\n\n\n\t\t\t\t\t\t Created by: \n\t\t\t\t\t\t Avignya Gautam \n\t\t\t\t\t\t Balram Sharma Kandel\n");
	printf(" \n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tPRESS ANY KEY TO CONTINUE\n");
	getch();
}


//RESET THE BOARD

void ResetBoard(){
	for(int i=0;i<15;i++){
		for(int j=0;j<15;j++){
			board[i][j]= ' ';
		}
	}
}


//PRINTING THE BOARD
void PrintBoard(){
	system("cls");
	int i;

	printf("\t\t\t\t\t\t\t\t      Current Board : \n");
	
	printf("\n\t\t\t\t\t\t|-1-|-2-|-3-|-4-|-5-|-6-|-7-|-8-|-9-|-10|-11|-12|-13|-14|-15|\n");
	for(int i=0;i<15;i++){
		printf("\n\t\t\t\t\t\t|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|\n");
		printf("\t\t\t\t\t%d\t| %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c |", i+1,
		board[i][0], board[i][1], board[i][2], board[i][3], board[i][4], board[i][5], board[i][6],board[i][7],
		board[i][8], board[i][9], board[i][10], board[i][11],board[i][12],board[i][13],board[i][14]);// row 0
	}
	printf("\n\t\t\t\t\t\t|-1-|-2-|-3-|-4-|-5-|-6-|-7-|-8-|-9-|-10|-11|-12|-13|-14|-15|\n");

}

//FREE SPACES CHECK
int CheckFreePlaces(){
    int free=225;

    for(int i=0;i<15;i++){
		for(int j=0;j<15;j++){
			if (board[i][j] != ' ' )
			free--;
		}

    	return free;
	}
}


// PLAYING MOVES 

void PlayerMove(){
	char a[10], b[10];
	do{
		printf("%c's Turn:\nEnter the row(1-15):", current_player);
		scanf("%s",a);
		printf("%c's Turn:\nEnter the column(1-15):", current_player);
		scanf("%s",b);
		
		int x = atoi(a);
		int y = atoi(b);
		x--; y--;
		
		if( (x < 0 || x > 14)){
			printf("\n INVALID MOVE in rows\n ");
			continue;
		}
		else if ((y < 0 || y > 14)){
			printf("\n INVALID MOVE in columns\n ");
			continue;
		}
		else if (board[x][y] != ' ' ){
			printf("\n INVALID MOVE \n ");
			continue;
		}
		else {
			board[x][y]= current_player;
			m = x;
			n = y;
			break;
		}
    } while(1);

	current_player = (current_player == PLAYER1) ? PLAYER2 : PLAYER1;
}


//FUTURE PROSPECT: BOT 
void BotMove(){

}

// check winning positions
char CheckdaWinner(){
	int count=1,i,j;
	
	// horizontal
	for(i=0;i<15;i++){
		if(board[m][i]==board[m][i+1] && board[m][i]!= ' ')
			count++;
  		else count =1;

  		if (count == 5 ){
  			return board[m][i];
  		}
    }
	
	//for vertical
	count=1;
	for(j=0;j<15;j++){
		if(board[j][n]==board[j+1][n] && board[j][n]!=' ')
			count++;
  		else
			count =1;

    	if(count == 5 )
      		return board[j][n];
    
    }

   //diagonals
   //for lft to rt dia row>column
   count = 1;

   if (m>=n){
	for(j=0;(m-n)+j+1<=15;j++){
		if(board[m-n+j][j]==board[m-n+j+1][j+1] && board[m-n+j][j]!=' ')
			count++;
		else
			count =1;

		if(count == 5 ){
			return board[m][n];
		}
	}
	}

	//rt dia col>row
 	count =1;

	if (m<n){
		for(j=0;(n-m)+j+1<15;j++){
			if(board[j][n-m+j]==board[j+1][n-m+j+1] && board[j][n-m+j]!=' ')
				count++;
			else
				count =1 ;
			
			if(count == 5 ){
				return board[m][n];
			}
		}
	}

	// rt to lft dia  row>=col
  	count = 1;
	
	if(m>=n){
		for (int j=0;(m+n)-j>0;j++){
   			if((m+n)-j>15){
        		continue;
    		}
    		if (j+1>15){
        		break;
    		}

  			if(board[j][m+n-j]==board[j+1][m+n-j-1] && board[j][m+n-j]!=' ')
    			count++;
  			else 
				count =1 ;
    		
			if(count == 5 ){
     			printf("count = %d \t",count);
      			return board[m][n];
    		}
		}
	}

	// rt to lft dia  row<col
  	count =1;
	if(m<n){
  		for (int j=0;(m+n)-j>0;j++){
    		if((m+n)-j>15)
        		continue;
    		
			if (j+1>15)
        		break;
  			
			if (board[m+n-j][j]==board[m+n-j-1][j+1] && board[m+n-j][j]!=' ')
    			count++;
  			else 
				count =1 ;
    		
			if(count == 5 ){
      			return board[m][n];
    		}
      }
	}

	return ' ';
}


//printing winner
void PrintdaWinner(char winner){
  	congrats();
  	if (CheckFreePlaces() == 0){
		tie();
		getch();
	}
	else{
		printf("\n\t\t\t\t\t\t\t %c WINS :) !", winner);
		getch();
	}
}

//  main body
int main() {

	loading();
    char winner = ' ';
    ResetBoard();
    PrintBoard();
    
	while(CheckFreePlaces()!=0){
		PlayerMove();
		winner = CheckdaWinner();
		if (winner != ' ' || CheckFreePlaces() == 0) 
            break;
            
            
		PrintBoard();
 	}

	PrintBoard();
	PrintdaWinner(winner);
    return 0;
}
