//
//  RecorderPalindromeState.cpp
//  shadow
//
//  Created by Guillaume LUNG TUNG on 15/09/13.
//
//

#include "RecorderState.h"
#include "OscGUISender.h"


RecorderPalindromeState::RecorderPalindromeState(AnimatedImageRecorder *rec)
{
    setType(RECORDER_STATE_PALINDROME);
    recorder = rec;
    isVisible = true;
    bIsRecording = false;
    bReadingBackward = true;
    readingPosition = recorder->sequence.end();
    
    bIsRecording.addListener(this, &RecorderPalindromeState::onRecChange);

}

//--------------------------------------------------------------
void RecorderPalindromeState::update()
{
    if (readingPosition == recorder->sequence.end())
        return;
    
    if (bReadingBackward)
        --readingPosition;
    else
        ++readingPosition;
    
    if (readingPosition == recorder->sequence.begin())
        bReadingBackward = false;
    else if (readingPosition + 1 == recorder->sequence.end())
        bReadingBackward = true;
    
    
    // limit buffer recording size
    if (isRecording() && recorder->sequence.size() > MAX_RECORDER_BUFFER_SIZE)
    {
        switchRecording();
    }
}

//--------------------------------------------------------------
void RecorderPalindromeState::record(ofPixels &p)
{
    recorder->sequence.push_back(SingleImageRecorder(p));
}

//--------------------------------------------------------------
void RecorderPalindromeState::clear()
{
    recorder->sequence.clear();
}

//--------------------------------------------------------------
void RecorderPalindromeState::draw(int x, int y, int width, int height)
{
    if (!bIsRecording && readingPosition != recorder->sequence.end())
        readingPosition->draw(x,y,width,height);
}


//--------------------------------------------------------------
void RecorderPalindromeState::switchRecording()
{
    if (!bIsRecording)
    {
        bIsRecording = true;
        clear();
        readingPosition = recorder->sequence.end();
        bReadingBackward = true;
    }
    else
    {
        bIsRecording = false;
        readingPosition = recorder->sequence.end() - 1;
    }

}

//--------------------------------------------------------------
void RecorderPalindromeState::keyPressed(int key)
{
    if (key == ' ')
        switchRecording();
}

//--------------------------------------------------------------
void RecorderPalindromeState::execute(string msg_string, float msg_arg)
{
    if (msg_string == "/shadow/recorder/palindrome/switch")
    {
        if (recorder->state->getType() != RECORDER_STATE_PALINDROME)
        {
            recorder->setState(RECORDER_STATE_PALINDROME);
            isVisible = true;
            bIsRecording = false;
            bReadingBackward = true;
            readingPosition = recorder->sequence.end();
        }
        
        switchRecording();
    }
}

//--------------------------------------------------------------
void RecorderPalindromeState::onRecChange(bool &value)
{
    static OscGUISender * sender = singleOscSender::Instance();
    sender->send("/shadow/recorder/palindrome/switch", ofToString(bIsRecording));
}
