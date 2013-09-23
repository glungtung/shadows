//
//  EffectContour.cpp
//  shadow
//
//  Created by Guillaume LUNG TUNG on 10/09/13.
//
//

#include "EffectContour.h"
#include "ofConstants.h"
#include "ofEvents.h"

using namespace cv;
using namespace ofxCv;


void EffectContour::init()
{
	contourFinder.setMinAreaRadius(10);
	contourFinder.setMaxAreaRadius(150);
    contourFinder.resetMaxArea();
    //contourFinder.setInvert(true);
}


void EffectContour::apply(ofBaseHasPixels& source)
{    

 //   threshold = ofMap(ofGetMouseX(), 0, ofGetWidth(), 0, 255);
//    contourFinder.setThreshold(threshold);
    contourFinder.findContours(source);
    


}


void EffectContour::draw()
{
    ofSetColor(255,0,0);
	ofSetLineWidth(2);
 //   drawHighlightString(ofToString((int) ofGetFrameRate()) + " fps", 10, 10);
//	drawHighlightString(ofToString((int) threshold) + " threshold", 10, 30);
    ofPushMatrix();
    ofTranslate(640,0);

    ofImage wings;
    wings.loadImage("wingsRight.jpg");
    for(int i = 0; i < (int)contourFinder.getPolylines().size(); i++) {

        //    float largeur = contourFinder.getBoundingRect(0).width*2;
        //    float hauteur = largeur * wings.height / wings.width;
   //     wings.draw(contourFinder.getCentroid(0).x, contourFinder.getCentroid(0).y);
    }
    

    ofPopMatrix();
    
}