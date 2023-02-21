//
// Created by HP on 5/24/2022.
//

#ifndef TESTQT_CONTROLLER_H
#define TESTQT_CONTROLLER_H


#include "repo.h"

class Controller {
private:
    Repo repo;

public:
    Controller(Repo r);


    std::vector<shoplist> get_all_shop() const;
};


#endif //TESTQT_CONTROLLER_H
