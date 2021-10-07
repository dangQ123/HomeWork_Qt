#include "monsterclose.h"
#include"config.h"
#include<QDebug>
#include"player.h"

MonsterClose::MonsterClose()
{
    this->setPos_x(GAME_WIDTH/2);
    this->setPos_y(GAME_HEIGHT-230);
    this->setFaceTo(FACE::toLeft);  //默认生命值为3
    this->walkLeftPixmap();
    this->walkRightPixmap();
    this->attackLeftPixmap();
    this->attackRightPixmap();
    this->underAttackLeftPixmap();
    this->underAttackRightPixmap();
}

MonsterClose::MonsterClose(double _x, double _y, int _faceTo, int _heath)
{
    this->setPos_x(_x);
    this->setPos_y(_y);
    this->setFaceTo(_faceTo);
    this->setHeath(_heath);
    this->walkLeftPixmap();
    this->walkRightPixmap();
    this->attackLeftPixmap();
    this->attackRightPixmap();
    this->underAttackLeftPixmap();
    this->underAttackRightPixmap();
}

void MonsterClose::walkLeftPixmap()
{
    int i;
    for(i=0;i<18;i++)
    {
        QString path=QString(":/enemy/close/walkmirror/GameSouce/enemy/PNG/Minotaur_01/PNG Sequences/WalkingMirror/monsterCloseWalkMirror(%1).png").arg(i);
        this->walkLeftPixmaps[i].load(path);
    }
}

void MonsterClose::walkRightPixmap()
{
    int i;
    for(i=0;i<18;i++)
    {
        QString path=QString(":/enemy/close/walk/GameSouce/enemy/PNG/Minotaur_01/PNG Sequences/Walking/monsterCloseWalk(%1).png").arg(i);
        this->walkRightPixmaps[i].load(path);
    }
}

void MonsterClose::attackLeftPixmap()
{
    int i;
    for(i=0;i<12;i++)
    {
        QString path=QString(":/enemy/close/attackmirror/GameSouce/enemy/PNG/Minotaur_01/PNG Sequences/AttackMirror/attackCloseMirror(%1).png").arg(i);
        this->attackLeftPixmaps[i].load(path);
    }
}

void MonsterClose::attackRightPixmap()
{
    int i;
    for(i=0;i<12;i++)
    {
        QString path=QString(":/enemy/close/attack/GameSouce/enemy/PNG/Minotaur_01/PNG Sequences/Attacking/attackClose(%1).png").arg(i);
        this->attackRightPixmaps[i].load(path);
    }
}

void MonsterClose::underAttackLeftPixmap()
{
    int i;
    for(i=0;i<12;i++)
    {
        QString path=QString(":/enemy/close/underattackmirror/GameSouce/enemy/PNG/Minotaur_01/PNG Sequences/underAttackMirror/underAttackClose(%1).png").arg(i);
        this->underAttackLeftPixmaps[i].load(path);
    }
}

void MonsterClose::underAttackRightPixmap()
{
    int i;
    for(i=0;i<12;i++)
    {
        QString path=QString(":/enemy/close/underattack/GameSouce/enemy/PNG/Minotaur_01/PNG Sequences/underAttack/underAttackClose(%1).png").arg(i);
        this->underAttackRightPixmaps[i].load(path);
    }
}

void MonsterClose::addCount(int&count,int maxNum)
{
    count++;
    if(count==maxNum)
        count=0;
}

void MonsterClose::turnTo(int face)
{
    this->setFaceTo(face);
    this->setWalkPixmaps(face);     //转向时加载设置图片
    this->setAttackPixmaps(face);
}

void MonsterClose::moveMonsterClose(Player&player)      //AI函数
{
    if(this->isUnderAttack)
    {
        this->underAttack();
    }
    else if(this->isDead())
        this->dead();
    else if(abs(player.p_x-this->getPos_x())<=80)
    {
        if(player.p_x<=this->getPos_x())
        {
            turnTo(FACE::toLeft);
        }
        else if(player.p_x>this->getPos_x())
        {
            turnTo(FACE::toRight);
        }
        if(abs(player.p_y-this->getPos_y())<=50)
            this->attack(player);
    }
    else
    {
        if(player.p_x<this->getPos_x())
        {
            turnTo(FACE::toLeft);
            this->walk();

        }
        else if(player.p_x>this->getPos_x())
        {
            turnTo(FACE::toRight);
            this->walk();
        }
    }
}

void MonsterClose::attack(Player& player)   //直接命中
{
    player.health-=1;
    isInAttack=1;
    isInWalk=0;
}













