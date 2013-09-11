//
//  EffectContrast.h
//  shadow
//
//  Created by Guillaume LUNG TUNG on 10/09/13.
//
//

#ifndef shadow_EffectContrast_h
#define shadow_EffectContrast_h

#include "ImageEffectInterface.h"

class EffectContrast : public ImageEffectInterface {
public:
    ~EffectContrast();
    void apply(ofBaseHasPixels& source);
    int drawGUI();
    
private:
    
};


#endif
