#include "guiWindow.hpp"


GuiWindow::GuiWindow() {
    //ctor
    wbg = 0;
}

GuiWindow::~GuiWindow() {
    //dtor
}

void GuiWindow::init() {
    if( wbg==0 )
        wbg=getTexture( "window_bg.png" );
    GuiContainer::init();
    return;
}

void GuiWindow::render() {
        glTranslatef( getRelPosX(), getRelPosY(), 0 );

        glBindTexture( GL_TEXTURE_2D, wbg );

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

/*
bool gui_window::take_input() {
    bool r=false;
    int mx, my, lb, mb, rb;
    FsGetMouseState( lb, mb, rb, mx, my );

    r=gui_container::take_input();

    if( mx>=get_abs_pos_x() && mx<=get_abs_pos_x()+get_size_x() && my>=get_abs_pos_y() && my<=get_abs_pos_y()+get_size_y() && is_active() )
        r=true;

    if( r==false && vanish==true ) {
        make_invisible();
        has_vanished=true;
    }


    return r;
}

void gui_window::autohide( bool v ) {
    vanish=v;
    return;
}

bool gui_window::has_hidden() {
    if( has_vanished==true ) {
        has_vanished=false;
        return true;
    }
    return false;
}*/
