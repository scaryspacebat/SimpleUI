#include "guicheckbox.h"
#include "fssimplewindow.h"

guiCheckbox::guiCheckbox() {
    //ctor
    state=0;

    cb=0;
}

guiCheckbox::~guiCheckbox() {
    //dtor
}


void guiCheckbox::init() {
    if(cb==0)
        cb = get_texture("checkbox.png");
    return;
}

void guiCheckbox::draw() {
    if(visible==1) {
        if(active==1) {
            glColor3f(1, 1, 1);
        } else {
            glColor3f(0.8, 0.8, 0.8);
        }

        glTranslatef(get_pos_x(), get_pos_y(), 0);

        glBindTexture(GL_TEXTURE_2D, cb);

        float offX=0;
        if(get_state()==false) offX=0.5;
        float offY=0;

        glBegin(GL_QUADS);
        //top left corner
        glTexCoord2f(0+offX, 0.5+offY);
        glVertex2d(0, 16);
        glTexCoord2f(0.5+offX, 0.5+offY);
        glVertex2d(16, 16);
        glTexCoord2f(0.5+offX, 0+offY);
        glVertex2d(16, 0);
        glTexCoord2f(0+offX, 0+offY);
        glVertex2d(0, 0);
        glEnd();
    }
    return;
}

bool guiCheckbox::take_input() {
    int mx,my,lb,mb,rb;

    FsGetMouseState(lb,mb,rb,mx,my);
    if(is_active()) {
        if(mx>=get_abs_pos_x() && mx<=get_abs_pos_x()+16 && my>=get_abs_pos_y() && my<=get_abs_pos_y()+16 && lb==1) {
            if(state==0) state=1;
            if(state==2) state=3;
        }
        else{
            if(state==1) state=2;
            if(state==3) state=0;
        }
    }

    if(mx>=get_abs_pos_x() && mx<=get_abs_pos_x()+16 && my>=get_abs_pos_y() && my<=get_abs_pos_y()+get_size_y() && visible){
        return true;
    }
    else{
        return false;
    }
    return false;
}

bool guiCheckbox::get_state() {
    if( state ==2 || state ==3 ) return true;
    return false;
}

void guiCheckbox::setState(bool s){
    if(s==true){
        state=2;
    }
    else{
        state=0;
    }
    return;
}
