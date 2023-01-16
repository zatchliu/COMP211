/* Zachary Liu
 * COMP 211
 * HW5 Problem 3
 *
 * Nim Game
 * */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int numPiles = 3;
int A[3];
int userChoice;
int stickRemove;
int userCount = 0;
int cpuCount = 0;

//Generates random number of sticks, change the number 10 to change max num of
//sticks in each pile
int makeSticks(){
    return rand() % 10 + 1;

}

//Prints initial piles and stick values
void makePiles(){
    int sticks;
    for (int i = 0; i < numPiles; i++){
        sticks = makeSticks();
        A[i] = sticks;
        printf("Pile %d: %d sticks.\n", i, sticks);
    }
}

//Checks if all the sticks in each pile is equal to 0
int checkGameOver(){
    int count = 0;
    for (int i = 0; i < numPiles; i++){
        if(A[i] == 0){
            count++;
        }
    }
    if (count == numPiles){
        return 1;
    } else{
        return 0;
    }
}

//Checks if user inputed pile choice is a valid pile choice
int isValidPile(int pile){
    if(A[pile] != 0){
        return 1;
    }else{
        return 0;
    }
}

//Checks if user inputed stick number of sticks is within the range
int isValidChoice(){
    if( stickRemove > 0 && stickRemove <= A[userChoice]){
        return 1;
    }else{
        printf("You must choose a number between 1 and %d.\n", A[userChoice]);
        return 0;
    }
}

//Generates random pile and stick number for the computer's move
void cpuMove(){
    cpuCount++;
    int cpuChoice = rand()%numPiles;
    while(isValidPile(cpuChoice)==0){
        cpuChoice = rand()%numPiles;
    }
    int numStick = rand()%A[cpuChoice]+1;
    A[cpuChoice] -= numStick;
    printf("I choose to remove %d sticks from pile %d\n", numStick, cpuChoice);
}

//Prints the piles and the number of sticks in the piles
void printPiles(){
    for (int i = 0; i < numPiles; i++){
        printf("Pile %d: %d sticks. \n", i, A[i]);
    }
}

//Scans in users inputed pile choice
void getUserInput(){
    printf("From which pile (0-%d) do you wnat to remove sticks? ", numPiles-1);
    scanf("%d", &userChoice);
}

//Scans in users inputed stick number to remove;
void getChoice(){
    printf("How many sticks (1-%d) do you want to remove? ", A[userChoice]);
    scanf("%d", &stickRemove);
}

int main(void){
    srand(time(NULL));
    makePiles();
    while(checkGameOver() == 0){
        getUserInput();
        while (isValidPile(userChoice)==0){
            printf("Invalid pile choice!\n");
            getUserInput();
        }
        getChoice();
        while(isValidChoice() == 0){
            getChoice();
        }
        A[userChoice] -= stickRemove;
        if(checkGameOver() == 1){
            break;
        }
        printPiles();
        cpuMove();
        if(checkGameOver() == 1){
            break;
        }
        printPiles();
        userCount++;
    }
    if(userCount >= cpuCount){
        printf("You Lose!\n");
    }else{
        printf("Oh no I lose!\n");
    }
    return -1;
}

