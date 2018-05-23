#include "guiTextLine.hpp"
#include <cmath>

GuiTextLine::GuiTextLine( std::string t ): text( t ) {
    //ctor
    i_font_size=8;

    f8_id = 0;
    f16_id = 0;
}

GuiTextLine::~GuiTextLine() {
    //dtor
}

void GuiTextLine::init() {
    if( f8_id==0 )
        f8_id=getTexture( "font-8.png" );
    if( f16_id==0 )
        f16_id=getTexture( "font-16.png" );
    return;
}

void GuiTextLine::render() {
        glTranslatef( getRelPosX(), getRelPosY(), 0 );

        if( i_font_size==8 )
            glBindTexture( GL_TEXTURE_2D, f8_id );
        else if( i_font_size==16 )
            glBindTexture( GL_TEXTURE_2D, f16_id );

        glBegin( GL_QUADS );

        for( int i=0; i<text.length(); i++ ) {
            char d = text[i];
            float x=d%16;
            float y=floor( d/16 );
            glTexCoord2f( x*0.0625, ( y+1 )*0.0625 );
            glVertex2d( i*i_font_size, i_font_size );

            glTexCoord2f( ( x+1 )*0.0625, ( y+1 )*0.0625 );
            glVertex2d( ( i+1 )*i_font_size, i_font_size );

            glTexCoord2f( ( x+1 )*0.0625, y*0.0625 );
            glVertex2d( ( i+1 )*i_font_size, 0 );

            glTexCoord2f( x*0.0625, y*0.0625 );
            glVertex2d( i*i_font_size, 0 );
        }

        glEnd();

    return;
}

void GuiTextLine::setText( std::string t ) {
    text=t;
    setSizeX(text.length()*i_font_size);
    return;
}

void GuiTextLine::setFontSize( int s ) {
    if( s==8 || s==16 )
        i_font_size=s;
    return;
}
