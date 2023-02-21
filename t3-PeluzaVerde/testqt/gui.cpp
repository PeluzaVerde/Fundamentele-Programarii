//
// Created by HP on 5/24/2022.
//

// You may need to build the project (run Qt uic code generator) to get "ui_GUI.h" resolved

#include "gui.h"
#include "ui_GUI.h"
#include <QMessageBox>
#include <sstream>
using namespace std;
GUI::GUI(Controller& s,QWidget *parent) :
        QWidget(parent), ui(new Ui::GUI), serv {s} {
    ui->setupUi(this);
    this->populateList();
    this->connectSignalsAndSlots();
}

GUI::~GUI() {
    delete ui;
}


void GUI::populateList() {
    this->ui->ShoplistWidget->clear();
    vector<shoplist> allshop = this->serv.get_all_shop();
    for(shoplist& t: allshop) {
        this->ui->ShoplistWidget->addItem(QString::fromStdString(
                t.get_category() + " - " + t.get_name() + " - " + to_string(t.get_quantity())));

    }
}

void GUI::connectSignalsAndSlots() {
    QObject::connect(this->ui->show_pushButton, &QPushButton::clicked, this, &GUI::filterShop);
    //QObject::connect(this->ui->lineEdit, &QLineEdit::textChanged, this,&GUI::filterList);

}

void GUI::filterShop() {
    this->ui->cat_listWidget->clear();
    string categ = this->ui->show_lineEdit->text().toStdString();

        auto allshop = this->serv.get_all_shop();
        for (shoplist &t: allshop) {

            if (t.get_category() == categ) {
                this->ui->cat_listWidget->addItem(QString::fromStdString(
                        t.get_category() + " - " + t.get_name() + " - " + to_string(t.get_quantity())));
            }
        }


}

void GUI::filterList() {
    this->ui->ShoplistWidget->clear();
    string categ = this->ui->lineEdit->text().toStdString();


    auto allshop = this->serv.get_all_shop();
    for (shoplist &t: allshop) {

        if (t.get_category().find(categ) || t.get_name().find(categ)) {
            this->ui->ShoplistWidget->addItem(QString::fromStdString(
                    t.get_category() + " - " + t.get_name() + " - " + to_string(t.get_quantity())));
        }
    }


}