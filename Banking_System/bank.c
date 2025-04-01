#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define CREDS 50

typedef struct
{
    char username[CREDS];
    int monum;
    int AccNum;
    float balance;
}Account;

void menu();
void create_acc();
void deposit_money();
void withdraw_money();
void check_balance();
void fgets_fix();

int main(){
    menu();
    return 0;
}

void menu(){
    while(1){
    int choice;
    printf("\n<----Banking Management system---->");
    printf("\n1. Create Account\n2. Deposit Money\n3. Withdraw Money\n4. Check Balance\n5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        create_acc();
        break;
    case 2:
        deposit_money();
        break;
    case 3:
        withdraw_money();
        break;
    case 4:
        check_balance();
        break;
    case 5:
        printf("\n<-----Logged out----->\n");
        exit(0);
    default:
        printf("Invalid Choice");
        break;
    }
   }
}

//Account Creation
void create_acc(){
    Account acc;
    //File handling(Writing in files)
    FILE *file = fopen("account.dat", "ab+");
    if(file == NULL){
        printf("Unable to open the file");
        return;
    }
    printf("\n<----Welcome to Nigg* Bank---->\n");
    printf("\n\033[31m(Please enter the following details to complete registration)\033[0m\n");
    //Bugfix(solving new line in input buffer problem)
    char c;
    do{
        c = getchar();
    }while(c != '\n' && c != EOF); //Ensures Consuming all the characters in the input buffer, including any stray newline characters that might have been left behind from previous user inputs.

    printf(">Name: ");
    fgets(acc.username, CREDS, stdin);
    fgets_fix(acc.username);

    printf(">Mobile Number: ");
    scanf("%d", &acc.monum);
    acc.balance = 0;

    //Account number generation
    srand(time(NULL));{
        acc.AccNum = rand()%100000 + 1;
    }

    fwrite(&acc, sizeof(acc), 1, file);
    fclose(file);

    printf("\n\033[32mAccount Created Successfully!\033[0m\n");
    printf("Account number Generated: %d\n", acc.AccNum);
    printf("\033[31m(Please note the account number, YOU WILL NEED THAT AGAIN FOR SURE:))\033[0m\n");

}

//Deposit money(First login)
void deposit_money(){
    FILE *file = fopen("account.dat", "rb+");
    if(file == NULL){
        printf("Unable to open account file!!");
    }

    int acc_no;
    Account acc_to_read;
    float money;
    printf("Enter your account number: ");
    scanf("%d", &acc_no);
    printf("Enter amount to deposit: ");
    scanf("%f", &money);

    while(fread(&acc_to_read, sizeof(acc_to_read), 1, file)){
        if(acc_to_read.AccNum == acc_no){
            acc_to_read.balance = acc_to_read.balance + money;
            fseek(file, -sizeof(acc_to_read), SEEK_CUR); //The read mode places the cursor at the end of the record it read so To move the cursor from the current position to the face that is front of the record we use this.
            fwrite(&acc_to_read, sizeof(acc_to_read), 1, file);//writing the content(overwriting)
            fclose(file);
            printf("Successfully deposited Rs.%.2f\n", money);
            printf("New balance: %.2f", acc_to_read.balance);
            return;
        }
    }
    fclose(file);
    printf("\nAccount no: %d was not found. Try again!", acc_no);
}

//Withdraw Money
void withdraw_money(){
    FILE *file = fopen("account.dat", "rb+");
    if(file == NULL){
        printf("Unable to open account file!!");
    }

    int acc_no;
    Account  acc_to_read;
    float money;
    printf("Enter your account number: ");
    scanf("%d", &acc_no);
    printf("Enter amount to withdraw: ");
    scanf("%f", &money);

    while(fread(&acc_to_read, sizeof(acc_to_read), 1, file)){
        if(acc_to_read.AccNum == acc_no){
            if(money > acc_to_read.balance){
                printf("Insufficient balance");
                return;
            }
            acc_to_read.balance = acc_to_read.balance - money;
            fseek(file, -sizeof(acc_to_read), SEEK_CUR);
            fwrite(&acc_to_read, sizeof(acc_to_read), 1, file);
            fclose(file);

            printf("\n\033[32mTranscation Successful\033[0m\n");
            printf("New balance: %.2f", acc_to_read.balance);
            return;
        }
    }
    fclose(file);
    printf("\nAccount no: %d was not found. Try again!", acc_no);
}

//Check balance
void check_balance(){
    FILE *file = fopen("account.dat", "rb");
    if(file == NULL){
        printf("Unable to open the file");
        return;
    }

    int acc_no;
    Account acc_read;
    printf("Enter your Account number: ");
    scanf("%d", &acc_no);

    while(fread(&acc_read, sizeof(acc_read), 1, file)){
        if(acc_read.AccNum == acc_no){
            printf("\nYour Current balance is Rs %.2f", acc_read.balance);
            fclose(file);
            return;
        }
    }
    fclose(file);
    printf("\nAccount no: %d was not found. Try again!", acc_no);

}

//Fix for fgets newline '\n
void fgets_fix(char* string){
    int index = strcspn(string, "\n");
    string[index] = '\0';
}