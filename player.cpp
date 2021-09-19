#include "player.h"
#include<qmath.h>
#include"config.h"
#include<QPoint>

Player::Player()
{
    this->set_width(50);
    this->set_height(100);
    this->set_r(111);
    this->set_pos(QPoint(GAME_WIDTH/2,GAME_HEIGHT-this->get_height()));
    this->set_pixmap(PLAYER_PATH);
}

void Player::walk(double distance)
{
    QPoint pos=this->get_pos();
    pos.setX(this->get_pos().x()+distance);
    this->set_pos(pos);
}
