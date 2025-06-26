#include "Base.hpp"
#include <cstdlib>
#include <exception>
#include <iostream>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base() 
{
    // std::cout << "Base's Destructor called\n";
}

Base    *generate(void)
{
    switch (arc4random() % MAX_DERIVED) {
        case 0 :
            return (new A);
            break ;
        case 1 :
            return (new B);
            break ;
        case 2 :
            return (new C);
            break ;
    }

    return (NULL);
}

void    identify(Base *p)
{
    Base    *ptr = NULL;

    ptr = dynamic_cast<A *>(p);
    if (ptr != NULL)
        std::cout << "\"A\"" << std::endl;
    
    ptr = dynamic_cast<B *>(p);
    if (ptr != NULL)
        std::cout << "\"B\"" << std::endl;
    
    ptr = dynamic_cast<C *>(p);
    if (ptr != NULL)
        std::cout << "\"C\"" << std::endl;
}

void    identify(Base &r)
{
    try
    {
        Base &ref = dynamic_cast<A &>(r);
        std::cout << "\"A\"" << std::endl;
        static_cast<void>(ref);
    }
    catch (std::exception &e)
    {
    }

    try
    {
        Base &ref = dynamic_cast<B &>(r);
        std::cout << "\"B\"" << std::endl;
        static_cast<void>(ref);
    }
    catch (std::exception &e)
    {
    }

    try
    {
        Base &ref = dynamic_cast<C &>(r);
        std::cout << "\"C\"" << std::endl;
        static_cast<void>(ref);
    }
    catch (std::exception &e)
    {
    }
}