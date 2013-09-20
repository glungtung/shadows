//
//  EffectBackgroundSimple.cpp
//  shadow
//
//  Created by Guillaume LUNG TUNG on 10/09/13.
//
//

#include "EffectBackgroundSimple.h"
#include "ofConstants.h"
#include "ofEvents.h"

using namespace cv;
using namespace ofxCv;


void EffectBackgroundSimple::initGUI()
{
    ofRegisterKeyEvents(this);
	addParameter(differenceMode.set("diff ABSDIFF/BRIGHTER/DARKER",0,0,2));
    bLearnBackground = true;
}


void EffectBackgroundSimple::apply(ofBaseHasPixels& source)
{
    if (isActive )
    {
        if (bLearnBackground)
        {
            background.setFromPixels(source.getPixelsRef());
            bLearnBackground = false;
        }
        
        foreground.setFromPixels(source.getPixelsRef());
		switch(differenceMode) {
			case 0: foreground.absDiff(background); break;
			case 1: foreground -= background; break;
//			case 2: foreground = background - foreground; break;
		}
        
        invert(foreground);
        source.getPixelsRef() = foreground.getPixelsRef();
    }
}



void EffectBackgroundSimple::keyPressed(ofKeyEventArgs & args) {
	if(args.key  == 'r') {
        bLearnBackground = true;
    }
}

