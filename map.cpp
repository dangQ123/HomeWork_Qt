#include "map.h"
#include"config.h"
#include<QDebug>
#include"monsterclose.h"

Map::Map()
{
    this->set_pixmap(MAP_PATH);
    this->set_pos(QPoint(0,0));
    this->numOfGameObject=0;
    //主平台
    GameObject mapFloor(QPoint(0,GAME_HEIGHT-80),GAME_WIDTH,80);
    this->addGameObject(mapFloor);
    //其他平台
    GameObject gob1(QPoint(650,600),300,100,":/Pad/GameSouce/jumpPad/Pads/Pad_04_1.png");
    this->addGameObject(gob1);
    GameObject gob2(QPoint(0,500),300,100,":/Pad/GameSouce/jumpPad/Pads/Pad_04_1.png");
    this->addGameObject(gob2);
    GameObject gob3(QPoint(450,400),300,100,":/Pad/GameSouce/jumpPad/Pads/Pad_04_1.png");
    this->addGameObject(gob3);

//    this->addMonsterClose(GAME_WIDTH/2,GAME_HEIGHT-250);
//    this->addMonsterClose(GAME_WIDTH/2+100,GAME_HEIGHT-250);
//    this->monsterClose[1].turnTo(FACE::toRight);
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
            //player.p_y-=player.gravity;
            player.p_y = gameobject[i].pos.y() - gameobject[i].height - 20;
            player.isOnPlat=true;
        }
    }
}

void Map::addMonsterClose(double pos_x, double pos_y)
{
    this->monsterClose[numOfMonsterClose]=new MonsterClose(pos_x,pos_y,FACE::toLeft,3);
    numOfMonsterClose++;
}









