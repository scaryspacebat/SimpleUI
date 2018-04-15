#include "gui_hor_slider.h"
#include "fssimplewindow.h"

GLuint gui_hor_slider::st = 0;

gui_hor_slider::gui_hor_slider() {
    //ctor
    value=1.0;
    size_y=16;
    if(st==0) st=load_texture("slider.png");
}

gui_hor_slider::~gui_hor_slider() {
    //dtor
}


void gui_hor_slider::draw() {
    if(visible==1) {
        if(active==1) {
            glColor3f(1, 1, 1);
        } else {
            glColor3f(0.8, 0.8, 0.8);
        }

        glTranslatef(get_pos_x(), get_pos_y(), 0);
        glBindTexture(GL_TEXTURE_2D, st);

        glBegin(GL_QUADS);
        //left end
        glTexCoord2f(0, 0.25);
        glVertex2d(0, 16);
        glTexCoord2f(0.25, 0.25);
        glVertex2d(16, 16);
        glTexCoord2f(0.25, 0);
        glVertex2d(16, 0);
        glTexCoord2f(0, 0);
        glVertex2d(0, 0);

        //middle
        glTexCoord2f(0.25, 0.25);
        glVertex2d(16, 16);
        glTexCoord2f(0.5, 0.25);
        glVertex2d(get_size_x()-16, 16);
        glTexCoord2f(0.5, 0);
        glVertex2d(get_size_x()-16, 0);
        glTexCoord2f(0.25, 0);
        glVertex2d(16, 0);

        //right end
        glTexCoord2f(0.5, 0.25);
        glVertex2d(get_size_x()-16, 16);
        glTexCoord2f(0.75, 0.25);
        glVertex2d(get_size_x(), 16);
        glTexCoord2f(0.75, 0);
        glVertex2d(get_size_x(), 0);
        glTexCoord2f(0.5, 0);
        glVertex2d(get_size_x()-16, 0);


        //overlay
        //left end
        float dv = value/(16/get_size_x());
        if(dv>1) dv = 1;
        glTexCoord2f(0, 0.5);
        glVertex2d(0, 16);
        glTexCoord2f(0.25*dv, 0.5);
        glVertex2d(16*dv, 16);
        glTexCoord2f(0.25*dv, 0.25);
        glVertex2d(16*dv, 0);
        glTexCoord2f(0, 0.25);
        glVertex2d(0, 0);


        //middle
        if((value*get_size_x())>16) {
            dv = (value*get_size_x()-16)/(get_size_x()-32);
            if(dv>1) dv = 1;
            glTexCoord2f(0.25, 0.5);
            glVertex2d(16, 16);
            glTexCoord2f(0.5, 0.5);
            glVertex2d(16.0+(get_size_x()-32.0)*dv, 16);
            glTexCoord2f(0.5, 0.25);
            glVertex2d(16.0+(get_size_x()-32.0)*dv, 0);
            glTexCoord2f(0.25, 0.25);
            glVertex2d(16, 0);
        }

        //right end
        if((value*get_size_x())>get_size_x()-16) {
            dv = (value*get_size_x()-get_size_x()+16)/16;
            if(dv>1) dv = 1;
            glTexCoord2f(0.5, 0.5);
            glVertex2d(get_size_x()-16, 16);
            glTexCoord2f(0.5+dv*0.25, 0.5);
            glVertex2d(get_size_x()-16+dv*16, 16);
            glTexCoord2f(0.5+dv*0.25, 0.25);
            glVertex2d(get_size_x()-16+dv*16, 0);
            glTexCoord2f(0.5, 0.25);
            glVertex2d(get_size_x()-16, 0);
        }


        //slider
        glTexCoord2f(0.75, 0.25);
        glVertex2d(value*(get_size_x()-16), 16);
        glTexCoord2f(1, 0.25);
        glVertex2d(value*(get_size_x()-16)+16, 16);
        glTexCoord2f(1, 0.);
        glVertex2d(value*(get_size_x()-16)+16, 0);
        glTexCoord2f(0.75, 0);
        glVertex2d(value*(get_size_x()-16), 0);

        glEnd();
    }
    return;
}

bool gui_hor_slider::take_input() {
    int mx,my,lb,mb,rb;
    FsGetMouseState(lb,mb,rb,mx,my);

    if(is_active()) {
        if(mx>=get_abs_pos_x() && mx<=get_abs_pos_x()+get_size_x() && my>=get_abs_pos_y() && my<=get_abs_pos_y()+get_size_y() && lb==1) {
            value=(mx-get_abs_pos_x()-8)/(get_size_x()-16);
        }
    }

    if(value>1) value=1;
    if(value<0) value=0;

    if(mx>=get_abs_pos_x() && mx<=get_abs_pos_x()+get_size_x() && my>=get_abs_pos_y() && my<=get_abs_pos_y()+get_size_y() && visible){
        return true;
    }
    else{
        return false;
    }
}

void gui_hor_slider::set_value(float v){
    value=v;
    return;
}

float gui_hor_slider::get_value(){
    return value;
}
