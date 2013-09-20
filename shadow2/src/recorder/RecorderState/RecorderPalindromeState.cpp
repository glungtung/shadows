//
//  RecorderPalindromeState.cpp
//  shadow
//
//  Created by Guillaume LUNG TUNG on 15/09/13.
//
//

#include "RecorderState.h"

RecorderPalindromeState::RecorderPalindromeState(AnimatedImageRecorder *rec)
{
    recorder = rec;
    isVisible = true;
    bIsRecording = false;
    bReadingBackward = true;
    readingPosition = recorder->sequence.end();
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

