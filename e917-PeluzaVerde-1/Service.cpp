
#include "Service.h"
std::vector<Sourcefile> Service::sort_by_name() {
    std::vector<Sourcefile> sorted=r.sarr;
    for(int i=0;i<sorted.size()-1;i++)
        for(int j=i+1;j<sorted.size();j++)
            if(sorted[i].name>sorted[j].name)
                std::swap(sorted[i],sorted[j]);
    return sorted;
}
void Service::add(std::string name,std::string name2) {
    for(int i=0;i<r.sarr.size();i++) {
        if(r.sarr[i].name==name)
            throw ServException("Already exists");
    }

    r.sarr.push_back(Sourcefile(name,"not_revised",name2," "));
}

void Service::change_status(std::string name, std::string status, std::string programmer) {
    for(int i=0;i<r.sarr.size();i++)
    {
        if(r.sarr[i].name==name) {
            r.sarr[i].status=status;
            r.sarr[i].reviewer=programmer;
            break;
        }

    }
}
void Service::update_hw(std::string programmer) {
    for(int i=0;i<r.tarr.size();i++)
    {
        if(r.tarr[i].name==programmer) {
            r.tarr[i].must_rev--;
            r.tarr[i].nr_rev++;
            break;
        }

    }
}