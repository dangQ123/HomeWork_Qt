#ifndef MAP_H
#define MAP_H

#include<QPoint>
#include<QPixmap>
#include<QString>

class Map
{
public:
    Map();

    double get_width();
    double get_height();
    QPoint get_pos();
    QPixmap get_pixmap();

    void set_width(double _width);
    void set_height(double _height);
    void set_pos(QPoint _pos);
    void set_pixmap(QString path);


private:
    double width,height;
    QPoint pos;
    QPixmap pixmap;
};

#endif // MAP_H
