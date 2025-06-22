#include "ScalarConverter.hpp"
#include <cstdlib>

int main(int ac, char **av) {
    
    if (ac != 2)
        return (1);

    ScalarConverter::convert(av[1]);

    return 0;
}