//
// Created by HP on 5/3/2022.
//

#ifndef T2_PELUZAVERDE_1_SERVICE_H
#define T2_PELUZAVERDE_1_SERVICE_H

#include <iostream>
#include <vector>
#include <fstream>
#include "../Header/hospitalDepartment.h"
class service {
public:
    std::vector<hospitalDepartment*> repo;

    void addDepartment(hospitalDepartment* m);
    std::vector<hospitalDepartment*> getAllDepartmentss();
    std::vector<hospitalDepartment*> getAllEfficientDepartmentss();
    void WriteToFile(std::string filename);
    service();
    ~service();

};



#endif //T2_PELUZAVERDE_1_SERVICE_H
