#include <stdio.h>

int main(){
    int space = 2*(4-1);
    for(int i = 1; i <= 4; i++){
        for(int j = 1; j<=i; j++){
            printf("%d", j);
        }
        for(int k = 1; k<=space; k++){
            printf(" ");
        }
        for(int l = i; l>=1; l--){
            printf("%d", l);
        }
        printf("\n");
        space -= 2;
    }
    return 0;
}