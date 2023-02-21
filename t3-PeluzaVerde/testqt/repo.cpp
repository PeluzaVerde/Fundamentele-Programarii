//
// Created by HP on 5/24/2022.
//


#include "repo.h"
#include <fstream>
#include <algorithm>


Repo::Repo() {

}


Repo::Repo(std::vector<shoplist>& repo_vect, std::string& shoplist_filename) {
    this->shoplistFileName = shoplist_filename;
    this->array= repo_vect;
}

void Repo::loadshoplistFromFile() {

    if(!this->shoplistFileName.empty()){
        shoplist shoplistFromFile;
        std::ifstream  fin(this->shoplistFileName);
        while(fin >> shoplistFromFile){
            if(std::find(this->array.begin(), this->array.end(), shoplistFromFile)==
               this->array.end())
                this->array.push_back(shoplistFromFile);
        }
        fin.close();
    }

}

void Repo::writeshoplistToFile(){
    if(!this->shoplistFileName.empty()){
        std::ofstream fout(this->shoplistFileName);
        for(const shoplist &t: this->array){
            fout << t <<"\n";
        }
        fout.close();
    }
}

void Repo::initRepo(){
    this->loadshoplistFromFile();
    for (int i=0; i<= this->array.size();i++)
        for(int j=i+1; j<this->array.size();j++)
            if(this->array[i].get_category() > this->array[j].get_category())
                std::swap(this->array[i],this->array[j]);
            else if (this->array[i].get_category()==this->array[j].get_category())
                if (this->array[i].get_name() > this->array[j].get_name())
                    std::swap(this->array[i], this->array[j]);





}


std::vector<shoplist> Repo:: get_all_shop() const{
    return array;
}


void Repo::filterR(){
    for (int i=0; i<= this->array.size();i++)
        for(int j=i+1; j<this->array.size();j++)
            if(this->array[i].get_quantity() > this->array[j].get_quantity())
                std::swap(this->array[i],this->array[j]);
}

void Repo::filterP(){
    for (int i=0; i<= this->array.size();i++)
        for(int j=i+1; j<this->array.size();j++)
            if(this->array[i].get_category() > this->array[j].get_category())
                std::swap(this->array[i],this->array[j]);
            else if (this->array[i].get_category()==this->array[j].get_category())
                if (this->array[i].get_name() > this->array[j].get_name())
                    std::swap(this->array[i], this->array[j]);
}
std::vector<shoplist> Repo:: get_all_shop2() {
    return array;
}
