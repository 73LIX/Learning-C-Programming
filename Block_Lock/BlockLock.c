#include <stdio.h>
#include <termios.h>
#include <unistd.h>

static struct termios old_props, new_props;

void reset_terminal();
void restore_terminal();

int main(){
    reset_terminal();
    restore_terminal();
    return 0;
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