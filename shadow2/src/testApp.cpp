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
}

//-----------------------------------------------------------------------------
void testApp::update() {
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
    recorder.draw();

    if (shadowImage.isAllocated())
        shadowImage.draw(0, 0);
    
    cam.draw(0, 0);
    
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
   // effects.addEffect(effectsFactory.createEffect("Crop"));
   // effects.addEffect(effectsFactory.createEffect("Equalize"));
    effects.addEffect(effectsFactory.createEffect("Threshold"));
   // effects.addEffect(effectsFactory.createEffect("ErodeDilate"));
  //  effects.addEffect(effectsFactory.createEffect("Contour"));
    effects.addEffect(effectsFactory.createEffect("Trails"));
    effects.addEffect(effectsFactory.createEffect(""));
}