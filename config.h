#ifndef CONFIG_H
#define CONFIG_H

//常量文件
//凡是带PATH的均为路径，类型为字符串

#define GAME_WIDTH 1300
#define GAME_HEIGHT 800
#define MAINSCENE_TITLE "HomeWor"
#define GAME_FPS 30
//重力加速度
#define G 1
#define REFRESH_FACROR 1.8

#define PLAYER_PATH ":/PlayWalk/GameSouce/PNG/Wraith_03/PNG Sequences/Walking/PlayerWalk(0).png"
#define MAP_PATH ":/Map/GameSouce/background/2/background.png"

#define PLAY_WIDTH 200
#define PLAY_HEIGHT 200

//判断两GameObject之间的位置关系，用于碰撞检测
enum RELAPOS
{
  at_up=1,at_down,at_left,at_right,at_coin   //上下左右重
};

#endif // CONFIG_H
