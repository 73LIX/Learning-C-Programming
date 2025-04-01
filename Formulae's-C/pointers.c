#include <stdio.h>

int main(void)
{
    const int size = 6; //use of const is important to use it in array
    int runs[size] = {6, 4, 2, 1, 1, 4};
    double sum = 0.0;
    double *pointer_to_sum = &sum;
    int i;

    printf("\nRuns Scored in an over\n");

    for(i = 0; i<size; i++)
    {
        printf("%d\t", runs[i]);
    }
    printf("\n\n");

    for(i = 0; i<size; i++)
    {
        sum = sum+runs[i];
    }
    printf("Average %.2lf\n\n", sum/size);
    printf("\n\n");

    printf("sum is at%p, or %p and is %lf\n", pointer_to_sum, pointer_to_sum, *pointer_to_sum);

    printf("Runs are at %p to %p\n", runs, runs+6);

    return 0;
}