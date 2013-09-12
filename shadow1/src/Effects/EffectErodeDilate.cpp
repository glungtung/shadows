//
//  EffectErodeDilate.cpp
//  shadow
//
//  Created by Guillaume LUNG TUNG on 10/09/13.
//
//

#include "EffectErodeDilate.h"

using namespace cv;
using namespace ofxCv;


void EffectErodeDilate::initGUI()
{
    addParameter(erodeIterations.set("Erode num iterations",0,0,10));
    addParameter(dilateIterations.set("Dilate num iterations",0,0,10));
    addParameter(dilateFirst.set("Dilate first",FALSE));
}


void EffectErodeDilate::apply(ofBaseHasPixels& source)
{
    if (isActive)
    {
        if (dilateFirst == false)
        {
            erode(source.getPixelsRef(), source.getPixelsRef(), erodeIterations);
            dilate(source.getPixelsRef(), source.getPixelsRef(), dilateIterations);
        }
        else
        {
            dilate(source.getPixelsRef(), source.getPixelsRef(), dilateIterations);
            erode(source.getPixelsRef(), source.getPixelsRef(), erodeIterations);
        }
    }
}

