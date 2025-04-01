#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void menu();
void addition();
void subtraction();
void multiplication();
void divide();
void modulus();
void power();

int main(){
    int ch;
    while(1){
        menu();
        scanf("%d", &ch);

        switch(ch){
            case 1:
             addition();
             break;
            case 2:
             subtraction();
             break;
            case 3:
             multiplication();
             break;
            case 4:
             divide();
             break;
            case 5:
             modulus();
             break;
            case 6:
             power();
             break;
            case 7:
             exit(0);
            default:
             printf("Invalid Choice");
        }
    }
}

void menu(){
    printf("\n<------------------------------------------>\n");
    printf("Welcome to Simple Calculator\n");

    printf("Choose one of the following options\n");
    printf("1. Add\n2. Subtract\n3. Multiply\n4. Divide\n5. Modulus\n6. Power\n7. Exit\n");
    printf("Now, enter your choice: ");
}

void addition(){
    int a, b, add;
    printf("Enter 2 numbers to Add: ");
    scanf("%d %d", &a, &b);
    add = a+b;
    printf("\n%d + %d = %d",a,b,add);
}

void subtraction(){
    int a, b, sub;
    printf("Enter 2 numbers to Subtract: ");
    scanf("%d %d", &a, &b);
    sub = a-b;
    printf("\n%d - %d = %d",a,b,sub);
}

void multiplication(){
    float a, b, multi;
    printf("Enter 2 numbers to Multiply: ");
    scanf("%f %f", &a, &b);
    multi = a*b;
    printf("\n%f * %f = %.2f",a,b,multi);
}

void divide(){
    float a, b, div;
    printf("Enter 2 numbers to Divide: ");
    scanf("%f %f", &a, &b);
    if (b == 0){ //error handling for division
        fprintf(stderr, "Invalid Argument for Division"); //fprintf is used for error handling and print error
        return NAN;
    } else {
    div= a/b;
    printf("\n%f / %f = %.2f", a, b, div);
    }
}

void modulus(){
    int a, b, mod;
    printf("Enter 2 numbers to calculate the remainder: ");
    scanf("%d %d", &a, &b);
    if ( b == 0){
        fprintf(stderr, "Invalid Argument for Modulus");
        return NAN;
    }
    else{
    mod = a%b;
    printf("\nRemainder = %d", mod);
    }
}

void power(){
    double a, b, power;
    printf("Enter the number and the exponent you want: ");
    scanf("%lf %lf", &a, &b);
    power = pow(a, b);
    printf("\nPower of %lf to %lf is %lf", a, b, power);
}

//use -lm while compiling the code to link the math library, which contains the pow function
//the linker needs to be told to include the actual compiled code for the function from the math library.
//"gcc calc.c -o calc.exe -lm"