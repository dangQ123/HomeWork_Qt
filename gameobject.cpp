#include "gameobject.h"
#include"config.h"
#include<QDebug>

GameObject::GameObject()
{
    this->set_isUnderG(false);  //默认不受重力影响
    this->set_pos(QPoint(0,0)); //出生(0,0)处
    this->set_width(0);
    this->set_height(0);
    //默认没有加载图片
}

GameObject::GameObject(QPoint _pos, double _width, double _height, QString path)
{
    this->set_pos(_pos);
    this->set_width(_width);
    this->set_height(_height);
    this->set_pixmap(path);
}

GameObject::GameObject(QPoint _pos, double _width, double _height)
{
    this->set_pos(_pos);
    this->set_width(_width);
    this->set_height(_height);
}

bool GameObject::isColid(Player &player)
{
    if(player.p_vy > 15&&
            this->get_pos().x()<player.p_x+PLAY_WIDTH-100&&
            this->get_pos().x()-100+this->get_width()>player.p_x&&
            fabs(player.p_y+PLAY_HEIGHT-this->get_pos().y()-100 + 10)<=17)
    {
        //qDebug()<<"发生碰撞";
        return true;
    }
    else if(player.p_vy > 10&&
            this->get_pos().x()<player.p_x+PLAY_WIDTH-100&&
            this->get_pos().x()-100+this->get_width()>player.p_x&&
            fabs(player.p_y+PLAY_HEIGHT-this->get_pos().y()-100 + 10)<=12)
    {
        //qDebug()<<"发生碰撞";
        return true;
    }
    else if(this->get_pos().x()<player.p_x+PLAY_WIDTH-100&&
            this->get_pos().x()-100+this->get_width()>player.p_x&&
            fabs(player.p_y+PLAY_HEIGHT-this->get_pos().y()-100 + 10)<=8&&
            player.p_vy > 0)
    {
        //qDebug()<<"发生碰撞";
        return true;
    }
    else
        return false;

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

bool GameObject::get_isUnderG()
{
    return this->isUnderG;
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

void GameObject::set_isUnderG(bool _isUnderG)
{
    this->isUnderG=_isUnderG;
}

void GameObject::set_speed_x(double _speed_x)
{
    this->speed_x=_speed_x;
}

double GameObject::get_speed_x()
{
    return this->speed_x;
}

void GameObject::set_speed_y(double _speed_y)
{
    this->speed_y=_speed_y;
}

double GameObject::get_speed_y()
{
    return this->speed_y;
}

void GameObject::moveAdd(QPoint temp)
{
    QPoint pos=this->get_pos();
    QPoint des;
    des.setX(pos.x()+temp.x());
    des.setY(pos.y()+temp.y());
    this->set_pos(des);
}





















