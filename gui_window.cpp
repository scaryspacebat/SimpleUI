#include "gui_window.h"
#include "fssimplewindow.h"

GLuint gui_window::wbg = 0;

gui_window::gui_window() {
    //ctor
    if(wbg==0) wbg=load_texture("window_bg.png");
    vanish=false;
    has_vanished=false;
}

gui_window::~gui_window() {
    //dtor
}


void gui_window::draw() {
    if(visible==1) {
        if(active==1) {
            glColor3f(1, 1, 1);
        } else {
            glColor3f(0.8, 0.8, 0.8);
        }

        glTranslatef(get_pos_x(), get_pos_y(), 0);
        glBindTexture(GL_TEXTURE_2D, wbg);

        glBegin(GL_QUADS);
        //top left corner
        glTexCoord2f(0, 0.25);
        glVertex2d(0, 16);
        glTexCoord2f(0.25, 0.25);
        glVertex2d(16, 16);
        glTexCoord2f(0.25, 0);
        glVertex2d(16, 0);
        glTexCoord2f(0, 0);
        glVertex2d(0, 0);

        //top right corner
        glTexCoord2f(0.5, 0.25);
        glVertex2d(get_size_x()-16, 16);
        glTexCoord2f(0.75, 0.25);
        glVertex2d(get_size_x(), 16);
        glTexCoord2f(0.75, 0);
        glVertex2d(get_size_x(), 0);
        glTexCoord2f(0.5, 0);
        glVertex2d(get_size_x()-16, 0);

        //bottom right corner
        glTexCoord2f(0.5, 0.75);
        glVertex2d(get_size_x()-16, get_size_y());
        glTexCoord2f(0.75, 0.75);
        glVertex2d(get_size_x(), get_size_y());
        glTexCoord2f(0.75, 0.5);
        glVertex2d(get_size_x(), get_size_y()-16);
        glTexCoord2f(0.5, 0.5);
        glVertex2d(get_size_x()-16, get_size_y()-16);

        //bottom left corner
        glTexCoord2f(0.0, 0.75);
        glVertex2d(0, get_size_y());
        glTexCoord2f(0.25, 0.75);
        glVertex2d(16, get_size_y());
        glTexCoord2f(0.25, 0.5);
        glVertex2d(16, get_size_y()-16);
        glTexCoord2f(0.0, 0.5);
        glVertex2d(0, get_size_y()-16);

        //left edge
        glTexCoord2f(0, 0.5);
        glVertex2d(0, get_size_y()-16);
        glTexCoord2f(0.25, 0.5);
        glVertex2d(16, get_size_y()-16);
        glTexCoord2f(0.25, 0.25);
        glVertex2d(16, 16);
        glTexCoord2f(0, 0.25);
        glVertex2d(0, 16);

        //top edge
        glTexCoord2f(0.25, 0.25);
        glVertex2d(16, 16);
        glTexCoord2f(0.5, 0.25);
        glVertex2d(get_size_x()-16, 16);
        glTexCoord2f(0.5, 0);
        glVertex2d(get_size_x()-16, 0);
        glTexCoord2f(0.25, 0);
        glVertex2d(16, 0);

        //right edge
        glTexCoord2f(0.5, 0.5);
        glVertex2d(get_size_x()-16, get_size_y()-16);
        glTexCoord2f(0.75, 0.5);
        glVertex2d(get_size_x(), get_size_y()-16);
        glTexCoord2f(0.75, 0.25);
        glVertex2d(get_size_x(), 16);
        glTexCoord2f(0.5, 0.25);
        glVertex2d(get_size_x()-16, 16);

        //bottom edge
        glTexCoord2f(0.25, 0.75);
        glVertex2d(16, get_size_y());
        glTexCoord2f(0.5, 0.75);
        glVertex2d(get_size_x()-16, get_size_y());
        glTexCoord2f(0.5, 0.5);
        glVertex2d(get_size_x()-16, get_size_y()-16);
        glTexCoord2f(0.25, 0.5);
        glVertex2d(16, get_size_y()-16);

        //middle
        glTexCoord2f(0.25, 0.5);
        glVertex2d(16, get_size_y()-16);
        glTexCoord2f(0.5, 0.5);
        glVertex2d(get_size_x()-16, get_size_y()-16);
        glTexCoord2f(0.5, 0.25);
        glVertex2d(get_size_x()-16, 16);
        glTexCoord2f(0.25, 0.25);
        glVertex2d(16, 16);

        glEnd();
    }

    gui_container::draw();
    return;
}

bool gui_window::take_input() {
    bool r=false;
    int i=0;
    int mx,my,lb,mb,rb;
    FsGetMouseState(lb,mb,rb,mx,my);

    r=gui_container::take_input();

    if(mx>=get_abs_pos_x() && mx<=get_abs_pos_x()+get_size_x() && my>=get_abs_pos_y() && my<=get_abs_pos_y()+get_size_y() && is_active()) {
        r=true;
    }

    if(r==false && vanish==true) {
        make_invisible();
        has_vanished=true;
    }


    return r;
}

void gui_window::autohide(bool v) {
    vanish=v;
    return;
}

bool gui_window::has_hidden(){
    if(has_vanished==true){
        has_vanished=false;
        return true;
    }
    return false;
}
