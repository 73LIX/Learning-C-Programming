/*
F(0) = 0, F(1) = 1
F(n) = F(n-1) + F(n-2)
*/

#include <stdio.h>

long int fibonacci(int n)
{
    long f2 = 0, f1=1, f_old;
    int i;

    for(i = 0; i<n; i++)
    {
        f_old = f2;
        f2 = f2+f1;
        f1 = f_old;
    }
    return f2;
}

long int recur_fibonacci(int n)
{
    if (n<=1) //You will get the F(0) as 0 and F(1) as 1 once you enter that, this makes it more efficient no need to go for the loop
    {
        return n;
    }
    else{
        return(recur_fibonacci(n-1) + recur_fibonacci(n-2));
    }
}

int main (void)
{
    int how_many = 0, i;
    printf("Enter the no. of values you want the fibonacci table to be printed .i.e n: ");

    scanf("%d", &how_many);
    printf("\nFibonacci\n");

    for(i = 0;i<=how_many; i++)
    {
        printf("\n%d\t %ld  %ld\n", i, fibonacci(i), recur_fibonacci(i));
    }
}