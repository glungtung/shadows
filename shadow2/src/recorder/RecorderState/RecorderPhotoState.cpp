//
//  RecorderPhotoState.cpp
//  shadow
//
//  Created by Guillaume LUNG TUNG on 15/09/13.
//
//

#include "RecorderState.h"

RecorderPhotoState::RecorderPhotoState(AnimatedImageRecorder *rec)
{
    recorder = rec;
    isVisible = true;
    bIsRecording = false;
}

void RecorderPhotoState::update()
{
}

void RecorderPhotoState::record(ofPixels &p)
{
    //clear();
    recorder->sequence.push_back(SingleImageRecorder(p));
    bIsRecording = false;
}

void RecorderPhotoState::clear()
{
    recorder->sequence.clear();
}

void RecorderPhotoState::draw(int x, int y, int width, int height)
{
    for (vector<SingleImageRecorder>::iterator it = recorder->sequence.begin(); it != recorder->sequence.end(); it++)
    {
        it->draw(x,y,width,height);
    }
}

void RecorderPhotoState::keyPressed(int key)
{
    if (key == ' ')
        bIsRecording = true;
}

