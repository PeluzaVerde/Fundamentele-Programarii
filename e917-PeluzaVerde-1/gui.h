
#ifndef E917_PELUZAVERDE_1_GUI_H
#define E917_PELUZAVERDE_1_GUI_H

#pragma once
#include "Service.h"
#include "QWidget"
#include "QBoxLayout"
#include "QPushButton"
#include "QLineEdit"
#include "QListWidget"
#include "QListWidgetItem"
#include "QFormLayout"
#include "QErrorMessage"
#include "QCloseEvent"
#include <sstream>
#include "QLabel"



class gui : public QWidget {
private:
Q_OBJECT

public:
    Service s;

    std::vector<QListWidget*> tasks;
    std::vector<QLineEdit*> file_name;
    std::vector<QPushButton*> add;
    std::vector<QPushButton*> revise;
    std::vector<QLabel*> nr_revised;
    std::vector<QLabel*> must_revise;

gui();
    void init_gui();
    void populate_gui();
    void connect_gui();

    void _add();
    void _revise();

};


#endif //E917_PELUZAVERDE_1_GUI_H


