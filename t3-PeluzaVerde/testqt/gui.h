//
// Created by HP on 5/24/2022.
//

#ifndef TESTQT_GUI_H
#define TESTQT_GUI_H
#include "controller.h"
#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class GUI; }
QT_END_NAMESPACE

class GUI : public QWidget {
    Q_OBJECT

public:
    explicit GUI(Controller& serv,QWidget *parent = nullptr);

    ~GUI() override;

private:
    Ui::GUI *ui;
    Controller& serv;
    void connectSignalsAndSlots();
    void populateList();
    void filterShop();
    void filterList();
};


#endif //TESTQT_GUI_H
