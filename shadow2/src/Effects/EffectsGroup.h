//
//  EffectThreshold.h
//  shadow
//
//  Created by Guillaume LUNG TUNG on 10/09/13.
//
//

#ifndef shadow_EffectsGroup_h
#define shadow_EffectsGroup_h

#include "ImageEffectInterface.h"
#include "ofxGui.h"

class EffectsGroup : public ImageEffectWithGUI {
public:
    EffectsGroup();
    ~EffectsGroup();
    
    void init();
    void apply(ofBaseHasPixels& source);
    
    void addEffect(ofPtr<ImageEffectInterface>);
    
    void draw();
    
private:
    vector< ofPtr <ImageEffectInterface> > effects;
    ofxPanel gui;
    ofParameter<string> fps;
};


#endif
