#include "../includes/utils.hpp"

int main()
{
    std::cout << GREEN << "TRACE:" << END << std::endl;
    try
    {
        std::vector<std::vector<K> > mat1 = {
        {1., 0.},
        {0., 1.}};
        std::vector<std::vector<K> > mat2 = {
        {2., -5., 0.},
        {4., 3., 7.},
        {-2., 3., 4.}};
        std::vector<std::vector<K> > mat3 = {
        {-2., -8., 4.},
        {1., -23., 4.},
        {0., 6., 4.}};

        Matrix m1(mat1);
        Matrix m2(mat2);
        Matrix m3(mat3);

        print_trace(m1);
        std::cout << std::endl;
        print_trace(m2);
        std::cout << std::endl;
        print_trace(m3);
    }
    catch (std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
