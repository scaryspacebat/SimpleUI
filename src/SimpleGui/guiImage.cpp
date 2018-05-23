#include "guiImage.hpp"

#include "../lodepng.h"

#include <cmath>
#include <vector>
#include <iostream>
#include <gl\gl.h>


GuiImage::GuiImage() {
    //ctor
    tex=0;
    gx=1;
    gy=1;
    loaded=false;
}

GuiImage::~GuiImage() {
    //dtor
}

void GuiImage::render() {
        float dx = 1;
        float dy = 1;

        float sx=getSizeX();
        float sy=getSizeY();

        float rat = sx/sy;

        if( gx/gy<rat )
            dx=( gx/gy )/rat;
        else if( gx/gy>rat )
            dy=rat/( gx/gy );

        glTranslatef( floor( getRelPosX()+( 1-dx )*0.5*sx ), floor( getRelPosY()+( 1-dy )*0.5*sy ), 0 );
        glBindTexture( GL_TEXTURE_2D, tex );

        glBegin( GL_QUADS );

        glTexCoord2f( 0, 1 );
        glVertex2d( 0, dy*sy );
        glTexCoord2f( 1, 1 );
        glVertex2d( dx*sx, dy*sy);
        glTexCoord2f( 1, 0 );
        glVertex2d( dx*sx, 0 );
        glTexCoord2f( 0, 0 );
        glVertex2d( 0, 0 );

        glEnd();

    return;
}

void GuiImage::setTexture( GLuint t ) {
    tex=t;
    loaded=true;
    return;
}

void GuiImage::setImageSize( int x, int y ) {
    gx=x;
    gy=y;
    return;
}

void GuiImage::loadFromFile( std::string filename ) {
    loaded=true;
    std::vector<unsigned char> image;
    unsigned width, height;
    lodepng::decode( image, width, height, filename );
    if( image.size()==0 )
        lodepng::decode( image, width, height, "gui/default/missing.png" );

    setImageSize( width, height );

    for( int y=0; y<height; y++ ) {
        for( int x=0; x<width; x++ ) {
            unsigned char r;
            unsigned char g;
            unsigned char b;
            unsigned char a;

            r=image[x*4+y*width*4];
            g=image[x*4+y*width*4+1];
            b=image[x*4+y*width*4+2];
            a=image[x*4+y*width*4+3];

            image[x*4+y*width*4]=( r*a )/255;
            image[x*4+y*width*4+1]=( g*a )/255;
            image[x*4+y*width*4+2]=( b*a )/255;
            image[x*4+y*width*4+3]=a;
        }
    }

    // unless tex==0 unload the texture first?

    glEnable( GL_TEXTURE_2D );
    glGenTextures( 1, &tex );

    glBindTexture( GL_TEXTURE_2D, tex );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST ); //GL_NEAREST = no smoothing
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST );
    glTexImage2D( GL_TEXTURE_2D, 0, 4, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, &image[0] );

    glBindTexture( GL_TEXTURE_2D, 0 );
    return;
}
