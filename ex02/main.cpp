#include <iostream>
#include "Base.h"
int main() {

    Base    *p = generate();

    std::cout << "identify pointer version: ";
    identify(p);
    std::cout << "identify reference version: ";
    identify(*p);

    delete p;
    return 0;
}