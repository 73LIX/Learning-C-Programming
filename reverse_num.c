#include <stdio.h>

int main(){
    int N;
    int revNum = 0;
    printf("Enter a Number: "); 
    scanf("%d", &N);
    while(N>0){
        int ExtractedDigit = N%10;
        N = N/10;
        revNum = (revNum*10) + ExtractedDigit;
    }
    printf("%d\n", revNum);
    return 0;
}