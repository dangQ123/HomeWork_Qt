#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include"player.h"
#include<QPixmap>
#include<QPoint>
#include<QString>
#include<QTimer>
#include"config.h"
#include"player.h"

class GameObject
{
public:
    GameObject();
    GameObject(QPoint _pos, double _width, double _height, QString path);
    GameObject(QPoint _pos, double _width, double _height); //空物体

    bool isColid(Player& player);

    double get_width();
    double get_height();
    double get_r();
    QPoint get_pos();
    bool get_isUnderG();
    QPixmap get_pixmap();

    void set_width(double _width);
    void set_height(double _height);
    void set_r(double _r);
    void set_pos(QPoint _pos);
    void set_pixmap(QString path);
    void set_isUnderG(bool _isUnderG);
    void set_speed_x(double _speed_x);
    double get_speed_x();
    void set_speed_y(double _speed_y);
    double get_speed_y();
    void moveAdd(QPoint temp);

    bool isDropping=false;
    QPoint pos;

    double width,height,r;  //宽度、高度、大致半径、坐标
    QPixmap pixmap;
    bool isUnderG;
    double speed_x,speed_y;
};

#endif // GAMEOBJECT_H
