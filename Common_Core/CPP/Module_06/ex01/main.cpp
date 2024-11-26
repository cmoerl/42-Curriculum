#include "Serializer.hpp"

int main()
{
    Data data;
    data.name = "Example";
    data.value = 42;
    std::cout << "Original Data: " << data.name << ", " << data.value << std::endl;
    std::cout << "Original Data Address: " << &data << std::endl;

    uintptr_t raw = Serializer::serialize(&data);
    std::cout << "Serialized Data: " << raw << std::endl;

    Data *ptr = Serializer::deserialize(raw);
    std::cout << "Deserialized Data: " << ptr->name << ", " << ptr->value << std::endl;
    std::cout << "Deserialized Data Address: " << ptr << std::endl;

    return 0;
}
