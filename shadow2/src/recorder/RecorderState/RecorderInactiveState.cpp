//
//  RecorderInactiveState.cpp
//  shadow
//
//  Created by Guillaume LUNG TUNG on 15/09/13.
//
//

#include "RecorderState.h"


RecorderInactiveState::RecorderInactiveState(AnimatedImageRecorder *rec)
{
    setType(RECORDER_STATE_INACTIVE);
    recorder = rec;
}


//--------------------------------------------------------------
void RecorderInactiveState::execute(string msg_string, float msg_arg){
    if (msg_string == "/shadow/recorder/normal" && msg_arg == 1.0)
        recorder->setState(RECORDER_STATE_INACTIVE);
}
