#ifndef GUI_H
#define GUI_H

#include "guiContainer.hpp"

#include <string>
#include <vector>


class GuiFramework : public GuiContainer {
public:
    GuiFramework( std::string t="default" );
    virtual ~GuiFramework();

    virtual void init();

    void update();

    virtual void draw();

    void drawBackground();

    bool hasRecievedInput();

    void setBackgroundVisibility( bool d );

    GuiFramework* getParentGuiFramework();

    void setSize(int x, int y);

    void setTheme( std::string t );

    GLuint loadTexture( std::string f );

protected:
private:
    GLuint tid;
    bool ui_rec;
    bool bg_visible;
    std::string s_theme;

    struct tex {
        std::string s_filename;
        GLuint id;
    };
    std::vector<tex*> texture_list;
};

#endif // GUI_H
