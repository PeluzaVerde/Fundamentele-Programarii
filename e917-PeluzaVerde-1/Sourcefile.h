#pragma once
#include <string>
#include <fstream>

class Sourcefile {



public:
    std::string name;
    std::string status;
    std::string creator;
    std::string reviewer;

    Sourcefile()=default;
    Sourcefile(std::string n,std::string status,std::string creator,std::string reviewer);
    friend std::istream& operator>>(std::istream& is, Sourcefile& p);
    friend std::ostream& operator<<(std::ostream& os, Sourcefile& p);
};




