#include "testApp.h"

using namespace ofxCv;
using namespace cv;

void testApp::setup() {
	ofSetVerticalSync(true);
	cam.initGrabber(640, 480);
    undistort.init();
}

void testApp::update() {
	cam.update();
	if(cam.isFrameNew()) {
        shadowImage.setFromPixels(cam.getPixelsRef());
        gray.apply(shadowImage);
        undistort.apply(shadowImage);
        thresh.apply(shadowImage);
        
        shadowImage.update();
	}
}

void testApp::draw() {
	ofSetColor(255);
	
    cam.draw(0, 0);
    if (shadowImage.isAllocated())
        shadowImage.draw(640, 0);
}
