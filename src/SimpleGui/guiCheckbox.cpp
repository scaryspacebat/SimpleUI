#include "guiCheckbox.hpp"


GuiCheckbox::GuiCheckbox() {
    //ctor
    setSizeX(16);
    setSizeY(16);

    cb=0;
    type=0;
}

GuiCheckbox::~GuiCheckbox() {
    //dtor
}


void GuiCheckbox::init() {
    if( cb==0 )
        cb = getTexture( "checkbox.png" );
    return;
}

void GuiCheckbox::render() {
        glTranslatef( getRelPosX(), getRelPosY(), 0 );

        glBindTexture( GL_TEXTURE_2D, cb );

        float offX=0;
        if( getToggleState()==false )
            offX=0.5;
        float offY=0;
        if( type==1)
            offY=0.5;

        float sx=getSizeX();
        float sy=getSizeY();

        glBegin( GL_QUADS );
        //top left corner
        glTexCoord2f( 0+offX, 0.5+offY );
        glVertex2d( 0, sy );
        glTexCoord2f( 0.5+offX, 0.5+offY );
        glVertex2d( sx, sy );
        glTexCoord2f( 0.5+offX, 0+offY );
        glVertex2d( sx, 0 );
        glTexCoord2f( 0+offX, 0+offY );
        glVertex2d( 0, 0 );
        glEnd();

    return;
}

void GuiCheckbox::setType(int t){
    type=t;
    return;
}
