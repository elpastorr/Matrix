#include "../includes/utils.hpp"

int main()
{
    std::cout << GREEN << "DETERMINANT:" << END << std::endl;
    try
    {
        std::vector<std::vector<K> > mat1 = {
        {1., -1.},
        {-1., 1.}};
        std::vector<std::vector<K> > mat2 = {
        {2., 0., 0.},
        {0., 2., 0.},
        {0., 0., 2.}};
        std::vector<std::vector<K> > mat3 = {
        {8., 5., -2.},
        {4., 7., 20.},
        {7., 6., 1.}};
        std::vector<std::vector<K> > mat4 = {
        {8., 5., -2., 4.},
        {4., 2.5, 20., 4.},
        {8., 5., 1., 4.},
        {28., -4., 17., 1.}};

        Matrix m1(mat1);
        Matrix m2(mat2);
        Matrix m3(mat3);
        Matrix m4(mat4);

        print_determinant(m1);
        std::cout << std::endl;
        print_determinant(m2);
        std::cout << std::endl;
        print_determinant(m3);
        std::cout << std::endl;
        print_determinant(m4);
    }
    catch (std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}