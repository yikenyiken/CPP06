#include "ScalarConverter.hpp"
#include "ScalarConverter.h"
#include <cstdlib>
#include <iostream>
#include <iomanip>

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

static void    printAsChar(std::string literal)
{
	std::cout << "char: ";

	if (isFloatingPointRep(literal))
	{
		int     c = static_cast<int>(std::strtol(literal.c_str(), NULL, BASE));
        long    lc = std::strtol(literal.c_str(), NULL, BASE);

        if (isOverflowing(c, lc))
            return ;

        if (isascii(c) && std::isprint(c))
        {
            std::cout << "'" << static_cast<char>(c) << "'" << std::endl;
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
        std::cout << "'" << literal[0] << "'" << std::endl;
        return ;
    }

    std::cout << "impossible\n";
}

static void    printAsInt(std::string literal)
{
    std::cout << "int: ";

    if (isFloatingPointRep(literal))
    {
        long    ln = std::strtol(literal.c_str(), NULL, BASE);
        int     n = static_cast<int>(std::strtol(literal.c_str(), NULL, BASE));

        if (isOverflowing(n, ln))
            return ;

        std::cout << n << std::endl;
        return ;
    }

    if (literal.length() == 1)
    {
        std::cout << static_cast<int>(literal[0]) << std::endl;
        return ;
    }

    std::cout << "impossible" << std::endl;
}

static void printAsFloat(std::string literal)
{
    std::cout << "float: ";

    if (isFloatingPointRep(literal) || isPseudoLiteral(literal))
    {
        double  f = std::atof(literal.c_str());

        std::cout << static_cast<float>(f) << FLOAT_SUFFIX << std::endl;
        return ;
    }

    if (literal.length() == 1)
    {
        std::cout << static_cast<float>(literal[0]) << FLOAT_SUFFIX << std::endl;
        return ;
    }

    std::cout << "impossible" << std::endl;
}

static void printAsDouble(std::string literal)
{
    std::cout << "double: ";

    if (isFloatingPointRep(literal) || isPseudoLiteral(literal))
    {
        double  d = atof(literal.c_str());

        std::cout << d << std::endl;
        return;
    }

    if (literal.length() == 1)
    {
        std::cout << static_cast<double>(literal[0]) << std::endl;
        return ;
    }

    std::cout << "impossible" << std::endl;
}

void    ScalarConverter::convert(std::string literal)
{
    std::cout << std::fixed << std::setprecision(1);

    printAsChar(literal);
    printAsInt(literal);
    printAsFloat(literal);
    printAsDouble(literal);
}