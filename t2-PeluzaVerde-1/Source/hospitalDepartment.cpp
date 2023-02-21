//
// Created by HP on 5/3/2022.
//

//
#include "../Header/hospitalDepartment.h"
#include <utility>


hospitalDepartment::hospitalDepartment() {
    this->hospitalName="";
    this->numberOfDoctors=-1;
}

hospitalDepartment::~hospitalDepartment() {

}

std::string hospitalDepartment::ToString() {
    std::string f;
    return f;
}

Surgery::Surgery(std::string hospitalName, int numberOfDoctors, int numberOfPatients) {
    this->hospitalName=std::move(hospitalName);
    this->numberOfDoctors=numberOfDoctors;
    this->numberOfPatients=numberOfPatients;

}

Surgery::Surgery() {

}
Surgery::~Surgery() {

}

bool Surgery::isEfficient() {
    if(this->numberOfDoctors*2<=this->numberOfPatients)
        return true;
    return false;
}

std::string Surgery::ToString() {
    std::string f = hospitalDepartment::ToString();
    f+= " Surgery " + this->hospitalName +"  Nr doctors:"+ std::to_string(this->numberOfDoctors)+" " + " Nr patients:"+ std::to_string(this->numberOfPatients)+ " effiecient:"+ std::to_string(this->isEfficient());
    return f;
}

NeonatalUnit::NeonatalUnit() {

}

NeonatalUnit::~NeonatalUnit() {

}
NeonatalUnit::NeonatalUnit(std::string hospitalName, int numberOfDoctors, int numberOfMothers, int numberOfNewborns,
                           double averageGrade) {
    this->hospitalName= std::move(hospitalName);
    this->numberOfMothers=numberOfMothers;
    this->averageGrade=averageGrade;
    this->numberOfDoctors=numberOfDoctors;
    this->numberOfNewborns= numberOfNewborns;

}

std::string NeonatalUnit::ToString() {
    std::string f = hospitalDepartment::ToString();
    f+= " Neonatal unit " + this->hospitalName +"  Nr doctors:"+ std::to_string(this->numberOfDoctors)+" " + " Nr newborns:"+ std::to_string(this->numberOfNewborns) + " average grade:"+ std::to_string(this->averageGrade) + " effiecient:"+ std::to_string(this->isEfficient());
    return f;
}

bool NeonatalUnit::isEfficient() {

    if(this->averageGrade> 8.5 && this->numberOfMothers<= this->numberOfNewborns)
        return true;
    return false;
}
