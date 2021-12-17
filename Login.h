#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "User.h"

void printLoginScreen();
int scanLoginScreen(User* users, User* currUser, int* currNumOfUsers);   
int* checkAccount(char ID[20], char PW[20], User* users, int numOfUsers);
void printSignUp();
int signUp(char ID[20], char PW[20], char name[20], User* users, int* currNumOfUser);
void printForgotAccount();
int findAccount(char name[20], User* users, int numOfUsers);