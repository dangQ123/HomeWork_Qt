#ifndef PLAYER_H
#define PLAYER_H

#include<QPixmap>
#include<QTimer>
#include<QWidget>

class Player
{

public:
int health=500;   //初始设定健康值

//判断是否在地板上
int isOnFloor;
//判断是否在平台上
int isOnPlat;
//判断是否为一段跳
int isjumpshort = 0;

double p_x,p_y;
double gravity;//重力
double p_vx, p_vy;

    Player();
    QPixmap pixmap[11];
    void walkHor(double speed);
    void walkVer(double speed);

    void speedX_Move(double speed);
    void speedY_Move(double speed);

    void rightWalkPixmap();
    void leftWalkPixmap();
};

#endif // PLAYER_H
