#include <stdio.h>

int main(){
    int N;
    printf("Enter a number: ");
    scanf("%d", &N);
    for(int i = 1; i <= N; i++){
        if(N%i == 0){
            printf("%d, ", i);
        }
    }
    printf("\n");
    return 0;
}