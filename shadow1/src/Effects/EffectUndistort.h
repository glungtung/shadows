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

class EffectUndistort : public ImageEffectInterface {
public:
    EffectUndistort();
    ~EffectUndistort();
    
    void apply(ofPixels & source);
    int drawGUI();
    
private:
};


#endif
