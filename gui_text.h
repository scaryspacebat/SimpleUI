#ifndef GUI_TEXT_H
#define GUI_TEXT_H
#include <string>
#include "gui_element.h"

class gui_text : public gui_element
{
    public:
        gui_text(std::string t="");
        virtual ~gui_text();

        virtual void init();

        virtual void draw();

        void set_text(std::string t);

        void set_text_size(int s);

    protected:
    private:
        std::string text;
        GLuint f8_id;
        GLuint f16_id;
        int t_size;
};

#endif // GUI_TEXT_H
