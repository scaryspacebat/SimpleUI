#include "guiButton.hpp"


GuiButton::GuiButton() {
    //ctor

    bt=0;
    bpt=0;

    off_x=0;
    off_y=2;
}

GuiButton::~GuiButton() {
    //dtor
}

void GuiButton::init() {
    if( bt==0 )
        bt = getTexture( "button.png" );
    if( bpt==0 )
        bpt = getTexture( "button_pressed.png" );
    GuiContainer::init();
    return;
}

void GuiButton::render() {
        glTranslatef( getRelPosX(), getRelPosY(), 0 );

        if( getState()==1 || getState()==2 )
            glBindTexture( GL_TEXTURE_2D, bpt );

        else
            glBindTexture( GL_TEXTURE_2D, bt );

        float sx = getSizeX();
        float sy = getSizeY();

        glBegin( GL_QUADS );
        //top left corner
        glTexCoord2f( 0, 0.25 );
        glVertex2d( 0, 16 );
        glTexCoord2f( 0.25, 0.25 );
        glVertex2d( 16, 16 );
        glTexCoord2f( 0.25, 0 );
        glVertex2d( 16, 0 );
        glTexCoord2f( 0, 0 );
        glVertex2d( 0, 0 );

        //top right corner
        glTexCoord2f( 0.5, 0.25 );
        glVertex2d( sx-16, 16 );
        glTexCoord2f( 0.75, 0.25 );
        glVertex2d( sx, 16 );
        glTexCoord2f( 0.75, 0 );
        glVertex2d( sx, 0 );
        glTexCoord2f( 0.5, 0 );
        glVertex2d( sx-16, 0 );

        //bottom right corner
        glTexCoord2f( 0.5, 0.75 );
        glVertex2d( sx-16, sy );
        glTexCoord2f( 0.75, 0.75 );
        glVertex2d( sx, sy );
        glTexCoord2f( 0.75, 0.5 );
        glVertex2d( sx, sy-16 );
        glTexCoord2f( 0.5, 0.5 );
        glVertex2d( sx-16, sy-16 );

        //bottom left corner
        glTexCoord2f( 0.0, 0.75 );
        glVertex2d( 0, sy );
        glTexCoord2f( 0.25, 0.75 );
        glVertex2d( 16, sy );
        glTexCoord2f( 0.25, 0.5 );
        glVertex2d( 16, sy-16 );
        glTexCoord2f( 0.0, 0.5 );
        glVertex2d( 0, sy-16 );

        //left edge
        glTexCoord2f( 0, 0.5 );
        glVertex2d( 0, sy-16 );
        glTexCoord2f( 0.25, 0.5 );
        glVertex2d( 16, sy-16 );
        glTexCoord2f( 0.25, 0.25 );
        glVertex2d( 16, 16 );
        glTexCoord2f( 0, 0.25 );
        glVertex2d( 0, 16 );

        //top edge
        glTexCoord2f( 0.25, 0.25 );
        glVertex2d( 16, 16 );
        glTexCoord2f( 0.5, 0.25 );
        glVertex2d( sx-16, 16 );
        glTexCoord2f( 0.5, 0 );
        glVertex2d( sx-16, 0 );
        glTexCoord2f( 0.25, 0 );
        glVertex2d( 16, 0 );

        //right edge
        glTexCoord2f( 0.5, 0.5 );
        glVertex2d( sx-16, sy-16 );
        glTexCoord2f( 0.75, 0.5 );
        glVertex2d( sx, sy-16 );
        glTexCoord2f( 0.75, 0.25 );
        glVertex2d( sx, 16 );
        glTexCoord2f( 0.5, 0.25 );
        glVertex2d( sx-16, 16 );

        //bottom edge
        glTexCoord2f( 0.25, 0.75 );
        glVertex2d( 16, sy );
        glTexCoord2f( 0.5, 0.75 );
        glVertex2d( sx-16, sy );
        glTexCoord2f( 0.5, 0.5 );
        glVertex2d( sx-16, sy-16 );
        glTexCoord2f( 0.25, 0.5 );
        glVertex2d( 16, sy-16 );

        //middle
        glTexCoord2f( 0.25, 0.5 );
        glVertex2d( 16, sy-16 );
        glTexCoord2f( 0.5, 0.5 );
        glVertex2d( sx-16, sy-16 );
        glTexCoord2f( 0.5, 0.25 );
        glVertex2d( sx-16, 16 );
        glTexCoord2f( 0.25, 0.25 );
        glVertex2d( 16, 16 );

        glEnd();

        if( getState()==1 || getState()==2 )
            glTranslatef( off_x, off_y, 0 );

    return;
}




