


#pragma once
#include <vector>
#include "Team.h"
#include "Sourcefile.h"

class Repo{
public:
    std::vector<Team> tarr;
    std::vector<Sourcefile> sarr;
    Repo();
    void read_from_file();
    void write_to_file();
    ~Repo();
};





