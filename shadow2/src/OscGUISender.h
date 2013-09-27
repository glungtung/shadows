//
//  OscGUISender.h
//  shadow
//
//  Created by Guillaume LUNG TUNG on 25/09/13.
//
//

#ifndef __shadow__OscGUISender__
#define __shadow__OscGUISender__

#include "ofMain.h"
#include "ofxOscSender.h"
#include "singleton.h"

class OscGUISender {
public:
    OscGUISender();
    ~OscGUISender() {};

    void init();
    void send(string msg_string, float msg_arg);
    void send(string msg_string, string msg_arg);
    void send(string msg_string, int msg_arg);
    
    ofxOscSender sender;

};


typedef Singleton<OscGUISender> singleOscSender;
#endif /* defined(__shadow__OscGUISender__) */
