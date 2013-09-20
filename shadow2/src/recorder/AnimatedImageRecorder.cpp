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
    sequence.reserve(600);
    state = ofPtr<ImageRecorderInterface>(new RecorderPalindromeState(this));
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

void AnimatedImageRecorder::draw(int x, int y)
{
    state->draw();
}


void AnimatedImageRecorder::keyPressed(int key)
{
    state->keyPressed(key);
}