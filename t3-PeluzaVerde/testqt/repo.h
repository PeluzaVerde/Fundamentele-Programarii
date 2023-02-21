//
// Created by HP on 5/24/2022.
//

#ifndef TESTQT_REPO_H
#define TESTQT_REPO_H
#include "shoplist.h"
#include <vector>
#include <iostream>

class Repo {
private:

    std::vector<shoplist> array;
    std::string shoplistFileName;

public:

    Repo();

    void loadshoplistFromFile();

    void writeshoplistToFile();

    void initRepo();
    void filterR();
    void filterP();

    explicit Repo(std::vector<shoplist>& repo_vect,  std::string& shop_filename);

    std::vector<shoplist> get_all_shop() const;
    std::vector<shoplist> get_all_shop2() ;

};
#endif //TESTQT_REPO_H
