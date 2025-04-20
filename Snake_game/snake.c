#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <time.h>

#define height 20
#define width 60

int score = 0;
int fruit_x, fruit_y;
int snakeHead_x, snakeHead_y;

struct termios old_props;

void clear_screen();
void set_terminal_attributes();
void reset_terminal_attributes();
void draw();
void setup(); //initally setups the values of fruit and snake

int main() {
    srand(time(NULL));
    set_terminal_attributes();
    setup();
    draw();
    return 0;
}

void draw(){
    clear_screen();
    printf("\t\tWelcome to The Snake Game!!!");
    printf("\n");
    for(int i = 0; i < width + 2; i++){
        printf("-");
    }

    for(int i = 0; i < height; i++){
        printf("\n|");
        for(int j = 0; j < width; j++){
            if (i == snakeHead_y && j == snakeHead_x){ //i is for rows that is y cordinate, and j is for columns that is x cordinate
                printf("O");
            } else if(i == fruit_y && j == fruit_x){
                printf("@");
            } else {
                printf(" ");
            }
        }printf("|");
    }
    printf("\n");
    for(int i = 0; i < width + 2; i++){
        printf("-");
    }
    printf("\n Score: %d\n", score);
}

//Setup's the positions of the fruit and snake head
void setup(){
    //snake will start from center
    snakeHead_x = width / 2;
    snakeHead_y = height / 2;
    //fruit will spawn randomly
    fruit_x = rand() % width;
    fruit_y = rand() % height;
}

void set_terminal_attributes(){
    struct termios new_props;
    tcgetattr(STDIN_FILENO, &old_props);
    atexit(reset_terminal_attributes); //Whenever we exit our program, this atexit will call the function passed to it that is reset_terminal_attr();
    new_props = old_props;
    new_props.c_lflag &= ~(ECHO | ICANON);
    tcsetattr(STDIN_FILENO, TCSANOW, &new_props);
}

void reset_terminal_attributes(){
    tcsetattr(STDIN_FILENO, TCSANOW, &old_props);
}

void clear_screen(){
    #ifdef _WIN32 
         system("cls");
        #else 
         system("clear");
        #endif
}