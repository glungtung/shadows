//
//  EffectTrails.h
//  shadow
//
//  Created by Guillaume LUNG TUNG on 10/09/13.
//
//

#ifndef shadow_EffectTrails_h
#define shadow_EffectTrails_h

#include "ImageEffectInterface.h"
#include "ofxCv.h"

class EffectTrails : public ImageEffectWithGUI {
public:
    ~EffectTrails() {};
    void apply(ofBaseHasPixels& source);
    void initGUI();
    
    void draw();
    
    void execute(string msg_string, float msg_arg);

private:
    //32 bits red, 32 bits green, 32 bits blue, from 0 to 1 in 'infinite' steps
    ofFbo rgbaFboFloat; // with alpha
    ofImage img;
    //ofFloatPixels pixf;
	ofParameter<int> fadeAmnt;

    ofPixels pix;

};


#endif
