//
//  ImageEffectWithGUI.h
//  shadow
//
//  Created by Guillaume LUNG TUNG on 07/09/13.
//
//

#ifndef shadow_ImageEffectWithGUI_h
#define shadow_ImageEffectWithGUI_h

#include "ofMain.h"

class ImageEffectInterface {
public:
    virtual ~ImageEffectInterface() {};
    virtual void init() {};
    virtual void draw() {};
    virtual void exit() {};
    virtual void apply(ofBaseHasPixels& source) = 0;
};

class ImageEffectWithGUI : public ImageEffectInterface {
public:
    virtual ~ImageEffectWithGUI() {};
    virtual void draw() {drawGUI();}
    virtual void drawGUI() {};
    virtual void setActive(bool b) { isActive = b; }
private:
    bool isActive;
    string name;
    
};

#endif
