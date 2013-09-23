//
//  RecorderPingPongState.cpp
//  shadow
//
//  Created by Guillaume LUNG TUNG on 15/09/13.
//
//

#include "RecorderState.h"

#define MAXSPEED 100

RecorderPingPongState::RecorderPingPongState(AnimatedImageRecorder *rec)
{
    setType(RECORDER_STATE_PINGPONG);
    recorder = rec;
    isVisible = true;
    bIsRecording = false;
    bReadingBackward = false;
    readingPosition = recorder->sequence.end();
    steps = 0;
    
    parameters.add(speed.set("speed",5,5,MAXSPEED));
    gui.setup(parameters);
}

//--------------------------------------------------------------
void RecorderPingPongState::update()
{
  //  if (readingPosition == recorder->sequence.end())
  //      return;
    if (recorder->sequence.size() <= speed) return;
    
    
    if (bReadingBackward)
        --readingPosition;
    else
        readingPosition += 2;
    
    if (readingPosition <= pongPosition - speed)
    {
        bReadingBackward = false;
        pingPosition = readingPosition;
    }
    else if (readingPosition >= recorder->sequence.end())
    {
        if (recorder->sequence.size() > MAXSPEED * 5)
            recorder->sequence.erase(recorder->sequence.begin(), pingPosition - (MAXSPEED*2));
        readingPosition == recorder->sequence.end() - 1;
        bReadingBackward = true;
        pongPosition = readingPosition - ofNoise(0)*speed/4;
    }
    

    
    // limit buffer recording size
    if (isRecording() && recorder->sequence.size() > MAX_RECORDER_BUFFER_SIZE)
    {
        switchRecording();
    }
}

//--------------------------------------------------------------
void RecorderPingPongState::record(ofPixels &p)
{
    recorder->sequence.push_back(SingleImageRecorder(p));
}

//--------------------------------------------------------------
void RecorderPingPongState::clear()
{
    recorder->sequence.clear();
}

//--------------------------------------------------------------
void RecorderPingPongState::draw(int x, int y, int width, int height)
{
    if (bIsRecording && readingPosition < recorder->sequence.end())
        readingPosition->draw(x,y,width,height);

    gui.draw();
}


//--------------------------------------------------------------
void RecorderPingPongState::switchRecording()
{
    if (!bIsRecording)
    {
        bIsRecording = true;
        clear();
        readingPosition = recorder->sequence.begin();
        bReadingBackward = false;
        pingPosition = recorder->sequence.begin();
        pongPosition = recorder->sequence.begin();
    }
    else
    {
        bIsRecording = false;
        readingPosition = recorder->sequence.end();
    }
}

//--------------------------------------------------------------
void RecorderPingPongState::keyPressed(int key)
{
    if (key == ' ')
        switchRecording();
}

//--------------------------------------------------------------
void RecorderPingPongState::execute(string msg_string, float msg_arg)
{
    if (msg_string == "/shadow/recorder/pingpong/switch" && msg_arg == 1.0)
    {
        if (recorder->state->getType() != RECORDER_STATE_PINGPONG)
        {
            recorder->setState(RECORDER_STATE_PINGPONG);
            isVisible = true;
            bIsRecording = false;
            readingPosition = recorder->sequence.end();
        }
        
        switchRecording();
    }
}
