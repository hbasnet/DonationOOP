#include "donate.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

Item::Item()
{
    Gtk::Window w;

    //w.set_size(500, 200); not able to change size

    Gtk::Dialog *dialog = new Gtk::Dialog();
    dialog->set_transient_for(w);
    dialog->set_title("Enter donate item info: ");

    Gtk::Label *nameLabel = new Gtk::Label("Enter item name: ");
    dialog->get_content_area()->pack_start(*nameLabel);
    nameLabel->show();

    dialog->add_button("Cancel", 0);  //when cancel is clicked it shouldn't add to list
    dialog->add_button("OK", 1);
    dialog->set_default_response(0);

    Gtk::Entry *entryName = new Gtk::Entry();
    entryName->set_text("Enter item name");
    entryName->set_max_length(50);
    entryName->show();
    dialog->get_vbox()->pack_start(*entryName);

    Gtk::Label *categoryLabel = new Gtk::Label("Enter item Category: ");
    dialog->get_content_area()->pack_start(*categoryLabel);
    categoryLabel->show();

    Gtk::Entry *entryCategory = new Gtk::Entry();
    entryCategory->set_text("category: furniture OR electronics OR others");
    entryCategory->set_max_length(50);
    entryCategory->show();
    dialog->get_vbox()->pack_start(*entryCategory);

    int result = dialog->run();
    item_name = entryName->get_text();
    item_category = entryCategory->get_text();

    dialog->close();

    delete dialog;
    delete nameLabel;
    delete categoryLabel;
    delete entryName;
    delete entryCategory;
}

Donate_window::Donate_window(string item_name, string item_category)
{
    set_title("--Add donated item to list--");
    set_size_request(300, 200);
    add(vbox);

    nameLabel.set_text("Item name: " + item_name);
    nameLabel.set_padding(10, 10);
    vbox.pack_start(nameLabel);

    categoryLabel.set_text("Item Category: " + item_category);
    categoryLabel.set_padding(10, 10);
    vbox.pack_start(categoryLabel);

    donateButton.set_label("OK");

    donateButton.signal_pressed().connect(sigc::mem_fun(*this, &Donate_window::on_donateButton_click));

    vbox.pack_start(donateButton);
    show_all_children();
}

Donate_window::~Donate_window(){};

void Donate_window::on_donateButton_click()
{
   
}
