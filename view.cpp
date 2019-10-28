#include "view.h"
#include <vector>
#include <iostream>

using namespace std;

View_window::View_window(std::vector<std::string> _furniture, std::vector<std::string> _electronics, std::vector<std::string> _others) : box(Gtk::ORIENTATION_VERTICAL), furniture_button("Furniture"), electronic_button("Electronic"),
                                                                                                                                         other_button("Other")
{
    this->furniture = _furniture;
    this->electronics = _electronics;
    this->others = _others;
    set_size_request(500, 200);
    set_title("--View Page--");

    add(box);

    furniture_button.signal_clicked().connect(sigc::mem_fun(*this, &View_window::on_click_furniture));
    box.pack_start(furniture_button);

    electronic_button.signal_clicked().connect(sigc::mem_fun(*this, &View_window::on_click_electronic));
    box.pack_start(electronic_button);

    other_button.signal_clicked().connect(sigc::mem_fun(*this, &View_window::on_click_other));
    box.pack_start(other_button);

    show_all_children();

    //Create Tree model with columns:
}
newDialog::newDialog(std::vector<std::string> list, std::string letter)
{
    set_size_request(500, 200);
    if (letter.compare("f") == 0)
    {
        set_title("Furniture");
    }
    else if (letter.compare("e") == 0)
    {
        set_title("Electronics");
    }
    else if (letter.compare("o") == 0)
    {
        set_title("Others");
    }

    label.set_text("Please select one of the following options:");
    label.set_padding(10, 10);
    vbox.pack_start(label);

    newDialog::r_tree = Gtk::ListStore::create(newDialog::m_Columns);

    newDialog::combo.set_model(r_tree);
    for (int i = 0; i < list.size(); i++)
    {
        Gtk::TreeModel::Row row = *(r_tree->append());
        row[m_Columns.m_col_id] = i + 1;
        row[m_Columns.m_col_name] = list[i];
        combo.set_active(row);
    }

    combo.pack_start(m_Columns.m_col_id);
    combo.pack_start(m_Columns.m_col_name);
    combo.pack_start(m_cell);

    vbox.pack_start(combo);
    add(vbox);

    combo.signal_changed().connect(sigc::mem_fun(*this, &newDialog::choose_combo));
    show_all_children();
}
void newDialog::choose_combo() //std::vector<std::string>item_list)
{
    Gtk::TreeModel::iterator iter = combo.get_active();
    if (iter)
    {
        Gtk::TreeModel::Row row = *iter;
        if (row)
        {
            int id = row[m_Columns.m_col_id];
            Glib::ustring name = row[m_Columns.m_col_name];
            Gtk::Window w;

            Gtk::Dialog *dialog = new Gtk::Dialog();
            dialog->set_transient_for(w);
            dialog->set_title("Information:");

            Gtk::Label *label = new Gtk::Label("You chose: " + name);
            dialog->get_content_area()->pack_start(*label);
            label->set_padding(50, 50);
            label->show();

            dialog->run();
            dialog->close();
            delete (dialog);

            //gtk_combo_box_text_remove();
        }
    }
    else
    {
        std::cout << "Invalid.." << std::endl;
    }
}
void View_window::on_click_furniture()
{

    newDialog *f = new newDialog(furniture, "f"); //new change
    f->show();
}
void View_window::on_click_electronic()
{
    newDialog *e = new newDialog(electronics, "e");
    e->show();
}
void View_window::on_click_other()
{
    newDialog *o = new newDialog(others, "o");
    o->show();
}

View_window::~View_window()
{
}

newDialog::~newDialog()
{
}