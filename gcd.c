#include <stdio.h>

int min(int a, int b){
    return a < b ? a : b;
}

int main(){
    int n1, n2;
    int gcd;
    printf("Enter 2 numbers: ");
    scanf("%d%d", &n1, &n2);
    for(int i = 1; i <= min(n1, n2); i++){
        if(n1%i==0 && n2%i==0){
            gcd = i;
        }
    }
    printf("%d\n", gcd);
    return 0;
}