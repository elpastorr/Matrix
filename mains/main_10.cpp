#include <iostream>

#include "../includes/Vector.hpp"
#include "../includes/Matrix.hpp"

#define GREEN "\e[32m"
#define END "\e[0m"

void    print_row_echelon(Matrix m) {
    std::cout << m << " = m" << std::endl << std::endl;

    std::cout << m.reduced_row_echelon() << " = m.reduced_row_echelon()" << std::endl;
}

int main()
{
    std::cout << GREEN << "ROW ECHELON FORM:" << END << std::endl;
    try
    {
        std::vector<std::vector<K> > mat1 = {
        {1., 0., 0.},
        {0., 1., 0.},
        {0., 0., 1.}};
        std::vector<std::vector<K> > mat2 = {
        {1., 2.},
        {3., 4.}};
        std::vector<std::vector<K> > mat3 = {
        {1., 2.},
        {2., 4.}};
        std::vector<std::vector<K> > mat4 = {
        {8., 5., -2., 4., 28.},
        {4., 2.5, 20., 4., -4.},
        {8., 5., 1., 4., 17.}};

        Matrix m1(mat1);
        Matrix m2(mat2);
        Matrix m3(mat3);
        Matrix m4(mat4);

        print_row_echelon(m1);
        std::cout << std::endl << std::endl;
        print_row_echelon(m2);
        std::cout << std::endl << std::endl;
        print_row_echelon(m3);
        std::cout << std::endl << std::endl;
        print_row_echelon(m4);
    }
    catch (std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}