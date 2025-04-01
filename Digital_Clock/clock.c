#include <stdio.h>
#include <stdlib.h> //use system commands on the terminal to clear the screen
#include <time.h>
#include <unistd.h> //to use sleep function

void get_time(char*, int);
void get_date(char*);
int input_choice();
void clear_screen();

int main(){
    char time[50], date[100];
    int choice = input_choice();

    while(1){
    get_time(time, choice);
    get_date(date);
    clear_screen();    
    printf("\nCurrent Time: %s\n", time);
    printf("Date: %s\n", date);
    sleep(1); //sleep for 1sec
    }
    return 0;
}

void clear_screen(){
    #ifdef _WIN32 //this is a preprocessor directive("If defined"): checks for windows, if it's windows then
    //_WIN32 symbol is defined by windows compilers
     system("cls"); //executes the 'cls' command in the shell
    #else //if _WIN32 is not defined then #else will be used
     system("clear"); //executes 'clear' for linux and macos
    #endif //end
}

int input_choice(){
    int choice;
    printf("\n Choose the time format: ");
    printf("\n1. 24 hour format\n2. 12 hour format(default)");
    printf("\nMake a choice(1 or 2): ");
    scanf("%d", &choice);
    return choice;
}

void get_time(char* buffer, int choice){ //string to show formated time(final formated time is stored here in)
    time_t rawtime; //variable created (time_t from time.h)
    struct tm *current_time; //structure defined in time.h that holds the components of a calendar.
    
    time(&rawtime); //inserting the current time number according to the system into rawtime variable.
    current_time = localtime(&rawtime); //converting rawtime into local time that is for example india in this case.
    if(choice == 1){
     strftime(buffer, 50, "%H:%M:%S %p", current_time); //string format time .i.e format the time into a string
    } else {
        strftime(buffer, 50, "%I:%M:%S %p", current_time);
    }
}

void get_date(char* buffer){
    time_t rawtime;
    struct tm *current_time;

    time(&rawtime);
    current_time = localtime(&rawtime);
    strftime(buffer, 100, "%a %d/%m/%y", current_time);
}