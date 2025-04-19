#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

int difficulty;

typedef struct {
    int playerWon;
    int computerWon;
    int draw;
} Score;

Score score = {.playerWon = 0, .computerWon = 0, .draw = 0}; //Initial scores

int menu();
void clear_screen();
void print_board(char board[BOARD_SIZE][BOARD_SIZE]);
int win_check(char board[BOARD_SIZE][BOARD_SIZE], char player); //taken char player to check which player has won, ---computer or the user---
int draw_check(char board[BOARD_SIZE][BOARD_SIZE]);
void play_game();
void player_move(char board[BOARD_SIZE][BOARD_SIZE], char);
void computer_move(char board[BOARD_SIZE][BOARD_SIZE], char);
int is_valid_move(char board[BOARD_SIZE][BOARD_SIZE], int row, int col);

int main()
{
    srand(time(NULL));
    int play_again;
    difficulty = menu();
    do {
        play_game();
        printf("\nPlay again?(1 for yes || 2 for no): ");
        scanf("%d", &play_again);
        } while (play_again == 1);

    printf("\nThanks for playing!!!\n");

    return 0;
}

void play_game(){
    char board[BOARD_SIZE][BOARD_SIZE] = { //initializing a chara array (board)(tmp)
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };
    //checking for who is the current_player and generating alternate chances
    char current_player = rand() % 2 == 0 ? 'X' : 'O'; //rand will generate random number, and then the remainder with 2 would be either 0 or 1, using ternary operator for deciding factor(can use if else), if 0 then X is playing that is the user or the computer that is O
    print_board(board);
    while(1){
        if(current_player == 'X'){// if yes than player will do the first move
            player_move(board, 'X'); //function to implement players move
            print_board(board);
            //for win, checking immediately after their move is made
            if(win_check(board, 'X')){
                score.playerWon++;
                print_board(board);
                printf("\nPlayer wins!!!\n");
                break;
            }
            //alternate move setting
            current_player = 'O'; //if X moves then its O's chance next
        } else { //else computer will play the first move
            computer_move(board, 'O');
            print_board(board);
            if(win_check(board, 'O')){
                score.computerWon++;
                print_board(board);
                printf("\nComputer wins!!!\n");
                break;
            }
            current_player = 'X'; //if O moves then its X's chance next
        }

        if(draw_check(board)){
            score.draw++;
            print_board(board);
            printf("\nIt's a draw!!!\n");
            break;
        }
    }
    //co - ordination for alternate chances(i.e. if player got the first move randomly then next move should be of computer and so on this keeps on repeating) and also check for draws and wins
    //for win, checking immediately after their move is made
}

int is_valid_move(char board[BOARD_SIZE][BOARD_SIZE], int row, int col){
    return !(row < 0 || col < 0 || row > 2 || col > 2 || board[row][col]!= ' ');
}

//User's move
void player_move(char board[BOARD_SIZE][BOARD_SIZE], char player){
    int row, col;
    do{
        printf("\nPlayer %c's turn.\n", player);
        printf("Enter row and column between(1-3) for %c: ", player);
        scanf("%d", &row);
        scanf("%d", &col);
        //row and col are 0,1,2 but the user enters number between 1-3 i.e. 1/2/3 so converting the user input to our row/col value.
        row--;
        col--;
    } while(!is_valid_move(board, row, col));
    board[row][col] = player;
}

//Computer move
void computer_move(char board[BOARD_SIZE][BOARD_SIZE], char player){
    player_move(board, player); //tmp

}

int menu(){
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
   return ch;
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
    return 0;
}

//just need to check whether all the spaces are filled or not and then if there a winner or not, if no then result == draw
int draw_check(char board[BOARD_SIZE][BOARD_SIZE]){
    for(int i = 0; i < BOARD_SIZE; i++){ //row
        for(int j = 0; j < BOARD_SIZE; j++){ //col
            if(board[i][j] == ' '){ //checking for empty spaces if yes then it's still not a draw so return 0(false)
                return 0;
            }
        }
    }
    return 1; //if above condition is false then it means its filled without getting any winner that is leading to draw
}