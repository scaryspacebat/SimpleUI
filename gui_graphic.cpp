#include "gui_graphic.h"
#include <cmath>
#include <vector>
#include <gl\gl.h>
#include "lodepng.h"
#include <iostream>

using namespace std;

gui_graphic::gui_graphic() {
    //ctor
    tex=0;
    gx=1;
    gy=1;
    loaded=false;
}

gui_graphic::~gui_graphic() {
    //dtor
}

void gui_graphic::draw() {
    if(visible==1) {
        if(active==1) {
            glColor3f(1, 1, 1);
        } else {
            glColor3f(0.8, 0.8, 0.8);
        }

        float dx = 1;
        float dy = 1;

        float rat = get_size_x()/get_size_y();

        if(gx/gy<rat){
            dx=(gx/gy)/rat;
        }
        else if(gx/gy>rat){
            dy=rat/(gx/gy);
        }


        glTranslatef(floor(get_pos_x()+(1-dx)*0.5*get_size_x()), floor(get_pos_y()+(1-dy)*0.5*get_size_y()), 0);
        glBindTexture(GL_TEXTURE_2D, tex);

        glBegin(GL_QUADS);

        glTexCoord2f(0, 1);
        glVertex2d(0, dy*get_size_y());
        glTexCoord2f(1, 1);
        glVertex2d(dx*get_size_x(), dy*get_size_y());
        glTexCoord2f(1, 0);
        glVertex2d(dx*get_size_x(), 0);
        glTexCoord2f(0, 0);
        glVertex2d(0, 0);

        glEnd();
    }
    return;
}

void gui_graphic::set_texture(GLuint t) {
    tex=t;
    return;
}

void gui_graphic::set_graphic_size(int x, int y) {
    gx=x;
    gy=y;
    return;
}

void gui_graphic::load_from_file(std::string filename){
    std::vector<unsigned char> image;
    unsigned width, height;
    lodepng::decode(image, width, height, filename);
    if(image.size()==0){
        lodepng::decode(image, width, height, "gui/default/missing.png");
    }

    set_graphic_size(width, height);

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
    glGenTextures(1, &tex);

    glBindTexture(GL_TEXTURE_2D, tex);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); //GL_NEAREST = no smoothing
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, 4, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, &image[0]);

    glBindTexture(GL_TEXTURE_2D, 0);
    return;
}
