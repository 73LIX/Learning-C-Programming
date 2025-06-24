#include <stdio.h>

int main(){
    for(int i = 0; i<5; i++){
        int ASCII = 69-i; //we calculate the correct starting ASCII value for that specific row.z
        for(int j = 0; j<=i; j++){
            printf("%c", ASCII);
            ASCII++;
        }
        printf("\n");
    }
    return 0;
}