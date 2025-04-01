#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int numGenerator();

int main(){
    int ch, rnd, count=0; 
    printf("Welcome to guessing the number game\n");
    srand(time(NULL));{ // Seed with the current time for different sequences each run
    rnd=numGenerator(); 
    }
    while(1){
    printf("Guess the number between(0 - 100): ");
    scanf("%d", &ch);
    count++;
    if(ch==rnd){
        printf("You won!\n");
        printf("Created by: Gour4v\n");
        printf("It took you a total of %d guesses\n", count);
        exit(0);
    }else if(ch>rnd){
        printf("Oh! Try a smaller number\n");
    }else if(ch<rnd){
        printf("HaHa! Try a bigger number\n");
    }
}

}

int numGenerator(){
    int num = rand()%100+1; //using rand function which generates random number
    //and the (%100+1) part generate between 0 and 99 + 1 for range 0 to 100
    return num;
}