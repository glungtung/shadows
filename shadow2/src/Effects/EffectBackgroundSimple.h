//
//  EffectBackgroundSimple.h
//  shadow
//
//  Created by Guillaume LUNG TUNG on 10/09/13.
//
//

#ifndef shadow_EffectBackgroundSimple_h
#define shadow_EffectBackgroundSimple_h

#include "ImageEffectInterface.h"
#include "ofxCv.h"
#include "ofxOpenCv.h"

class EffectBackgroundSimple : public ImageEffectWithGUI {
public:
    ~EffectBackgroundSimple() {};
    void apply(ofBaseHasPixels& source);
    void initGUI();
    
    void keyPressed( ofKeyEventArgs & args );
    void keyReleased( ofKeyEventArgs & args ) {};
        
private:
    ofParameter<int> differenceMode;
   // ofPixels background;
    bool bLearnBackground;
   // ofPixels foreground;

    ofxCvGrayscaleImage background, foreground;
};


#endif
