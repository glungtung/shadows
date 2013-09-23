//
//  AnimatedImageRecorder.cpp
//  shadow
//
//  Created by Guillaume LUNG TUNG on 15/09/13.
//
//

#include "AnimatedImageRecorder.h"



AnimatedImageRecorder::AnimatedImageRecorder()
{
    stateList.resize(6);
    stateList[RECORDER_STATE_INACTIVE] = ofPtr<ImageRecorderStateInterface>(new RecorderInactiveState(this));
    stateList[RECORDER_STATE_PHOTO] = ofPtr<ImageRecorderStateInterface>(new RecorderPhotoState(this));
    stateList[RECORDER_STATE_PALINDROME] = ofPtr<ImageRecorderStateInterface>(new RecorderPalindromeState(this));
    stateList[RECORDER_STATE_MULTIX] = ofPtr<ImageRecorderStateInterface>(new RecorderMultixState(this));
    stateList[RECORDER_STATE_STOPREC] = ofPtr<ImageRecorderStateInterface>(new RecorderStopRecState(this));
    stateList[RECORDER_STATE_PINGPONG] = ofPtr<ImageRecorderStateInterface>(new RecorderPingPongState(this));

    setState(RECORDER_STATE_PINGPONG);

    sequence.reserve(MAX_RECORDER_BUFFER_SIZE+10);
}


void AnimatedImageRecorder::update()
{
    state->update();
    
}

bool AnimatedImageRecorder::isRecording()
{
    return state->isRecording();
}


void AnimatedImageRecorder::record(ofPixels &p)
{
    state->record(p);
}

void AnimatedImageRecorder::clear()
{
    state->clear();
}

void AnimatedImageRecorder::draw(int x, int y, int width, int height)
{
    state->draw(x,y,width,height);
}


void AnimatedImageRecorder::setState(int stateType)
{
    state.reset();
    state = stateList[stateType];
}

void AnimatedImageRecorder::keyPressed(int key)
{
    state->keyPressed(key);
}

void AnimatedImageRecorder::execute(string msg_string, float msg_arg)
{
    for (vector<ofPtr<ImageRecorderStateInterface> >::iterator it = stateList.begin(); it < stateList.end(); it++)
        (*it)->execute(msg_string, msg_arg);
}
