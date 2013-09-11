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
    for(vector<ofPtr <ImageEffectInterface> >::iterator it = effects.begin(); it != effects.end(); it++) {
        (*it)->init();
    }
}

void EffectsGroup::apply(ofBaseHasPixels& source)
{
    for(vector<ofPtr <ImageEffectInterface> >::iterator it = effects.begin(); it != effects.end(); it++) {
        (*it)->apply(source);
    }
}

void EffectsGroup::drawGUI()
{
    
}

void EffectsGroup::addEffect(ofPtr<ImageEffectInterface> effect) {
    if (effect)
    {
        cout << "add effect" << std::endl;
        effects.push_back(effect);
    }
}
