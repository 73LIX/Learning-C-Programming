#include <stdio.h>

int main(){
    for(int i = 1; i <= 4; i++){
        int ASCII = 65;
        int breakpoint = (2*i-1) / 2;
        for(int j = 1; j <= 4 - i; j++){
            printf(" ");
        }
        for(int k = 1; k <= 2*i-1; k++){
            printf("%c", ASCII);
            if(k <= breakpoint){
                ASCII++;
            } else {
                ASCII--;
            }
        }
        for(int l = 1; l <= 4 - i; l++){
            printf(" ");
        }
        printf("\n");
    }
    return 0;
}