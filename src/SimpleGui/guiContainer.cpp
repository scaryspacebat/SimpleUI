#include "guiContainer.hpp"

#include "../log.h"


GuiContainer::GuiContainer()
{
    //ctor
    setSizeX( 0, 1 );
    setSizeY( 0, 1 );
}

GuiContainer::~GuiContainer()
{
    //dtor
}

void GuiContainer::init() {
    for( int i=0; i<vge_content.size(); i++ )
        vge_content[i]->init();
    return;
}

void GuiContainer::draw() {
    if( isVisible()==true ) {
        if( isActive()==false )
            glColor4f( 0.8, 0.8, 0.8, 1.0 );
        render();
        //for(int i=content.get_size()-1; i>=0; i--){ // reversed order
        for( int i=0; i<vge_content.size(); i++ ) {
            glPushMatrix();
            vge_content[i]->draw();
            glPopMatrix();
        }
        if( isActive()==false )
            glColor4f( 1.0, 1.0, 1.0, 1.0 );
    }

    return;
}

bool GuiContainer::assessInput( int mx, int my, int lb, int mb, int rb ) {
    bool r=false;
    if( isActive()==true ) {
        int i=vge_content.size()-1;
        while( i>=0 && r!=true ) {
            r=vge_content[i]->assessInput( mx, my, lb, mb, rb );
            i--;
        }
        if( r==false )
            r=acceptInput( mx, my, lb, mb, rb );
    }
    return r;
}

void GuiContainer::addElement( GuiElement* new_el ) {
    if( new_el!=nullptr ) {
        new_el->setParent( this );
        vge_content.push_back( new_el );
    }
    return;
}

bool GuiContainer::removeElement( GuiElement* el ) {
    bool found=false;
    if( el!=nullptr ) {
        int i=0;
        while( found==false && i<vge_content.size() ) {
            if( vge_content[i]==el ) {
                found=true;
                vge_content.erase(vge_content.begin()+i);
            }
            i++;
        }
    }
    return found;
}

float GuiContainer::getAnchorPointX() {
    return getAbsPosX();
}

float GuiContainer::getAnchorPointY() {
    return getAbsPosY();
}

float GuiContainer::getUsableWidth() {
    return getSizeX();
}

float GuiContainer::getUsableHeight() {
    return getSizeY();
}

void GuiContainer::recalculate() {
    GuiElement::recalculate();
    for( int i=0; i<vge_content.size(); i++ )
        vge_content[i]->recalculate();
    return;
}

void GuiContainer::setSizeX( float x, float rx ) {
    GuiElement::setSizeX( x, rx );
    recalculate();
    return;
}

void GuiContainer::setSizeY( float y, float ry ) {
    GuiElement::setSizeY( y, ry );
    recalculate();
    return;
}

void GuiContainer::setPosX( float x, float rx ) {
    GuiElement::setPosX( x, rx );
    recalculate();
    return;
}

void GuiContainer::setPosY( float y, float ry ) {
    GuiElement::setPosY( y, ry );
    recalculate();
    return;
}
