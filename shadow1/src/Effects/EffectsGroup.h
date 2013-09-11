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

class EffectsGroup : public ImageEffectWithGUI {
public:
    EffectsGroup();
    ~EffectsGroup();
    
    void apply(ofBaseHasPixels& source);
    void drawGUI();
    
    void addEffect(ofPtr<ImageEffectWithGUI>);
    
private:
    vector< ofPtr <ImageEffectWithGUI> > effects;
};


#endif
