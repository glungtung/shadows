//
//  WebcamGrab.cpp
//  shadow
//
//  Created by Guillaume LUNG TUNG on 06/09/13.
//
//

#include "WebcamGrab.h"

void WebcamGrab::init() {
    cam.initGrabber(640, 480);
}

void WebcamGrab::update() {
    cam.update();
}

bool WebcamGrab::isFrameNew() {
    return cam.isFrameNew();
}

unsigned char * WebcamGrab::getPixels() {
    return cam.getPixels();
}

ofPixels & WebcamGrab::getPixelsRef() {
    return cam.getPixelsRef();
}

void WebcamGrab::exit() {
    cam.initGrabber(640, 480);
}
