#include <stdlib.h>
#include <QApplication>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QFormLayout>
#include <QtWidgets/QApplication>
#include "gui.h"
#include <QtWidgets/QApplication>
#include <QHBoxLayout>
#include <QSpinBox>
#include <QSlider>
int main(int argc, char *argv[]) {

    QApplication a(argc, argv);

    std::vector<shoplist> RepoVect;
    RepoVect.reserve(10);
    std::string filename = R"(C:/Users/HP/CLionProjects/testqt/shop.txt)";
    Repo repository = Repo{RepoVect, filename};
    repository.initRepo();


    Controller c(repository);

    GUI w{c};
    w.show();

    return a.exec();
}
