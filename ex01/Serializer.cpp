#include "Serializer.hpp"
#include <iostream>

Serializer::Serializer()
{
    std::cout << "Serializer's Default Constructor called\n";
}

Serializer::Serializer(const Serializer &other) 
{
    std::cout << "Serializer's Copy Constructor called\n";

    *this = other;
}

Serializer::~Serializer() 
{
    std::cout << "Serializer's Destructor called\n";
}


Serializer    &Serializer::operator = (const Serializer &rhs) 
{
    (void)rhs;

    return (*this);
}

uintptr_t   Serializer::serialize(Data *ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data    *Serializer::deserialize(uintptr_t raw)
{
    return (reinterpret_cast<Data *>(raw));
}