#ifndef GUI_H
#define GUI_H
#include <string>
#include "gui_container.h"

using namespace std;

class gui : public gui_container
{
    public:
        gui(string t="default");
        virtual ~gui();

        virtual void init();

        virtual void draw();

        void drawBackground();

        virtual float get_abs_pos_x();
        virtual float get_abs_pos_y();

        virtual float get_size_x();
        virtual float get_size_y();

        bool has_recieved_input();

        void set_bg_visibility(bool d);

        gui* get_parent_gui();

        void setTheme(string t);

        GLuint load_texture(string f);

    protected:
    private:
        GLuint tid;
        bool ui_rec;
        bool bg_visible;
        string theme;

        struct tex{
            string filename;
            GLuint id;
        };
        chain<tex*> texture_list;
};

#endif // GUI_H
