#ifndef Serializer_HPP
# define Serializer_HPP
# include "stdint.h"
# include "Data.hpp"

class Serializer
{
    private:
        Serializer();
        Serializer(const Serializer &other);
    public:
        ~Serializer();

        Serializer          &operator = (const Serializer &rhs);
        static uintptr_t    serialize(Data *ptr);
        static Data         *deserialize(uintptr_t raw);
};

#endif