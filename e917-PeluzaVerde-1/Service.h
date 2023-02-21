


#pragma once
#include "Repo.h"

//class TaskException:public std::exception{
//private:
//    std::string message;
//public:
//    explicit TaskException(std::string _message):message(_message){}
//    std::string get_message(){return message;}
//};


class ServException:public std::exception{
private:
    std::string message;
public:
    explicit ServException(std::string _message):message(_message){}
    std::string get_message(){return message;}
};
class Service{
public:
    Repo r;
    Service()=default;
    std::vector<Sourcefile> sort_by_name();
    void add(std::string name,std::string name2);
    void change_status(std::string name,std::string status, std::string programmer);
    void update_hw(std::string programmer);
    //    void remove(std::string desc);
//    void done(std::string desc,int programmer_id);
};



