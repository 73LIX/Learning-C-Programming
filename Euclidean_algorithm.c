//Euclidean algorithm is a method for efficiently finding the greatest common divisor (GCD) of two integers
#include <stdio.h>

int main(){
    int a, b;
    int gcd;
    printf("Enter 2 numbers: ");
    scanf("%d%d", &a, &b);
    while(a > 0 && b > 0){
        if(a>b){
            a = a % b;
        } else {
            b = b % a;
        }
        if(a == 0){
            gcd = b;
        } else {
            gcd = a;
        }
    }
    printf("GCD: %d\n", gcd);
    return 0;
}