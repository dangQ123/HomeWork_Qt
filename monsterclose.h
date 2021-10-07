#ifndef MONSTERCLOSE_H
#define MONSTERCLOSE_H
#include"monster.h"
#include"player.h"

class MonsterClose:public Monster
{
public:
    MonsterClose();
    MonsterClose(double _x, double _y, int _faceTo, int _heath);

    void walkLeftPixmap();      //修改为初始化函数，将对应的图片加载到程序中
    void walkRightPixmap(); //修改为初始化函数，将对应的图片加载到程序中

    void attackLeftPixmap();
    void attackRightPixmap();

    void underAttackLeftPixmap();
    void underAttackRightPixmap();

    int attackCount=0;
    int underAttackCount=0;

    int walkCount=0;
    void addCount(int &count, int maxNum);

    void turnTo(int face);  //转向函数，用于写AI
    void moveMonsterClose(Player &player);    //AI函数
    void attack(Player &player);
};

#endif // MONSTERCLOSE_H
