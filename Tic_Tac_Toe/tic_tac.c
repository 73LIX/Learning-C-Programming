#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int playerWon;
    int computerWon;
    int draw;
} Score;

Score score = {.playerWon = 0, .computerWon = 0, .draw = 0}; //Initial scores

void menu();
void clear_screen();
void print_board();

int main()
{
    menu();
    print_board();
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

void print_board(){
    clear_screen();
    printf("\nScore - Player: %d, Computer: %d, Draws: %d", score.playerWon, score.computerWon, score.draw);
}

void clear_screen(){
    #ifdef _WIN32 
         system("cls");
        #else 
         system("clear");
        #endif
}