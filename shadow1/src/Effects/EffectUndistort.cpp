//
//  EffectUndistort.cpp
//  shadow
//
//  Created by Guillaume LUNG TUNG on 10/09/13.
//
//

#include "EffectUndistort.h"

using namespace cv;
using namespace ofxCv;

void EffectUndistort::init()
{
    std::cout << "EffectUndistort::init()" << std::endl;
    calibration.setFillFrame(true); // true by default
	calibration.load("mbp-2011-isight.yml");
}

void EffectUndistort::apply(ofBaseHasPixels& source)
{
    calibration.undistort(toCv(source));
}


