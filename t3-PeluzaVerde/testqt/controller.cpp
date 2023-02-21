//
// Created by HP on 5/24/2022.
//


#include "controller.h"


Controller::Controller(Repo r) {
    this->repo = r;
}


std::vector<shoplist> Controller::get_all_shop() const {
    return repo.get_all_shop();
}
