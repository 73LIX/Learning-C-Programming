#include <stdio.h> 

int main(){
    for(int i = 1; i<=5; i++){
        int ASCII = 65;
        for(int j = 1; j <= 5-i+1; j++){
            printf("%c ", ASCII);
            ASCII++;
        }
        printf("\n");
    }
    return 0;
}