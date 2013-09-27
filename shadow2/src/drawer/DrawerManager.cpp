//
//  DrawerManager.cpp
//  shadow
//
//  Created by Guillaume LUNG TUNG on 22/09/13.
//
//

#include "DrawerManager.h"

void DrawerManager::init()
{
    drawers.resize(3);
    drawers[DRAWER_BASIC] = new drawerBasic(this);
    drawers[DRAWER_POST] = new drawerPostProcessing(this);
    drawers[DRAWER_WINGS] = new drawerWings(this);
    
    for (vector<drawerInterface *>::iterator it = drawers.begin(); it < drawers.end(); it++)
        (*it)->init();
    
   // setDrawer(DRAWER_BASIC);
}

void DrawerManager::setDrawer(int type)
{
    activeDrawer = drawers[type];
}

drawerInterface* DrawerManager::getDrawer()
{
    return activeDrawer;
}

void DrawerManager::update(ofBaseHasPixels &source)
{
    getDrawer()->update(source);
}

void DrawerManager::draw(int x, int y, int width, int height)
{
    getDrawer()->draw(x,y,width,height);
}

void DrawerManager::keyPressed(int key)
{
    getDrawer()->keyPressed(key);
}

void DrawerManager::execute(string msg_string, float msg_arg)
{
    for (vector<drawerInterface *>::iterator it = drawers.begin(); it < drawers.end(); it++)
        (*it)->execute(msg_string, msg_arg);
}
