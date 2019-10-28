#include "index.h"
#include "donate.h"
#include "view.h"
#include "about.h"
#include <iostream>

using namespace std;

vector<string> furniture_list;
vector<string> electronics_list;
vector<string> other_list;

Index_window::Index_window() : box(Gtk::ORIENTATION_VERTICAL), donate_button("DONATE"),
                               view_button("VIEW"), about_button("ABOUT"), logout_button("LOG OUT")
{
    set_size_request(500, 200);
    set_title("--Index Page--");

    add(box);

    donate_button.signal_clicked().connect(sigc::mem_fun(*this, &Index_window::on_donate_button_click));
    box.pack_start(donate_button);

    view_button.signal_clicked().connect(sigc::mem_fun(*this, &Index_window::on_view_button_click));
    box.pack_start(view_button);

    about_button.signal_clicked().connect(sigc::mem_fun(*this, &Index_window::on_about_button_click));
    box.pack_start(about_button);

    logout_button.signal_clicked().connect(sigc::mem_fun(*this, &Index_window::on_logout_button_click));
    box.pack_start(logout_button);

    show_all_children();
}

Index_window::~Index_window() {}

void Index_window::on_donate_button_click()
{
    Item i;
    Donate_window *window = new Donate_window(i.item_name, i.item_category);
    if (i.item_category == "furniture")
    {
        furniture_list.push_back(i.item_name);
    }
    else if (i.item_category == "electronics")
    {
        electronics_list.push_back(i.item_name);
    }
    else
    {
        other_list.push_back(i.item_name);
    }
    window->show();
}

void Index_window::on_view_button_click()
{
    View_window *view = new View_window(furniture_list, electronics_list, other_list);
    view->show();
}

void Index_window::on_about_button_click()
{
    About_window *about = new About_window();
    about->show();
}

void Index_window::on_logout_button_click()
{
    hide(); //i can;t hide and run login window either nor can do opposite
}