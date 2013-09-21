//
//  RecorderStopRecState.cpp
//  shadow
//
//  Created by Guillaume LUNG TUNG on 15/09/13.
//
//

#include "RecorderState.h"


RecorderStopRecState::RecorderStopRecState(AnimatedImageRecorder *rec)
{
    setType(RECORDER_STATE_STOPREC);
    recorder = rec;
    isVisible = true;
    bIsRecording = false;
    bIsPlaying = false;
    readingPosition = recorder->sequence.end();
}

//--------------------------------------------------------------
void RecorderStopRecState::update()
{
    if (!recorder->sequence.empty() && bIsPlaying && readingPosition != recorder->sequence.end())
        readingPosition++;
}

//--------------------------------------------------------------
void RecorderStopRecState::record(ofPixels &p)
{
    recorder->sequence.push_back(SingleImageRecorder(p));
}

//--------------------------------------------------------------
void RecorderStopRecState::clear()
{
    recorder->sequence.clear();
}

//--------------------------------------------------------------
void RecorderStopRecState::draw(int x, int y, int width, int height)
{
    if (!recorder->sequence.empty() && readingPosition != recorder->sequence.end())
        readingPosition->draw();
}


//--------------------------------------------------------------
void RecorderStopRecState::switchRecording()
{
    if (!bIsRecording && recorder->sequence.empty())
    {
        bIsRecording = true;
        bIsPlaying = false;
        readingPosition = recorder->sequence.begin();
    }
    else if (bIsRecording)
    {
        bIsRecording = false;
        bIsPlaying = true;
    }
    else if (bIsPlaying)
        bIsPlaying = false;
    else if (!bIsPlaying)
        bIsPlaying = true;
}

//--------------------------------------------------------------
void RecorderStopRecState::keyPressed(int key)
{
    if (key == ' ')
        switchRecording();
}

//--------------------------------------------------------------
void RecorderStopRecState::execute(string msg_string, float msg_arg)
{
    if (msg_string == "/shadow/recorder/stoprec/switch" && msg_arg == 1.0)
    {
        if (recorder->state->getType() != RECORDER_STATE_STOPREC)
        {
            recorder->setState(RECORDER_STATE_STOPREC);
            clear();
        }
        switchRecording();
    }
}
