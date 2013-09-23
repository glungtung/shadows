//
//  EffectMirror.h
//  shadow
//
//  Created by Guillaume LUNG TUNG on 10/09/13.
//
//

#ifndef shadow_EffectMirror_h
#define shadow_EffectMirror_h

#include "ImageEffectInterface.h"
#include "ofxOpenCv.h"

class EffectMirror : public ImageEffectWithGUI {
public:
    ~EffectMirror() {};
    void init();
    void apply(ofBaseHasPixels& source);
    
    ofxCvGrayscaleImage mirror;
    ofParameter<bool> flipVertical, flipHorizontal;

};


#endif
