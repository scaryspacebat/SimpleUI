#include "guiElement.hpp"

#include "guiFramework.hpp"
#include "guiContainer.hpp"

#include "../log.h"

#include <iostream>


GuiElement::GuiElement() {
    //ctor
    f_size_x=0;
    f_size_y=0;
    f_rel_size_x=0;
    f_rel_size_y=0;

    f_pos_x=0;
    f_pos_y=0;
    f_rel_pos_x=0;
    f_rel_pos_y=0;

    f_abs_size_x=-1;
    f_abs_size_y=-1;

    f_abs_pos_x=-1;
    f_abs_pos_y=-1;

    b_active=true;
    b_visible=true;

    _gc_parent=nullptr;
}

GuiElement::~GuiElement() {
    //dtor
}

void GuiElement::init() {

    return;
}

void GuiElement::render() {

    return;
}

void GuiElement::draw() {
    if( b_visible==true ) {
        if( isActive()==false )
            glColor4f( 0.8, 0.8, 0.8, 1.0);
        render();
        if( isActive()==false )
            glColor4f( 1.0, 1.0, 1.0, 1.0);
    }
    return;
}

float GuiElement::getRelPosX() {
    if(_gc_parent)
        return f_pos_x+f_rel_pos_x*_gc_parent->getUsableWidth();
    return f_pos_x;
}

float GuiElement::getRelPosY() {
    if(_gc_parent)
        return f_pos_y+f_rel_pos_y*_gc_parent->getUsableHeight();
    return f_pos_y;
}

float GuiElement::getAbsPosX() {
    if( f_abs_pos_x<0 ){
        f_abs_pos_x=getRelPosX();
        if(_gc_parent) f_abs_pos_x+=_gc_parent->getAnchorPointX();
    }
    return f_abs_pos_x;
}

float GuiElement::getAbsPosY() {
    if( f_abs_pos_y<0 ){
        f_abs_pos_y=getRelPosY();
        if(_gc_parent) f_abs_pos_y+=_gc_parent->getAnchorPointY();
    }
    return f_abs_pos_y;
}

float GuiElement::getSizeX() {
    if( f_abs_size_x<0 ){
        f_abs_size_x=f_size_x;
        if(_gc_parent) f_abs_size_x+=f_rel_size_x*_gc_parent->getUsableWidth();
    }
    return f_abs_size_x;
}

float GuiElement::getSizeY() {
    if( f_abs_size_y<0 ){
        f_abs_size_y=f_size_y;
        if(_gc_parent) f_abs_size_y+=f_rel_size_y*_gc_parent->getUsableHeight();
    }
    return f_abs_size_y;
}

void GuiElement::setSizeX( float x, float rx ) {
    f_size_x=x;
    f_rel_size_x=rx;
    f_abs_size_x=-1;
    return;
}

void GuiElement::setSizeY( float y, float ry ) {
    f_size_y=y;
    f_rel_size_y=ry;
    f_abs_size_y=-1;
    return;
}

void GuiElement::setPosX( float x, float rx ){
    f_pos_x=x;
    f_rel_pos_x=rx;
    f_abs_pos_x=-1;
    return;
}

void GuiElement::setPosY( float y, float ry ){
    f_pos_y=y;
    f_rel_pos_y=ry;
    f_abs_pos_y=-1;
    return;
}

void GuiElement::setParent( GuiContainer* p ) {
    _gc_parent=p;
    f_abs_pos_x=-1;
    f_abs_pos_y=-1;
    f_abs_size_x=-1;
    f_abs_size_y=-1;
    return;
}

GuiFramework* GuiElement::getParentGuiFramework() {
    if( _gc_parent!=nullptr )
        return _gc_parent->getParentGuiFramework();
    return nullptr;
}

bool GuiElement::assessInput( int mx, int my, int lb, int mb, int rb ) {
    if( isActive()==false )
        return false;
    return acceptInput( mx, my, lb, mb, rb );
}

bool GuiElement::acceptInput( int mx, int my, int lb, int mb, int rb ) {
    return false;
}

void GuiElement::activate() {
    b_active=true;
    return;
}

void GuiElement::deactivate() {
    b_active=false;
    return;
}

void GuiElement::makeVisible() {
    b_visible=true;
    return;
}

void GuiElement::makeInvisible() {
    b_visible=false;
    return;
}

void GuiElement::toggleVisibillity(){
    b_visible=!b_visible;
    return;
}

bool GuiElement::isActive() {
    if( b_active==true && b_visible==true )
        return true;
    else
        return false;
}

bool GuiElement::isVisible() {
    return b_visible;
}

GLuint GuiElement::getTexture( std::string f ) {
    GuiFramework* g=getParentGuiFramework();
    if( g==nullptr ) {
        log::writeToLog( "Unable to find parent GUI to load texture"+f, -1 );
        return 0;
    }
    else
        return g->loadTexture( f );
}

void GuiElement::recalculate(){
    f_abs_pos_x=-1;
    f_abs_pos_y=-1;
    f_abs_size_x=-1;
    f_abs_size_y=-1;
    return;
}
