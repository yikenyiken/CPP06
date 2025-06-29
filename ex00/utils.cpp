#include <cerrno>
#include <string>
#include <cstring>
#include <iostream>
#define DOT '.'
#define PLUS_SIGN '+'
#define HYPHEN '-'
#define FLOAT_SUFFIX 'f'
#define INF std::string("inf")
#define NAN std::string("nan")

bool    isPseudoLiteral(std::string literal)
{
    return (literal == INF || literal == HYPHEN + INF || literal == HYPHEN + INF + FLOAT_SUFFIX
        || literal == PLUS_SIGN + INF || literal == PLUS_SIGN + INF + FLOAT_SUFFIX
        || literal == INF + FLOAT_SUFFIX || literal == NAN || literal == NAN + FLOAT_SUFFIX);
}

bool    isOverflowing(int n, long ln)
{

    if (n != ln || errno == ERANGE)
    {
        std::cout << "impossible" << std::endl;
        return (true);
    }

    return (false);
}

bool    isFloatingPointRep(std::string literal)
{
    int dots = -1;

    for (size_t i = 0; i < literal.length(); ++i)
    {
        if (!i && (literal[i] == HYPHEN || literal[i] == PLUS_SIGN))
            continue ;

        if (literal[i] == DOT)
            ++dots;

        if (dots > 0 || (!isdigit(literal[i]) && ((literal[i] != FLOAT_SUFFIX && literal[i] != DOT)
            || (literal[i] == FLOAT_SUFFIX && (!i || literal[i - 1] == DOT || (literal.length() - 1 != i))))))
            return (false);
    }

    if (!dots && literal.length() == 1)
        return (false);

    return (true);
}