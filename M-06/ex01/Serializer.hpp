#pragma once
#include <stdint.h>
#include "Data.hpp"

class Serializer {
    public:
        ~Serializer();

        static uintptr_t serialize(Data *ptr);
        static Data *deserialize(uintptr_t raw);
    private:
        Serializer();
        Serializer(const Serializer & ref);
        const Serializer &operator=(const Serializer &ref);
};