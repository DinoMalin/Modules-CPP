#include "Serializer.hpp"
#include <iostream>

int main() {
    Data data;

    data.dataOne = 42;
    data.dataTwo = 21;

    Data *ptr(&data);
    std::cout << ptr->dataOne << std::endl;
    std::cout << ptr->dataTwo << std::endl;

    uintptr_t raw(Serializer::serialize(ptr));
    Data *deserialized(Serializer::deserialize(raw));
    
    std::cout << deserialized->dataOne << std::endl;
    std::cout << deserialized->dataTwo << std::endl;
}