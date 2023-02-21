//
// Created by HP on 5/24/2022.
//

#include "shoplist.h"
#include <vector>
#include <sstream>
shoplist::shoplist(std::string _category,std::string _name, int _quantity) {

    name=_name;
    category=_category;
    quantity = _quantity;
}

shoplist::shoplist() {
    name="";
    category= "";
    quantity=0;
}

std::string shoplist::get_name() const {
    return this->name;
}

int shoplist::get_quantity() const {
    return this->quantity;
}

std::string shoplist::get_category() const {
    return this->category;
}

bool shoplist::operator==(const shoplist&t) {
    if (name != t.name)
        return false;
    return true;
}

std::vector<std::string> field_delimiter(const std::string& str, char delimiter) {
    std::vector<std::string> result;
    std::stringstream ss(str);
    std::string field;
    while (getline(ss, field, delimiter))
        result.push_back(field);
    return result;
}

std::istream &operator>>(std::istream &inputStream, shoplist &e) {
    std::string line;
    std::getline(inputStream, line);
    std::vector<std::string> fields;
    if (line.empty())
        return inputStream;
    fields = field_delimiter(line, '|');
    e.category = fields[0];
    e.name = fields[1];
    e.quantity = std::stoi(fields[2]);
    return inputStream;
}

std::ostream &operator<<(std::ostream &outputStream, const shoplist &shoplistOutput) {
    outputStream << shoplistOutput.category << "|" <<shoplistOutput.name<< "|" << shoplistOutput.quantity;
    return outputStream;
}
