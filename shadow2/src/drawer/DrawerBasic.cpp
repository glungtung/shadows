//
//  drawerBasic.cpp
//  shadow
//
//  Created by Guillaume LUNG TUNG on 22/09/13.
//
//

#include "DrawerInterface.h"


void drawerBasic::update(ofBaseHasPixels& source)
{
    tex.loadData(source.getPixelsRef());
}

void drawerBasic::draw(int x, int y, int width, int height)
{
    tex.draw(x,y,width,height);
}

