

#ifndef CLION_MEASUREMENT_H
#define CLION_MEASUREMENT_H
#include "iostream"
#include "cstring"

class hospitalDepartment {

public:

    hospitalDepartment();
    virtual bool isEfficient()=0;
    virtual std::string ToString();
    virtual ~hospitalDepartment();
    std::string hospitalName;
    int numberOfDoctors;
};

class Surgery: public hospitalDepartment{
private:

    int numberOfPatients;

public:
    Surgery(std::string hospitalName,int numberOfDoctors, int numberOfPatients);
    Surgery();

    bool isEfficient() override;


    std::string ToString() override;

    ~Surgery();


};

class NeonatalUnit: public hospitalDepartment{
private:
    int numberOfMothers, numberOfNewborns;
    double averageGrade;

public:
    NeonatalUnit();
    NeonatalUnit(std::string hospitalName, int numberOfDoctors, int numberOfMothers, int numberOfNewborns, double averageGrade ) ;

    bool isEfficient() override;


    std::string ToString() override;


    ~NeonatalUnit();
};


#endif //CLION_MEASUREMENT_H
