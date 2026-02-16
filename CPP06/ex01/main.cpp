#include "Serializer.hpp"
#include <iostream>

int main()
{
    Data data("Example", 42);
    
    uintptr_t ptr = Serializer::serialize(&data);
    
    Data* deserializedData = Serializer::deserialize(ptr);
    
    std::cout << "Name: " << deserializedData->name << ", ID: " << deserializedData->id << std::endl;
    
    std::cout << (deserializedData == &data ? "Deserialization == data" : "Deserialization != data") << std::endl;
    return 0;
}
