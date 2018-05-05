#include "gui_progressbar.h"


gui_progressbar::gui_progressbar()
{
    //ctor
    value=0.0;
    size_y=16;

    pb = 0;
}

gui_progressbar::~gui_progressbar()
{
    //dtor
}

void gui_progressbar::init(){
    if(pb==0) pb=get_texture("progressbar.png");
    return;
}

void gui_progressbar::draw() {
    if(visible==1) {
        if(active==1) {
            glColor3f(1, 1, 1);
        } else {
            glColor3f(0.8, 0.8, 0.8);
        }

        glTranslatef(get_pos_x(), get_pos_y(), 0);
        glBindTexture(GL_TEXTURE_2D, pb);

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

        glEnd();
    }
    return;
}

void gui_progressbar::set_value(float v){
    value=v;
    return;
}

float gui_progressbar::get_value(){
    return value;
}
