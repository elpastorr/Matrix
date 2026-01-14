#include <iostream>

#include "../Vector.hpp"
#include "../Matrix.hpp"

int main()
{
    std::cout << ":" << std::endl;
    try
    {

    }
    catch (std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}