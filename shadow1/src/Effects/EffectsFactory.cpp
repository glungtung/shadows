//
//  EffectsFactory.cpp
//  shadow
//
//  Created by Guillaume LUNG TUNG on 11/09/13.
//
//

#include "EffectsFactory.h"
#include "EffectConvert2Gray.h"
#include "EffectUndistort.h"
#include "EffectThreshold.h"
#include "EffectContrast.h"


/*
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

}*/

 
ofPtr<ImageEffectInterface>  EffectsFactory::createEffect(string name)
{
    if (name == "ConvertToGray") {
        EffectConvert2Gray *effect =  new EffectConvert2Gray();
        return ofPtr<ImageEffectInterface>(effect);
    }
    else if (name == "Undistort") {
        EffectUndistort *effect = new EffectUndistort();
        return ofPtr<ImageEffectInterface>(effect);
    }
    else if (name == "Threshold") {
        EffectThreshold *effect = new EffectThreshold();
        effect->setName("Cam Threshold");
        return ofPtr<ImageEffectWithGUI>(effect);
    }
    else if (name == "Constrast") {
        EffectContrast *effect = new EffectContrast();
        return ofPtr<ImageEffectInterface>(effect);
    }
    else return ofPtr<ImageEffectInterface>();
  
}
  
