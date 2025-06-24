#include <stdio.h>

int main(){
    int space_bottom = 2*(5-1);
    for(int i = 1; i <= 5; i++){
        for(int j = 1; j<=i; j++){
            printf("*");
        }
        for(int k = 1; k<=space_bottom; k++){
            printf(" ");
        }
        for(int l = 1; l<=i; l++){
            printf("*");
        }
        printf("\n");
        space_bottom -= 2;
    }
    int space_top = 2;
    for(int i = 1; i <= 4; i++){
        for(int j = 1; j<=4-i+1; j++){
            printf("*");
        }
        for(int k = 1; k<=space_top; k++){
            printf(" ");
        }
        for(int l = 1; l<=4-i+1; l++){
            printf("*");
        }
        printf("\n");
        space_top += 2;
    }
    return 0;
}