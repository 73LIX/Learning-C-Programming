#include <stdio.h>
#include <math.h>

int count_digits(int n){
    int cnt = 0;
    while(n > 0){
        n = n/10;
        cnt++;
    }
    return cnt;
}

int main(){
    int N, count;
    int sum = 0;
    int orig;
    printf("Enter a Number: "); 
    scanf("%d", &N);
    count = count_digits(N);
    orig = N;
    while(N>0){
        int ExtractedDigit = N%10;
        N = N/10;
        sum = sum + pow(ExtractedDigit, count);
    }
    if(sum == orig){
        printf("The number %d is a armstrong number\n", orig);
    } else {
        printf("The number %d is not a armstrong number\n", orig);
    }
    return 0;
}