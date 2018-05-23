#include "guiProgressbar.hpp"


GuiProgressbar::GuiProgressbar()
{
    //ctor
    f_value=0.0;
    setSizeY(16);

    pb = 0;
}

GuiProgressbar::~GuiProgressbar()
{
    //dtor
}

void GuiProgressbar::init() {
    if( pb==0 )
        pb=getTexture( "progressbar.png" );
    return;
}

void GuiProgressbar::render() {
        glTranslatef( getRelPosX(), getRelPosY(), 0 );

        glBindTexture( GL_TEXTURE_2D, pb );

        float sx=getSizeX();

        glBegin( GL_QUADS );
        //left end
        glTexCoord2f( 0, 0.25 );
        glVertex2d( 0, 16 );
        glTexCoord2f( 0.25, 0.25 );
        glVertex2d( 16, 16 );
        glTexCoord2f( 0.25, 0 );
        glVertex2d( 16, 0 );
        glTexCoord2f( 0, 0 );
        glVertex2d( 0, 0 );

        //middle
        glTexCoord2f( 0.25, 0.25 );
        glVertex2d( 16, 16 );
        glTexCoord2f( 0.5, 0.25 );
        glVertex2d( sx-16, 16 );
        glTexCoord2f( 0.5, 0 );
        glVertex2d( sx-16, 0 );
        glTexCoord2f( 0.25, 0 );
        glVertex2d( 16, 0 );

        //right end
        glTexCoord2f( 0.5, 0.25 );
        glVertex2d( sx-16, 16 );
        glTexCoord2f( 0.75, 0.25 );
        glVertex2d( sx, 16 );
        glTexCoord2f( 0.75, 0 );
        glVertex2d( sx, 0 );
        glTexCoord2f( 0.5, 0 );
        glVertex2d( sx-16, 0 );


        //overlay
        //left end
        float dv = f_value/( 16/sx );
        if( dv>1 )
            dv = 1;
        glTexCoord2f( 0, 0.5 );
        glVertex2d( 0, 16 );
        glTexCoord2f( 0.25*dv, 0.5 );
        glVertex2d( 16*dv, 16 );
        glTexCoord2f( 0.25*dv, 0.25 );
        glVertex2d( 16*dv, 0 );
        glTexCoord2f( 0, 0.25 );
        glVertex2d( 0, 0 );


        //middle
        if( ( f_value*sx )>16 ) {
            dv = ( f_value*sx-16 )/( sx-32 );
            if( dv>1 )
                dv = 1;
            glTexCoord2f( 0.25, 0.5 );
            glVertex2d( 16, 16 );
            glTexCoord2f( 0.5, 0.5 );
            glVertex2d( 16.0+( sx-32.0 )*dv, 16 );
            glTexCoord2f( 0.5, 0.25 );
            glVertex2d( 16.0+( sx-32.0 )*dv, 0 );
            glTexCoord2f( 0.25, 0.25 );
            glVertex2d( 16, 0 );
        }

        //right end
        if( ( f_value*sx )>sx-16 ) {
            dv = ( f_value*sx-sx+16 )/16;
            if( dv>1 )
                dv = 1;
            glTexCoord2f( 0.5, 0.5 );
            glVertex2d( sx-16, 16 );
            glTexCoord2f( 0.5+dv*0.25, 0.5 );
            glVertex2d( sx-16+dv*16, 16 );
            glTexCoord2f( 0.5+dv*0.25, 0.25 );
            glVertex2d( sx-16+dv*16, 0 );
            glTexCoord2f( 0.5, 0.25 );
            glVertex2d( sx-16, 0 );
        }

        glEnd();

    return;
}

void GuiProgressbar::setValue( float v ) {
    f_value=v;
    return;
}

float GuiProgressbar::getValue() {
    return f_value;
}
