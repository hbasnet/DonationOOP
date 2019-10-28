#ifndef INDEX_H
#define INDEX_H

#include <gtkmm.h>

class Index_window : public Gtk::Window
{
public:
    Index_window();
    virtual ~Index_window();

protected:
    Gtk::Button donate_button, view_button, about_button, logout_button;
    Gtk::Box box;

    void on_donate_button_click();
    void on_view_button_click();
    void on_about_button_click();
    void on_logout_button_click();
};

#endif