#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QWidget>
#include"player.h"
#include<QTimer>
#include<QKeyEvent>
#include"config.h"
#include"map.h"
#include<audio.h>

class MainScene : public QWidget
{
    Q_OBJECT

public:
    MainScene(QWidget *parent = 0);
    ~MainScene();
    void playerGame();

    void paintEvent(QPaintEvent *event);


    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    void timerEvent(QTimerEvent *);

    Player player;
    QTimer timer;
    Map map;

    int count;

    //设置音乐
    Audio MusicPlay;
    void addCountOfMonsterCloseInMap(Map& map);
    void allMonsterCloseMoveInMap(Map& map);

private :
bool PressFlag=false;//按键形式

};

#endif // MAINSCENE_H
