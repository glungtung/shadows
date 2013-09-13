#pragma once

#include "ofMain.h"
#include "ofxCv.h"
#include "WebcamGrab.h"
#include "EffectsGroup.h"
#include "EffectsFactory.h"
#include "PS3CamGrab.h"

class testApp : public ofBaseApp {
public:
	void setup();
	void update();
	void draw();
    
    void createBaseEffects();
	
	PS3CamGrab cam;
	ofImage  shadowImage;
    
    EffectsGroup effects;
    EffectsFactory effectsFactory;
};
