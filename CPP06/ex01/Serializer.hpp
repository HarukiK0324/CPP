#ifndef Serializer_HPP
#define Serializer_HPP

#include "Data.hpp"

#include <stdint.h>

class Serializer {
    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
    private:
        Serializer();
        Serializer(const Serializer& src);
        Serializer& operator=(const Serializer& rhs);
        ~Serializer();
};

#endif
