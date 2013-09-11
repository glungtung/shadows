#include "testApp.h"

using namespace ofxCv;
using namespace cv;

void testApp::setup() {
	ofSetVerticalSync(true);
	cam.initGrabber(640, 480);
	calibration.setFillFrame(true); // true by default
	calibration.load("mbp-2011-isight.yml");
	imitate(undistorted, cam);
	shadowImage.allocate(640, 480, OF_IMAGE_GRAYSCALE);
    tex.allocate(shadowImage);
}

void testApp::update() {
	cam.update();
	if(cam.isFrameNew()) {
		calibration.undistort(toCv(cam), toCv(undistorted));
        convertColor(undistorted, shadowImage, CV_RGB2GRAY);

        thresh.apply(shadowImage);
        
	}
}

void testApp::draw() {
	ofSetColor(255);
	cam.draw(0, 0);
	tex.loadData(shadowImage);
    tex.draw(640, 0);
}
