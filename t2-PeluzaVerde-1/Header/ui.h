

#ifndef CLION_UI_H
#define CLION_UI_H


#include <iostream>
#include "../Header/service.h"

class UI {
private:
    service serv;
public:

    void menu(){
        std::cout<<"1.add a new department\n2.show all departments\n3.show all efficient departments\n4.Save hospital data to file\n";
    }
    int get_option() {
        int option;
        std::cout<<"option:";
        std::cin >> option;
        return option;
    }

    void start() {



        hospitalDepartment* s1;
        hospitalDepartment* s2;
        hospitalDepartment* n1;
        s1 = new Surgery("Pedi3",12, 30);
        s2 = new Surgery("Spitalu craiova", 10, 6);
        n1 = new NeonatalUnit("ReginaMaria",30,20,28, 9);
        this->serv.addDepartment(s1);
        this->serv.addDepartment(s2);
        this->serv.addDepartment(n1);

        bool run= true;

        while (run) {
            menu();
            int opt = get_option();
            switch (opt) {
                case 1: {
                    hospitalDepartment* m;
                    std::string hospitalName,type;
                    int numberOfDoctors;
                    std::cout<<"Enter hospital name ";
                    std::cin>>hospitalName;
                    std::cout<<"Enter number of Doctors ";
                    std::cin>>numberOfDoctors;
                    std::cout<<"Enter type of department(NeonatalUnit or Surgery) ";
                    std::cin>>type;
                    if(type == "NeonatalUnit"){
                        int nrM,nrN;
                        double av;
                        std::cout<<"Enter number of mothers ";
                        std::cin>>nrM;
                        std::cout<<"Enter number of newborns ";
                        std::cin>>nrN;
                        std::cout<<"Enter average grade ";
                        std::cin>>av;

                        m= new NeonatalUnit(hospitalName, numberOfDoctors, nrM, nrN, av);
                        this->serv.addDepartment(m);

                    }
                    else if (type== "Surgery")
                    {
                        int nrP;
                        std::cout<<"Enter number of Patients ";
                        std::cin>>nrP;

                        m= new Surgery(hospitalName, numberOfDoctors, nrP);
                        this->serv.addDepartment(m);
                    }
                    else
                    {
                        std::cout<<"invalid type";
                        break;
                    }
                    break;

                }

                case 2: {
                    for (auto i: this->serv.getAllDepartmentss())
                        std::cout << i->ToString() << std::endl;
                    break;
                }
                case 3:{
                    for (auto i: this->serv.getAllEfficientDepartmentss())
                        std::cout << i->ToString() << std::endl;

                    break;

                }
                case 4:{
                    serv.WriteToFile("hospital.txt");
                    std::cout<<"data saved to file.\n";
                    break;
                }
                case 5:{
                    std::cout<<"Goodbye";
                    run = false;
                    break;
                }
                default: {
                    std::cout<<"invalid option"<<std::endl;
                    break;
                }

            }
        }
    }
};

#endif //CLION_UI_H
