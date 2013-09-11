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


void EffectThreshold::apply(ofBaseHasPixels& source)
{
    if (source.getPixelsRef().getImageType() == OF_IMAGE_GRAYSCALE)
        autothreshold(source.getPixelsRef());
}

void EffectThreshold::drawGUI()
{
    
}