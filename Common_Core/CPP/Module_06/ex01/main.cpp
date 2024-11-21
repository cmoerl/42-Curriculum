#include "Serializer.hpp"
#include "Data.hpp"

int main()
{
    Data data;
    data.setNumber(0);
    std::cout << "Original Number: " << data.getNumber() << std::endl;
    uintptr_t raw = Serializer::serialize(&data);
    std::cout << "Serialized Number: " << raw << std::endl;
    Data *ptr = Serializer::deserialize(raw);
    std::cout << "Deserialized Number: " << ptr->getNumber() << std::endl;
    return (0);
}
