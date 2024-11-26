#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <stdint.h>
#include <iostream>

struct Data
{
    std::string name;
    int         value;
};

class Serializer
{
    private:
        Serializer();
        Serializer(const Serializer &copy);
        Serializer &operator=(const Serializer &copy);

    public:
        virtual ~Serializer();

        static uintptr_t serialize(Data *ptr);
        static Data* deserialize(uintptr_t raw);

};

#endif
