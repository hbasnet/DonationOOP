#ifndef ABOUT_H
#define ABOUT_H

#include <gtkmm.h>

class About_window : public Gtk::Window
{
    public:
    About_window();
    virtual ~About_window();

    protected:
    Gtk::Box box;
    Gtk::Label colzlabel,phonelabel,sitelabel;
    Gtk::Button hide;
};

#endif