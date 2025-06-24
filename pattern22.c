#include <stdio.h>

int main(){
    for(int i = 0; i<4; i++){
        for(int j = 0; j<4; j++){
            if(i == 0 || j == 0 || i == 4-1 || j == 4-1){
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}