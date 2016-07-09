#include <time.h>
#include <stdlib.h>

int randSeeded = 0;

int playerActionWorked(){
    if(!randSeeded){
        srand(time(NULL));
        randSeeded = 1;
    }
    return rand() % 2;
}

int passBecameAssist(){
    return playerActionWorked();
}

int shotBecameGoal(int power){
    return power > 4 || playerActionWorked();
}