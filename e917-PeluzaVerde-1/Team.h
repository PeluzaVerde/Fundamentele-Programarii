
#pragma once
#include <string>
#include <fstream>

class Team{
public:
    std::string name;
    int nr_rev;
    int must_rev;
    Team()=default;
    Team(std::string n,int nr_rev, int must_rev);
    friend std::istream& operator>>(std::istream& is, Team& p);
    friend std::ostream& operator<<(std::ostream& os, Team& p);
};






