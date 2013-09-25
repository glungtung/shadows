//
//  AnimatedImageRecorder.h
//  shadow
//
//  Created by Guillaume LUNG TUNG on 15/09/13.
//
//

#ifndef shadow_AnimatedImageRecorder_h
#define shadow_AnimatedImageRecorder_h

#include "ImageRecorderInterface.h"
#include "SingleImageRecorder.h"
#include "RecorderState/RecorderState.h"

#define MAX_RECORDER_BUFFER_SIZE 3000


class ImageRecorderStateInterface;

class AnimatedImageRecorder : public ImageRecorderInterface {
public:
    AnimatedImageRecorder();
    ~AnimatedImageRecorder() {};
    
    void update();
    void clear();
    void draw(int x=0, int y=0, int width=0, int height=0);
    bool isRecording();
    void record(ofPixels &pixels) ;
    inline void setVisible(bool b) {isVisible = b;}
    void keyPressed(int key);
    void execute(string msg_string, float msg_arg);
    void setState(int stateType);
    
    bool isVisible, isGUIVisible;
    
    vector<SingleImageRecorder> sequence;
    ofPtr<ImageRecorderStateInterface> state;
    vector<ofPtr<ImageRecorderStateInterface> > stateList;
};

#endif
