//
//  EffectErodeDilate.h
//  shadow
//
//  Created by Guillaume LUNG TUNG on 10/09/13.
//
//

#ifndef shadow_EffectErodeDilate_h
#define shadow_EffectErodeDilate_h

#include "ImageEffectInterface.h"
#include "ofxCv.h"

class EffectErodeDilate : public ImageEffectWithGUI {
public:
    ~EffectErodeDilate() {};
    void apply(ofBaseHasPixels& source);
    void initGUI();
    
private:
	ofParameter<int> erodeIterations;
    ofParameter<int> dilateIterations;
    ofParameter<bool>dilateFirst;
};


#endif
