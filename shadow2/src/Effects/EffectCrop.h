//
//  EffectCrop.h
//  shadow
//
//  Created by Guillaume LUNG TUNG on 10/09/13.
//
//

#ifndef shadow_EffectCrop_h
#define shadow_EffectCrop_h

#include "ImageEffectInterface.h"
#include "ofxCv.h"

class EffectCrop : public ImageEffectWithGUI {
public:
    ~EffectCrop() {};
    void apply(ofBaseHasPixels& source);
    void initGUI();
    
private:
	ofParameter<int> cropX, cropY, cropWidth, cropHeight;    
};


#endif
