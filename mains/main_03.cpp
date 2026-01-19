#include <iostream>

#include "../includes/Vector.hpp"
#include "../includes/Matrix.hpp"

#define GREEN "\e[32m"
#define END "\e[0m"

void    print_dot_product(Vector u, Vector v)
{
        std::cout << u << " = u" << std::endl;
        std::cout << v << " = v" << std::endl;

        std::cout << "u . v = " << u.dot(v) << std::endl;
}


int main()
{
    std::cout << GREEN << "DOT PRODUCT:" << END << std::endl;
    try
    {
        std::vector<K> vec_u = {0., 0.};
        std::vector<K> vec_v = {1., 1.};

        Vector u(vec_u);
        Vector v(vec_v);

        print_dot_product(u, v);
        std::cout << std::endl;

        std::vector<K> vec_u2 = {1., 1.};
        Vector u2(vec_u2);

        print_dot_product(u2, v);
        std::cout << std::endl;

        std::vector<K> vec_u3 = {-1., 6.};
        std::vector<K> vec_v3 = {3., 2.};

        Vector u3(vec_u3);
        Vector v3(vec_v3);
        print_dot_product(u3, v3);
    }
    catch (std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}