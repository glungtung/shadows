//
//  drawerInterface
//  shadow
//
//  Created by Guillaume LUNG TUNG on 15/09/13.
//
//

#ifndef shadow_drawerInterface_h
#define shadow_drawerInterface_h

#include "ofMain.h"
#include "ofxPostProcessing.h"
#include "DrawerManager.h"
#include "ofxCv.h"


class DrawerManager;

class drawerInterface {
public:
    virtual void init() = 0;
    virtual void update(ofBaseHasPixels& source) = 0;
    virtual void draw(int x=0, int y=0, int width=0, int height=0) = 0;
    virtual void keyPressed(int key) = 0;
    virtual void execute(string msg_string, float msg_arg) = 0;
    
};

class drawerPostProcessing : public drawerInterface
{
public:
    drawerPostProcessing(DrawerManager *m);
    ~drawerPostProcessing() {};
    
     void init();
     void update(ofBaseHasPixels& source);
     void draw(int x=0, int y=0, int width=0, int height=0);
    void keyPressed(int key) {};
    void execute(string msg_string, float msg_arg);
    
    ofxPostProcessing post;

    ofTexture tex;
    DrawerManager *manager;
};


class drawerBasic : public drawerInterface
{
public:
    drawerBasic(DrawerManager *m)  {manager = m;}
    ~drawerBasic() {};
    
    void init() {};
    void update(ofBaseHasPixels& source);
    void draw(int x=0, int y=0, int width=0, int height=0);
    void keyPressed(int key) {};
    void execute(string msg_string, float msg_arg) {};
        
    ofTexture tex;
    DrawerManager *manager;

};

class drawerWings : public drawerInterface
{
public:
    drawerWings(DrawerManager *m)  {manager = m;}
    ~drawerWings() {};
    
    void init() {};
    void update(ofBaseHasPixels& source);
    void draw(int x=0, int y=0, int width=0, int height=0);
    void keyPressed(int key) {};
    void execute(string msg_string, float msg_arg) {};
    
    ofTexture tex;
    DrawerManager *manager;
    ofxCv::ContourFinder contourFinder;

};
#endif
