#ifndef MAP_H
#define MAP_H

#include<QPoint>
#include<QPixmap>
#include<QString>
#include"gameobject.h"
#include"player.h"
#include"monsterclose.h"
#include"boss.h"

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

    GameObject gameobject[50];
    void addGameObject(GameObject& gameobject);
    int numOfGameObject=0;

    //检测该地图上所有GOB与player的位置关系，如果有
    void examAllGameObject(Player& player);
    int numOfMonsterClose=0;
    MonsterClose *monsterClose[20];
    void addMonsterClose(double pos_x,double pos_y);

    void checkAllAttack(Player &player);

    Boss *boss;


private:
    double width,height;
    QPoint pos;
    QPixmap pixmap;

};

#endif // MAP_H
