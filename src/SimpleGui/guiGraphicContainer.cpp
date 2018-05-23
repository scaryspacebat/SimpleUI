#include "GuiGraphicContainer.hpp"


GuiGraphicContainer::GuiGraphicContainer()
{
    //ctor
    cst1 = 0;
    cst2 = 0;
    cst3 = 0;

    i_style = 1;
}

GuiGraphicContainer::~GuiGraphicContainer()
{
    //dtor
}

void GuiGraphicContainer::init() {
    if( cst1==0 )
        cst1 = getTexture( "container_bg_1.png" );
    if( cst2==0 )
        cst2 = getTexture( "container_bg_2.png" );
    if( cst3==0 )
        cst3 = getTexture( "container_bg_3.png" );
    GuiContainer::init();
}

void GuiGraphicContainer::render() {
        glTranslatef( getRelPosX(), getRelPosY(), 0 );

        if( i_style == 1 )
            glBindTexture( GL_TEXTURE_2D, cst1 );
        else if( i_style == 2 )
            glBindTexture( GL_TEXTURE_2D, cst2 );
        else if( i_style == 3 )
            glBindTexture( GL_TEXTURE_2D, cst3 );

        float sx=getSizeX();
        float sy=getSizeY();

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

    return;
}

void GuiGraphicContainer::setStyle( int s ) {
    i_style = s;
    return;
}
