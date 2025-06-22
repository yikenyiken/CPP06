#include "ScalarConverter.hpp"
#include <_ctype.h>
#include <cctype>
#include <cstdlib>
#include <iostream>
#include "ScalarConverter.h"
#include <ctype.h>

ScalarConverter::ScalarConverter()
{
    std::cout << "ScalarConverter's Default Constructor called\n";
}

ScalarConverter::ScalarConverter(const ScalarConverter &other) 
{
    std::cout << "ScalarConverter's Copy Constructor called\n";

    *this = other;
}

ScalarConverter::~ScalarConverter() 
{
    std::cout << "ScalarConverter's Destructor called\n";
}


ScalarConverter    &ScalarConverter::operator = (const ScalarConverter &rhs) 
{
    (void)rhs;

    return (*this);
}

void    printAsChar(std::string literal)
{
	std::cout << "char: ";

	if (isNumeric(literal))
	{
		int c = std::strtol(literal.c_str(), NULL, 10);

        if (isascii(c) && std::isprint(c))
        {
            std::cout << static_cast<char>(c) << std::endl;
            return ;
        }

        if (isascii(c) && !std::isprint(c))
        {
            std::cout << "Non displayable" << std::endl;
            return ;
        }
	}

	if (literal.length() == 1)
    {
        std::cout << literal[0] << std::endl;
        return ;
    }

    std::cout << "impossible\n";
}

void    printAsInt(std::string literal)
{
    std::cout << "int: ";

    if (isNumeric(literal) || isNumeric(literal.c_str() + 1)
        && (literal[0] == '+' || literal[0] == '-'))
    {
        long    ln = std::strtol(literal.c_str(), NULL, 10);
        int     n = std::strtol(literal.c_str(), NULL, 10);

        if (is_overflowing(n, ln))
            return ;

        std::cout << n << std::endl;
        return ;
    }

    std::cout << "impossible" << std::endl;
}

void    ScalarConverter::convert(std::string literal)
{
    printAsChar(literal);
    printAsInt(literal);
    // printAsFloat(literal);
    // printAsDouble(literal);
}