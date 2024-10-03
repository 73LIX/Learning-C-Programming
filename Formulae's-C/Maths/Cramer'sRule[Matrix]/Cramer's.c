#include <stdio.h>

//Determinant calculation eqn for 3x3 matrix only
float determinant(float matrix[3][3]){
    float det = matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1])
              - matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0])
              + matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]);

    return det;
}

int main(){
    int i, j;
    float a[3][3]; //Coefficient matrix
    float d[3]; //Constant terms
    float detA, detX, detY, detZ; //we will store the determinant in these var

    printf("NOTE:Cramer's rule only works for square systems of equations, where the number of equations is equal to the number of unknowns.\n\n");

    //input coefficient matrix
    printf("Enter the coefficients of the equations(.i.e the coefficients of x/y/z from the eqns):\n");
    for (i = 0;i<3;i++){
        for(j = 0;j<3;j++){
            printf("a[%d][%d]: ", i+1, j+1); //prompts the user for aij
            scanf("%f", &a[i][j]);
        }
    }

    //input constant terns
    printf("Enter the constant terms(.i.e the 'd'): \n");
    for(i = 0; i<3;i++){
        printf("d[%d]: ", i+1);
        scanf("%f", &d[i]);
    }

    //find determinant of coefficient matrix let name be [A]
    detA = determinant(a); //this will calculate the determinant of 'a' using the determinant function defined above
    if(detA == 0){
        printf("The system has no unique solution.\n");
        return 0;
    }
    //replace first column with constants for determinant of x
    float temp[3][3];
    for(i = 0;i<3;i++) {
        for(j =0; j<3; j++){
            temp[i][j] = a[i][j];
        }
    }
    for(i = 0; i<3; i++) temp[i][0] = d[i];
    detX = determinant(temp);

    //replace second column with constant for determinant of Y
    for(i = 0;i<3;i++) temp[i][0] = a[i][0]; //restore the first column back to original
    for(i =0;i<3;i++) temp[i][1] = d[i];
    detY = determinant(temp);

    //REplace third colum with constants for determinant of Z
    for(i = 0;i<3;i++) temp[i][1] = a[i][1]; //restore the second cloumn
    for(i = 0;i<3;i++) temp[i][2] = d[i];
    detZ = determinant(temp);

    //compute
    float x = detX/detA;
    float y = detY/detA;
    float z = detZ/detA;

    printf("The solution is as follows:-\n");
    printf("x = %f\n", x);
    printf("y = %f\n", y);
    printf("z = %f\n", z);

    return 0;
}