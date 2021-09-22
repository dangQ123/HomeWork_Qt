#include "mainscene.h"
#include<QPainter>
#include<QTimer>
#include<QDebug>
#include"config.h"
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

    this->startTimer(GAME_FPS);//每50秒运行一次timerEvent函数
    qDebug()<<this->map.gameobject[0].pos.y();

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
            player.isjumpshort = 1;
        }
        break;
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
    qDebug()<<player.p_y;
}


