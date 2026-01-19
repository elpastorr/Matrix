#include "../includes/utils.hpp"

int main()
{
    std::cout << GREEN << "RANK:" << END << std::endl;
    try
    {
        std::vector<std::vector<K> > mat1 = {
        {1., 0., 0.},
        {0., 1., 0.},
        {0., 0., 1.}};
        std::vector<std::vector<K> > mat2 = {
        {1., 2., 0., 0.},
        {2., 4., 0., 0.},
        {-1., 2., 1., 1.}};
        std::vector<std::vector<K> > mat3 = {
        {8., 5., -2.},
        {4., 7., 20.},
        {7., 6., 1.},
        {21., 18., 7.}};

        Matrix m1(mat1);
        Matrix m2(mat2);
        Matrix m3(mat3);

        print_rank(m1);
        std::cout << std::endl;
        print_rank(m2);
        std::cout << std::endl;
        print_rank(m3);
    }
    catch (std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}