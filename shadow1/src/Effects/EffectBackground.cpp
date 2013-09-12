//
//  EffectBackground.cpp
//  shadow
//
//  Created by Guillaume LUNG TUNG on 10/09/13.
//
//

#include "EffectBackground.h"
#include "ofConstants.h"
#include "ofEvents.h"

using namespace cv;
using namespace ofxCv;


void EffectBackground::initGUI()
{
    ofRegisterKeyEvents(this);
   // ofAddListener(ofEvents().keyPressed, this, &EffectBackground::keyPressed);
/*    learningTime.addListener(this, &EffectBackground::backgroundSettingsChanged);
    thresholdValue.addListener(this, &EffectBackground::backgroundSettingsChanged);
    ignoreForeground.addListener(this, &EffectBackground::backgroundSettingsChanged);
    differenceMode.addListener(this, &EffectBackground::backgroundSettingsChanged);
*/
	addParameter(learningTime.set("Learning time",900,0,1800));
    addParameter(thresholdValue.set("Thresh value",25,0,255));
    addParameter(ignoreForeground.set("Ignore foreground",FALSE));
	addParameter(differenceMode.set("diff ABSDIFF/BRIGHTER/DARKER",0,0,2));
}


void EffectBackground::apply(ofBaseHasPixels& source)
{
    if (isActive)
    {
        backgroundSettingsChanged();
		background.update(source.getPixelsRef(), thresholded);
        source.getPixelsRef() = thresholded;
    }
}


void EffectBackground::backgroundSettingsChanged() {
    background.setLearningTime(learningTime);
    background.setThresholdValue(thresholdValue);
    background.setIgnoreForeground(ignoreForeground);
    switch (differenceMode) {
        case 0:
            background.setDifferenceMode(background.ABSDIFF);
            break;
        case 1:
            background.setDifferenceMode(background.BRIGHTER);
            break;
        case 2:
            background.setDifferenceMode(background.DARKER);
            break;
        default:
            break;
    }    
}

void EffectBackground::keyPressed(ofKeyEventArgs & args) {
	if(args.key  == ' ') {
		background.reset();
	}
}

