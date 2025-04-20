#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>

struct termios old_props;

void clear_screen();
void set_terminal_attributes();
void reset_terminal_attributes();

int main() {
    set_terminal_attributes();
    return 0;
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