#ifndef GUI_WINDOW_ACCESSOIRE_H
#define GUI_WINDOW_ACCESSOIRE_H

#include "GuiIsClickable.h"
#include "guiHasAdjustablePosX.h"


class GuiWindowAccessoire : public GuiIsClickable, public GuiHasAdjustablePosX {
public:
    GuiWindowAccessoire();
    ~GuiWindowAccessoire();

    void init();

    void setType( int t );

    virtual void render();

protected:

private:
    int i_type;
    GLuint wat;
};

#endif // GUI_WINDOW_ACCESSOIRE_H
