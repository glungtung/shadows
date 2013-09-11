#pragma once

#include "ofMain.h"
#include "ofxCv.h"
#include "WebcamGrab.h"
#include "EffectThreshold.h"
#include "EffectUndistort.h"
#include "EffectConvert2Gray.h"

class testApp : public ofBaseApp {
public:
	void setup();
	void update();
	void draw();
	
	ofVideoGrabber cam;
	ofImage undistorted, shadowImage;
    ofTexture tex;
    
    EffectThreshold thresh;
    EffectUndistort undistort;
    EffectConvert2Gray gray;
};
