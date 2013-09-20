//
//  SingleImageRecorder.cpp
//  shadow
//
//  Created by Guillaume LUNG TUNG on 15/09/13.
//
//

#include "SingleImageRecorder.h"

SingleImageRecorder::SingleImageRecorder()
{
    isVisible = true;
    bIsRecording = false;
}

SingleImageRecorder::SingleImageRecorder(ofPixels &p)
{
    SingleImageRecorder();
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
        
        ofTexture tex;
        tex.loadData(pixels);
        tex.draw(x,y,ofGetWidth(),ofGetHeight());
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