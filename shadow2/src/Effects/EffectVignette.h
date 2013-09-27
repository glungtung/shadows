//
//  EffectVignette.h
//  shadow
//
//  Created by Guillaume LUNG TUNG on 10/09/13.
//
//

#ifndef shadow_EffectVignette_h
#define shadow_EffectVignette_h

#include "ImageEffectInterface.h"
#include "ofxCv.h"

class EffectVignette : public ImageEffectWithGUI {
public:
    ~EffectVignette() {};
    void apply(ofBaseHasPixels& source);
    void initGUI();
    
    void draw();
    
    void execute(string msg_string, float msg_arg);

private:
    //32 bits red, 32 bits green, 32 bits blue, from 0 to 1 in 'infinite' steps
    ofFbo fbo; // with alpha
    ofImage img, vignette;
    //ofFloatPixels pixf;
	ofParameter<int> scale;

    ofPixels pix;

};


#endif
