//
//  ImageEffectInterface.h
//  shadow
//
//  Created by Guillaume LUNG TUNG on 07/09/13.
//
//

#ifndef shadow_ImageEffectInterface_h
#define shadow_ImageEffectInterface_h

#include "ofMain.h"

class ImageEffectInterface {
public:
    virtual void apply(ofPixels & source) = 0;
    virtual int drawGUI() = 0;
    virtual void setActive(bool b) { isActive = b; }
private:
    bool isActive;
    
};

#endif
