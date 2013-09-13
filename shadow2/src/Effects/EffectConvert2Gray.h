//
//  EffectConvert2Gray.h
//  shadow
//
//  Created by Guillaume LUNG TUNG on 10/09/13.
//
//

#ifndef shadow_EffectConvert2Gray_h
#define shadow_EffectConvert2Gray_h

#include "ImageEffectInterface.h"
#include "ofxCv.h"

class EffectConvert2Gray : public ImageEffectInterface {
public:
    ~EffectConvert2Gray() {};
    void apply(ofBaseHasPixels& source);
};


#endif
