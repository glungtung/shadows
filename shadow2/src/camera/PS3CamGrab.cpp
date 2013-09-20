//
//  PS3CamGrab.cpp
//  shadow
//
//  Created by Guillaume LUNG TUNG on 06/09/13.
//
//

#include "PS3CamGrab.h"

void PS3CamGrab::init() {
	ps3eye.initGrabber(640, 480);
	
    autoGainShutter.addListener(this, &PS3CamGrab::onAutoGainAndShutterChange);
    gain.addListener(this, &PS3CamGrab::onGainChange);
    shutter.addListener(this, &PS3CamGrab::onShutterChange);
    gamma.addListener(this, &PS3CamGrab::onGammaChange);
    brightness.addListener(this, &PS3CamGrab::onBrightnessChange);
    contrast.addListener(this, &PS3CamGrab::onContrastChange);
    hue.addListener(this, &PS3CamGrab::onHueChange);
    flickerType.addListener(this, &PS3CamGrab::onFlickerChange);
    whiteBalanceMode.addListener(this, &PS3CamGrab::onWhiteBalanceChange);
    
	gui.setName("PS3 Eye");
    parameters.add(fps);
    parameters.add(autoGainShutter.set("Auto Gain & Shutter", false));
    parameters.add(gain.set("Gain", 0.5, 0.0, 1.0));
    parameters.add(shutter.set("Shutter", 0.5, 0.0, 1.0));
    parameters.add(gamma.set("Gamma", 0.5, 0.0, 1.0));
    parameters.add(brightness.set("Brightness", 0.5, 0.0, 1.0));
    parameters.add(contrast.set("Contrast", 0.5, 0.0, 1.0));
    parameters.add(hue.set("Hue", 0.5, 0.0, 1.0));
    parameters.add(flickerType.set("Flicker Type", 0, 0, 2));
    parameters.add(whiteBalanceMode.set("White Balance Mode", 4, 1, 4));

    gui.setup(parameters);
}

void PS3CamGrab::update() {
    ps3eye.update();
    fps.set(ofToString(ps3eye.getRealFrameRate()) + "fps");
}

bool PS3CamGrab::isFrameNew() {
    return ps3eye.isFrameNew();
}

unsigned char * PS3CamGrab::getPixels() {
    return ps3eye.getPixels();
}

ofPixels & PS3CamGrab::getPixelsRef() {
    return ps3eye.getPixelsRef();
}



//--------------------------------------------------------------
void PS3CamGrab::draw(int x, int y){
	//ps3eye.draw(0, 0);
	gui.draw();
}

//--------------------------------------------------------------
void PS3CamGrab::onAutoGainAndShutterChange(bool & value){
	ps3eye.setAutoGainAndShutter(value);
}

//--------------------------------------------------------------
void PS3CamGrab::onGainChange(float & value){
	// Only set if auto gain & shutter is off
	if(!autoGainShutter){
		ps3eye.setGain(value);
	}
}

//--------------------------------------------------------------
void PS3CamGrab::onShutterChange(float & value){
	// Only set if auto gain & shutter is off
	if(!autoGainShutter){
		ps3eye.setShutter(value);
	}
}

//--------------------------------------------------------------
void PS3CamGrab::onGammaChange(float & value){
	ps3eye.setGamma(value);
}

//--------------------------------------------------------------
void PS3CamGrab::onBrightnessChange(float & value){
	ps3eye.setBrightness(value);
}

//--------------------------------------------------------------
void PS3CamGrab::onContrastChange(float & value){
	ps3eye.setContrast(value);
}

//--------------------------------------------------------------
void PS3CamGrab::onHueChange(float & value){
	ps3eye.setHue(value);
}

//--------------------------------------------------------------
void PS3CamGrab::onLedChange(bool & value){
	ps3eye.setLed(value);
}

//--------------------------------------------------------------
void PS3CamGrab::onFlickerChange(int & value){
	ps3eye.setFlicker(value);
}

//--------------------------------------------------------------
void PS3CamGrab::onWhiteBalanceChange(int & value){
	ps3eye.setWhiteBalance(value);
}
