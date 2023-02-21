
#include "gui.h"



gui::gui() {
    init_gui();
    populate_gui();
    connect_gui();
}

void gui::init_gui() {
    std::vector<QWidget*> window;
    std::vector<QVBoxLayout*> layout;
    for(int i=0;i<s.r.tarr.size();i++)
    {
        window.push_back(new QWidget);
        window[i]=new QWidget;
        window[i]->setWindowTitle(QString::fromStdString(s.r.tarr[i].name));
        layout.push_back(new QVBoxLayout(window[i]));
        tasks.push_back(new QListWidget());
        file_name.push_back(new QLineEdit());
        add.push_back(new QPushButton("Add"));
        revise.push_back(new QPushButton("Revise"));
        layout[i]->addWidget(tasks[i]);
        layout[i]->addWidget(file_name[i]);
        layout[i]->addWidget(add[i]);
        layout[i]->addWidget(revise[i]);
        nr_revised.push_back(new QLabel(QString::fromStdString(std::to_string( s.r.tarr[i].nr_rev))));
        must_revise.push_back(new QLabel(QString::fromStdString(std::to_string( s.r.tarr[i].must_rev))));
        layout[i]->addWidget(nr_revised[i]);
        layout[i]->addWidget(must_revise[i]);
        window[i]->show();
    }

}


void gui::populate_gui() {
    for(int i=0;i<s.r.tarr.size();i++)
    {
        tasks[i]->clear();
        std::vector<Sourcefile> sorted=s.sort_by_name();
        for(auto sr:sorted){
            QString string=QString::fromStdString(sr.name+","+sr.status+","+sr.creator+","+sr.reviewer);
            //QString lol = QString::fromStdString(std::to_string( s.r.tarr[i].nr_rev));
            //nr_revised[i]->text().swap(lol);
            //nr_revised[i]=new QLabel(QString::fromStdString(std::to_string( s.r.tarr[i].nr_rev)));
            //must_revise[i]=new QLabel(QString::fromStdString(std::to_string( s.r.tarr[i].must_rev)));
            QListWidgetItem* item=new QListWidgetItem(string);
            if(sr.status=="not_revised"){
                //item->font().bold();
                item->font().setBold(true);
                QFont fo =  (*item).font();
                fo.setBold(true);
                (*item).setFont(fo);

                //item->setFont(font().);
                //item->text()
                //item->font();
            }
            else{
                QColor color(0, 255, 0);
                QBrush brush(color);
                item->setBackground(brush);
            }

            tasks[i]->addItem(item);
        }
    }
}





void gui::_add() {
    int window_index;
    for(int i=0;i<s.r.tarr.size();i++)
        if(sender()==add[i])
        {
            window_index=i;
            break;
        }
    try {
        std::string data = file_name[window_index]->text().toStdString();
        if(!data.empty()){
        std::string data2 = s.r.tarr[window_index].name;
        s.add(data, data2);
        this->populate_gui();}
        else{
            QErrorMessage *error = new QErrorMessage();
            error->showMessage("Cant be empty");
        }
    }
    catch (...){
        QErrorMessage *error = new QErrorMessage();
        error->showMessage("That already exists");
    }
}

void gui::connect_gui() {
    for(int i=0;i<s.r.tarr.size();i++) {
        QObject::connect(add[i],&QPushButton::clicked, this,&gui::_add);
        QObject::connect(revise[i],&QPushButton::clicked, this,&gui::_revise);
    }

}
void gui::_revise() {
    try {
    int window_index;
    for(int i=0;i<s.r.tarr.size();i++)
        if(sender()==revise[i])
        {
            window_index=i;
            break;
        }

        std::string data = tasks[window_index]->currentItem()->text().toStdString();


    std::string string_name;
    std::string string_status;
    std::string string_creator;
    std::istringstream f(data);
    std::getline(f, string_name, ',');
    std::getline(f, string_status, ',');
    std::getline(f, string_creator, ',');
    //QErrorMessage *error = new QErrorMessage();
    //error->showMessage( QString::fromStdString( string_name));
    if(string_status=="revised") {
        QErrorMessage *error = new QErrorMessage();
        error->showMessage("That is already Revised");
    }
    else if(string_creator==s.r.tarr[window_index].name){
        QErrorMessage *error = new QErrorMessage();
        error->showMessage("Cant revise your own question!");
    }
    else {
        //std::string data=file_name[window_index]->text().toStdString();
        std::string data2 = s.r.tarr[window_index].name;
        s.change_status(string_name, "revised", data2);
        s.update_hw(data2);
        //QColor color(0, 255, 0);
        //QBrush brush(color);
        //tasks[window_index]->currentItem()->setBackground(brush);
        if (s.r.tarr[window_index].must_rev == 0) {
            QErrorMessage *error = new QErrorMessage();
            error->showMessage("Congratulations!");
        }

        this->populate_gui();
    }


    }
    catch(...)
    {
        QErrorMessage *error = new QErrorMessage();
        error->showMessage("select something will you?");
    }
}