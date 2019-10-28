#ifndef VIEW_H
#define VIEW_H

#include "donate.h"
#include <vector>
#include <gtkmm.h>

class View_window : public Gtk::Window
{
public:
    std::vector<std::string> furniture;
    std::vector<std::string> electronics;
    std::vector<std::string> others;
    View_window(std::vector<std::string> _furniture, std::vector<std::string> _electronics, std::vector<std::string> _others);
    virtual ~View_window();

    Gtk::Button furniture_button, electronic_button, other_button;
    Gtk::Box box;

    void on_click_furniture();
    void on_click_electronic();
    void on_click_other();
};
class newDialog : public Gtk::Window
{
public:
    newDialog(std::vector<std::string> list, std::string letter);
    virtual ~newDialog();

    void choose_combo(); //std::vector<std::string>item_list);new

    class Columns : public Gtk::TreeModel::ColumnRecord
    {
    public:
        Columns()
        {
            add(m_col_id);
            add(m_col_name);
        }
        Gtk::TreeModelColumn<int> m_col_id;
        Gtk::TreeModelColumn<Glib::ustring> m_col_name;
    };

    Columns m_Columns;
    Gtk::Image image;
    Gtk::VBox vbox;
    Gtk::Label label;
    Gtk::ComboBox combo;
    Gtk::CellRendererText m_cell;
    Glib::RefPtr<Gtk::ListStore> r_tree;
};

#endif