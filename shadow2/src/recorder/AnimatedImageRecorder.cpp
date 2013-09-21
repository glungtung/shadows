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
    stateList.resize(5);
    stateList[RECORDER_STATE_INACTIVE] = ofPtr<ImageRecorderStateInterface>(new RecorderInactiveState(this));
    stateList[RECORDER_STATE_PHOTO] = ofPtr<ImageRecorderStateInterface>(new RecorderPhotoState(this));
    stateList[RECORDER_STATE_PALINDROME] = ofPtr<ImageRecorderStateInterface>(new RecorderPalindromeState(this));
    stateList[RECORDER_STATE_MULTIX] = ofPtr<ImageRecorderStateInterface>(new RecorderMultixState(this));
    stateList[RECORDER_STATE_STOPREC] = ofPtr<ImageRecorderStateInterface>(new RecorderStopRecState(this));
    
    setState(RECORDER_STATE_PHOTO);

    sequence.reserve(600);
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
    switch (stateType) {
        case RECORDER_STATE_INACTIVE:
            state = stateList[RECORDER_STATE_INACTIVE];
            break;
        case RECORDER_STATE_PHOTO:
            state = stateList[RECORDER_STATE_PHOTO];
            break;
        case RECORDER_STATE_PALINDROME:
            state = stateList[RECORDER_STATE_PALINDROME];
            break;
        case RECORDER_STATE_MULTIX:
            state = stateList[RECORDER_STATE_MULTIX];
            break;
        case RECORDER_STATE_STOPREC:
            state = stateList[RECORDER_STATE_STOPREC];
            break;
        default:
            break;
    }
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
