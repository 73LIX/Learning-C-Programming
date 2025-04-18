#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 3

typedef struct {
    int playerWon;
    int computerWon;
    int draw;
} Score;

Score score = {.playerWon = 0, .computerWon = 0, .draw = 0}; //Initial scores

void menu();
void clear_screen();
void print_board(char board[BOARD_SIZE][BOARD_SIZE]);
int win_check(char board[BOARD_SIZE][BOARD_SIZE], char player); //taken char player to check which player has won, ---computer or the user---
int draw_check(char board[BOARD_SIZE][BOARD_SIZE]);

int main()
{
    char board[BOARD_SIZE][BOARD_SIZE] = { //initializing a chara array (board)
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };
    menu();
    print_board(board);
    return 0;
}

void menu(){
    int ch;
    while(1){
    printf("\n<--- Select difficulty level --->\n");
    printf("1 - Standard mode\n");
    printf("2 - God mode\n");
    printf("Choice: ");
    scanf("%d", &ch);

    if (ch != 1 && ch != 2) {
        printf ("\n\n Incorrect choice, Try again!!!");
    } else {
        break;
    }
   }
}

void print_board(char board [BOARD_SIZE][BOARD_SIZE]){
    clear_screen();
    printf("Score - Player: %d, Computer: %d, Draws: %d", score.playerWon, score.computerWon, score.draw);
    printf("\nTic-Tac-Toe\n");

    for(int i = 0; i < BOARD_SIZE; i++){ //iterates through the rows of the board
        printf("\n");
        for(int j = 0; j < BOARD_SIZE; j++){ //iterates through the cols of the current row

            printf(" %c ", board[i][j]); //this prints the character stored in the current cell board[i][j] (which will be ' ', 'X', or 'O') surrounded by spaces for formatting.
            if(j<BOARD_SIZE - 1) { //after printing a cell, this if condition checks if it's not the last cell in the current row. If it's not, it prints a vertical bar '|' to separate the cells.
                printf("|");
            }
        }
        if (i<BOARD_SIZE-1){ //after printing a row, this if condition checks if it's not the last row. If it's not, it prints a horizontal separator to visually separate the rows.
            printf("\n---+---+---");
        }
    }
    printf("\n\n"); //adds some spacing at the end
}

void clear_screen(){
    #ifdef _WIN32 
         system("cls");
        #else 
         system("clear");
        #endif
}

//checking for win or draw (3 rows and col win, 2 diagonal win)
int win_check(char board[BOARD_SIZE][BOARD_SIZE], char player){
    for (int i = 0; i<BOARD_SIZE; i++){
        //Row check for win
        if(board[i][0] == player && board[i][1] == player && board[i][2] == player){
            return 1;
        }
        //Column check for win
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player){
            return 1;
        }
    }

    //Hardcoding diagonal check (because board size ain't gonna change for this game so yeah :)
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player){
        return 1;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player){
        return 1;
    }
}

//just need to check whether all the spaces are filled or not and then if there a winner or not, if no then result == draw
int draw_check(char board[BOARD_SIZE][BOARD_SIZE]){
    for(int i = 0; i < BOARD_SIZE; i++){ //row
        for(int j = 0; j < BOARD_SIZE; i++){ //col
            if(board[i][j] == ' '){ //checking for empty spaces if yes then it's still not a draw so return 0(false)
                return 0;
            }
        }
    }
    return 1; //if above condition is false then it means its filled without getting any winner that is leading to draw
}