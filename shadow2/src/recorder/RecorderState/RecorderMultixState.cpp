//
//  RecorderMultixState.cpp
//  shadow
//
//  Created by Guillaume LUNG TUNG on 15/09/13.
//
//

#include "RecorderState.h"
#include "OscGUISender.h"

RecorderMultixState::RecorderMultixState(AnimatedImageRecorder *rec)
{
    setType(RECORDER_STATE_MULTIX);
    recorder = rec;
    isVisible = true;
    bIsRecording = false;
    
    bIsRecording.addListener(this, &RecorderMultixState::onRecChange);
    nb.addListener(this, &RecorderMultixState::onNbChange);
    offset.addListener(this, &RecorderMultixState::onOffsetChange);
    parameters.add(nb.set("number",2,2,15));
    parameters.add(offset.set("offset",1,1,100));
    gui.setup(parameters);

}

//--------------------------------------------------------------
void RecorderMultixState::update()
{
    if (recorder->sequence.size() > nb * offset * 2)
    {
        recorder->sequence.erase(recorder->sequence.begin(), recorder->sequence.begin() + nb*offset);
    }
    if (isRecording() && recorder->sequence.size() == MAX_RECORDER_BUFFER_SIZE)
        switchRecording();
}

//--------------------------------------------------------------
void RecorderMultixState::record(ofPixels &p)
{
    recorder->sequence.push_back(SingleImageRecorder(p));
}

//--------------------------------------------------------------
void RecorderMultixState::clear()
{
    recorder->sequence.clear();
}

//--------------------------------------------------------------
void RecorderMultixState::draw(int x, int y, int width, int height)
{
    if (bIsRecording && recorder->sequence.size() > 0)
    {
        int printed = 0;
        int step = offset;
        for (vector<SingleImageRecorder>::reverse_iterator it = recorder->sequence.rbegin(); it != recorder->sequence.rend() && printed < nb; it++)
        {
            if (step == offset)
            {
                it->draw(x,y,width,height);
                printed++;
                step = 0;
            }
            else
                step++;
        }
    }
    if (recorder->isGUIVisible)
        gui.draw();
}


//--------------------------------------------------------------
void RecorderMultixState::switchRecording()
{
    if (!bIsRecording)
    {
        bIsRecording = true;
        clear();
    }
    else
    {
        bIsRecording = false;
    }
    

}

//--------------------------------------------------------------
void RecorderMultixState::keyPressed(int key)
{
    if (key == ' ')
        switchRecording();
}

//--------------------------------------------------------------
void RecorderMultixState::execute(string msg_string, float msg_arg)
{
    if (msg_string == "/shadow/recorder/multix/switch")
    {
        recorder->setState(RECORDER_STATE_MULTIX);
        switchRecording();
    }
    else if (msg_string == "/shadow/recorder/multix/nb")
    {
        nb.set(int(msg_arg));

    }
    else if (msg_string == "/shadow/recorder/multix/offset")
    {
        offset.set(int(msg_arg));
    }
}

//--------------------------------------------------------------
void RecorderMultixState::onNbChange(int &value)
{
    static OscGUISender * sender = singleOscSender::Instance();
    sender->send("/1/multixNb", ofToString(value));
}

//--------------------------------------------------------------
void RecorderMultixState::onOffsetChange(int &value)
{
    static OscGUISender * sender = singleOscSender::Instance();
    sender->send("/1/multixOffset", ofToString(value));
}

//--------------------------------------------------------------
void RecorderMultixState::onRecChange(bool &value)
{
    static OscGUISender * sender = singleOscSender::Instance();
    sender->send("/shadow/recorder/multix/switch", ofToString(bIsRecording));
}