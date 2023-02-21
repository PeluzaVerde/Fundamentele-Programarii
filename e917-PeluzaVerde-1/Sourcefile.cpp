

#include "Sourcefile.h"




std::ostream &operator<<(std::ostream &os, Sourcefile &p) {
    if(p.name.empty())
        return os;
    os<<p.name<<","<<p.status<<","<<p.creator<<","<<p.reviewer<<"\n";
    return os;
}

std::istream &operator>>(std::istream &is,Sourcefile& p) {
    if(is.eof())
    {
        is.setstate(std::ios_base::failbit);
        return is;
    }
    std::getline(is,p.name,',');
    if(p.name.empty())
        return is;
    std::getline(is,p.status,',');
    std::getline(is,p.creator,',');
    std::getline(is,p.reviewer,'\n');
    return is;
}

Sourcefile::Sourcefile(std::string n, std::string status, std::string creator, std::string reviewer) {
    this->name=n;
    this->status=status;
    this->creator=creator;
    this->reviewer=reviewer;

}
