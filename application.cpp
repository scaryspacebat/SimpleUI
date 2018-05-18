#include "application.h"

#include "log.h"
#include "fssimplewindow.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <thread>
#include <chrono>
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


application::application() : sizeX("SizeX", 800), sizeY("SizeY", 600), theme("Theme", "default")
{
    //ctor
    log::writeToLog("Initiating application.");
    log::addTab();

    addSetting(&sizeX);
    addSetting(&sizeY);
    addSetting(&theme);

    setVerticalFOV(45);

    state=0;

    mode=0;

    setMeasurementSize(200);

    Gui.set_bg_visibility(true);

    log::removeTab();
    log::writeToLog("Finished initiating application");
    log::nextLine();
}

application::~application()
{
    //dtor
    log::writeToLog("Terminating Application");
    saveSettingsToFile("settings.txt");
}

void application::init()
{

    return;
}

void application::init_window()
{
    log::writeToLog("Creating window");
    FsOpenWindow(32,32,size_x,size_y,1); // 800x600 pixels, useDoubleBuffer=1

    log::writeToLog("Initiating OpenGL");
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

void application::set_size(int x, int y)
{
    if(x!=size_x || y!=size_y)
    {
        log::writeToLog("Setting application size to "+std::to_string(x)+" x "+std::to_string(y));
        size_x=x;
        size_y=y;
        sizeX.setIntegerValue(x);
        sizeY.setIntegerValue(y);
        Gui.set_size(size_x, size_y);
    }
    return;
}

void application::run()
{
    loadSettingsFromFile("settings.txt");

    set_size(sizeX.getIntegerValue(), sizeY.getIntegerValue());
    Gui.setTheme(theme.getStringValue());

    init_window();

    log::writeToLog("Initiating application");
    log::addTab();
    init();
    log::removeTab();
    log::writeToLog("Finished initiating application");
    log::nextLine();

    Gui.init();
    audio.init();

    log::writeToLog("Entering main loop");
    log::nextLine();

    while(get_state()==0)
    {
        auto start = std::chrono::steady_clock::now();
        FsPollDevice();

        Gui.update();

        auto gupdate = std::chrono::steady_clock::now();

        audio.update();

        auto aupdate = std::chrono::steady_clock::now();
        aDur.push_front(std::chrono::duration_cast<std::chrono::duration<double>>(aupdate - gupdate).count());
        while(aDur.size()>measurement_size){
            aDur.pop_back();
        }

        int wid,hei;
        FsGetWindowSize(wid,hei);
        set_size(wid, hei);

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clear The Screen And The Depth Buffer

        glViewport(0,0,wid,hei);

        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(0,(float)wid-1,(float)hei-1,0,-1,1);

        Gui.drawBackground();

        if(mode==3)
        {
            glEnable(GL_DEPTH_TEST);
            glDepthFunc(GL_LEQUAL);
            glMatrixMode(GL_PROJECTION);
            glLoadIdentity();
            //glFrustum(-1, 1, -1, 1, 0.1, 1000);
            gluPerspective(fovy, static_cast<float>(size_x)/static_cast<float>(size_y), 0.1, 1000);
        }
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        main_loop();

        auto mupdate = std::chrono::steady_clock::now();

        mlDur.push_front(std::chrono::duration_cast<std::chrono::duration<double>>(mupdate - aupdate).count());
        while(mlDur.size()>measurement_size){
            mlDur.pop_back();
        }


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

        auto finish = std::chrono::steady_clock::now();
        frameDur.push_front(std::chrono::duration_cast<std::chrono::duration<double>>(finish - start).count());
        while(frameDur.size()>measurement_size){
            frameDur.pop_back();
        }
    }
    return;
}

void application::main_loop()
{

    return;
}

int application::get_state()
{
    return state;
}

void application::setVerticalFOV(double f)
{
    fovy=f;
    return;
}

void application::setMode(int m)
{
    mode=m;
    return;
}

void application::setState(int s){
    state=s;
    return;
}

void application::setMeasurementSize(int m){
    measurement_size=m;
    return;
}

double application::getFPS(){
    if (frameDur.size()==0) return 0;
    double r=0;
    for (auto const& i : frameDur)  r+=i;
    return 1.0f/(r/frameDur.size());
}

double application::getMainLoopDuration(){
    if (mlDur.size()==0) return 0;
    double r=0;
    for (auto const& i : mlDur)  r+=i;
    return r/mlDur.size();
}

double application::getAudioUpdateDuration(){
    if (aDur.size()==0) return 0;
    double r=0;
    for (auto const& i : aDur)  r+=i;
    return r/aDur.size();
}
