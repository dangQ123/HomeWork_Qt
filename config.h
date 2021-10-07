#ifndef CONFIG_H
#define CONFIG_H

//常量文件
//凡是带PATH的均为路径，类型为字符串

#define GAME_WIDTH 1300
#define GAME_HEIGHT 800
#define MAINSCENE_TITLE "HomeWork"
#define GAME_FPS 30
//重力加速度
#define G 1
#define REFRESH_FACROR 1.8

//音乐
#define BGM1_PATH "D:/study/HomeWork/HomeWork2/GameSouce/music/background/BGM1.mp3"

#define JUMP_MUS_PATH "D:/study/HomeWork/testAnimutot/QtMario-master/resources/snd/jump.wav"

//图片
#define PLAYER_PATH ":/PlayWalk/GameSouce/PNG/Wraith_03/PNG Sequences/Walking/PlayerWalk(0).png"
#define MAP_PATH ":/Map/GameSouce/background/2/background.png"
#define MONSTERCLOSE_PATH":/enemy/close/walk/GameSouce/enemy/PNG/Minotaur_01/PNG Sequences/Walking/monsterCloseWalk(0).png"

#define PLAY_WIDTH 200
#define PLAY_HEIGHT 200
#define MOSTER_WIDTH PLAY_WIDTH
#define MOSTER_HEIGHT PLAY_HEIGHT

//判断两GameObject之间的位置关系，用于碰撞检测
enum RELAPOS
{
  at_up=1,at_down,at_left,at_right,at_coin   //上下左右重
};

enum FACE
{
  toLeft,toRight
};

enum SITUATION              //所处状态，目前可用于怪物
{
    isWalking,isAttacking
};

#endif // CONFIG_H
