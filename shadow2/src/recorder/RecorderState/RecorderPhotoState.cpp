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
    setType(RECORDER_STATE_PHOTO);
    recorder = rec;
    isVisible = true;
    bIsRecording = false;
    
    parameters.add(duration.set("duration",1000,1,10000));
    gui.setup(parameters);
}

void RecorderPhotoState::update()
{
}

void RecorderPhotoState::record(ofPixels &p)
{
    //clear();
    recorder->sequence.push_back(SingleImageRecorder(p));
    timestamps.push_back(ofGetElapsedTimeMillis());
    bIsRecording = false;
}

void RecorderPhotoState::clear()
{
    recorder->sequence.clear();
    timestamps.clear();
}

void RecorderPhotoState::draw(int x, int y, int width, int height)
{
    vector<SingleImageRecorder>::iterator it = recorder->sequence.begin();
    vector<unsigned long long>::iterator it_time = timestamps.begin();
    for (; it != recorder->sequence.end(); it++)
    {
        if (ofGetElapsedTimeMillis() > *it_time + 2000 && it->brightness >= 0)
            it->brightness--;
        it->draw(x,y,width,height);
        it_time++;
    }
}

void RecorderPhotoState::keyPressed(int key)
{
    if (key == ' ')
        bIsRecording = true;
}

//--------------------------------------------------------------
void RecorderPhotoState::execute(string msg_string, float msg_arg)
{
    if (msg_string == "/shadow/recorder/photo/switch" && msg_arg == 1.0)
    {
        if (recorder->state->getType() != RECORDER_STATE_PHOTO)
        {
            recorder->setState(RECORDER_STATE_PHOTO);
            clear();
        }
        bIsRecording = true;
    }
}