#include <iostream>

#include "../includes/Vector.hpp"
#include "../includes/Matrix.hpp"

#define GREEN "\e[32m"
#define END "\e[0m"

void    print_transpose(Matrix m) {
        std::cout << m << " = m" << std::endl << std::endl;

        std::cout << m.transpose() << " = transpose(m)" << std::endl;
}

int main()
{
    std::cout << GREEN << "TRANSPOSE:" << END << std::endl;
    try
    {
        std::vector<std::vector<K> > mat1 = {
        {1., 5.},
        {-3., 2.},
        {1., -4.}};
        std::vector<std::vector<K> > mat2 = {
        {1., 2., 3.},
        {4., 5., 6.},
        {7., 8., 9.}};
        std::vector<std::vector<K> > mat3 = {
        {1., 2., 3.},
        {4., 5., 6.}};

        Matrix m1(mat1);
        Matrix m2(mat2);
        Matrix m3(mat3);

        print_transpose(m1);
        std::cout << std::endl << std::endl;
        print_transpose(m2);
        std::cout << std::endl << std::endl;
        print_transpose(m3);
    }
    catch (std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}