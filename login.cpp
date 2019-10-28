#include "login.h"
#include "index.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

Login_window::Login_window() : box(Gtk::ORIENTATION_VERTICAL), button_signin("Sign In")
{
    set_size_request(300, 200);
    set_title("Login Page");

    add(box);

    label.set_text("Enter the UTA email that ends with @mavs.uta.edu to login: ");
    box.pack_start(label);

    entryEmail.set_max_length(30);
    entryEmail.set_text("Enter email: ");
    entryEmail.select_region(0, entryEmail.get_text_length());
    box.pack_start(entryEmail);

    box.pack_start(emailBox);

    entryName.set_max_length(30);
    entryName.set_text("Enter name: ");
    entryName.select_region(0, entryName.get_text_length());
    box.pack_start(entryName);

    box.pack_start(nameBox);

    button_signin.signal_clicked().connect(sigc::mem_fun(*this, &Login_window::sign_in));
    box.pack_start(button_signin);

    show_all_children();
}

Login_window::~Login_window() {}

void Login_window::sign_in()
{
    int ret;
    string student_email = entryEmail.get_text();
    string student_name = entryName.get_text();
    string intermediate;
    stringstream ss(student_email);
    getline(ss, intermediate, '@');
    getline(ss, intermediate);

    if (intermediate == "mavs.uta.edu")
    {
        hide();
    }
    else
    {
        //edited
        Gtk::MessageDialog dialog(*this, "Invalid Email!!!",false,Gtk::MESSAGE_WARNING);
        dialog.run();
    }
}