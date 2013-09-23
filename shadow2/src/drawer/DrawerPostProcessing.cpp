//
//  DrawerPostProcessing.cpp
//  shadow
//
//  Created by Guillaume LUNG TUNG on 22/09/13.
//
//

#include "DrawerInterface.h"


drawerPostProcessing::drawerPostProcessing(DrawerManager *m)
{
    //init();
    manager = m;
    

}

void drawerPostProcessing::init()
{
   // ofSetCoordHandedness(OF_RIGHT_HANDED);
    // Setup post-processing chain
    post.init(ofGetWidth(), ofGetHeight());
    
    //post.passes.clear();
    post.createPass<FxaaPass>()->setEnabled(false);
    post.createPass<BloomPass>()->setEnabled(false);
    post.createPass<DofPass>()->setEnabled(false);
    post.createPass<KaleidoscopePass>()->setEnabled(false);
    post.createPass<NoiseWarpPass>()->setEnabled(false);
    post.createPass<PixelatePass>()->setEnabled(false);
    post.createPass<EdgePass>()->setEnabled(false);

}

void drawerPostProcessing::update(ofBaseHasPixels& source)
{
    tex.loadData(source.getPixelsRef());
}

void drawerPostProcessing::draw(int x, int y, int width, int height)
{
    ofEnableAlphaBlending();
    post.begin();
    tex.draw(x,y,width,height);
    post.end();
    ofDisableAlphaBlending();
}

void drawerPostProcessing::execute(string msg_string, float msg_arg)
{
    bool bOn = (msg_arg == 1.0)?true:false;
    if (msg_string == "/shadow/drawer/postprocessing/fxaa/switch")
        post[0]->setEnabled(bOn);
    if (msg_string == "/shadow/drawer/postprocessing/bloom/switch")
        post[1]->setEnabled(bOn);
    if (msg_string == "/shadow/drawer/postprocessing/dof/switch")
        post[2]->setEnabled(bOn);
    if (msg_string == "/shadow/drawer/postprocessing/kaleido/switch")
        post[3]->setEnabled(bOn);
    if (msg_string == "/shadow/drawer/postprocessing/wrap/switch")
        post[4]->setEnabled(bOn);
    if (msg_string == "/shadow/drawer/postprocessing/pixel/switch")
        post[5]->setEnabled(bOn);
    if (msg_string == "/shadow/drawer/postprocessing/edge/switch")
        post[6]->setEnabled(bOn);
    
}