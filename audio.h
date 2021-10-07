#ifndef AUDIO_H
#define AUDIO_H

#include<QMediaPlayer>

class Audio
{
public:
    Audio();

    void playBGM();
    void playJump();

    QMediaPlayer *BGM;
    //其他音效
    QMediaPlayer *myAudio[20];
};

#endif // AUDIO_H
