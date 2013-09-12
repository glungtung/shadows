//
//  EffectThreshold.cpp
//  shadow
//
//  Created by Guillaume LUNG TUNG on 10/09/13.
//
//

#include "EffectsGroup.h"



EffectsGroup::EffectsGroup()
{
    effects.reserve(10);
}

EffectsGroup::~EffectsGroup()
{
    
}

void EffectsGroup::init()
{
    ImageEffectWithGUI::init();
    addParameter(fps);
    for(vector<ofPtr <ImageEffectInterface> >::iterator it = effects.begin(); it != effects.end(); it++) {
        (*it)->init(this);
    }
    gui.setup(parameters);
}

void EffectsGroup::apply(ofBaseHasPixels& source)
{
    if (isActive)
    {
        for(vector<ofPtr <ImageEffectInterface> >::iterator it = effects.begin(); it != effects.end(); it++) {
            (*it)->apply(source);
        }
    }
}

void EffectsGroup::draw()
{
    //fps.setName(ofToString(ofGetFrameRate()) + "fps");
    fps.set(ofToString((int)ofGetFrameRate()) + "fps");
    gui.draw();
    for(vector<ofPtr <ImageEffectInterface> >::iterator it = effects.begin(); it != effects.end(); it++) {
        (*it)->draw();
    }
}

void EffectsGroup::addEffect(ofPtr<ImageEffectInterface> effect) {
    if (effect)
    {
        effects.push_back(effect);
    }
}
