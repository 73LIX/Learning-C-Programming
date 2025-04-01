#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>

const int bAR_LENGTH = 50; //total bar length including both the spaces + '=' progress
const int MAX_TASKS = 5; //Number of tasks

typedef struct
{
    int id;
    int progress;
    int step;
}Task;

void print_bar(Task task);
void clear_screen();

int main(){
    Task tasks[MAX_TASKS];
    int i;
    srand(time(NULL)); //random seed generator

    //Initialization
    for(i = 0; i<MAX_TASKS; i++){
        tasks[i].id = i+1;
        tasks[i].progress = 0;
        tasks[i].step = rand() % 5 + 1; //random number generation
    }
    //Loop to increase the progress and simulate the steps
    int tasks_incomplete = 1;
    while(tasks_incomplete){
       tasks_incomplete = 0;
       for(i = 0; i<MAX_TASKS; i++){
         tasks[i].progress += tasks[i].step;
         if (tasks[i]. progress > 100){
            tasks[i].progress = 100;
         }
          else if (tasks[i].progress < 100){
            tasks_incomplete = 1;
        }
        print_bar(tasks[i]);
       }
        sleep(1); //Sleep for 1second

        clear_screen();

    }

    printf("All tasks are completed!\n");
    return 0;
}

void clear_screen(){
    #ifdef _WIN32 
         system("cls");
        #else 
         system("clear");
        #endif
}

void print_bar(Task task){
    int bars_to_show = task.progress * bAR_LENGTH / 100; //calculating the amount of progress to start initially

    printf("\nTask %d: [", task.id);
    for(int i = 0; i<bAR_LENGTH; i++){
        if(i < bars_to_show){ //if i is less than the amount of bars we calculated then '=' would be printed to show the amount of progress initially
            printf("=");
        } else {
            printf(" "); //for the remaining progress to be covered it would be left with spaces.
        }
    }
    printf("] %d%%\n", task.progress);
}