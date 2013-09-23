//
//  SingleImageRecorder.cpp
//  shadow
//
//  Created by Guillaume LUNG TUNG on 15/09/13.
//
//

#include "SingleImageRecorder.h"
#include "ofxOpenCv.h"

SingleImageRecorder::SingleImageRecorder()
{


}

SingleImageRecorder::SingleImageRecorder(ofPixels &p)
{
    //SingleImageRecorder::SingleImageRecorder();
    isVisible = true;
    bIsRecording = false;
    brightness = 0;
    
    record(p);
    
}

void SingleImageRecorder::record(ofPixels &p)
{
    pixels = p;
    bIsRecording = false;
}

void SingleImageRecorder::clear()
{
    pixels.clear();
}

void SingleImageRecorder::draw(int x, int y, int width, int height)
{
    if (pixels.isAllocated())
    {

        if (width == 0) width = pixels.getWidth();
        if (height == 0) height = pixels.getHeight();
            
/*        ofTexture tex;
        tex.loadData(pixels);
        tex.draw(x,y,ofGetWidth(),ofGetHeight());*/
/*        ofImage img;
        img.setFromPixels(pixels);
        img.draw(x,y,ofGetWidth(),ofGetHeight());*/
        ofxCvGrayscaleImage gray;
        gray.allocate(pixels.getWidth(), pixels.getHeight());
        gray.setFromPixels(pixels);
        if (brightness != 0)
            gray.brightnessContrast(brightness/100., 0);
        gray.draw(x,y,ofGetWidth(),ofGetHeight());
    }
}

void SingleImageRecorder::keyPressed(int key)
{
    if (key == ' ')
        bIsRecording = true;
}

unsigned char * SingleImageRecorder::getPixels() {
    return pixels.getPixels();
}

ofPixels & SingleImageRecorder::getPixelsRef() {
    return pixels;
}