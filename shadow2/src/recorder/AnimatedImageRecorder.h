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

class AnimatedImageRecorder : public ImageRecorderInterface {
public:
    AnimatedImageRecorder();
    ~AnimatedImageRecorder() {};
    
    void update();
    void clear();
    void draw(int x=0, int y=0);
    bool isRecording();
    void record(ofPixels &pixels) ;
    inline void setVisible(bool b) {isVisible = b;}
    void keyPressed(int key);
    
    bool isVisible;
    
    vector<SingleImageRecorder> sequence;
    ofPtr<ImageRecorderInterface> state;
};

#endif
