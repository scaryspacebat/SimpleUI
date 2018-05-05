#include "gui_button.h"
#include "fssimplewindow.h"

gui_button::gui_button() {
    //ctor
    state=0;

    bt=0;
    bpt=0;

    off_x=0;
    off_y=2;
}

gui_button::~gui_button() {
    //dtor
}

void gui_button::init(){
    if(bt==0) bt = get_texture("button.png");
    if(bpt==0) bpt = get_texture("button_pressed.png");
    gui_container::init();
    return;
}

void gui_button::draw() {
    if(visible==1) {
        if(active==1) {
            glColor3f(1, 1, 1);
        } else {
            glColor3f(0.8, 0.8, 0.8);
        }

        glTranslatef(get_pos_x(), get_pos_y(), 0);
        if(get_state()==1 || get_state()==2) {
            glBindTexture(GL_TEXTURE_2D, bpt);
        } else {
            glBindTexture(GL_TEXTURE_2D, bt);
        }

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

        if(get_state()==1 || get_state()==2) glTranslatef(off_x, off_y, 0);

        gui_container::draw();
    }
    return;
}

bool gui_button::take_input() {
    int mx,my,lb,mb,rb;

    FsGetMouseState(lb,mb,rb,mx,my);
    if(is_active()) {
        if(mx>=get_abs_pos_x() && mx<=get_abs_pos_x()+get_size_x() && my>=get_abs_pos_y() && my<=get_abs_pos_y()+get_size_y() && lb==1) {
            if(state==0 || state==3) {
                state=1;
            } else {
                state=2;
            }
        } else {
            if(state==1 || state==2) {
                state=3;
            } else {
                state=0;
            }
        }
    } else {
        state=0;
    }

    if(mx>=get_abs_pos_x() && mx<=get_abs_pos_x()+get_size_x() && my>=get_abs_pos_y() && my<=get_abs_pos_y()+get_size_y() && visible){
        return true;
    }
    else{
        return false;
    }
    return false;
}

int gui_button::get_state() {
    return state;
}

/*
float gui_button::get_abs_pos_x(){
    float r=gui_element::get_abs_pos_x();
    if(get_state()==1 || get_state()==2) r+=off_x;
    return r;
}

float gui_button::get_abs_pos_y(){
    float r=gui_element::get_abs_pos_y();
    if(get_state()==1 || get_state()==2) r+=off_y;
    return r;
}

float gui_button::get_pos_x(){
    float r=gui_element::get_pos_x();
    if(get_state()==1 || get_state()==2) r+=off_x;
    return r;
}

float gui_button::get_pos_y(){
    float r=gui_element::get_pos_y();
    if(get_state()==1 || get_state()==2) r+=off_y;
    return r;
}
*/
