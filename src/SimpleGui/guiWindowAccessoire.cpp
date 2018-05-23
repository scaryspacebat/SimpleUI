#include "guiWindowAccessoire.hpp"


GuiWindowAccessoire::GuiWindowAccessoire() {
    //ctor
    wat=0;
    i_type=0;
    setSizeX( 16 );
    setSizeY( 16 );
    i_state=0;
}

GuiWindowAccessoire::~GuiWindowAccessoire() {
    //dtor
}

void GuiWindowAccessoire::init() {
    if( wat==0 )
        wat = getTexture( "window_accessoires.png" );
    return;
}

void GuiWindowAccessoire::setType( int t ) {
    i_type=t;
    return;
}

void GuiWindowAccessoire::render() {
    glBindTexture( GL_TEXTURE_2D, wat );

    glTranslatef( getRelPosX(), getRelPosY(), 0 );

    float tx=0;
    float ty=0;
    if( i_type==1 || i_type==3 )
        tx=0.5;
    if( i_type>1 )
        ty=0.5;
    float ex=tx+0.5;
    float ey=ty+0.5;

    float sx=getSizeX();
    float sy=getSizeY();

    glBegin( GL_QUADS );
    //top left corner
    glTexCoord2f( tx, ey );
    glVertex2d( 0,  sy );
    glTexCoord2f( ex, ey );
    glVertex2d( sx,  sy );
    glTexCoord2f( ex, ty );
    glVertex2d( sx, 0 );
    glTexCoord2f( tx, ty );
    glVertex2d( 0, 0 );
    glEnd();

    return;
}

