//
//  EffectsFactory.cpp
//  shadow
//
//  Created by Guillaume LUNG TUNG on 11/09/13.
//
//

#include "EffectsFactory.h"



ofPtr<ImageEffectInterface>  EffectsFactory::createEffect(string name)
{
    if (name == "ConvertToGray") {
         return ofPtr<ImageEffectInterface>(new EffectConvert2Gray());
    }
    else if (name == "Undistort") {
        return ofPtr<ImageEffectInterface>(new EffectUndistort());
    }
    else if (name == "Threshold") {
        return ofPtr<ImageEffectWithGUI>(new EffectThreshold());
    }
    else if (name == "Constrast") {
        return ofPtr<ImageEffectInterface>(new EffectContrast());
    }
    else return ofPtr<ImageEffectInterface>();

}