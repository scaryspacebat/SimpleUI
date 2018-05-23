#ifndef GUI_CONTAINER_H
#define GUI_CONTAINER_H

#include "guiElement.hpp"

#include <vector>


class GuiContainer : virtual public GuiElement {
public:
    GuiContainer();
    virtual ~GuiContainer();

    virtual void init();

    virtual void draw();

    virtual bool assessInput( int mx, int my, int lb, int mb, int rb );

    void addElement( GuiElement* new_el );

    float getAnchorPointX();
    float getAnchorPointY();

    float getUsableWidth();
    float getUsableHeight();

    virtual void recalculate();

protected:
    std::vector<GuiElement*> vge_content;

    virtual void setSizeX(float x, float rx=0);
    virtual void setSizeY(float y, float ry=0);
    virtual void setPosX(float x, float rx=0);
    virtual void setPosY(float y, float ry=0);
private:
};

#endif // GUI_CONTAINER_H
