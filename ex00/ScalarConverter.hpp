#ifndef ScalarConverter_HPP
# define ScalarConverter_HPP
# include <string>
# include <iostream>
# define BASE 10

class ScalarConverter
{
    private:
        ScalarConverter();
    public:
        ScalarConverter(const ScalarConverter &other);
        ~ScalarConverter();

        ScalarConverter	&operator = (const ScalarConverter &rhs);

        static void convert(std::string literal);
};

#endif