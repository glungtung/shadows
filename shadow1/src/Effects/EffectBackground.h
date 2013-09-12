//
//  EffectBackground.h
//  shadow
//
//  Created by Guillaume LUNG TUNG on 10/09/13.
//
//

#ifndef shadow_EffectBackground_h
#define shadow_EffectBackground_h

#include "ImageEffectInterface.h"
#include "ofxCv.h"
#include "ofxButton.h"

class EffectBackground : public ImageEffectWithGUI {
public:
    ~EffectBackground() {};
    void apply(ofBaseHasPixels& source);
    void initGUI();
    
    void keyPressed( ofKeyEventArgs & args );
    void keyReleased( ofKeyEventArgs & args ) {};
    
    void backgroundSettingsChanged();
    
private:
	ofParameter<int> learningTime;
    ofParameter<int> thresholdValue;
    ofParameter<bool> ignoreForeground;
    ofParameter<int> differenceMode;
    ofxButton resetBackground;
    
    ofxCv::RunningBackground background;
    ofPixels thresholded;

};


#endif
