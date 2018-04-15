#ifndef GUI_GRAPHIC_H
#define GUI_GRAPHIC_H
#include <string>
#include "gui_element.h"


class gui_graphic : public gui_element
{
    public:
        gui_graphic();
        virtual ~gui_graphic();

        virtual void draw();

        void set_texture(GLuint t);

        void set_graphic_size(int x, int y);

        void load_from_file(std::string filename);

    protected:
    private:
        float gx;
        float gy;
        GLuint tex;
        bool loaded;
};

#endif // GUI_GRAPHIC_H
