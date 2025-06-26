#include <stdio.h>

int main(){
    int N;
    int original;
    int revNum = 0;
    printf("Enter a Number: "); 
    scanf("%d", &N);
    original = N;
    while(N>0){
        int ExtractedDigit = N%10;
        N = N/10;
        revNum = (revNum*10) + ExtractedDigit;
    }
    printf("Its reverse is %d\n", revNum);
    if(revNum == original){
        printf("The number %d is a palindrome\n", original);
    } else {
        printf("The number %d is not a palindrome\n", original);
    }
    return 0;
}