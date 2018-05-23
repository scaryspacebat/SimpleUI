#ifndef GUI_GRAPHIC_H
#define GUI_GRAPHIC_H

#include "guiIsSolid.h"
#include "GuiHasAdjustableSizeXY.h"
#include "guiHasAdjustablePosXY.h"

#include <string>


class GuiImage :    public GuiIsSolid,
                    public GuiHasAdjustableSizeXY, public GuiHasAdjustablePosXY {
public:
    GuiImage();
    virtual ~GuiImage();

    virtual void render();

    void setTexture( GLuint t );

    void setImageSize( int x, int y );

    void loadFromFile( std::string filename );

protected:
private:
    float gx;
    float gy;
    GLuint tex;
    bool loaded;
};

#endif // GUI_GRAPHIC_H
