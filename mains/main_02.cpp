#include <iostream>

#include "../includes/Vector.hpp"
#include "../includes/Matrix.hpp"

#define GREEN "\e[32m"
#define END "\e[0m"

template<typename V>
V lerp(V u, V v, float t)
{
    if (t < 0. || t > 1.)
        throw std::out_of_range("t must be in [0, 1]");
    return (u * (1 - t) + v * t);
}

template<typename V>
void   print_linear_interpolation(V u, V v, float t)
{
    std::cout << "Linear interpolation between " << u << " and " << v << std::endl;
    std::cout << "with t = " << t << " is: " << lerp(u, v, t) << std::endl;
}


int main()
{
    std::cout << GREEN << "LINEAR INTERPOLATION:" << END <<std::endl;
    try
    {
        std::vector<K> vec = {2., 1.};
        std::vector<K> vec2 = {4., 2.};

        Vector v1(vec);
        Vector v2(vec2);

        std::vector<std::vector<K> > mat = {vec, {3., 4.}};
        Matrix m1(mat);
        Matrix mat2 = mat;
        mat2.scl(10.);
        Matrix m2(mat2);

        print_linear_interpolation(0., 1., 0.);
        std::cout << std::endl;
        print_linear_interpolation(0., 1., 1.);
        std::cout << std::endl;
        print_linear_interpolation(0., 1., 0.5);
        std::cout << std::endl;
        print_linear_interpolation(21., 42., 0.3);
        std::cout << std::endl;
        print_linear_interpolation(v1, v2, 0.3);
        std::cout << std::endl;
        print_linear_interpolation(m1, m2, 0.5);
    }
    catch (std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
