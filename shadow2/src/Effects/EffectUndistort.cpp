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

void EffectUndistort::initGUI()
{
   // calibration.setFillFrame(true); // true by default
	//calibration.load("mbp-2011-isight.yml");
    addParameter(radialX.set("RadialX",0,-0.1,0));
    addParameter(radialY.set("RadialY",0,-0.1,0));
    undistorted.allocate(640, 480);
}

void EffectUndistort::apply(ofBaseHasPixels& source)
{
    if (isActive && (source.getPixelsRef().getNumChannels() == 1))
    {
        //calibration.undistort(toCv(source));
        undistorted.setFromPixels(source.getPixelsRef());
        undistorted.undistort( radialX, radialY, 0, 0, 200, 200, undistorted.getWidth()/2, undistorted.getHeight()/2 );
        source.getPixelsRef() = undistorted.getPixelsRef();
    }
}


