#include "login.h"
#include "index.h"
#include "donate.h"
#include "view.h"
#include <vector>
#include <iostream>

using namespace std;

#include <gtkmm.h>

int main(int argc, char *argv[])
{
    Gtk::Main app(argc, argv);
    Login_window login;
    Gtk::Main::run(login);  

    Index_window win;
    Gtk::Main::run(win);
    
    return 0;
}