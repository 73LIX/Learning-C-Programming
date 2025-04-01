#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h> //to access terminal properties
#include <termios.h> //edit terminal functions to enable masking

#define MAX_USERS 10 //Max users our program can hold //can increase it on your use case 
#define CREDENTIALS_LENGTH 30 //Max length of pass and username

typedef struct{ //structure is better to keep the username and password for each user as every user will have separate pair of these values, so decalaring is separately would be a pain
   char username[CREDENTIALS_LENGTH];
   char password[CREDENTIALS_LENGTH];
}User;

User users[MAX_USERS]; //User(structure) type array to store the data of different users
int user_count = 0; //Counter to count the number of users.

void menu(); //Menu for the program
void regi(); //function to handle registration
int login(); //Returns the user index or -1 for invalid credentials
void fgets_fix (char*); //fgets ignores the escape sequence '/n', so to fix that issue, gonna use the /0 to end a string.
void input_password(char*); //function to input pass with masking.

int main (){
    menu();
    return 0;
}

void menu(){
    int ch;
    int user_index;
    while(1){
    printf("\n1. Register\n2. Login\n3. Exit");
    printf("\nSelect an option: ");
    scanf("%d", &ch);
    getchar(); //Consume extra "enter"

    switch(ch){
        case 1:
         regi();
         break;
        case 2:
         user_index = login(); //user index returned by the login() function will be stored here in user_index
         if (user_index >= 0){ //if return -1 then this part won't be evaluated
            printf("\nLogged in successfully! Welcome, %s (^_^)\n", users[user_index].username); //Prints successfull login with username/ How? - So basically we use the returned index as the index for the users array we created earlier where all the detailes for every use is saved, and the '.' dot notation helps us to access the member of one of the structure variable in the users arrays.
         } else {
            printf("\nInvalid username or password\n");
         }
         break;
        case 3:
         printf("<------Exiting program------>\n");
         exit(0);
        default:
         printf("Invalid choice please try again!");
         break;
    }
  }
}

void regi(){
    if (user_count == MAX_USERS){
        printf("Maximum %d users are supported!\nNo more registrations allowed\n", MAX_USERS);
        return; //function will be closed immediately after this, that's why return is added here although its a void type.
    }

    int new_index = user_count;
    printf("\n<------Register a new user------>\n");
    printf("Enter username: ");
    fgets(users[new_index].username, CREDENTIALS_LENGTH, stdin);
    fgets_fix(users[new_index].username);
    input_password(users[new_index].password);

    user_count++;
    printf("\nRegistration Successful!\n");
}

int login(){
    char username[CREDENTIALS_LENGTH], pass[CREDENTIALS_LENGTH]; //local variable declaration to compare and check whether the username and pass we have in our users array mathches this or not. //If any pass and username matches then that user would be logged in and prompted success.
    printf("\n<------Login------>\n");
    printf("Enter username: ");
    fgets(username, CREDENTIALS_LENGTH, stdin);
    fgets_fix(username);
    input_password(pass);

    for(int i = 0; i < user_count; i++){
        if (strcmp(username, users[i].username) == 0 && strcmp(pass, users[i].password) == 0){
            return i;
        }
    }
    return -1;
}

void input_password(char* password){

    printf("Enter password: ");
    //Change terminal properties
    struct termios old_props, new_props; //existing properties would be in old_props and new props would be the copy of the old_props where we would made our changes, understand old_props like our backup.
    tcgetattr(STDIN_FILENO, &old_props); //attributes from the standard input would be extracted here and stored in old_props
    new_props = old_props;
    new_props.c_lflag &= ~(ECHO | ICANON);
    tcsetattr(STDIN_FILENO, TCSANOW, &new_props);
    
    char ch;
    int i = 0;
    while (i < CREDENTIALS_LENGTH - 1 && (ch = getchar()) != '\n' && ch != EOF){ //until and unless the user presses enter the while loop will keep on running.
        //Handling
        //Backspace is also a chara, so need to ignore it while password input
        if (ch == '\b' || ch == 127){ //'\b' is backspace and 27 is DEL in ASCII
            if( i > 0){ //otherwise it can also delete our prompt, so we set a range for this to work.
             i--; //go back by 1-index
             printf("\b \b"); //to delete the asterik with backspace.
            }
        }else{
         password[i++] = ch;
         printf("*");
         fflush(stdout); //it forces the output buffer to flush to print asterik(*) immediately
        }
    }
    password[i] = '\0';
    tcsetattr(STDIN_FILENO, TCSANOW, &old_props); //to revert back the changes made to the terminal properties
    printf("\n");
} 

void fgets_fix(char *string){ //basically what we are doing is finding \n then replacing it with \0 from the string.
    int index = strcspn(string, "\n"); //finds \n from the passed string, returns its index of the first occurence.
    string[index] = '\0'; //and then replaces \n with \0 at that index, to make the string end/terminate there. or else fgets will input the "Enter" key press as a string too.
}