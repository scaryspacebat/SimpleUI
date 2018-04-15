#include "gui_graphic_container.h"

GLuint gui_graphic_container::cst1 = 0;
GLuint gui_graphic_container::cst2 = 0;
GLuint gui_graphic_container::cst3 = 0;

gui_graphic_container::gui_graphic_container()
{
    //ctor
    if(cst1==0) cst1 = load_texture("container_bg_1.png");
    if(cst2==0) cst2 = load_texture("container_bg_2.png");
    if(cst3==0) cst3 = load_texture("container_bg_3.png");
    style = 1;
}

gui_graphic_container::~gui_graphic_container()
{
    //dtor
}

void gui_graphic_container::draw() {
    if(visible==1) {
        if(active==1) {
            glColor3f(1, 1, 1);
        } else {
            glColor3f(0.8, 0.8, 0.8);
        }

        glTranslatef(get_pos_x(), get_pos_y(), 0);
        if(style == 1) glBindTexture(GL_TEXTURE_2D, cst1);
        else if(style == 2) glBindTexture(GL_TEXTURE_2D, cst2);
        else if(style == 3) glBindTexture(GL_TEXTURE_2D, cst3);

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

void gui_graphic_container::set_style(int s){
    style = s;
    return;
}
