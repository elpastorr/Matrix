#include <iostream>

#include "../Vector.hpp"
#include "../Matrix.hpp"

#define GREEN "\e[32m"
#define END "\e[0m"

int main()
{
    std::cout << GREEN << "TRANSPOSE:" << END << std::endl;
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