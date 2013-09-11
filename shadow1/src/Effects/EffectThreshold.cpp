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

EffectThreshold::EffectThreshold()
{
    
}

EffectThreshold::~EffectThreshold()
{
    
}

void EffectThreshold::apply(ofPixels & source)
{
    if (source.getImageType() == OF_IMAGE_GRAYSCALE)
        autothreshold(source);
}

int EffectThreshold::drawGUI()
{
    
}