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
#include "EffectContour.h"
#include "EffectCrop.h"
#include "EffectBackgroundSimple.h"
#include "EffectTrails.h"
#include "EffectMirror.h"
#include "EffectVignette.h"
 
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
    else if (name == "Contour") {
        EffectContour *effect = new EffectContour();
        return ofPtr<ImageEffectInterface>(effect);
    }
    else if (name == "Crop") {
        EffectCrop *effect = new EffectCrop();
        effect->setName("Crop");
        return ofPtr<ImageEffectWithGUI>(effect);
    }
    else if (name == "BackgroundSimple") {
        EffectBackgroundSimple *effect = new EffectBackgroundSimple();
        return ofPtr<ImageEffectInterface>(effect);
    }
    else if (name == "Trails") {
        EffectTrails *effect = new EffectTrails();
        effect->setName("Trails");
        return ofPtr<ImageEffectWithGUI>(effect);
    }
    else if (name == "Mirror") {
        EffectMirror *effect = new EffectMirror();
        effect->setName("Mirror");
        return ofPtr<ImageEffectWithGUI>(effect);
    }
    else if (name == "Vignette") {
        EffectVignette *effect = new EffectVignette();
        effect->setName("Vignette");
        return ofPtr<ImageEffectWithGUI>(effect);
    }
    else return ofPtr<ImageEffectInterface>();
  
}
  
