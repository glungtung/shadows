//
//  ImageRecorderInterface.h
//  shadow
//
//  Created by Guillaume LUNG TUNG on 15/09/13.
//
//

#ifndef shadow_ImageRecorderInterface_h
#define shadow_ImageRecorderInterface_h

#include "ofMain.h"

class ImageRecorderInterface {
public:
    virtual void update() = 0;
    virtual void clear() = 0;
    virtual void draw(int x=0, int y=0, int width=0, int height=0) = 0;
    virtual bool isRecording() = 0;
    virtual void record(ofPixels &pixels) = 0;
    virtual void keyPressed(int key) = 0;
    
};

#endif
