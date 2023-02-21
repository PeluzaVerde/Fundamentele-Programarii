//
// Created by HP on 5/3/2022.
//

#include "../Header/service.h"

void service::addDepartment(hospitalDepartment *m) {
    this->repo.push_back(m);
}

std::vector<hospitalDepartment *> service::getAllDepartmentss() {
    return this->repo;
}

std::vector<hospitalDepartment *> service::getAllEfficientDepartmentss() {
    std::vector<hospitalDepartment*> alldep = getAllDepartmentss();
    std::vector<hospitalDepartment*> effdep;
    for (auto m: alldep)
    {
        if (m->isEfficient())
            effdep.push_back(m);
    }
    return effdep;
}

void service::WriteToFile(std::string filename) {
    std::ofstream g(filename);
    std::vector<hospitalDepartment*> to_write = getAllDepartmentss();

    for (auto m: to_write)
        g<<m->ToString()<<"\n";
    g.close();
}

service::service() {

}

service::~service() {
for(auto i:this->repo)
    delete i;
}
