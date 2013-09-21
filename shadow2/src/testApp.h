#pragma once

#include "ofMain.h"
#include "ofxCv.h"
#include "WebcamGrab.h"
#include "EffectsGroup.h"
#include "EffectsFactory.h"
#include "PS3CamGrab.h"
#include "AnimatedImageRecorder.h"
#include "ofxOsc.h"

class testApp : public ofBaseApp {
public:
	void setup();
	void update();
	void draw();
    
    void createBaseEffects();
    
    void keyPressed(int key);
	
	WebcamGrab cam;
	ofImage  shadowImage;
    
    EffectsGroup effects;
    EffectsFactory effectsFactory;
    
    AnimatedImageRecorder recorder;
    
    ofxOscReceiver receiver;

};
