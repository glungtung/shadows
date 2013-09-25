//
//  EffectUndistort.h
//  shadow
//
//  Created by Guillaume LUNG TUNG on 10/09/13.
//
//

#ifndef shadow_EffectUndistort_h
#define shadow_EffectUndistort_h

#include "ImageEffectInterface.h"
#include "ofxCv.h"
#include "ofxOpenCv.h"

class EffectUndistort : public ImageEffectWithGUI {
public:
    ~EffectUndistort() {};
    void initGUI();

    void apply(ofBaseHasPixels& source);
    
private:
    ofxCv::Calibration calibration;
	ofParameter<float> radialX, radialY;
    ofxCvGrayscaleImage undistorted;
};


#endif
