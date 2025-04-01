#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int rnd, guess, count=0;
    srand(time(NULL));

    printf("Enter a number to guess: ");
    rnd = rand() % 100 +1;

    do { //do while because kam se kam ek number guess to chaiye hee user se
        printf("\nPlease enter your guess between(1-100): ");
        scanf("%d", &guess);
        count++;

        if(guess < rnd){
            printf("Guess larger number\n");
        } else if(guess > rnd){
            printf("Guess a smaller number\n");
        } else {
            printf("congratulations! You have successfully guessed the number in %d attempts.\n", count);
        }
    } while (guess != rnd);

    printf("Thanks for players\n");
    printf("Developed by: Gour4v\n");
}