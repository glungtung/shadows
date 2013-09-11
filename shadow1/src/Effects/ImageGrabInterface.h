//
//  ImageGrabInterface.h
//  shadow
//
//  Created by Guillaume LUNG TUNG on 06/09/13.
//
//

#ifndef shadow_ImageGrabInterface_h
#define shadow_ImageGrabInterface_h

#include "ofMain.h"

class ImageGrabInterface : public ofBaseHasPixels {
public:
    virtual ~ImageGrabInterface() {};
    virtual void init() = 0;
    virtual void update() = 0;
    virtual bool isFrameNew() = 0;
    virtual void exit() = 0;
    
    
};


#endif
