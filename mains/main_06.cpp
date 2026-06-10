#include "../includes/utils.hpp"

int main()
{
    std::cout << GREEN << "CROSS PRODUCT:" << END << std::endl;
    try
    {
        std::vector<K> vec1 = {0., 0., 1.};
        std::vector<K> vec2 = {1., 0., 0.};
        std::vector<K> vec3 = {1., 2., 3.};
        std::vector<K> vec4 = {4., 5., 6.};
        std::vector<K> vec5 = {4., 2., -3.};
        std::vector<K> vec6 = {-2., -5., 16.};

        Vector v1(vec1);
        Vector v2(vec2);
        Vector v3(vec3);
        Vector v4(vec4);
        Vector v5(vec5);
        Vector v6(vec6);

        print_cross_product(v1, v2);
        std::cout << std::endl;
        print_cross_product(v3, v4);
        std::cout << std::endl;
        print_cross_product(v5, v6);
    }
    catch (std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
