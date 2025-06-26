#ifndef Serializer_HPP
# define Serializer_HPP
# include <cstdint>
# include "Data.hpp"

class Serializer
{
    private:
        Serializer();
        Serializer(const Serializer &other);
    public:
        ~Serializer();

        Serializer          &operator = (const Serializer &rhs);
        static uintptr_t    serialze(Data *ptr);
        static Data         *deserialize(uintptr_t raw);
};

#endif