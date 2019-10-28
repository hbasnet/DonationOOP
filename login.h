#ifndef LOGIN_H
#define LOGIN_H

#include <gtkmm.h>

class Login_window : public Gtk::Window
{
public:
    Login_window();
    virtual ~Login_window();

protected:
    void sign_in();

    Gtk::Box box;
    Gtk::Label label;
    Gtk::Box emailBox, nameBox;
    Gtk::Entry entryEmail, entryName;
    Gtk::Button button_signin;
};

#endif