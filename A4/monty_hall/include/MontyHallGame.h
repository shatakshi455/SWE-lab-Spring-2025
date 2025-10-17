#ifndef MONTYHALLGAME_H
#define MONTYHALLGAME_H
#include<random>
using namespace std;


class MontyHallGame
{
    private:
    int car;
    int choice;
    public:
    MontyHallGame(int a, int b);
    int switchDoor();
    int stickWithChoice();
};
#endif // MONTYHALLGAME_H