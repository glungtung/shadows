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

class EffectsGroup : public ImageEffectInterface {
public:
    EffectsGroup();
    ~EffectsGroup();
    
    void apply(ofPixels & source);
    int drawGUI();
    
    void addEffect(ofPtr<ImageEffectInterface>);
    
private:
    vector< ofPtr <ImageEffectInterface> > effects;
};


#endif
