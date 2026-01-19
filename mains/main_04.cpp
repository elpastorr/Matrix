#include "../includes/utils.hpp"

int main()
{
    std::cout << GREEN << "NORM:" << END << std::endl;
    try
    {
        std::vector<K> vec1 = {0., 0., 0.};
        std::vector<K> vec2 = {1., 2., 3.};
        std::vector<K> vec3 = {-1., -2.};

        Vector v1(vec1);
        Vector v2(vec2);
        Vector v3(vec3);

        print_norms(v1);
        std::cout << std::endl;
        print_norms(v2);
        std::cout << std::endl;
        print_norms(v3);
    }
    catch (std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}