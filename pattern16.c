#include <stdio.h> 

int main(){
    int ASCII = 65;
    for(int i = 1; i<=5; i++){
        for(int j = 1; j <= i; j++){
            printf("%c ", ASCII);
        }
        printf("\n");
        ASCII++; //or ASCII = ASCII + 1;
    }
    return 0;
}