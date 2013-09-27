//
//  EffectVignette.cpp
//  shadow
//
//  Created by Guillaume LUNG TUNG on 10/09/13.
//
//

#include "EffectVignette.h"

using namespace cv;
using namespace ofxCv;


void EffectVignette::initGUI()
{
    addParameter(scale.set("Fade",2,2,50));

    vignette.allocate(640,480, OF_IMAGE_GRAYSCALE);
    vignette.loadImage("vignette.jpg");

    //    rgbaFboFloat.allocate(640, 480, GL_RGBA32F_ARB);
    fbo.allocate(640, 480, GL_RGB);
    fbo.begin();
	ofClear(255,255,255, 0);
    vignette.draw(0,0);
    fbo.end();
    img.allocate(640,480, OF_IMAGE_GRAYSCALE);
    isActive.set(true);
    
    pix.allocate(640,480, 1);

}


void EffectVignette::apply(ofBaseHasPixels& source)
{
    if (isActive)
    {
        fbo.begin();
        ofClear(255,255,255, 0);
        vignette.draw(0,0);

  //      ofEnableAlphaBlending();
  //      ofFill();
  //      ofSetColor(255,255,255);
  //      vignette.draw(0,0);
        ofEnableBlendMode(OF_BLENDMODE_DARKEN);
        ofSetColor(255);
        img.setFromPixels(source.getPixelsRef());
        img.draw(0,0);
        
        fbo.end();
        
        //rgbaFboFloat.readToPixels(pixf);
        //source.getPixelsRef() = pixf;
        fbo.readToPixels(source.getPixelsRef());
        
        if (source.getPixelsRef().getImageType() != OF_IMAGE_GRAYSCALE)
        {
            convertColor(source.getPixelsRef(), pix, CV_RGB2GRAY);
            source.getPixelsRef() = pix; 
        }
    }
}

void EffectVignette::draw()
{
   // rgbaFboFloat.draw(0,0);
    
}

void EffectVignette::execute(string msg_string, float msg_arg)
{
    if (msg_string == "/shadow/effects/vignette/switch")
    {
        if (msg_arg == 0.0)
            isActive.set(false);
        else
        {
            isActive.set(true);
            fbo.begin();
            ofClear(255,255,255, 0);
            fbo.end();
        }
    }
    
    if (msg_string == "/shadow/effects/vignette/scale")
    {
        scale.set(int(msg_arg));
    }
}