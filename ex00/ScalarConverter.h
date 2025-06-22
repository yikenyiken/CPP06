#ifndef ScalarConverter_H
# define ScalarConverter_H
# include <string>
# define IS_OVERFLOW(n, ln) n < ln ? true : false

bool    isNumeric(std::string literal);
bool    is_overflowing(int n, long ln);

#endif