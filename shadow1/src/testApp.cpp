#include "testApp.h"

using namespace ofxCv;
using namespace cv;

void testApp::setup() {
	ofSetVerticalSync(true);
	cam.initGrabber(640, 480);
    createBaseEffects();
    effects.init();
}

void testApp::update() {
	cam.update();
	if(cam.isFrameNew()) {
        shadowImage.setFromPixels(cam.getPixelsRef());
        effects.apply(shadowImage);
        shadowImage.update();
	}
}

void testApp::draw() {
	ofSetColor(255);
	
    cam.draw(0, 0);
    if (shadowImage.isAllocated())
        shadowImage.draw(640, 0);
    effects.drawGUI();
}


void testApp::createBaseEffects() {
    effects.addEffect(effectsFactory.createEffect("ConvertToGray"));
    effects.addEffect(effectsFactory.createEffect("Undistort"));
    effects.addEffect(effectsFactory.createEffect("Threshold"));
    effects.addEffect(effectsFactory.createEffect(""));
    effects.addEffect(effectsFactory.createEffect(""));



}