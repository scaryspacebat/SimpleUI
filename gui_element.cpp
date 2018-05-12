#include "gui_element.h"

#include "lodepng.h"
#include "log.h"
#include "gui.h"

#include <iostream>

gui_element::gui_element()
{
    //ctor
    size_x=100;
    size_y=100;

    r_size_x=0;
    r_size_y=0;

    pos_x=0;
    pos_y=0;

    r_pos_x=0;
    r_pos_y=0;

    active=1;
    visible=1;

    parent=nullptr;
}

gui_element::~gui_element()
{
    //dtor
}

void gui_element::init(){

    return;
}

void gui_element::draw(){

    return;
}

void gui_element::set_size(float x, float y, float rx, float ry){
    size_x = x;
    size_y = y;
    r_size_x = rx;
    r_size_y = ry;
}

void gui_element::set_pos(float x, float y, float rx, float ry){
    pos_x = x;
    pos_y = y;
    r_pos_x = rx;
    r_pos_y = ry;
}

float gui_element::get_size_x(){
    if(parent==nullptr){
        return size_x;
    }
    else{
        return size_x+parent->get_size_x()*r_size_x;
    }
}

float gui_element::get_size_y(){
    if(parent==nullptr){
        return size_y;
    }
    else{
        return size_y+parent->get_size_y()*r_size_y;
    }
}

float gui_element::get_pos_x(){
    return pos_x+parent->get_size_x()*r_pos_x;
}

float gui_element::get_pos_y(){
    return pos_y+parent->get_size_y()*r_pos_y;
}

float gui_element::get_abs_pos_x(){
    return get_pos_x()+parent->get_abs_pos_x();
}

float gui_element::get_abs_pos_y(){
    return get_pos_y()+parent->get_abs_pos_y();
}

void gui_element::set_parent(gui_element* p){
    parent=p;
    return;
}

gui* gui_element::get_parent_gui(){
    if(parent!=nullptr) return parent->get_parent_gui();
    return nullptr;
}

bool gui_element::take_input(){
    return false;
}

void gui_element::make_active(){
    active=1;
    return;
}

void gui_element::make_inactive(){
    active=0;
    return;
}

void gui_element::make_visible(){
    visible=1;
    return;
}

void gui_element::make_invisible(){
    visible=0;
    return;
}

int gui_element::is_active(){
    if(active==1 && visible==1){
        return 1;
    }
    else{
        return 0;
    }
}

GLuint gui_element::get_texture(std::string f) {
    gui* g=get_parent_gui();
    if(g==nullptr){
        log::writeToLog("unable to find parent GUI to load "+f, -1);
        return 0;
    }
    else return get_parent_gui()->load_texture(f);
    /*
    GLuint tid;
    vector<unsigned char> image;
    unsigned width, height;
    log_manager::write_log("loading texture from gui/"+theme+"/"+f);
    lodepng::decode(image, width, height, "gui/"+theme+"/"+f);
    if(image.size()==0){
        log_manager::write_log("Unable to load texture from gui/"+theme+"/"+f);
        lodepng::decode(image, width, height, "gui/default/"+f);
    }

    for(int y=0; y<height; y++) {
        for(int x=0; x<width; x++) {
            unsigned char r;
            unsigned char g;
            unsigned char b;
            unsigned char a;

            r=image[x*4+y*width*4];
            g=image[x*4+y*width*4+1];
            b=image[x*4+y*width*4+2];
            a=image[x*4+y*width*4+3];

            image[x*4+y*width*4]=(r*a)/255;
            image[x*4+y*width*4+1]=(g*a)/255;
            image[x*4+y*width*4+2]=(b*a)/255;
            image[x*4+y*width*4+3]=a;
        }
    }

    glEnable(GL_TEXTURE_2D);
    glGenTextures(1, &tid);

    glBindTexture(GL_TEXTURE_2D, tid);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); //GL_NEAREST = no smoothing
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, 4, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, &image[0]);

    glBindTexture(GL_TEXTURE_2D, 0);
    */
}
