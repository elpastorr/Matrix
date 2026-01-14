#include <iostream>

#include "../Vector.hpp"
#include "../Matrix.hpp"

template<typename V>
V lerp(V u, V v, float t)
{
    if (t < 0. || t > 1.)
        throw std::out_of_range("t must be in [0, 1]");
    return (u * (1 - t) + v * t);
}

void   print_linear_interpolation(V u, V v, float t)
{
    std::cout << "Linear interpolation between" << std::endl;
    std::cout << u << std::endl;
    std::cout << "and" << std::endl;
    std::cout << v << std::endl;
    std::cout << "with t = " << t << " is:" << std::endl;
    V result = lerp(u, v, t);
    std::cout << result << std::endl;
}


int main()
{
    std::cout << "LINEAR INTERPOLATION:" << std::endl;
    try
    {
        std::vector<K> vec = {2., 1.};
        std::vector<K> vec2 = {4., 2.};

        Vector v1(vec);
        Vector v2(vec2);

        std::vector<std::vector<K> > mat = {vec, vec2};
        Matrix m1(mat);
        Matrix m2 = m1 * 10;

        print_linear_interpolation(0., 1., 0.);
        // print_linear_interpolation(0., 1., 1.);
        // print_linear_interpolation(0., 1., 0.5);
        // print_linear_interpolation(21., 42., 0.3);
        // print_linear_interpolation(v1, v2, 0.3);
        // print_linear_interpolation(m1, m2, 0.5);
    }
    catch (std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
