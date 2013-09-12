//
//  EffectHistNorm.h
//  shadow
//
//  Created by Guillaume LUNG TUNG on 10/09/13.
//
//

#ifndef shadow_EffectHistNorm_h
#define shadow_EffectHistNorm_h

#include "ImageEffectInterface.h"
#include "ofxCv.h"

class EffectHistNorm : public ImageEffectWithGUI {
public:
    ~EffectHistNorm() {};
    void apply(ofBaseHasPixels& source);
    void initGUI();
    
private:
    ofParameter<bool>bNormalize;
    ofParameter<bool>histEqualize;
};


#endif
