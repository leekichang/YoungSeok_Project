#include "TimeManager.h"

void initTable(char table[10][6][20]){
    strcpy(table[0][0], (const char*)"             ");
    strcpy(table[0][1], (const char*)"     Mon     ");
    strcpy(table[0][2], (const char*)"     Tue     ");
    strcpy(table[0][3], (const char*)"     Wed     ");
    strcpy(table[0][4], (const char*)"     Thu     ");
    strcpy(table[0][5], (const char*)"     Fri     ");

    strcpy(table[1][0], (const char*)" 09:00~10:00 ");
    strcpy(table[2][0], (const char*)" 10:00~11:00 ");
    strcpy(table[3][0], (const char*)" 11:00~12:00 ");
    strcpy(table[4][0], (const char*)" 12:00~13:00 ");
    strcpy(table[5][0], (const char*)" 13:00~14:00 ");
    strcpy(table[6][0], (const char*)" 14:00~15:00 ");
    strcpy(table[7][0], (const char*)" 15:00~16:00 ");
    strcpy(table[8][0], (const char*)" 16:00~17:00 ");
    strcpy(table[9][0], (const char*)" 17:00~18:00 ");

    for(int i = 1; i < 10; i++){
        for(int j = 1; j < 6; j++){
            strcpy(table[i][j], (const char*)"             ");
        }
    }
}

void initLecture(Lecture lectures[45]){
    for(int i = 0; i < 45; i++){
        strcpy(lectures[i].lectureName, (const char*)"             ");
        lectures[i].day = -1;
        lectures[i].time = -1;
    }
}

void setLecture(Lecture lectures[45], char lectureName[20], int time, int day){
    strcpy(lectures[time*5+day].lectureName, lectureName);
    lectures[time*5+day].day = day;
    lectures[time*5+day].time = time;
}

void setTable(Lecture lectures[45], char table[10][6][20]){
    for(int i = 0; i < 45; i ++){
        if (lectures[i].day != -1){
            strcpy(table[(lectures[i].time)+1][(lectures[i].day)+1], lectures[i].lectureName);
        }
    }
    
}

void printTable(char table[10][6][20]){
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 6; j++){
            printf("%s", table[i][j]);
        }
        printf("\n");
    }
    printf("----------------------------------------------\n\n");
    return;
}

void printLectureList(Lecture lectures[45]){
    printf("---------------LECTURE LIST-----------------\n\n");
    int count = 1;
    for(int i = 0; i < 45; i++){
            if(lectures[i].day != -1){
                printf("%d) %s\n", count, lectures[i].lectureName);
                count++;
            }
    }

    printf("----------------------------------------------\n\n");
}


void cal_time(int time, int alarm){
    switch(time){
        case 0:
            printf("08:%d", 60-alarm);
            break;
        case 1:
            printf("09:%d", 60-alarm);
            break;
        case 2:
            printf("10:%d", 60-alarm);
            break;
        case 3:
            printf("11:%d", 60-alarm);
            break;
        case 4:
            printf("12:%d", 60-alarm);
            break;
        case 5:
            printf("13:%d", 60-alarm);
            break;
        case 6:
            printf("14:%d", 60-alarm);
            break;
        case 7:
            printf("15:%d", 60-alarm);
            break;
        case 8:
            printf("16:%d", 60-alarm);
            break;
    }
}

int getCommand(Lecture lectures[45], char table[10][6][20]){
    int command;
    char lectureName[20];
    int time;
    int day;
    int timeBefore = 0;

    printf("1) Add Alarm\n");
    printf("2) Add Lecture\n");
    printf("3) Quit\n");
    scanf("%d", &command);
    switch(command){
        case 1:         //Alarm
            printf("몇분 전에 알려드릴까요?(0~59): ");
            scanf("%d", &timeBefore);
            for(int i = 0; i < 45; i ++){
                if(lectures[i].day != -1){
                    switch(lectures[i].day){
                        case 0:
                            printf("Alarm at Monday : ");
                            break;
                        case 1:
                            printf("Alarm at Tuesday : ");
                            break;
                        case 2:
                            printf("Alarm at Wednesday : ");    
                            break;
                        case 3:
                            printf("Alarm at Thursday : ");
                            break;
                        case 4:
                            printf("Alarm at Friday : ");
                            break;
                    }
                    cal_time(lectures[i].time, timeBefore);
                    printf("\n");
                }
            }
            return 1;
        case 2:         //
            printf("Lecture Name : ");
            scanf("%s", lectureName);
            printf("Lecture Time(09:00~10:00 == 1, 10:00~11:00 == 2...) : ");
            scanf("%d", &time);
            printf("Lecture Day(Mon == 1, Tue == 2...) : ");
            scanf("%d", &day);
            setLecture(lectures, lectureName, time-1, day-1);
            setTable(lectures, table);
            return 2;
        case 3:
            return -1;
    }
    return 0;
}