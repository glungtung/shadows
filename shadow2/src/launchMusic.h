//
//  launchMusic.h
//  shadow
//
//  Created by Guillaume LUNG TUNG on 26/09/13.
//
//

#ifndef __shadow__launchMusic__
#define __shadow__launchMusic__

#include "ofMain.h"
//#define OF_SOUND_PLAYER_QUICKTIME

class launchMusic
{
public:
    launchMusic() {}
    ~launchMusic() {};
    void init();
    void execute(string msg_string, float msg_arg);
    
    ofSoundPlayer zik;
    
};

#endif /* defined(__shadow__launchMusic__) */
