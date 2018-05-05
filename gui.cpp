#include "gui.h"
#include "lodepng.h"
#include "log_manager.h"
#include <iostream>

using namespace std;


gui::gui(string t): theme(t) {
    //ctor
    tid=0;
    ui_rec=false;
    bg_visible=true;
}

gui::~gui() {
    //dtor
    for(int i=0; i<texture_list.get_size(); i++) {
        delete texture_list.get_data(i);
    }
}

void gui::init() {
    if(tid==0) tid = get_texture("background.png");
    gui_container::init();
    return;
}

void gui::draw() {
    glViewport(0,0,size_x,size_y);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0,(float)size_x-1,(float)size_y-1,0,-1,1);

    ui_rec=gui_container::take_input();
    gui_container::draw();
    return;
}

void gui::drawBackground(){
    glColor3f(1, 1, 1);
    if(bg_visible) {
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
    return;
}

float gui::get_abs_pos_x() {
    return 0;
}

float gui::get_abs_pos_y() {
    return 0;
}

float gui::get_size_x() {
    return size_x;
}

float gui::get_size_y() {
    return size_y;
}

bool gui::has_recieved_input() {
    return ui_rec;
}

void gui::set_bg_visibility(bool d) {
    bg_visible=d;
    return;
}

gui* gui::get_parent_gui() {
    return this;
}

void gui::setTheme(string t) {
    theme=t;
    return;
}

GLuint gui::load_texture(string f) {
    for(int i=0; i<texture_list.get_size(); i++) {
        if(texture_list.get_data(i)->filename==f){ // found an already loaded texture
            log_manager::write_log("found an already loaded texture for "+f);
            return texture_list.get_data(i)->id;
        }
    }

    GLuint tid;
    vector<unsigned char> image;
    unsigned width, height;
    log_manager::write_log("loading texture from gui/"+theme+"/"+f);
    lodepng::decode(image, width, height, "gui/"+theme+"/"+f);
    if(image.size()==0) {
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

    tex* tEntry = new tex;
    tEntry->filename=f;
    tEntry->id=tid;
    texture_list.add(tEntry);

    return tid;
}





