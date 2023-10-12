#include <stdio.h>
#include <string.h>

#define DB_sz 100000
int idx = 0;

struct userData{
    char UserName[100], Password[100], Email[100];
};

struct userData systemUsers[DB_sz];

void userRegister(){
    if(idx == DB_sz){
        printf("Sorry, The database is full\n");
        return;
    }
    struct userData newUser; 
    printf("Please, Enter your username: ");
    scanf("%s", newUser.UserName);
    printf("Please, Enter your password: ");
    scanf("%s", newUser.Password);
    printf("Please, Enter your email: ");
    scanf("%s", newUser.Email);
    for(int i=0; i<=idx; i++){
        if(strcmp(systemUsers[i].Email, newUser.Email) == 0){
            printf("This email has an account already\n");
            return;
        }
    }
    printf("You register successfully\n");
    systemUsers[idx] = newUser, idx++;
}

void userLogin(){
    char username[100], password[100], email[100];
    printf("Please, Enter your username: ");
    scanf("%s", username);
    printf("Please, Enter your password: ");
    scanf("%s", password);
    printf("Please, Enter your email: ");
    scanf("%s", email);
    for(int i=0; i<=idx; i++){
        int cmpUsername = strcmp(systemUsers[i].UserName, username);
        int cmpPassword = strcmp(systemUsers[i].Password, password);
        int cmpEmail = strcmp(systemUsers[i].Email, email);
        if(cmpUsername == 0 && cmpPassword == 0 && cmpEmail == 0){
            printf("Welcome, %s\n", username);
            return;
        }
    }
    printf("Invalid data\n");
}

int main(){
    while(1){
        printf("Enter 1 to register\n");
        printf("Enter 2 to login\n");
        printf("Enter 3 to exit\n");
        printf("Your response is: ");
        int option;
        scanf("%d", &option);
        if(option == 3){
            printf("You exit this system");
            return 0;
        }
        if(option == 1) userRegister();
        else if(option == 2) userLogin();
    }

    return 0;
}