#include <stdio.h>
#include <math.h>

int main(){
    int N;
    int count;
    printf("Enter a Number: "); 
    scanf("%d", &N);
    while(N>0){
        N = N/10;
        count++;
    }
    printf("Number of digits: %d\n", count);
}