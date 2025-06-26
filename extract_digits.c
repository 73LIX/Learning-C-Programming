#include <stdio.h>

int main(){
    int N;
    int count;
    printf("Enter a Number to be Extracted: "); 
    scanf("%d", &N);
    while(N>0){
        int ExtractedDigit = N%10;
        count++;
        printf("%d, ", ExtractedDigit);
        N = N/10;
    }
    printf("\nNumber of digits: %d\n", count);
}