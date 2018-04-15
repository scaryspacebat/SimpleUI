#include "gui_container.h"

gui_container::gui_container()
{
    //ctor
    size_x = 0;
    size_y = 0;
}

gui_container::~gui_container()
{
    //dtor
}

void gui_container::draw(){
    for(int i=0; i<content.get_size(); i++){
    //for(int i=content.get_size()-1; i>=0; i--){
        glPushMatrix();
        content.get_data(i)->draw();
        glPopMatrix();
    }
    return;
}

bool gui_container::take_input(){
    bool r=false;
    int i=content.get_size()-1;
    while(i>=0 && r!=true){
        r=content.get_data(i)->take_input();
        i--;
    }
    return r;
}

void gui_container::add_element(gui_element* new_el){
    new_el->set_parent(this);
    content.add(new_el);
    return;
}

void gui_container::make_active(){
    active=1;
    for(int i=0; i<content.get_size(); i++){
        content.get_data(i)->make_active();
    }
    return;
}

void gui_container::make_inactive(){
    active=0;
    for(int i=0; i<content.get_size(); i++){
        content.get_data(i)->make_inactive();
    }
    return;
}

void gui_container::make_visible(){
    visible=1;
    for(int i=0; i<content.get_size(); i++){
        content.get_data(i)->make_visible();
    }
    return;
}

void gui_container::make_invisible(){
    visible=0;
    for(int i=0; i<content.get_size(); i++){
        content.get_data(i)->make_invisible();
    }
    return;
}

