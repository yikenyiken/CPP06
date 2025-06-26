#include <iostream>
#include "Data.hpp"
#include "Serializer.hpp"

int main() {

    Data    *ptr = new Data(5);
    Data    *PostSerialize = Serializer::deserialize(Serializer::serialze(ptr));

    if (ptr == PostSerialize)
    {
        std::cout << ptr << " == " << PostSerialize << std::endl;
        delete (PostSerialize);
        return (0);
    }

    std::cout << ptr << " != " << PostSerialize << std::endl;
    delete (ptr);
    return (1);
}