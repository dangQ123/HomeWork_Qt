#include "monster.h"

Monster::Monster()
{
    this->pos_x=GAME_WIDTH/2;
    faceTo=FACE::toLeft;
    heath=15;    //默认生命值为3
}

Monster::Monster(double _x, double _y, int _faceTo,int _heath)
{
    this->pos_x=_x;
    this->pos_y=_y;
    this->faceTo=_faceTo;
    this->heath=_heath;

}

double Monster::getPos_x() const
{
    return pos_x;
}

void Monster::setPos_x(double value)
{
    pos_x = value;
}

double Monster::getPos_y() const
{
    return pos_y;
}

void Monster::setPos_y(double value)
{
    pos_y = value;
}

int Monster::getFaceTo() const
{
    return faceTo;
}

void Monster::setFaceTo(int value)
{
    faceTo = value;
}

bool Monster::isDead()
{
    if(heath<=0)
        return true;
    else
        return false;
}

void Monster::dead()
{
    this->isInAttack=0;
    this->isInWalk=0;
    this->isUnderAttack=0;

}

int Monster::getHeath() const
{
    return heath;
}

void Monster::setHeath(int value)
{
    heath = value;
}

void Monster::underAttack()
{
    this->isUnderAttack=1;
    this->isInWalk=0;
    this->isInAttack=0;
    if(this->isDead())
        this->dead();
    setUnderAttackPixmaps(this->getFaceTo());
    if(this->getFaceTo()==FACE::toLeft)
        this->setPos_x(this->getPos_x()+3);
    else if(this->getFaceTo()==FACE::toRight)
        this->setPos_x(this->getPos_x()-3);
}

void Monster::walk()
{
    if(this->faceTo==FACE::toRight)
        this->pos_x+=3;
    else if(this->faceTo==FACE::toLeft)
        this->pos_x-=3;
    isInAttack=0;
    isInWalk=1;
}

void Monster::setWalkPixmaps(int face)
{
    int i;
    if(face==FACE::toLeft)
    {
        for(i=0;i<18;i++)
        {
            this->walkPixmaps[i]=this->walkLeftPixmaps[i];
        }
    }
    else
    {
        for(i=0;i<18;i++)
        {
            this->walkPixmaps[i]=this->walkRightPixmaps[i];
        }
    }
}

void Monster::setAttackPixmaps(int face)
{
    int i;
    if(face==FACE::toLeft)
    {
        for(i=0;i<18;i++)
        {
            this->attackPixmaps[i]=this->attackLeftPixmaps[i];
        }
    }
    else
    {
        for(i=0;i<18;i++)
        {
            this->attackPixmaps[i]=this->attackRightPixmaps[i];
        }
    }
}

void Monster::setUnderAttackPixmaps(int face)
{
    int i;
    if(face==FACE::toLeft)
    {
        for(i=0;i<18;i++)
        {
            this->underAttackPixmaps[i]=this->underAttackLeftPixmaps[i];
        }
    }
    else
    {
        for(i=0;i<18;i++)
        {
            this->underAttackPixmaps[i]=this->underAttackRightPixmaps[i];
        }
    }
}


