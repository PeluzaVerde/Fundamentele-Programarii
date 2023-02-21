

#include "Repo.h"


Repo::Repo() {
    read_from_file();
}

void Repo::read_from_file() {
    std::ifstream f1("C:/Users/HP/Documents/GitHub/e917-PeluzaVerde-1/Prog.txt");
    std::ifstream f2("C:/Users/HP/Documents/GitHub/e917-PeluzaVerde-1/Sour.txt");

    if(!f1.is_open()||!f2.is_open())
        return;

    Team p;
    while(f1>>p)
        tarr.push_back(p);
    f1.close();

    Sourcefile s;
    while (f2>>s)
        sarr.push_back(s);
    f2.close();
}

void Repo::write_to_file() {
    std::ofstream f("C:/Users/HP/Documents/GitHub/e917-PeluzaVerde-1/Sour.txt");
    std::ofstream f2("C:/Users/HP/Documents/GitHub/e917-PeluzaVerde-1/Prog.txt");

    for(auto s:sarr)
    {
        f<<s;
    }
    f.close();


    for(auto s:tarr)
    {
        f2<<s;
    }
    f2.close();
}

Repo::~Repo() {
    write_to_file();
}
