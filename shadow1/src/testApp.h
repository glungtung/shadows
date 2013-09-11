#pragma once

#include "ofMain.h"
#include "ofxCv.h"
#include "WebcamGrab.h"
#include "EffectThreshold.h"

class testApp : public ofBaseApp {
public:
	void setup();
	void update();
	void draw();
	
	ofVideoGrabber cam;
	ofImage undistorted;
    ofPixels shadowImage;
    ofTexture tex;
	ofxCv::Calibration calibration;
    
    EffectThreshold thresh;
};
