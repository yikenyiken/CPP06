#ifndef ScalarConverter_H
# define ScalarConverter_H
# include <string>
# define FLOAT_SUFFIX 'f'

bool    isOverflowing(int n, long ln);
bool    isFloatingPointRep(std::string literal);
bool    isSpecialVal(std::string literal);

#endif