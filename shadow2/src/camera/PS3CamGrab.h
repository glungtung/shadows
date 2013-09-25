//
//  PS3CamGrab.h
//  shadow
//
//  Created by Guillaume LUNG TUNG on 06/09/13.
//
//

#ifndef shadow_PS3CamGrab_h
#define shadow_PS3CamGrab_h

#include "ImageGrabInterface.h"
#include "ofxGui.h"
#include "ofxMacamPs3Eye.h"

class PS3CamGrab : public ImageGrabInterface {
public:
    PS3CamGrab() {};
    ~PS3CamGrab() {};
    
    void init();
    void update();
    bool isFrameNew();
    void draw(int x, int y);
    void exit() {};
    
    unsigned char * getPixels();
    ofPixels & getPixelsRef();
    
    void onAutoGainAndShutterChange(bool & value);
	void onGainChange(float & value);
	void onShutterChange(float & value);
	void onGammaChange(float & value);
	void onBrightnessChange(float & value);
	void onContrastChange(float & value);
	void onHueChange(float & value);
	void onLedChange(bool & value);
	void onFlickerChange(int & value);
	void onWhiteBalanceChange(int & value);
    
	ofxMacamPs3Eye ps3eye;

    ofxPanel gui;
    ofParameterGroup parameters;
    ofParameter<bool> autoGainShutter;
    ofParameter<float> gain;
    ofParameter<float> shutter;
    ofParameter<float> gamma;
    ofParameter<float> brightness;
    ofParameter<float> contrast;
    ofParameter<float> hue;
    ofParameter<int> flickerType;
    ofParameter<int> whiteBalanceMode;
    ofParameter<string> fps;
  
    bool isGUIVisible;
};
#endif
