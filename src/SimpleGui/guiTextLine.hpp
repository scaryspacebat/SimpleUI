#ifndef GUI_TEXT_H
#define GUI_TEXT_H

#include "GuiHasAdjustablePosXY.h"

#include <string>


class GuiTextLine : public GuiHasAdjustablePosXY {
public:
    GuiTextLine( std::string t="" );
    virtual ~GuiTextLine();

    virtual void init();

    virtual void render();

    void setText( std::string t );

    void setFontSize( int s );

protected:
private:
    std::string text;
    GLuint f8_id;
    GLuint f16_id;
    int i_font_size;
};

#endif // GUI_TEXT_H
