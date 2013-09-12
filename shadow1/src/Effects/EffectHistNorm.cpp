//
//  EffectHistNorm.cpp
//  shadow
//
//  Created by Guillaume LUNG TUNG on 10/09/13.
//
//

#include "EffectHistNorm.h"

using namespace cv;
using namespace ofxCv;


void EffectHistNorm::initGUI()
{
    addParameter(bNormalize.set("Normalize",FALSE));
    addParameter(histEqualize.set("Equalize histogram",FALSE));
}


void EffectHistNorm::apply(ofBaseHasPixels& source)
{
    if (isActive)
    {
        if (bNormalize)
        {
            normalize(source.getPixelsRef());
        }
        if (histEqualize)
        {
            equalizeHist(source.getPixelsRef());
        }
    }
}

