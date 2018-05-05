#include "gui_text.h"
#include <cmath>

gui_text::gui_text(std::string t): text(t) {
    //ctor
    t_size=8;

    f8_id = 0;
    f16_id = 0;
}

gui_text::~gui_text() {
    //dtor
}

void gui_text::init() {
    if(f8_id==0) f8_id=get_texture("font-8.png");
    if(f16_id==0) f16_id=get_texture("font-16.png");
    return;
}

void gui_text::draw() {
    if(visible==1) {
        if(active==1) {
            glColor3f(1, 1, 1);
        } else {
            glColor3f(0.8, 0.8, 0.8);
        }

        glTranslatef(get_pos_x(), get_pos_y(), 0);
        if(t_size==8) glBindTexture(GL_TEXTURE_2D, f8_id);
        else if(t_size==16) glBindTexture(GL_TEXTURE_2D, f16_id);

        glBegin(GL_QUADS);

        for(int i=0; i<text.length(); i++) {
            char d = text[i];
            float x=d%16;
            float y=floor(d/16);
            glTexCoord2f(x*0.0625, (y+1)*0.0625);
            glVertex2d(i*t_size, t_size);

            glTexCoord2f((x+1)*0.0625, (y+1)*0.0625);
            glVertex2d((i+1)*t_size, t_size);

            glTexCoord2f((x+1)*0.0625, y*0.0625);
            glVertex2d((i+1)*t_size, 0);

            glTexCoord2f(x*0.0625, y*0.0625);
            glVertex2d(i*t_size, 0);
        }

        glEnd();
    }

    return;
}

void gui_text::set_text(std::string t) {
    text=t;
    return;
}

void gui_text::set_text_size(int s) {
    if(s==8 || s==16) {
        t_size=s;
    }
    return;
}
