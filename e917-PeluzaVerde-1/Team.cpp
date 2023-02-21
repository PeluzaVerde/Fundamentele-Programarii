

#include "Team.h"




std::ostream &operator<<(std::ostream &os, Team &p) {
    if(p.name.empty())
        return os;
    os<<p.name<<","<<p.nr_rev<<","<<p.must_rev<<"\n";
    return os;
}

std::istream &operator>>(std::istream &is,Team& p) {
    if(is.eof())
    {
        is.setstate(std::ios_base::failbit);
        return is;
    }
    std::getline(is,p.name,',');
    if(p.name.empty())
        return is;
    std::string var;
    std::getline(is,var,',');
    p.nr_rev=std::stoi(var);
    std::getline(is,var,'\n');
    p.must_rev=std::stoi(var);
    return is;
}

Team::Team(std::string n, int nr_rev, int must_rev) {
    this->name=n;
    this->nr_rev=nr_rev;
    this->must_rev=must_rev;

}
