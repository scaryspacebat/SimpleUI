#include "guiCheckbox.hpp"


GuiCheckbox::GuiCheckbox() {
    //ctor
    setSizeX(16);
    setSizeY(16);

    cb=0;
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


/*bool GuiCheckbox::take_input() {
    int mx, my, lb, mb, rb;

    FsGetMouseState( lb, mb, rb, mx, my );
    if( is_active() ) {
        if( mx>=get_abs_pos_x() && mx<=get_abs_pos_x()+16 && my>=get_abs_pos_y() && my<=get_abs_pos_y()+16 && lb==1 ) {
            if( state==0 )
                state=1;
            if( state==2 )
                state=3;
        }
        else {
            if( state==1 )
                state=2;
            if( state==3 )
                state=0;
        }
    }

    if( mx>=get_abs_pos_x() && mx<=get_abs_pos_x()+16 && my>=get_abs_pos_y() && my<=get_abs_pos_y()+get_size_y() && visible )
        return true;
    else
        return false;
    return false;
}

bool guiCheckbox::get_state() {
    if( state ==2 || state ==3 )
        return true;
    return false;
}

void guiCheckbox::setState( bool s ) {
    if( s==true )
        state=2;
    else
        state=0;
    return;
}
*/
