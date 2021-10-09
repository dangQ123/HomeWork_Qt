#ifndef MONSTER_H
#define MONSTER_H

#include"config.h"
#include<QPixmap>
#include<audio.h>

class Monster
{
public:
    int maxHealth=3;
    int isInWalk=0,isInAttack=0,isUnderAttack=0;
    Monster();
    Monster(double _x, double _y, int _faceTo, int _heath);

    double getPos_x() const;
    void setPos_x(double value);

    double getPos_y() const;
    void setPos_y(double value);


    int getFaceTo() const;
    void setFaceTo(int value);
    bool isDead();
    void dead();

    QPixmap walkLeftPixmaps[20];
    QPixmap walkRightPixmaps[20];
    QPixmap walkPixmaps[20];

    QPixmap attackPixmaps[20];
    QPixmap attackLeftPixmaps[20];
    QPixmap attackRightPixmaps[20];

    QPixmap underAttackPixmaps[20];
    QPixmap underAttackLeftPixmaps[20];
    QPixmap underAttackRightPixmaps[20];
    QPixmap nothing;

    int getHeath() const;
    void setHeath(int value);
    void underAttack();

    void walk();
    void setWalkPixmaps(int face);
    void setAttackPixmaps(int face);
    void setUnderAttackPixmaps(int face);

    //设置音乐
    Audio MusicPlay;

private:
    double pos_x,pos_y;
    int faceTo;
    int heath;
};

#endif // MONSTER_H
