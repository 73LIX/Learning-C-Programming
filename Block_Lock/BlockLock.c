#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <stdlib.h>

static struct termios old_props, new_props;
static char keystate[256];

void reset_terminal();
void restore_terminal();
void process_input();

int main(){
    reset_terminal();
    while(1){
        process_input();
        usleep(20000);
    }
    restore_terminal();
    return 0;
}

void process_input(){
    char c;
    for(int i = 0; i < 256; i++){
        keystate[i] = 0;
    }
    //Reading input
    while(read(STDIN_FILENO, &c, 1) > 0){
        printf("\ninput: %c", c);
        unsigned char uc = (unsigned char) c;
        keystate[uc] = 1;
    }
}

void reset_terminal(){
    tcgetattr(STDIN_FILENO, &old_props);
    new_props = old_props;
    new_props.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &new_props);
    fflush(stdout);
}

void restore_terminal(){
    tcsetattr(STDIN_FILENO, TCSANOW, &old_props);
    printf("terminal porperties restored*\n");
}