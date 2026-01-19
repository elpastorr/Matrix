#include "../includes/utils.hpp"

void    print_linear_combination(std::vector<Vector> &e_vectors, std::vector<K> coefs)
{
    std::cout << "Linear combination of" << std::endl;
    for (usize_t i = 0; i < e_vectors.size(); i++)
        std::cout << e_vectors[i] << std::endl;
    std::cout << "with coefficients " << coefs << " is:" << std::endl;
    std::cout << linear_combination(e_vectors, coefs) << std::endl;
}


int main()
{
    std::cout << GREEN << "LINEAR COMBINATIONS:" << END << std::endl;
    try
    {
        std::vector<K> vec_e1 = {1., 0., 0.};
        std::vector<K> vec_e2 = {0., 1., 0.};
        std::vector<K> vec_e3 = {0., 0., 1.};

        std::vector<K> vec_v1 = {1., 2., 3.};
        std::vector<K> vec_v2 = {0., 10., -100.};

        Vector e1(vec_e1);
        Vector e2(vec_e2);
        Vector e3(vec_e3);

        std::vector<Vector> e_vecs = {e1, e2, e3};

        Vector v1(vec_v1);
        Vector v2(vec_v2);

        std::vector<Vector> v_vecs = {v1, v2};

        std::vector<K> coeff_1 = {10., -2., 0.5};
        std::vector<K> coeff_2 = {10., -2.};

        print_linear_combination(e_vecs, coeff_1);
        std::cout << std::endl;
        print_linear_combination(v_vecs, coeff_2);
    }
    catch (std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
