#ifndef GUI_ELEMENT_H
#define GUI_ELEMENT_H
#include <gl\gl.h>
#include <string>

class gui_element
{
    public:
        gui_element();
        virtual ~gui_element();

        virtual void draw();

        void set_size(float x, float y, float rx=0, float ry=0);
        void set_pos(float x, float y, float rx=0, float ry=0);

        float get_pos_x();
        float get_pos_y();

        virtual float get_abs_pos_x();
        virtual float get_abs_pos_y();

        virtual float get_size_x();
        virtual float get_size_y();

        void set_parent(gui_element* p);

        virtual bool take_input();

        virtual void make_active();
        virtual void make_inactive();
        virtual void make_visible();
        virtual void make_invisible();

        virtual int is_active();

        static void use_theme(std::string t);

    protected:
        float size_x;
        float size_y;

        float r_size_x;
        float r_size_y;

        float pos_x;
        float pos_y;

        float r_pos_x;
        float r_pos_y;

        int active;
        int visible;

        gui_element* parent;

        static GLuint load_texture(std::string f);
        static std::string theme;

    private:
};

#endif // GUI_ELEMENT_H
