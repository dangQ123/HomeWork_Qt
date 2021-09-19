#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QWidget>
#include"player.h"
#include"map.h"
#include<QTimer>

class MainScene : public QWidget
{
    Q_OBJECT

public:
    MainScene(QWidget *parent = 0);

    Player player;
    Map map;
    QTimer timer;

    void paintEvent(QPaintEvent *event);
    void keyPressEvent(QKeyEvent *event);

    void initMainScene();
    void playGame();

    ~MainScene();

};

#endif // MAINSCENE_H
