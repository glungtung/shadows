#include "testApp.h"

using namespace ofxCv;
using namespace cv;

//-----------------------------------------------------------------------------
void testApp::setup() {
	ofSetVerticalSync(true);
	//cam.initGrabber(640, 480);
    cam.init();
   // cam.setDesiredFrameRate(60);
    createBaseEffects();
    effects.init();
    
    receiver.setup(8000);
}

//-----------------------------------------------------------------------------
void testApp::update() {
    // check for waiting messages
	while(receiver.hasWaitingMessages()){
		// get the next message
		ofxOscMessage m;
		receiver.getNextMessage(&m);
        string msg_string = m.getAddress();
        float msg_arg = 0.;
        // TODO:  deal with num of args
        if (m.getNumArgs() == 1 && m.getArgType(0) == OFXOSC_TYPE_FLOAT)
            msg_arg = m.getArgAsFloat(0);
        recorder.execute(msg_string, msg_arg);
        effects.execute(msg_string, msg_arg);
    }
    
    recorder.update();
    
    if (recorder.isRecording())
        recorder.record(shadowImage.getPixelsRef());
	
    cam.update();
	if(cam.isFrameNew()) {
        shadowImage.setFromPixels(cam.getPixelsRef());
        effects.apply(shadowImage);
        shadowImage.update();
	}
}

//-----------------------------------------------------------------------------
void testApp::draw() {
    ofBackground(255);
    
	ofSetColor(255);
	


    ofEnableBlendMode(OF_BLENDMODE_DARKEN);
    recorder.draw(0,0,ofGetWidth(),ofGetHeight());

    if (shadowImage.isAllocated())
        shadowImage.draw(0, 0, ofGetWidth(), ofGetHeight());
    
    cam.draw(200, 0);
    
    ofEnableBlendMode(OF_BLENDMODE_DISABLED);
    effects.draw();
}

//-----------------------------------------------------------------------------
void testApp::keyPressed(int key) {
    if (key==' ')
        recorder.keyPressed(key);
    else if (key=='f')
        ofToggleFullscreen();
}


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void testApp::createBaseEffects() {
    effects.setName("Cam Effect Group");
    //effects.addEffect(effectsFactory.createEffect("Undistort"));
//    effects.addEffect(effectsFactory.createEffect("Background"));
    effects.addEffect(effectsFactory.createEffect("ConvertToGray"));
    effects.addEffect(effectsFactory.createEffect("BackgroundSimple"));
    effects.addEffect(effectsFactory.createEffect("Crop"));
   // effects.addEffect(effectsFactory.createEffect("Equalize"));
    effects.addEffect(effectsFactory.createEffect("Threshold"));
   // effects.addEffect(effectsFactory.createEffect("ErodeDilate"));
  //  effects.addEffect(effectsFactory.createEffect("Contour"));
    effects.addEffect(effectsFactory.createEffect("Trails"));
    effects.addEffect(effectsFactory.createEffect(""));
}