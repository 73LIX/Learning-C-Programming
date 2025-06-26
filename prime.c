#include <stdio.h>

int main(){
    int N, count;
    printf("Enter a number: ");
    scanf("%d", &N);
    for(int i = 1; i <= N; i++){
        if(N%i == 0){
            count++;
        }
    }
    if(count == 2){
        printf("The number %d is a prime number\n", N);
    } else {
        printf("The number %d is not a prime number\n", N);
    }
    return 0;
}