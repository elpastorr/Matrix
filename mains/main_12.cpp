#include "../includes/utils.hpp"

int main()
{
    std::cout << GREEN << "INVERSE:" << END << std::endl;
    try
    {
        std::vector<std::vector<K> > mat1 = {
        {1., 0., 0.},
        {0., 1., 0.},
        {0., 0., 1.}};
        std::vector<std::vector<K> > mat2 = {
        {2., 0., 0.},
        {0., 2., 0.},
        {0., 0., 2.}};
        std::vector<std::vector<K> > mat3 = {
        {8., 5., -2.},
        {4., 7., 20.},
        {7., 6., 1.}};

        Matrix m1(mat1);
        Matrix m2(mat2);
        Matrix m3(mat3);

        print_inverse(m1);
        std::cout << std::endl << std::endl;
        print_inverse(m2);
        std::cout << std::endl << std::endl;
        print_inverse(m3);
    }
    catch (std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}