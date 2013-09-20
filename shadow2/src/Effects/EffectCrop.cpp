//
//  EffectCrop.cpp
//  shadow
//
//  Created by Guillaume LUNG TUNG on 10/09/13.
//
//

#include "EffectCrop.h"

using namespace cv;
using namespace ofxCv;


void EffectCrop::initGUI()
{
    addParameter(cropX.set("x",0,0,640));
    addParameter(cropY.set("y",0,0,480));
    addParameter(cropWidth.set("width",640,0,640));
    addParameter(cropHeight.set("height",480,0,480));
}


void EffectCrop::apply(ofBaseHasPixels& source)
{
    if (isActive)
    {
        if (cropX < cropWidth && cropY < cropHeight)
        {
            
            source.getPixelsRef().crop(cropX, cropY, cropWidth - cropX, cropHeight - cropY);
            source.getPixelsRef().resize(640,480);
        }
    }
}

