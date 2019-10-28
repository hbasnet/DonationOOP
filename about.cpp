#include "about.h"
#include <iostream>

About_window::About_window() : box(Gtk::ORIENTATION_VERTICAL)
{
    set_size_request(500, 200);
    set_title("--About Page--");

    add(box);

    colzlabel.set_text("This is non-profit University of Texas at Arlington donation site.");
    colzlabel.set_padding(5, 5);
    box.pack_start(colzlabel);

    phonelabel.set_text("Contact on : (817) 272-2011");
    phonelabel.set_padding(5, 5);
    box.pack_start(phonelabel);

    sitelabel.set_text("Go to : https://www.uta.edu");
    sitelabel.set_padding(5, 5);
    box.pack_start(sitelabel);

    hide.set_label("Close");
    hide.signal_pressed().connect(sigc::mem_fun(*this, &About_window::close));
    box.pack_start(hide);

    show_all_children();
}

About_window::~About_window(){};