//
//  launchMusic.cpp
//  shadow
//
//  Created by Guillaume LUNG TUNG on 26/09/13.
//
//

#include "launchMusic.h"

void launchMusic::init()
{
  //  ofSoundUpdate();
    //zik.loadSound("zik1.mp3", true);
  //  zik2.loadSound("zik2.mp3");
    zik.setMultiPlay(false);
  //  zik.loadSound("zik1.mp3", true);
}

void launchMusic::execute(string msg_string, float msg_arg)
{

    
    if (msg_string == "/shadow/music/zik1" && msg_arg == 1.0)
    {
        zik.stop();
        zik.loadSound("zik1.mp3", true);
        zik.play();
    }
    if (msg_string == "/shadow/music/zik2" && msg_arg == 1.0)
    {
        zik.stop();
        zik.loadSound("zik2.mp3", true);
        zik.play();
    }
    if (msg_string == "/shadow/music/stop" && msg_arg == 1.0)
    {
        zik.stop();
    }
    
}