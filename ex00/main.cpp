#include <iostream>

#include "../includes/Vector.hpp"
#include "../includes/Matrix.hpp"

#define GREEN "\e[32m"
#define END "\e[0m"

int main()
{
    {
        std::cout << GREEN << "VECTOR TESTS:" << END << std::endl;

        std::vector<K> vec = {2., 3.};
        Vector u(vec);
        std::cout << "u = " << u << std::endl;

        std::vector<K> vec2 = {5., 7.};
        Vector v(vec2);
        std::cout << "v = " << v << std::endl;

        Vector tmp = u;
        tmp.add(v);
        std::cout << "u + v = " << tmp << std::endl;

        tmp = u;
        tmp.sub(v);
        std::cout << "u - v = " << tmp << std::endl;

        tmp = u;
        tmp.scl(2.);
        std::cout << "u * 2 = " << tmp << std::endl;
    }
    {
        std::cout << "\nMATRIX TESTS:" << std::endl;
        std::vector<std::vector<K> > mat = {
        {1., 2.},
        {3., 4.}};
        Matrix u(mat);
        std::cout << "u = " << u << std::endl;

        std::vector<std::vector<K> > mat2 = {
        {7., 4.},
        {-2., 2.}};
        Matrix v(mat2);
        std::cout << "v = " << v << std::endl;

        Matrix tmp = u;
        tmp.add(v);
        std::cout << "u + v = " << tmp << std::endl;

        tmp = u;
        tmp.sub(v);
        std::cout << "u - v = " << tmp << std::endl;

        tmp = u;
        tmp.scl(2.);
        std::cout << "u * 2 = " << tmp << std::endl;
    }
    return 0;
}