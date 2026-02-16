#ifndef DATA_HPP
#define DATA_HPP

#include <string>
class Data {
    public:
        std::string name;
        int id;
        
        Data() : name(""), id(0) {}
        Data(const std::string& name, int id) : name(name), id(id) {}
        Data(const Data& src) : name(src.name), id(src.id) {}
        Data& operator=(const Data& src) {   
            name = src.name;
            id = src.id;
            return *this;
        }
        ~Data() {}
};

#endif
