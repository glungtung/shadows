//
//  SingleImageRecorder.h
//  shadow
//
//  Created by Guillaume LUNG TUNG on 15/09/13.
//
//

#ifndef shadow_SingleImageRecorder_h
#define shadow_SingleImageRecorder_h

#include "ImageRecorderInterface.h"

class SingleImageRecorder : public ImageRecorderInterface, ofBaseHasPixels {
public:
    SingleImageRecorder();
    SingleImageRecorder(ofPixels &p);
    ~SingleImageRecorder() {};
    
    void update() {};
    void clear();
    void draw(int x=0, int y=0);
    bool isRecording() {return bIsRecording;};
    void record(ofPixels &pixels);
    void setVisible(bool b) {isVisible = b;}
    void keyPressed(int key);
    
    bool isVisible, bIsRecording;
    
    unsigned char * getPixels();
    ofPixels & getPixelsRef();
    
    ofPixels pixels;
};

#endif
