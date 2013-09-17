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
#include "ofParameterGroup.h"
#include "ofParameter.h"

class ImageEffectInterface {
public:
    virtual ~ImageEffectInterface() {};
    virtual void init() { };
    inline virtual void init(ImageEffectInterface *parent) {init(); }
    virtual void draw() {};
    virtual void exit() {};
    virtual void apply(ofBaseHasPixels& source) = 0;
};

class ImageEffectWithGUI : public ImageEffectInterface {
public:
    virtual ~ImageEffectWithGUI() {};
    virtual void init() {
        addParameter(isActive.set("Active",true));
        initGUI();
    }
    virtual void init(ImageEffectInterface *parent) {
        init();
        ImageEffectWithGUI * p;
        p = (ImageEffectWithGUI *)(parent);
        p->addParameter(parameters);
    }
    virtual void draw() {};
    virtual void initGUI() {};
//    inline virtual void setActive(bool b) { isActive = b; }
    
    inline void addParameter(ofAbstractParameter & param) { parameters.add(param); }
    inline void setName(string name) {parameters.setName(name);}

    ofParameterGroup parameters;
    ofParameter<bool> isActive;

};


	



#endif
