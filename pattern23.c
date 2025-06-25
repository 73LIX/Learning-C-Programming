#include <stdio.h>
   
int min(int a, int b) {
    return (a < b) ? a : b;
}

int main(){
    for(int i = 0; i<2*4-1; i++){
        for(int j = 0; j<2*4-1; j++){
            int top = i; 
            int left = j;
            int right = (2*4-2) - j;
            int down = (2*4-2) - i;
            int result = 4 - min(min(top, down), min(left, right));
            printf("%d ", result);
        }
        printf("\n");
    }
    return 0;
}
