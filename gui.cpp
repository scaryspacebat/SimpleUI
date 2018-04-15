#include "gui.h"
#include "lodepng.h"
#include <iostream>

using namespace std;


gui::gui() {
    //ctor
    tid = load_texture("background.png");
    ui_rec=false;
    bg_visible=false;
}

gui::~gui() {
    //dtor
}

void gui::draw() {
    glColor3f(1, 1, 1);
    if(bg_visible){
    glBindTexture(GL_TEXTURE_2D, tid);

    glBegin(GL_QUADS);
    glTexCoord2f(0, (size_y+1)/16.0);
    glVertex2d(0, size_y);

    glTexCoord2f((size_x+1)/16.0, (size_y+1)/16.0);
    glVertex2d(size_x, size_y);

    glTexCoord2f((size_x+1)/16.0, 0);
    glVertex2d(size_x, 0);

    glTexCoord2f(0, 0);
    glVertex2d(0, 0);
    glEnd();
    }

    glViewport(0,0,size_x,size_y);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(0,(float)size_x-1,(float)size_y-1,0,-1,1);

    ui_rec=gui_container::take_input();
    gui_container::draw();
    return;
}

float gui::get_abs_pos_x(){
    return 0;
}

float gui::get_abs_pos_y(){
    return 0;
}

float gui::get_size_x(){
    return size_x;
}

float gui::get_size_y(){
    return size_y;
}

bool gui::has_recieved_input(){
    return ui_rec;
}

void gui::set_bg_visibility(bool d){
    bg_visible=d;
    return;
}
