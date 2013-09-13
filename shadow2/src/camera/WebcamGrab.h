//
//  WebcamGrab.h
//  shadow
//
//  Created by Guillaume LUNG TUNG on 06/09/13.
//
//

#ifndef shadow_WebcamGrab_h
#define shadow_WebcamGrab_h

#include "ImageGrabInterface.h"

class WebcamGrab : public ImageGrabInterface {
public:
    WebcamGrab() {};
    ~WebcamGrab() {};
    
    void init();
    void update();
    bool isFrameNew();
    void draw(int x, int y);
    void exit();
    
    unsigned char * getPixels();
    ofPixels & getPixelsRef();
    
private:
    ofVideoGrabber cam;

};
#endif
