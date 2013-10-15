#include <cmath>
#include <iostream>

#include "System.h"

int main(int argc, char const *argv[])
{
    System sys(3);
    sys.set(7);
    std::cout << sys << std::endl;
    return 0;
}