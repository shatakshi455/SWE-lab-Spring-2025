#include <iostream>
#include <random>
#include "MontyHallGame.h"
using namespace std;

int main()
{
    unsigned int seed = 42; // Change this to get different random numbers
    mt19937 gen(seed);
    uniform_int_distribution<> dis(1, 3);
    uniform_int_distribution<> dis_sec(1, 3);

    cout<<"First round of play, Enter your choice(1, 2 or 3):"<<endl;
    int car1 = dis(gen);
    int ch;
    cin>>ch;
    if(ch>3 || ch<=0) cout<<"Invalid input"<<endl;
    else {
        cout<<"A gate not chosen by you is revealed to have a goat!!"<<endl;
        cout<<"Do you want to switch to another gate?(1 to switch, 0 to stay):"<<endl;
        int sw;
        cin>>sw;
        if(car1==ch && sw) cout<<"YOU LOST :("<<endl;
        if(car1==ch && !sw) cout<<"YOU WON :)"<<endl;
        if(car1!=ch && !sw) cout<<"YOU LOST :("<<endl;
        if(car1!=ch && sw) cout<<"YOU WON :)"<<endl;
    }
    cout<<"STIMULATING 1000 CASES...."<<endl;

    int switchWin=0;
    int switchLoss=0;
    int simulations = 1000;
    for (int i = 0; i < simulations; ++i)
    {
        MontyHallGame game(dis(gen), dis_sec(gen));
        if(game.switchDoor()) switchWin++;
        if(game.stickWithChoice()) switchLoss++;
    }
    cout<<"Swapping leads to victory in " << ((double)(100*switchWin))/simulations << " percentage cases."<<endl;
    return 0;
}