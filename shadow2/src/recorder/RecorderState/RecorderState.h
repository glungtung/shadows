//
//  RecorderPalindromeState.h
//  shadow
//
//  Created by Guillaume LUNG TUNG on 15/09/13.
//
//

#ifndef shadow_RecorderPalindromeState_h
#define shadow_RecorderPalindromeState_h

#include "ImageRecorderInterface.h"
#include "AnimatedImageRecorder.h"

/*
class RecorderPalindromeState : public ImageRecorderInterface{
public:    
    RecorderPalindromeState(ImageRecorderInterface &parent);
    ~RecorderPalindromeState() {};
    
    void update();
    void clear();
    void draw(int x=0, int y=0);
    inline bool isRecording() {return bIsRecording;};
    void record(ofPixels &pixels);
    void setVisible(bool b) {isVisible = b;}
    void keyPressed(int key);
    
    bool isVisible, bIsRecording;

};*/

class AnimatedImageRecorder;

class RecorderPhotoState : public ImageRecorderInterface{
public:
    RecorderPhotoState(AnimatedImageRecorder *rec);
    ~RecorderPhotoState() {};
    
    void update();
    void clear();
    void draw(int x=0, int y=0);
    inline bool isRecording() {return bIsRecording;};
    void record(ofPixels &pixels);
    void setVisible(bool b) {isVisible = b;}
    void keyPressed(int key);
    
    bool isVisible, bIsRecording;
    AnimatedImageRecorder *recorder;
    
};
#endif