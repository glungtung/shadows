//
//  EffectContour.h
//  shadow
//
//  Created by Guillaume LUNG TUNG on 10/09/13.
//
//

#ifndef shadow_EffectContour_h
#define shadow_EffectContour_h

#include "ImageEffectInterface.h"
#include "ofxCv.h"
#include "ofxButton.h"

class EffectContour : public ImageEffectInterface {
public:
    ~EffectContour() {};
    void apply(ofBaseHasPixels& source);
    void init();
    void draw();
    
    ofxCv::ContourFinder contourFinder;
  //  int threshold;


};


#endif
