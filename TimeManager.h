#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "User.h"

typedef struct{
    char lectureName[20];
    int day;
    int time;
}Lecture;

void initTable(char table[10][6][20]);
void setLecture(Lecture lectures[45], char lectureName[20], int time, int day);
void setTable(Lecture lectures[45], char table[10][6][20]);
void printTable(char table[10][6][20]);
void initLecture(Lecture lectures[45]);
void printLectureList(Lecture lectures[45]);
int getCommand(Lecture lectures[45], char table[10][6][20]);