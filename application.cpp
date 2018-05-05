#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifdef WIN32
#include <windows.h>
#endif

#ifndef MACOSX
#include <GL/gl.h>
#include <GL/glu.h>
#else
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#endif

#include "application.h"
#include "log_manager.h"
#include "fssimplewindow.h"
#include "log_manager.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <thread>

using namespace std;

application::application() {
    //ctor
    log_manager::write_log("Initiating application.");
    size_x=800;
    size_y=600;

    setVerticalFOV(45);

    state=0;

    init_window();

    Gui.set_size(size_x, size_y);
    Gui.set_bg_visibility(true);

    log_manager::write_log("Finished initiating application.");
}

application::~application() {
    //dtor
}

void application::init() {

    return;
}

void application::init_window() {
    log_manager::write_log("Creating window");
    FsOpenWindow(32,32,size_x,size_y,1); // 800x600 pixels, useDoubleBuffer=1

    log_manager::write_log("Initiating OpenGL");
    glEnable(GL_DEPTH_TEST);
    glDisable(GL_LIGHTING);
    glDepthFunc(GL_ALWAYS);
    glClearColor(0.0f, 0.0f, 0.0f, 0.5f);					// Black Background
    glShadeModel(GL_SMOOTH);
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_BLEND);										// Enable Blending
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);		// Type Of Blending To Use
    glClear(GL_COLOR_BUFFER_BIT);

    glCullFace(GL_BACK); // Enable Culling
    glEnable(GL_CULL_FACE);

    glEnable( GL_LINE_SMOOTH ); // Antialiased Lines
    glHint( GL_LINE_SMOOTH_HINT, GL_NICEST );


    //glFrustum(0, size_x, 0, size_y, 0.1, 1000);

    srand(time(NULL));
    //srand(0);
    return;
}

void application::set_size(int x, int y) {
    if(x!=size_x || y!=size_y) {
        size_x=x;
        size_y=y;
        Gui.set_size(size_x, size_y);
    }
    return;
}

void application::loop() {
    log_manager::write_log("Initiating GUI");
    Gui.init();

    while(get_state()==0) {
        FsPollDevice();

        int wid,hei;
        FsGetWindowSize(wid,hei);
        set_size(wid, hei);

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clear The Screen And The Depth Buffer

        glViewport(0,0,wid,hei);

        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(0,(float)wid-1,(float)hei-1,0,-1,1);

        Gui.drawBackground();

        glEnable(GL_DEPTH_TEST);
        glDepthFunc(GL_LEQUAL);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        //glFrustum(-1, 1, -1, 1, 0.1, 1000);
        gluPerspective(fovy, static_cast<float>(size_x)/static_cast<float>(size_y), 0.1, 1000);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        main_loop();


        glDisable(GL_DEPTH_TEST);
        glDepthFunc(GL_ALWAYS);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(0,(float)wid-1,(float)hei-1,0,-1,1);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        Gui.draw();

        glFlush();

        FsSwapBuffers();
        //FsSleep(10);
    }
    return;
}

void application::main_loop() {

    return;
}

int application::get_state() {
    return state;
}

void application::setVerticalFOV(double f){
    fovy=f;
    return;
}

