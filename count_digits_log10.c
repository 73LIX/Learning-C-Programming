#include <stdio.h>
#include <math.h>

int count_digits(int n){
    int cnt = floor(log10(n))+1;
    return cnt;
}

int main(){
    int N;
    printf("Enter a Number: "); 
    scanf("%d", &N);
    int digits = count_digits(N);
    printf("Number of digits: %d\n", digits);
    return 0;
}