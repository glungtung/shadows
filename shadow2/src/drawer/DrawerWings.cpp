//
//  drawerBasic.cpp
//  shadow
//
//  Created by Guillaume LUNG TUNG on 22/09/13.
//
//

#include "DrawerInterface.h"

using namespace ofxCv;
using namespace cv;

void drawerWings::init()
{
    contourFinder.setMinAreaRadius(50);
	//contourFinder.setMaxAreaRadius(150);
    contourFinder.resetMaxArea();
    contourFinder.setInvert(true);
    graySource.setROI(100,100,450,350);
    
    wingsL.loadImage("wingsRight2.jpg");
    wingsR.loadImage("wingsLeft2.jpg");


    fbo.allocate(640, 480, GL_LUMINANCE);
    fbo.begin();
	ofClear(255,255,255, 0);
    fbo.end();
}

void drawerWings::update(ofBaseHasPixels& source)
{
    graySource.setFromPixels(source.getPixelsRef());
    
    int   threshold = ofMap(ofGetMouseX(), 0, ofGetWidth(), 0, 255);
        contourFinder.setThreshold(threshold);
    contourFinder.findContours(graySource);
    

}

void drawerWings::draw(int x, int y, int width, int height)
{
    fbo.begin();
	ofClear(255,255,255, 0);

    int   threshold = abs(ofMap(ofGetMouseX(), 0, ofGetWidth(), 0, 255));
    graySource.draw(x,y,width,height);
    for(int i = 0; i < (int)contourFinder.getPolylines().size(); i++) {
        ofSetColor(255,0,0);
        ofSetLineWidth(2);
        
        //convexHull(contourFinder.getPolyline(i).getResampledBySpacing(threshold)).draw() ;
        //contourFinder.
        
        // convex hull of the contour
		ofSetColor(yellowPrint);
		ofPolyline convexHull = toOf(contourFinder.getConvexHull(i));
		convexHull.draw();
		
        //ofSetColor(0,0,255);
		// defects of the convex hull
		//vector<cv::Vec4i> defects = contourFinder.getConvexityDefects(i);
		//for(int j = 0; j < defects.size(); j++) {
		//	ofLine(defects[j][0], defects[j][1], defects[j][2], defects[j][3]);
		//}
		
		// some different styles of contour centers
		ofVec2f centroid = toOf(contourFinder.getCentroid(i));
		//ofVec2f average = toOf(contourFinder.getAverage(i));
		//ofVec2f center = toOf(contourFinder.getCenter(i));
		ofSetColor(cyanPrint);
		ofCircle(centroid, 5);
        
        //const vector<ofPoint> convex = convexHull.getVertices();
        
        ofPoint left, right;
        left.set(convexHull.getPointAtPercent(0));
        right.set(convexHull.getPointAtPercent(0));
        for (float j = 0; j < 1.0; j+=0.01)
        {
            if (convexHull.getPointAtPercent(j).x < left.x)
                left.set(convexHull.getPointAtPercent(j));
            if (convexHull.getPointAtPercent(j).x > right.x)
                right.set(convexHull.getPointAtPercent(j));
            cout << convexHull.getPointAtPercent(j).x << endl;
        }
        ofSetColor(255,0,0);
        ofLine(left.x, left.y, centroid.x, centroid.y);
        ofSetColor(0,255,0);
        ofLine(centroid.x, centroid.y, right.x, right.y);

        ofSetColor(255);
        
        int leftAngle = ofRadToDeg( atan2(  left.y - centroid.y, left.x - centroid.x ) ) ;
        int rightAngle = ofRadToDeg( atan2( centroid.y - right.y, centroid.x - right.x ) );
       // cout << left.x << " : " << right.x << endl;
 
        ofEnableBlendMode(OF_BLENDMODE_DARKEN);
        ofPushMatrix();
        ofTranslate(centroid.x, centroid.y);
        ofRotate(leftAngle);
        wingsL.setAnchorPercent(0.0, 0.5);
        wingsL.draw(0,0);
        ofPopMatrix();
        //ofSetColor(0,255,255);
        ofPushMatrix();
        ofTranslate(centroid.x, centroid.y);
        ofRotate(rightAngle);
        wingsR.setAnchorPercent(1.0, 0.5);
        wingsR.draw(0,0);
        ofPopMatrix();

        //cout << ofToString( ofVec2f(0,1).angle(ofVec2f(left.distance(centroid))) ) << endl;
//        wings.draw(centroid, <#float w#>, <#float h#>)
		//ofSetColor(magentaPrint);
		//ofCircle(average, 5);
		//ofSetColor(yellowPrint);
		//ofCircle(center, 5);
		
		// you can also get the area and perimeter using ofPolyline:
		// ofPolyline::getArea() and ofPolyline::getPerimeter()
		//double area = contourFinder.getContourArea(i);
		//double length = contourFinder.getArcLength(i);
		
		// balance is useful for detecting when a shape has an "arm" sticking out
		// if balance.length() is small, the shape is more symmetric: like I, O, X...
		// if balance.length() is large, the shape is less symmetric: like L, P, F...
		//ofVec2f balance = toOf(contourFinder.getBalance(i));
		//ofPushMatrix();
		//ofTranslate(centroid.x, centroid.y);
		//ofScale(5, 5);
        //ofSetColor(ofColor::green);
		//ofLine(0, 0, balance.x, balance.y);
		//ofPopMatrix();

        
        
        //    float largeur = contourFinder.getBoundingRect(0).width*2;
        //    float hauteur = largeur * wings.height / wings.width;
        //     wings.draw(contourFinder.getCentroid(0).x, contourFinder.getCentroid(0).y);
    }
    
    fbo.end();
    
    fbo.readToPixels(pix);
    
 /*   if (pix.getPixelsRef().getImageType() != OF_IMAGE_GRAYSCALE)
    {
        convertColor( pix, pix, CV_RGB2GRAY);
    }
   */
    pix.resize(width, height);
    pix.draw(0,0,width,height);
}

