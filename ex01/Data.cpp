#include "Data.hpp"
#include <iostream>

Data::Data(int x) : x(x)
{
    // std::cout << "Data's Constructor called\n";
}

Data::Data(const Data &other) 
{
    // std::cout << "Data's Copy Constructor called\n";

    *this = other;
}

Data::~Data() 
{
    // std::cout << "Data's Destructor called\n";
}


Data    &Data::operator = (const Data &rhs) 
{
    (void)rhs;

    return (*this);
}