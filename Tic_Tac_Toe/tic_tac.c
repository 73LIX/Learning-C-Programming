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

int main()
{
    char board[BOARD_SIZE][BOARD_SIZE] = {
        {' ', 'O', ' '},
        {'X', ' ', 'X'},
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

    for(int i = 0; i < BOARD_SIZE; i++){
        printf("\n");
        for(int j = 0; j < BOARD_SIZE; j++){
            printf(" %c ", board[i][j]);
            if(j<BOARD_SIZE - 1) {
                printf("|");
            }
        }
        if (i<BOARD_SIZE-1){
            printf("\n---+---+---");
        }
    }
    printf("\n");
}

void clear_screen(){
    #ifdef _WIN32 
         system("cls");
        #else 
         system("clear");
        #endif
}