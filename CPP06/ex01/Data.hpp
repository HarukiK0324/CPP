#ifndef DATA_HPP
#define DATA_HPP

#include <string>
class Data {
    public:
        std::string name;
        int id;
        
        Data();
        Data(const std::string& name, int id);
        Data(const Data& src);
        Data& operator=(const Data& src);
        ~Data();
};

#endif
