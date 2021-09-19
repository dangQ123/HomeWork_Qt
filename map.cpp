#include "map.h"
#include"config.h"

Map::Map()
{
    this->set_pixmap(MAP_PATH);
}

double Map::get_width()
{
    return this->width;
}

double Map::get_height()
{
    return this->height;
}

QPoint Map::get_pos()
{
    return this->pos;
}

QPixmap Map::get_pixmap()
{
    return this->pixmap;
}

void Map::set_width(double _width)
{
    this->width=_width;
}

void Map::set_height(double _height)
{
    this->height=_height;
}

void Map::set_pos(QPoint _pos)
{
    this->pos=_pos;
}

void Map::set_pixmap(QString path)
{
    this->pixmap.load(path);
}






