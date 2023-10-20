#include <stdio.h>
#include <string.h>

#define DB_sz 100000
int idx = 0;

struct userData{
    char UserName[100], Password[100], Email[100];
    union isActive{
        int activeState1;
        char activeState2[100];
    }accountState;
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
    printf("Enter 1 or true if this account will be active\n");
    printf("Enter 0 or false if this account will be inactive\n");
    while(1){
        printf("Your response is: ");
        char str[100];
        scanf("%s", str);
        if(strcmp(str, "true") != 0 && strcmp(str, "1") != 0 && strcmp(str, "false") != 0 && strcmp(str, "0") != 0){
            printf("Invalid response, Your response must be 1 or true or 0 or false\n");
        }
        else{            
            if(strcmp(str, "true") == 0) strcpy(newUser.accountState.activeState2, "true");
            else if(strcmp(str, "false") == 0) strcpy(newUser.accountState.activeState2, "false");
            else if(strcmp(str, "1") == 0) newUser.accountState.activeState1 = 1;
            else newUser.accountState.activeState1 = 0;
            break;
        }
    }
    printf("You register successfully\n\n");
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
            if(systemUsers[i].accountState.activeState1 == 1 || strcmp(systemUsers[i].accountState.activeState2, "true") == 0){
                printf("Welcome, %s\n\n", username);
                return;
            }
            else{
                printf("You entered the correct data but this account isn't active yet\n\n");
                return;
            }
        }
    }
    printf("Invalid data\n\n");
}

int main(){
    while(1){
        printf("Enter 1 to register\n");
        printf("Enter 2 to login\n");
        printf("Enter 3 to exit\n");
        printf("Your response is: ");
        char option[100];
        scanf("%s", option);
        if(strcmp(option, "3") == 0){
            printf("You exit this system");
            return 0;
        }
        if(strcmp(option, "1") == 0) userRegister();
        else if(strcmp(option, "2") == 0) userLogin();
        else{
            printf("Invalid response, Your response must be 1 or 2 or 3\n\n");
        }
    }

    return 0;
}