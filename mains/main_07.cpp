#include "../includes/utils.hpp"

int main()
{
    std::cout << GREEN << "MATRIX MULTIPLICATION:" << END << std::endl;
    try
    {
        std::vector<std::vector<K> > mat1 = {
        {1., 0.},
        {0., 1.}};
        std::vector<std::vector<K> > mat2 = {
        {2., 0.},
        {0., 2.}};
        std::vector<std::vector<K> > mat3 = {
        {2., -2.},
        {-2., 2.}};
        std::vector<std::vector<K> > mat4 = {
        {2., 1.},
        {4., 2.}};
        std::vector<std::vector<K> > mat5 = {
        {3., -5.},
        {6., 8.}};
        
        Matrix m1(mat1);
        Matrix m2(mat2);
        Matrix m3(mat3);
        Matrix m4(mat4);
        Matrix m5(mat5);

        std::vector<K> vec = {4., 2.};

        Vector v(vec);

        print_mul_vec(m1, v);
        std::cout << std::endl;
        print_mul_vec(m2, v);
        std::cout << std::endl;
        print_mul_vec(m3, v);
        std::cout << std::endl;
        print_mul_mat(m1, m1);
        std::cout << std::endl;
        print_mul_mat(m1, m4);
        std::cout << std::endl;
        print_mul_mat(m5, m4);
    }
    catch (std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
