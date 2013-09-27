//
//  DrawerManager.h
//  shadow
//
//  Created by Guillaume LUNG TUNG on 22/09/13.
//
//

#ifndef __shadow__DrawerManager__
#define __shadow__DrawerManager__

#include "DrawerInterface.h"

#define DRAWER_BASIC 0
#define DRAWER_POST 1
#define DRAWER_WINGS 2

class drawerInterface;

class DrawerManager  {
public:
    void init();
    void update(ofBaseHasPixels& source);
    void draw(int x=0, int y=0, int width=0, int height=0);
    void keyPressed(int key);
    void execute(string msg_string, float msg_arg);
    
    drawerInterface * getDrawer();
    void setDrawer(int type);
    
    vector<drawerInterface *> drawers;
    drawerInterface *activeDrawer;
};
#endif /* defined(__shadow__DrawerManager__) */
