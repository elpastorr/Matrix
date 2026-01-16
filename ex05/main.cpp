#include <iostream>

#include "../includes/Vector.hpp"
#include "../includes/Matrix.hpp"

#define GREEN "\e[32m"
#define END "\e[0m"

void    print_cosine(Vector u, Vector v)
{
        std::cout << u << " = u" << std::endl;
        std::cout << v << " = v" << std::endl;

        K cosine = angle_cos(u, v);

        std::cout << "cosine(u, v) = " << cosine << std::endl;
}


int main()
{
    std::cout << GREEN << "COSINE:" << END << std::endl;
    try
    {
        std::vector<K> vec1 = {1., 0.};
        std::vector<K> vec2 = {0., 1.};
        std::vector<K> vec3 = {-1., 1.};
        std::vector<K> vec4 = {1., -1.};
        std::vector<K> vec5 = {2., 1.};
        std::vector<K> vec6 = {4., 2.};
        std::vector<K> vec7 = {1., 2., 3.};
        std::vector<K> vec8 = {4., 5., 6.};

        Vector v1(vec1);
        Vector v2(vec2);
        Vector v3(vec3);
        Vector v4(vec4);
        Vector v5(vec5);
        Vector v6(vec6);
        Vector v7(vec7);
        Vector v8(vec8);

        print_cosine(v1, v1);
        std::cout << std::endl;
        print_cosine(v1, v2);
        std::cout << std::endl;
        print_cosine(v3, v4);
        std::cout << std::endl;
        print_cosine(v5, v6);
        std::cout << std::endl;
        print_cosine(v7, v8);
    }
    catch (std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}