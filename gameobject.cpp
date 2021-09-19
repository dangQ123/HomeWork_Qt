#include "gameobject.h"

GameObject::GameObject()
{

}

double GameObject::get_width()
{
    return this->width;
}

double GameObject::get_height()
{
    return this->height;
}

double GameObject::get_r()
{
    return this->r;
}

QPoint GameObject::get_pos()
{
    return this->pos;
}

QPixmap GameObject::get_pixmap()
{
    return this->pixmap;
}

void GameObject::set_width(double _width)
{
    this->width=_width;
}

void GameObject::set_height(double _height)
{
    this->height=_height;
}

void GameObject::set_r(double _r)
{
    this->r=_r;
}

void GameObject::set_pos(QPoint _pos)
{
    this->pos=_pos;
}

void GameObject::set_pixmap(QString path)
{
    this->pixmap.load(path);
}




















