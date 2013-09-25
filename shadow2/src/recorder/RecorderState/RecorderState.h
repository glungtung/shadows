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
#include "ofxGui.h"

class AnimatedImageRecorder;
#define RECORDER_STATE_INACTIVE 0 
#define RECORDER_STATE_PHOTO 1
#define RECORDER_STATE_PALINDROME 2
#define RECORDER_STATE_MULTIX 3
#define RECORDER_STATE_STOPREC 4
#define RECORDER_STATE_PINGPONG 5

//--------------------------------------------------------------
class ImageRecorderStateInterface : public ImageRecorderInterface{
public:
    inline virtual void setType(int t) {type = t;}
    inline virtual int getType() {return type;}
private:
    int type;
};

//--------------------------------------------------------------
class RecorderPhotoState : public ImageRecorderStateInterface{
public:
    RecorderPhotoState(AnimatedImageRecorder *rec);
    ~RecorderPhotoState() {};
    
    void update();
    void clear();
    void draw(int x=0, int y=0, int width=0, int height=0);
    inline bool isRecording() {return bIsRecording;};
    void record(ofPixels &pixels);
    void setVisible(bool b) {isVisible = b;}
    void keyPressed(int key);
    void execute(string msg_string, float msg_arg);

    bool isVisible, bIsRecording;
    AnimatedImageRecorder *recorder;
    
    int type;
    
    vector<unsigned long long> timestamps;
    
    ofxPanel gui;
    ofParameterGroup parameters;
    ofParameter<int> duration;
    ofParameter<bool> fade;
};


//--------------------------------------------------------------
class RecorderPalindromeState : public ImageRecorderStateInterface{
public:
    RecorderPalindromeState(AnimatedImageRecorder *parent);
    ~RecorderPalindromeState() {};
    
    void update();
    void clear();
    void draw(int x=0, int y=0, int width=0, int height=0);
    inline bool isRecording() {return bIsRecording;};
    void record(ofPixels &pixels);
    void setVisible(bool b) {isVisible = b;}
    void keyPressed(int key);
    void execute(string msg_string, float msg_arg);

    void switchRecording();
    
    bool isVisible, bIsRecording;
    AnimatedImageRecorder *recorder;
    
    bool bReadingBackward;
    vector<SingleImageRecorder>::iterator readingPosition;
    
    int type;
};

//--------------------------------------------------------------
class RecorderMultixState : public ImageRecorderStateInterface{
public:
    RecorderMultixState(AnimatedImageRecorder *parent);
    ~RecorderMultixState() {};
    
    void update();
    void clear();
    void draw(int x=0, int y=0, int width=0, int height=0);
    inline bool isRecording() {return bIsRecording;};
    void record(ofPixels &pixels);
    void setVisible(bool b) {isVisible = b;}
    void keyPressed(int key);
    void execute(string msg_string, float msg_arg);

    void switchRecording();
    
    bool isVisible, bIsRecording;
    AnimatedImageRecorder *recorder;
    

    ofxPanel gui;
    ofParameterGroup parameters;
    ofParameter<int> nb;
    ofParameter<int> offset;
    
    int type;
};

//--------------------------------------------------------------
class RecorderInactiveState : public ImageRecorderStateInterface{
public:
    RecorderInactiveState(AnimatedImageRecorder *parent);
    ~RecorderInactiveState() {};
    
    void update() {};
    void clear() {};
    void draw(int x=0, int y=0, int width=0, int height=0) {};
    inline bool isRecording() {return false;}
    void record(ofPixels &pixels) {};
    void setVisible(bool b) {};
    void keyPressed(int key) {};
    void execute(string msg_string, float msg_arg);

    AnimatedImageRecorder *recorder;
    int type;
};

//--------------------------------------------------------------
class RecorderStopRecState : public ImageRecorderStateInterface{
public:
    RecorderStopRecState(AnimatedImageRecorder *parent);
    ~RecorderStopRecState() {};
    
    void update();
    void clear();
    void draw(int x=0, int y=0, int width=0, int height=0);
    inline bool isRecording() {return bIsRecording;};
    void record(ofPixels &pixels);
    void setVisible(bool b) {isVisible = b;}
    void keyPressed(int key);
    void execute(string msg_string, float msg_arg);
    
    void switchRecording();
    
    bool isVisible, bIsRecording, bIsPlaying;
    AnimatedImageRecorder *recorder;
    
    vector<SingleImageRecorder>::iterator readingPosition;
    
    int type;
};

//--------------------------------------------------------------
class RecorderPingPongState : public ImageRecorderStateInterface{
public:
    RecorderPingPongState(AnimatedImageRecorder *parent);
    ~RecorderPingPongState() {};
    
    void update();
    void clear();
    void draw(int x=0, int y=0, int width=0, int height=0);
    inline bool isRecording() {return bIsRecording;};
    void record(ofPixels &pixels);
    void setVisible(bool b) {isVisible = b;}
    void keyPressed(int key);
    void execute(string msg_string, float msg_arg);
    
    void switchRecording();
    
    bool isVisible, bIsRecording;
    AnimatedImageRecorder *recorder;
    
    bool bReadingBackward;
    vector<SingleImageRecorder>::iterator readingPosition, pingPosition, pongPosition;

    int type;
    
    ofxPanel gui;
    ofParameterGroup parameters;
    ofParameter<int> speed;
    int steps;
};
#endif
