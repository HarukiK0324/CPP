#include "Data.hpp"

Data::Data() : name(""), id(0) {}

Data::Data(const std::string& name, int id) : name(name), id(id) {}

Data::Data(const Data& src) : name(src.name), id(src.id) {}

Data& Data::operator=(const Data& src) {   
    name = src.name;
    id = src.id;
    return *this;
}

Data::~Data() {}
