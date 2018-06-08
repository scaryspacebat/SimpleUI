#ifndef GUI_ELEMENT_H
#define GUI_ELEMENT_H

#include <gl\gl.h>
#include <string>

class GuiFramework;

class GuiContainer;

class GuiElement {
public:
    GuiElement();
    virtual ~GuiElement();

    virtual void init();

    virtual void draw();

    virtual float getRelPosX();
    virtual float getRelPosY();

    virtual float getAbsPosX();
    virtual float getAbsPosY();

    virtual float getSizeX();
    virtual float getSizeY();

    void setParent( GuiContainer* p );
    virtual GuiFramework* getParentGuiFramework();

    virtual bool assessInput( int mx, int my, int lb, int mb, int rb );

    virtual void activate();
    virtual void deactivate();
    virtual void makeVisible();
    virtual void makeInvisible();
    virtual void toggleVisibillity();

    virtual bool isActive();
    virtual bool isVisible();

    virtual void recalculate();

protected:
    bool b_active;
    bool b_visible;

    GuiContainer* _gc_parent;

    void setSizeX( float x, float rx=0 );
    void setSizeY( float y, float ry=0 );

    void setPosX( float x, float ry=0 );
    void setPosY( float x, float ry=0 );

    virtual void render();

    virtual bool acceptInput( int mx, int my, int lb, int mb, int rb );

    GLuint getTexture( std::string f );

private:
    float f_size_x;
    float f_size_y;
    float f_rel_size_x;
    float f_rel_size_y;

    float f_pos_x;
    float f_pos_y;
    float f_rel_pos_x;
    float f_rel_pos_y;

    float f_abs_size_x;
    float f_abs_size_y;

    float f_abs_pos_x;
    float f_abs_pos_y;
};

#endif // GUI_ELEMENT_H
