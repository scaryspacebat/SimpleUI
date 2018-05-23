#include "guiFramework.hpp"

#include "../lodepng.h"
#include "../log.h"
#include "../fssimplewindow.h"


GuiFramework::GuiFramework( std::string t ): s_theme( t ) {
    //ctor
    log::writeToLog( "Creating GUI" );
    log::addTab();

    tid=0;
    ui_rec=false;
    bg_visible=true;

    log::removeTab();
    log::nextLine();
}

GuiFramework::~GuiFramework() {
    //dtor
    for( int i=0; i<texture_list.size(); i++ )
        delete texture_list[i];
}

void GuiFramework::init() {
    log::writeToLog( "Initiating GUI" );
    log::addTab();

    if( tid==0 )
        tid = getTexture( "background.png" );

    GuiContainer::init();

    log::removeTab();
    log::nextLine();
    return;
}

void GuiFramework::update() {
    int mx;
    int my;
    int lb;
    int mb;
    int rb;

    FsGetMouseState( lb, mb, rb, mx, my );

    ui_rec=GuiContainer::assessInput(mx, my, lb, mb, rb);

    return;
}

void GuiFramework::draw(){
    glColor4f(1.0, 1.0, 1.0, 1.0);
    GuiContainer::draw();
    return;
}

void GuiFramework::drawBackground() {
    glColor3f( 1, 1, 1 );
    if( bg_visible ) {
        glBindTexture( GL_TEXTURE_2D, tid );

        float sx=getSizeX();
        float sy=getSizeY();

        glBegin( GL_QUADS );
        glTexCoord2f( 0, ( sy+1 )/16.0 );
        glVertex2d( 0, sy );

        glTexCoord2f( ( sx+1 )/16.0, ( sy+1 )/16.0 );
        glVertex2d( sx, sy );

        glTexCoord2f( ( sx+1 )/16.0, 0 );
        glVertex2d( sx, 0 );

        glTexCoord2f( 0, 0 );
        glVertex2d( 0, 0 );
        glEnd();
    }
    return;
}

bool GuiFramework::hasRecievedInput() {
    return ui_rec;
}

void GuiFramework::setBackgroundVisibility( bool d ) {
    bg_visible=d;
    return;
}

GuiFramework* GuiFramework::getParentGuiFramework() {
    return this;
}

void GuiFramework::setSize(int x, int y){
    setSizeX(x);
    setSizeY(y);
    return;
}

void GuiFramework::setTheme( std::string t ) {
    s_theme=t;
    log::writeToLog( "Setting theme "+t );
    return;
}

GLuint GuiFramework::loadTexture( std::string f ) {
    for( int i=0; i<texture_list.size(); i++ ) {
        if( texture_list[i]->s_filename==f ) { // found an already loaded texture
            log::writeToLog( "found an already loaded texture for "+f, 3 );
            return texture_list[i]->id;
        }
    }

    GLuint tid;
    std::vector<unsigned char> image;
    unsigned width, height;
    log::writeToLog( "loading texture from gui/"+s_theme+"/"+f, 3 );
    lodepng::decode( image, width, height, "gui/"+s_theme+"/"+f );
    if( image.size()==0 ) {
        log::writeToLog( "Unable to load texture from gui/"+s_theme+"/"+f, -1 );
        lodepng::decode( image, width, height, "gui/default/"+f );
    }

    for( int y=0; y<height; y++ ) {
        for( int x=0; x<width; x++ ) {
            unsigned char r;
            unsigned char g;
            unsigned char b;
            unsigned char a;

            r=image[x*4+y*width*4];
            g=image[x*4+y*width*4+1];
            b=image[x*4+y*width*4+2];
            a=image[x*4+y*width*4+3];

            image[x*4+y*width*4]=( r*a )/255;
            image[x*4+y*width*4+1]=( g*a )/255;
            image[x*4+y*width*4+2]=( b*a )/255;
            image[x*4+y*width*4+3]=a;
        }
    }

    glEnable( GL_TEXTURE_2D );
    glGenTextures( 1, &tid );

    glBindTexture( GL_TEXTURE_2D, tid );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST ); //GL_NEAREST = no smoothing
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST );
    glTexImage2D( GL_TEXTURE_2D, 0, 4, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, &image[0] );

    glBindTexture( GL_TEXTURE_2D, 0 );

    tex* tEntry = new tex;
    tEntry->s_filename=f;
    tEntry->id=tid;
    texture_list.push_back( tEntry );

    return tid;
}





