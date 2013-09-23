//
//  EffectConvert2Gray.cpp
//  shadow
//
//  Created by Guillaume LUNG TUNG on 10/09/13.
//
//

#include "EffectConvert2Gray.h"

using namespace cv;
using namespace ofxCv;

void EffectConvert2Gray::init()
{
    pix.allocate(640,480, 1);
    
}


void EffectConvert2Gray::apply(ofBaseHasPixels& source)
{
    if (source.getPixelsRef().getImageType() != OF_IMAGE_GRAYSCALE)
    {
        convertColor(source.getPixelsRef(), pix, CV_RGB2GRAY);
        source.getPixelsRef() = pix; // DANGER ??
    }
}

