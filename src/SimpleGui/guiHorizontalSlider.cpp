#include "guiHorizontalSlider.hpp"


GuiHorizontalSlider::GuiHorizontalSlider() {
    //ctor
    f_value=0.5;
    setSizeY(16);

    st = 0;
}

GuiHorizontalSlider::~GuiHorizontalSlider() {
    //dtor
}

void GuiHorizontalSlider::init() {
    if( st==0 )
        st=getTexture( "slider.png" );
    return;
}

void GuiHorizontalSlider::render() {
        glTranslatef( getRelPosX(), getRelPosY(), 0 );

        glBindTexture( GL_TEXTURE_2D, st );

        float sx=getSizeX();
        float sy=getSizeY();

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
        float dv = f_value/( 16/sx);
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


        //slider
        glTexCoord2f( 0.75, 0.25 );
        glVertex2d( f_value*( sx-16 ), 16 );
        glTexCoord2f( 1, 0.25 );
        glVertex2d( f_value*( sx-16 )+16, 16 );
        glTexCoord2f( 1, 0. );
        glVertex2d( f_value*( sx-16 )+16, 0 );
        glTexCoord2f( 0.75, 0 );
        glVertex2d( f_value*( sx-16 ), 0 );

        glEnd();

    return;
}

bool GuiHorizontalSlider::acceptInput(int mx, int my, int lb, int mb, int rb) {
    bool r=GuiIsSolid::acceptInput( mx, my, lb, mb, rb );
    if( r && lb>0 ) {
        f_value=( mx-getAbsPosX()-8 )/( getSizeX()-16 );
    }

    if( f_value>1 )
        f_value=1;
    if( f_value<0 )
        f_value=0;

    return r;
}

void GuiHorizontalSlider::setValue( float v ) {
    f_value=v;
    return;
}

float GuiHorizontalSlider::getValue() {
    return f_value;
}
