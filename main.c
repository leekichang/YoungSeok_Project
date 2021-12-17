#include <stdio.h>
#include "Login.h"
#include "TimeManager.h"

int currNumOfUser = 0;

int main(){
    User* users = (User*)malloc(sizeof(User)*MAXNUMOFUSERS);
    User* currUser = (User*)malloc(sizeof(User));
    Lecture lectures[MAXNUMOFUSERS][45];

    char table[10][6][20];

    int page = 0;
    while(page == 0){
        printLoginScreen();
        page = scanLoginScreen(users, currUser, &currNumOfUser);
    }

    printf("Curr User : %s(%s)\n", currUser->name, currUser->ID); 
    int result = 0;
    while(page == 1){
        initTable(table);
        initLecture(lectures[currUser->num]);
        while(1){
            setLecture(lectures[currUser->num], "char lecture", 1, 1);
            setTable(lectures[currUser->num], table);
            printTable(table);
            printLectureList(lectures[currUser->num]);
            result = getCommand(lectures[currUser->num], table);
            if(result == -1){
                break;
            }
        }
        
        // initLecture(currUser);

        // setLecture(currUser, "YOUNGFOREST", 0, 0);

        // setTable(currUser, table);

        // printTable(table);
    }
    //printf("%s\n%s", user->ID, user->PW);
    return 0;
}