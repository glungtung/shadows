//
//  EffectThreshold.cpp
//  shadow
//
//  Created by Guillaume LUNG TUNG on 10/09/13.
//
//

#include "EffectThreshold.h"

using namespace cv;
using namespace ofxCv;


void EffectThreshold::initGUI()
{
    addParameter(automatic.set("Automatic",true));
	addParameter(thresholdValue.set("Thresh value",100,0,255));
}


void EffectThreshold::apply(ofBaseHasPixels& source)
{
    if (isActive)
    {
        if (source.getPixelsRef().getImageType() == OF_IMAGE_GRAYSCALE)
        {
            if (automatic)
                autothreshold(source.getPixelsRef());
            else
                threshold(source.getPixelsRef(), thresholdValue);

        }
    }
}

