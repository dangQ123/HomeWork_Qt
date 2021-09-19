#ifndef PLAYER_H
#define PLAYER_H
//玩家

#include"gameobject.h"
#include<QKeyEvent>

class Player : public GameObject
{
public:
    Player();
    void walk(double distance);
};

#endif // PLAYER_H
