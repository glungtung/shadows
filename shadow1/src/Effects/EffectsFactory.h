//
//  EffectsFactory.h
//  shadow
//
//  Created by Guillaume LUNG TUNG on 11/09/13.
//
//

#ifndef shadow_EffectsFactory_h
#define shadow_EffectsFactory_h

#include "ofMain.h"
#include "ImageEffectInterface.h"
#include "EffectUndistort.h"
#include "EffectThreshold.h"
#include "EffectConvert2Gray.h"
#include "EffectContrast.h"


class EffectsFactory {
public:
    ofPtr<ImageEffectInterface> createEffect(string name);
};

#endif
