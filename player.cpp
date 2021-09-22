#include "player.h"
#include<QTimer>
#include<QWidget>
#include<QDebug>

Player::Player()
{
    p_x = 50;
    p_y = 100;
    //竖直方向下的加速度
    gravity = 0.8;
    //速度都为零
    p_vx = 0, p_vy = 0;

}

void Player::walkHor(double speed)
{
    p_vx = speed;
}
void Player::walkVer(double speed)
{
    qDebug()<<"跳了";
    p_vy = speed;
}

void Player::rightWalkPixmap()
{
    int i;
    for(i=0;i<11;i++)
    {
        QString path=QString(":/PlayWalk/GameSouce/PNG/Wraith_03/PNG Sequences/Walking/PlayerWalk(%1).png").arg(i);
        this->pixmap[i].load(path);
    }
}

void Player::leftWalkPixmap()
{
    int i;
    for(i=0;i<11;i++)
    {
        QString path=QString(":/PlayWalk/GameSouce/PNG/Wraith_03/PNG Sequences/Walking/PlayerWalk(%1).png").arg(i);
        this->pixmap[i].load(path);
    }
    for(i=0;i<11;i++)
    {
        QImage mirror=this->pixmap[i].toImage();
        this->pixmap[i]=QPixmap::fromImage(mirror.mirrored(true,false));
    }
}

