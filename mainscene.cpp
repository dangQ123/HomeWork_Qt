#include "mainscene.h"
#include<QPainter>
#include<QTimer>
#include<QDebug>
#include"config.h"
#include<audio.h>
#include<QMediaPlayer>

//页面大小
int Width = GAME_WIDTH;
int Height = GAME_HEIGHT;

int levelFloor = 100;
//时间间隔
int Interval = GAME_FPS;

MainScene::MainScene(QWidget *parent)
    : QWidget(parent)
{
    count=0;
    //创建页面
    this->setFixedSize(Width,Height);
    this->player.rightWalkPixmap();
    timer.setInterval(Interval);
    playerGame();
    player.isOnFloor = 1;//在地
    this->startTimer(GAME_FPS);//每0.03秒运行一次timerEvent函数
    //背景音乐
    MusicPlay.playBGM();

    this->map.addMonsterClose(GAME_WIDTH-150,GAME_HEIGHT-250);
    //this->map.addMonsterClose(50,GAME_HEIGHT-250);
    //qDebug()<<this->map.monsterClose[0]->getPos_y();

}

MainScene::~MainScene()
{

}

void MainScene::playerGame()
{
    timer.start();
    connect(&timer,&QTimer::timeout,[=]()
    {
        update();
        count++;
        if(count==10)
            count=0;
        addCountOfMonsterCloseInMap(this->map);
        this->allMonsterCloseMoveInMap(this->map);
        qDebug()<<"health="<<this->map.monsterClose[0]->getHeath();

    }
                );
}

void MainScene::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
        //A键被按下，向左
        case Qt::Key_A:
        if(event->isAutoRepeat()&&!PressFlag)
        {   //长按
            PressFlag=true; //长按flag
            //此处添加长按需要实现的代码;
            player.walkHor(-10);
        }
        if(!PressFlag)
        {
            player.walkHor(-10);
        }
        this->player.leftWalkPixmap();
        break;
        //D键被按下，向右
        case Qt::Key_D:
        if(event->isAutoRepeat()&&!PressFlag)
        {   //长按
            PressFlag=true; //长按flag
            //此处添加长按需要实现的代码;
            player.walkHor(10);
        }
        if(!PressFlag)
        {   //按下
            player.walkHor(10);
        }
        this->player.rightWalkPixmap();
        break;
        //W键，跳
        case Qt::Key_W:
        qDebug()<<PressFlag;
        if(event->isAutoRepeat()&&!PressFlag&&(player.isOnFloor||player.isOnPlat))
        {   //长按
            PressFlag=true; //长按flag
            player.walkVer(-20);
            player.isOnFloor = 0;//不在地
        }
        if(!PressFlag&&(player.isOnFloor||player.isOnPlat))
        {   //按下
            player.walkVer(-20);
            player.isOnFloor = 0;//不在地
            player.isOnPlat = 0;

            //跳跃音乐
            MusicPlay.playJump();
        }
        break;
        case Qt::Key_J:
            this->map.monsterClose[0]->setHeath(this->map.monsterClose[0]->getHeath()-1);
            this->map.monsterClose[0]->underAttack();
        default: break;
    }
    //QWidget::keyPressEvent(event);
}

void MainScene::keyReleaseEvent(QKeyEvent *event)
{
    switch(event->key())
    {
        case Qt::Key_A:

        if(!PressFlag&&!event->isAutoRepeat())
        {
            //此处写短按需要实现的代码;
            //x速度清零
            player.walkHor(0);
        }
        else if(PressFlag&&!event->isAutoRepeat())
        {
            PressFlag=false;
            //x速度清零
            player.walkHor(0);
        }
        this->player.leftWalkPixmap();
        break;
        case Qt::Key_D:

        if(!PressFlag&&!event->isAutoRepeat())
        {
            //此处写短按需要实现的代码;
            //x速度清零
            player.walkHor(0);
        }
        else if(PressFlag&&!event->isAutoRepeat()){
            PressFlag=false;
            player.walkHor(0);
        }
        this->player.rightWalkPixmap();
        break;
        case Qt::Key_W:

        if(!PressFlag&&!event->isAutoRepeat())
        {

        }
        else if(PressFlag&&!event->isAutoRepeat())
        {
            PressFlag=false;
            player.isjumpshort = 0;
        }
        break;

        default: break;
    }
}

void MainScene::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    //背景
    painter.drawPixmap(0, 0, GAME_WIDTH,GAME_HEIGHT,this->map.get_pixmap());
    int i;
    for(i=0;i<this->map.numOfGameObject;i++)
    {
        painter.drawPixmap(this->map.gameobject[i].pos.x(),
                           this->map.gameobject[i].pos.y(),
                           this->map.gameobject[i].get_width(),
                           this->map.gameobject[i].get_height(),
                           this->map.gameobject[i].get_pixmap()
                           );
    }

    painter.drawPixmap(this->player.p_x,this->player.p_y,PLAY_WIDTH,PLAY_HEIGHT,player.pixmap[count]);
    for(i=0;i<this->map.numOfMonsterClose;i++)
    {
        qDebug()<<"isInWalk="<<map.monsterClose[0]->isInWalk
               <<" isInAttack="<<map.monsterClose[0]->isInAttack
              <<" isUnderAttack="<<map.monsterClose[0]->isUnderAttack;  //测试怪物所处状态

        if(this->map.monsterClose[i]->isInWalk)
            painter.drawPixmap(this->map.monsterClose[i]->getPos_x(),
                           this->map.monsterClose[i]->getPos_y(),
                           MOSTER_WIDTH,MOSTER_HEIGHT,
                           this->map.monsterClose[i]->walkPixmaps[this->map.monsterClose[i]->walkCount]
                           );
        else if(this->map.monsterClose[i]->isInAttack)
            painter.drawPixmap(this->map.monsterClose[i]->getPos_x(),
                               this->map.monsterClose[i]->getPos_y(),
                               MOSTER_WIDTH,MOSTER_HEIGHT,
                               this->map.monsterClose[i]->attackPixmaps[this->map.monsterClose[i]->attackCount]
                               );
        else if(this->map.monsterClose[i]->isUnderAttack)
            painter.drawPixmap(this->map.monsterClose[i]->getPos_x(),
                               this->map.monsterClose[i]->getPos_y(),
                               MOSTER_WIDTH,MOSTER_HEIGHT,
                               this->map.monsterClose[i]->underAttackPixmaps[this->map.monsterClose[i]->underAttackCount]
                               );
        else
            painter.drawPixmap(this->map.monsterClose[i]->getPos_x(),
                               this->map.monsterClose[i]->getPos_y(),
                               MOSTER_WIDTH,MOSTER_HEIGHT,
                               this->map.monsterClose[i]->nothing
                               );
    }
}
//核心
void MainScene::timerEvent(QTimerEvent *e)
{
    player.p_x = player.p_x + player.p_vx;//根据x方向速度更新其x坐标
    player.p_vy = player.p_vy + player.gravity;//根据中立加速度更新小球y方向速度
    player.p_y = player.p_y + player.p_vy;//根据y方向速度更新其y坐标
    this->map.examAllGameObject(this->player);
    if(player.p_y>=GAME_HEIGHT-200)
        player.p_y=GAME_HEIGHT-200;

}

void MainScene::addCountOfMonsterCloseInMap(Map &map)
{
    int i;
    for(i=0;i<map.numOfMonsterClose;i++)
    {
        //qDebug()<<"isInWalk="<<map.monsterClose[i]->isInWalk<<"isInAttack="<<map.monsterClose[i]->isInAttack;
        if(map.monsterClose[i]->isInWalk)
        {
            map.monsterClose[i]->addCount(map.monsterClose[i]->walkCount,18);
        }
        else if(map.monsterClose[i]->isInAttack)
        {
            map.monsterClose[i]->addCount(map.monsterClose[i]->attackCount,12);
        }
        else if(map.monsterClose[i]->isUnderAttack)
        {
            map.monsterClose[i]->addCount(map.monsterClose[i]->underAttackCount,12);
            if(map.monsterClose[i]->underAttackCount==11)
            {
                map.monsterClose[i]->isInWalk=1;
                map.monsterClose[i]->isInAttack=0;
                map.monsterClose[i]->isUnderAttack=0;
            }

        }
    }
}

void MainScene::allMonsterCloseMoveInMap(Map &map)
{
    int i;
    for(i=0;i<map.numOfMonsterClose;i++)
    {
        map.monsterClose[i]->moveMonsterClose(this->player);
        map.monsterClose[i]->setWalkPixmaps(map.monsterClose[i]->getFaceTo());
        if(map.monsterClose[i]->getHeath()<map.monsterClose[i]->maxHealth)
        {
            map.monsterClose[i]->underAttack();
            map.monsterClose[i]->maxHealth=map.monsterClose[i]->getHeath();
        }
        if(map.monsterClose[i]->isDead())
        {
            //delete map.monsterClose[i];           //清除对应的怪物
        }

    }
}



