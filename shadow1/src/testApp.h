#pragma once

#include "ofMain.h"
#include "ofxCv.h"
#include "WebcamGrab.h"
#include "EffectsGroup.h"
#include "EffectsFactory.h"

class testApp : public ofBaseApp {
public:
	void setup();
	void update();
	void draw();
    
    void createBaseEffects();
	
	ofVideoGrabber cam;
	ofImage  shadowImage;
    
    EffectsGroup effects;
    EffectsFactory effectsFactory;
};
