#include <cerrno>
#include <cinttypes>
#include <string>
#include <iostream>

bool    isNumeric(std::string literal)
{
    for (int i = 0; i < literal.length(); i++)
    {
        if (!std::isdigit(literal[i]))
			return (false);
	}

	return (true);
}

bool    is_overflowing(int n, long ln)
{
    std::cout << "long: " << ln << std::endl;
    std::cout << "int: " << n << std::endl;

    if (n < ln || errno == ERANGE)
    {
        std::cout << "impossible" << std::endl;
        return (true);
    }

    return (false);
}