#ifndef MONTYHALLGAME
#define MONTYHALLGAME

#include "MontyHallGame.h"
using namespace std;

MontyHallGame::MontyHallGame(int a, int b): car(a), choice(b){}

int MontyHallGame::switchDoor(){
    if(car!=choice) return 1;
    return 0;
}

int MontyHallGame::stickWithChoice(){
        if(car==choice) return 1;
        return 0;
}

#endif 