//
//  EffectMirror.cpp
//  shadow
//
//  Created by Guillaume LUNG TUNG on 10/09/13.
//
//

#include "EffectMirror.h"



void EffectMirror::init()
{
    addParameter(flipVertical.set("vertical", false));
    addParameter(flipHorizontal.set("horizontal", false));
    mirror.allocate(640,480);
}

void EffectMirror::apply(ofBaseHasPixels& source)
{
    if (source.getPixelsRef().getImageType() == OF_IMAGE_GRAYSCALE)
    {
        mirror.setFromPixels(source.getPixelsRef());
        mirror.mirror(flipVertical, flipHorizontal);
        source.getPixelsRef() = mirror.getPixelsRef();
    }
}

//--------------------------------------------------------------
void EffectMirror::execute(string msg_string, float msg_arg)
{

    if (msg_string == "/shadow/effect/mirror/horizontal")
    {
        flipHorizontal.set((msg_arg == 1.0)?true:false);
    }
    if (msg_string == "/shadow/effect/mirror/vertical")
    {
        flipVertical.set((msg_arg == 1.0)?true:false);
    }
}
