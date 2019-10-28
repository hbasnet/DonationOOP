#ifndef DONATE_H
#define DONATE_H

#include <gtkmm.h>

class Item
{
public:
    std::string item_name;
    std::string item_category;

    Item();
};

class Donate_window : public Gtk::Window
{
public:
    Donate_window(std::string item_name, std::string item_category);
    virtual ~Donate_window();

protected:
    Gtk::VBox vbox;
    Gtk::Label nameLabel, categoryLabel;
    Gtk::Button donateButton;

    void on_donateButton_click();
};

#endif
