//
// Created by HP on 5/24/2022.
//

#ifndef TESTQT_SHOPLIST_H
#define TESTQT_SHOPLIST_H
#include <string>
#include <windows.h>


class shoplist {

private:
    std::string category;
    std::string name;
    int quantity;

public:
    shoplist();
    shoplist(std::string category, std::string name, int quantity);

    std::string get_name() const;
    std::string get_category() const;
    int get_quantity() const;

    bool operator==(const shoplist& t);
    friend std::istream& operator>>(std::istream& inputStream, shoplist& t);

    friend std::ostream & operator<<(std::ostream& outputStream, const shoplist& shopOutput);
};


#endif //TESTQT_SHOPLIST_H
