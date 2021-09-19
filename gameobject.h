#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include<QPixmap>
#include<QPoint>
#include<QString>

class GameObject
{
public:
    GameObject();

    double get_width();
    double get_height();
    double get_r();
    QPoint get_pos();
    QPixmap get_pixmap();

    void set_width(double _width);
    void set_height(double _height);
    void set_r(double _r);
    void set_pos(QPoint _pos);
    void set_pixmap(QString path);

private:
    double width,height,r;  //宽度、高度、大致半径、坐标
    QPoint pos;
    QPixmap pixmap;
};

#endif // GAMEOBJECT_H
