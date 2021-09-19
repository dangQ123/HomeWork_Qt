#include "mainscene.h"
#include"config.h"
#include<QPainter>
#include"map.h"

MainScene::MainScene(QWidget *parent)
    : QWidget(parent)
{
    initMainScene();    //初始化
    playGame();         //其中包含计时器，每隔GAME_FPS调用一次 update()
}

MainScene::~MainScene()
{

}

void MainScene::initMainScene()
{
    setWindowTitle(MAINSCENE_TITLE);
    setFixedSize(GAME_WIDTH,GAME_HEIGHT);
    timer.setInterval(GAME_FPS);
}

void MainScene::paintEvent(QPaintEvent *)
{
    QPainter paint(this);
    paint.drawPixmap(this->map.get_pos().x(),this->map.get_pos().y(),
                     GAME_WIDTH, GAME_HEIGHT,this->map.get_pixmap());
    paint.drawPixmap(this->player.get_pos().x(),this->player.get_pos().y(),this->player.get_width(),
                     this->player.get_height(),this->player.get_pixmap());

}

void MainScene::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_A)
        player.walk(-PLAYER_SPEED);
    else if(event->key()==Qt::Key_D)
        player.walk(+PLAYER_SPEED);
}

void MainScene::playGame()
{
    this->timer.start();
    connect(&timer,&QTimer::timeout,[=]()
    {
        update();   //调用MainScene::paintEvent函数
    }
            );
}
