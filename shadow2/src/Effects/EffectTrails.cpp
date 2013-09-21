//
//  EffectTrails.cpp
//  shadow
//
//  Created by Guillaume LUNG TUNG on 10/09/13.
//
//

#include "EffectTrails.h"

using namespace cv;
using namespace ofxCv;


void EffectTrails::initGUI()
{
    addParameter(fadeAmnt.set("Fade",10,0,250));

    rgbaFboFloat.allocate(640, 480, GL_RGBA32F_ARB);
    rgbaFboFloat.begin();
	ofClear(255,255,255, 0);
    rgbaFboFloat.end();
    img.allocate(640,480, OF_IMAGE_GRAYSCALE);
    isActive.set(false);
}


void EffectTrails::apply(ofBaseHasPixels& source)
{
    if (isActive)
    {
        rgbaFboFloat.begin();
        ofEnableAlphaBlending();
        ofFill();
        ofSetColor(255,255,255, fadeAmnt);
        ofRect(0,0,640,480);
        ofDisableAlphaBlending();
        ofEnableBlendMode(OF_BLENDMODE_DARKEN);
        ofSetColor(255);
        img.setFromPixels(source.getPixelsRef());
        img.draw(0,0);
        
        rgbaFboFloat.end();
        
        rgbaFboFloat.readToPixels(pixf);
        source.getPixelsRef() = pixf;
    }
}

void EffectTrails::draw()
{
   // rgbaFboFloat.draw(0,0);
    
}

void EffectTrails::execute(string msg_string, float msg_arg)
{
    if (msg_string == "/shadow/effects/trails/switch")
    {
        if (msg_arg == 0.0)
            isActive.set(false);
        else
            isActive.set(true);
    }
    
    if (msg_string == "/shadow/effects/trails/amnt")
    {
        fadeAmnt.set(int(msg_arg));
    }
}