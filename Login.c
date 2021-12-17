#include "Login.h"

void printLoginScreen(){
    printf("ㅣ ———————————————— ㅣ\n");
    printf("ㅣ ㅣ                              ㅣㅣ\n"); 
    printf("ㅣ ㅣ ID : ________                ㅣㅣ\n");
    printf("ㅣ ㅣ PW : ________                ㅣㅣ\n");
    printf("ㅣ ㅣ                              ㅣㅣ\n");
    printf("ㅣ ㅣ     [회원가입]  [ID/PW]        ㅣㅣ\n");
    printf("ㅣ ———————————————— ㅣ\n");
    return;
}

int scanLoginScreen(User* users, User* currUser, int* currNumOfUsers){
    int ans;
    printf("1) Login\n");
    printf("2) Sign Up\n");
    printf("3) Forgot Password\n");
    scanf("%d", &ans);
    
    char ID[20];
    char PW[20];
    char name[20];

    int* check = (int*)malloc(sizeof(int)*2);

    switch (ans){
        case 1:     //login
            while(1){
                printf("ID : (Enter Q for Quit)");
                scanf("%s", ID);
                if(strcmp(ID, (const char*)"Q") == 0){
                    break;
                }
                printf("PW : ");    
                scanf("%s", PW);
                memcpy(check, checkAccount(ID, PW, (User*)users, MAXNUMOFUSERS), sizeof(sizeof(int)*2));
                if(*check == 1){
                    memcpy(currUser, (users+sizeof(User)*(*(check+sizeof(int)))), sizeof(User));
                    return 1;
                }
            }
            break;
        case 2:     //Sign Up
            while(1){
                printf("ID : ");
                scanf("%s", ID);
                printf("PW : ");
                scanf("%s", PW);
                printf("name : ");
                scanf("%s", name);
                if(signUp(ID, PW, name, users, currNumOfUsers) == 1){
                    *currNumOfUsers += 1;
                    break;
                }
            }
            break;
        case 3:     // Forgot Password
            while(1){
                printf("name(Enter Q for exit) : ");
                scanf("%s", name);
                if(findAccount(name, users, MAXNUMOFUSERS) == 1 || strcmp(name, (const char*)"Q") == 0){
                    break;
                }
            }
            break;
    }

    return 0;
}

int* checkAccount(char ID[20], char PW[20], User* users, int numOfUsers){
    int* result = (int*)malloc(sizeof(int)*2);
    *result = 0;
    *(result+sizeof(int)) = -1;
    for(int i = 0; i < numOfUsers; ++i){
        if(strcmp(ID, (users+sizeof(User)*i)->ID) == 0){
            if(strcmp(PW, (users+sizeof(User)*i)->PW) == 0){
                printf("\nㅣ ———————————————— ㅣ\n");
                printf("\nLogin Successed\n");
                printf("\nㅣ ———————————————— ㅣ\n");
                *result = 1;
                *(result+sizeof(int)) = i;
                return result;
            }
            else{
                printf("\nㅣ ———————————————— ㅣ\n");
                printf("Wrong Password\n");
                printf("\nㅣ ———————————————— ㅣ\n");
                *(result+sizeof(int)) = i;
                return result;
            }            
        }
    }
    printf("ID doesn't exist\n");
    return result;
}

void printSignUp(){
    printf("ㅣ ———————————————— ㅣ\n");
    printf("ㅣ ㅣ 회원가입                       ㅣㅣ\n"); 
    printf("ㅣ ㅣ 이름: ________                ㅣㅣ\n"); 
    printf("ㅣ ㅣ ID : ________                ㅣㅣ\n");
    printf("ㅣ ㅣ PW : ________                ㅣㅣ\n");
    printf("ㅣ ㅣ                              ㅣㅣ\n");
    printf("ㅣ ———————————————— ㅣ\n");
}

int signUp(char ID[20], char PW[20], char name[20], User* users, int* currNumOfUsers){
    if(*(checkAccount(ID, PW, users, MAXNUMOFUSERS)) == -1 ){
        printf("\nㅣ ———————————————— ㅣ\n");
        printf("Account already exist\n");
        printf("\nㅣ ———————————————— ㅣ\n");
        return 0;
    }
    else{
        strcpy((users+sizeof(User)*(*currNumOfUsers))->ID, ID);
        strcpy((users+sizeof(User)*(*currNumOfUsers))->PW, PW);
        strcpy((users+sizeof(User)*(*currNumOfUsers))->name, name);
        (users+sizeof(User)*(*currNumOfUsers))->num = *currNumOfUsers;
        printf("\nㅣ ———————————————— ㅣ\n");
        printf("Account Successfully Created!\n");
        printf("\nㅣ ———————————————— ㅣ\n");
       return 1;
    }
}

void printForgotAccount(){
    printf("ㅣ ———————————————— ㅣ\n");
    printf("ㅣ ㅣ ID/PW찾기                     ㅣㅣ\n"); 
    printf("ㅣ ㅣ 이름: ________                ㅣㅣ\n"); 
    printf("ㅣ ㅣ                              ㅣㅣ\n"); 
    printf("ㅣ ———————————————— ㅣ\n");
}

int findAccount(char name[20], User* users, int numOfUsers){
    for(int i = 0; i < numOfUsers; i++){
        if(strcmp(name, (users+(sizeof(User)*i))->name) == 0){
            printf("\nㅣ ———————————————— ㅣ\n");
            printf("%s's Account Information\n", (users+(sizeof(User)*i))->name);
            printf("ID : %s\n", (users+(sizeof(User)*i))->ID);
            printf("PW : %s\n", (users+(sizeof(User)*i))->PW);
            printf("\nㅣ ———————————————— ㅣ\n");
            return 1;
        }
        else{
            printf("\nㅣ ———————————————— ㅣ\n");
            printf("Thre is no Account\n");
            printf("\nㅣ ———————————————— ㅣ\n");
            return 0;
        }
    }
    return 0;
}