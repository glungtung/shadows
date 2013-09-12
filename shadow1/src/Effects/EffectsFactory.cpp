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
#include "EffectErodeDilate.h"
#include "EffectHistNorm.h"
#include "EffectBackground.h"

 
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
    else if (name == "ErodeDilate") {
        EffectErodeDilate *effect = new EffectErodeDilate();
        effect->setName("Erode and Dilate");
        return ofPtr<ImageEffectWithGUI>(effect);
    }
    else if (name == "Equalize") {
        EffectHistNorm *effect = new EffectHistNorm();
        effect->setName("Equalize");
        return ofPtr<ImageEffectWithGUI>(effect);
    }
    else if (name == "Background") {
        EffectBackground *effect = new EffectBackground();
        effect->setName("Background");
        return ofPtr<ImageEffectWithGUI>(effect);
    }
    else return ofPtr<ImageEffectInterface>();
  
}
  
