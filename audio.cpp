#include "audio.h"
#include<config.h>
#include<QMediaPlayer>
#include<QMediaPlaylist>

Audio::Audio()
{


}

void Audio::playBGM()
{
    BGM = new QMediaPlayer;
    //创建播放列表，以实现循环播放
    QMediaPlaylist *BGMlist = new QMediaPlaylist;

    //插入音乐
    BGMlist->addMedia(QUrl::fromLocalFile(BGM1_PATH));
    BGMlist->setCurrentIndex(1);
    //BGM->setMedia(QUrl::fromLocalFile(BGM1_PATH));
    //播放音乐
    BGM->setPlaylist(BGMlist);
    BGM->setVolume(30);
    BGM->play();
}

void Audio::playJump()
{
    myAudio[0] = new QMediaPlayer;
    myAudio[0]->setMedia(QUrl::fromLocalFile(JUMP_MUS_PATH));
    myAudio[0]->setVolume(80);
    myAudio[0]->play();
}
