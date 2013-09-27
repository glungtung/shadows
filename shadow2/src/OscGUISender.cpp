//
//  OscGUISender.cpp
//  shadow
//
//  Created by Guillaume LUNG TUNG on 25/09/13.
//
//

#include "OscGUISender.h"

OscGUISender::OscGUISender()
{
    init();
}

void OscGUISender::init()
{
    sender.setup("192.168.0.28", 9000);

}

void OscGUISender::send(string msg_string, float msg_arg)
{
    ofxOscMessage m;
    m.setAddress(msg_string);
    m.addFloatArg(msg_arg);
    sender.sendMessage(m);
}

void OscGUISender::send(string msg_string, string msg_arg)
{
    ofxOscMessage m;
    m.setAddress(msg_string);
    m.addStringArg(msg_arg);
    sender.sendMessage(m);
}

void OscGUISender::send(string msg_string, int msg_arg)
{
    ofxOscMessage m;
    m.setAddress(msg_string);
    m.addIntArg(msg_arg);
    sender.sendMessage(m);
}