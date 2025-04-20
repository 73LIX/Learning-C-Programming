#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <time.h>
#include <sys/time.h>

#define height 20
#define width 60

typedef enum {
    UP,
    DOWN,
    LEFT,
    RIGHT,
    STOP
} Direction;

Direction dir;
int score = 0;
int fruit_x, fruit_y;
int snakeHead_x, snakeHead_y;

struct termios old_props;

void clear_screen();
void set_terminal_attributes();
void reset_terminal_attributes();
void draw();
void setup(); //initally setups the values of fruit and snake
void game_play();
int input_available();

int main() {
    srand(time(NULL));
    set_terminal_attributes();
    setup();
    while(1){
        draw();
        game_play();
        sleep(1);
    }
    return 0;
}

void draw(){
    clear_screen();
    printf("\t\tWelcome to The Snake Game!!!");
    printf("\n");
    for(int i = 0; i < width + 2; i++){
        printf("/");
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
        printf("/");
    }
    printf("\n Score: %d\n", score);
}

void game_play(){
    //controls
    switch (dir)
    {
    case UP:
        snakeHead_y--;
        break;
    case DOWN:
        snakeHead_y++;
        break;
    case LEFT:
        snakeHead_x--;
        break;
    case RIGHT:
        snakeHead_x++;
        break;
    case STOP:
        //eat 5⭐ do nothing
        break;
    }

    //Pass through boundaries

    //Check if the snake head is outside of the board or not and make it appear on the opposite side
    if(snakeHead_x < 0){
        snakeHead_x = width - 1; //if less than 0 then make it appear on the last end
    } else if(snakeHead_x >= width){ //if already crossed the last end then make it appear on the start that is = 0
        snakeHead_x = 0;
    }

    if(snakeHead_y < 0){
        snakeHead_y = height - 1;
    } else if (snakeHead_y >= height){
        snakeHead_y = 0;
    }

    //If the fruit is eaten
    if(snakeHead_x == fruit_x && snakeHead_y == fruit_y){ //Meaning head is exactly on the food
        score += 10;
        //randomize the fruit spawn again
        fruit_x = rand() % width;
        fruit_y = rand() % height;  
    } 
}

//Check for input in the input buffer recieved from the keyboard
int input_available(){
    struct timeval tv = {0L, 0L};
    fd_set fds;
    FD_SET(0, &fds);
    return select(1, &fds, NULL, NULL, &tv);
}

//Setup's the positions of the fruit and snake head
void setup(){
    //snake will start from center
    snakeHead_x = width / 2;
    snakeHead_y = height / 2;
    //fruit will spawn randomly
    fruit_x = rand() % width;
    fruit_y = rand() % height;
    dir = DOWN; //initally tmp settings for direction(just for testing out pass through boundaries)
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