//
//  EffectThreshold.h
//  shadow
//
//  Created by Guillaume LUNG TUNG on 10/09/13.
//
//

#ifndef shadow_EffectThreshold_h
#define shadow_EffectThreshold_h

#include "ImageEffectInterface.h"
#include "ofxCv.h"

class EffectThreshold : public ImageEffectInterface {
public:
    EffectThreshold();
    ~EffectThreshold();
    
    void apply(ofPixels & source);
    int drawGUI();
    
private:
    int thresholdValue;
};


#endif
