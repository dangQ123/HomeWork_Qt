#include "map.h"
#include"config.h"
#include<QDebug>

Map::Map()
{
    this->set_pixmap(MAP_PATH);
    this->set_pos(QPoint(0,0));
    this->numOfGameObject=0;
    GameObject mapFloor(QPoint(0,GAME_HEIGHT-80),GAME_WIDTH,80,":/Pad/GameSouce/jumpPad/Pads/Pad_04_1.png");
    this->addGameObject(mapFloor);
    GameObject gob1(QPoint(650,600),300,100,":/Pad/GameSouce/jumpPad/Pads/Pad_04_1.png");
    this->addGameObject(gob1);
    GameObject gob2(QPoint(0,500),300,100,":/Pad/GameSouce/jumpPad/Pads/Pad_04_1.png");
    this->addGameObject(gob2);
    GameObject gob3(QPoint(450,400),300,100,":/Pad/GameSouce/jumpPad/Pads/Pad_04_1.png");
    this->addGameObject(gob3);
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

void Map::addGameObject(GameObject &_gameobject)
{
    this->gameobject[numOfGameObject]=_gameobject;
    this->numOfGameObject++;
}

void Map::examAllGameObject(Player &player)
{
    int i;
    for(i=0;i<numOfGameObject;i++)
    {
        if(this->gameobject[i].isColid(player))
        {
            //qDebug()<<"发生碰撞";
            player.p_vy=0;
            player.p_y-=player.gravity;
            player.isOnPlat=true;
        }
    }
}








