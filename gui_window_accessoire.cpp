#include "gui_window_accessoire.h"
#include "fssimplewindow.h"


gui_window_accessoire::gui_window_accessoire() {
    //ctor
    wat=0;
    set_size(16, 16);
    state=0;
}

gui_window_accessoire::~gui_window_accessoire() {
    //dtor
}

void gui_window_accessoire::init(){
    if(wat==0) wat = get_texture("window_accessoires.png");
    return;
}

void gui_window_accessoire::set_type(int t) {
    type=t;
    return;
}

void gui_window_accessoire::draw() {
    if(visible==1) {
        if(active==1) {
            glColor3f(1, 1, 1);
        } else {
            glColor3f(0.8, 0.8, 0.8);
        }

        glBindTexture(GL_TEXTURE_2D, wat);

        glTranslatef(get_pos_x(), get_pos_y(), 0);

        float tx=0;
        float ty=0;
        if(type==1 || type==3) tx=0.5;
        if(type>1) ty=0.5;
        float ex=tx+0.5;
        float ey=ty+0.5;

        glBegin(GL_QUADS);
        //top left corner
        glTexCoord2f(tx, ey); glVertex2d(           0,  get_size_y());
        glTexCoord2f(ex, ey); glVertex2d(get_size_x(),  get_size_y());
        glTexCoord2f(ex, ty); glVertex2d(get_size_x(),             0);
        glTexCoord2f(tx, ty); glVertex2d(           0,             0);
        glEnd();
    }
    return;
}

bool gui_window_accessoire::take_input() {
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
}

int gui_window_accessoire::get_state() {
    if(is_active()) {
        return state;
    } else {
        return 0;
    }
}
