#define COMPLEX 1

#include "../includes/utils.hpp"

template<typename V>
V lerp(V u, V v, float t)
{
    if (t < 0. || t > 1.)
        throw std::out_of_range("t must be in [0, 1]");
    return (u * (1 - t) + v * t);
}

template<typename V>
void   print_linear_interpolation(V u, V v, float t)
{
    std::cout << "Linear interpolation between " << u << " and " << v << std::endl;
    std::cout << "with t = " << t << " is: " << lerp(u, v, t) << std::endl;
}

int main()
{
    std::cout << GREEN << "COMPLEX TESTS:" << END << std::endl;
    try
    {
        std::cout << GREEN << "BASIC OPERATION TEST:" << END << std::endl;
        Complex c1(4., 6.);
        Complex c2(-8., 3.);

        std::cout << "c1: " << c1 << std::endl;
        std::cout << "c2: " << c2 << std::endl;
        std::cout << "c1 / c2: " << c1 / c2 << std::endl;
        std::cout << "Result should be: -0.191781 - 0.821918i\n" << std::endl;
        std::cout << "c1 * c2: " << c1 * c2 << std::endl;
        std::cout << "Result should be: -50 - 36i\n" << std::endl;
        std::cout << "c1 + c2: " << c1 + c2 << std::endl;
        std::cout << "Result should be: -4 + 9i\n" << std::endl;
        std::cout << "c1 - c2: " << c1 - c2 << std::endl;
        std::cout << "Result should be: 12 + 3i\n" << std::endl;
        std::cout << "c1 == c2: " << (c1 == c2) << std::endl;
        std::cout << "Result should be: 0\n" << std::endl;
        std::cout << "c1 != c2: " << (c1 != c2) << std::endl;
        std::cout << "Result should be: 1\n" << std::endl;
        std::cout << "c1 * 3: " << c1 * 3 << std::endl;
        std::cout << "Result should be: 12 + 18i\n" << std::endl;
        std::cout << "c1 + 3: " << c1 + 3 << std::endl;
        std::cout << "Result should be: 7 + 6i\n" << std::endl;
        {
            std::cout << GREEN << "MATRIX TEST:" << END << std::endl;

            std::vector<std::vector<K> > mat = {
            {{1., 1.}, {2., 2.}},
            {{3., 3.}, {4., 4.}}};
            Matrix u(mat);
            std::cout << "u = " << u << std::endl << std::endl;
            std::vector<std::vector<K> > mat2 = {
            {{7., 2.}, {4., 0.}},
            {{-2., 2.}, {2., -2.}}};
            Matrix v(mat2);
            std::cout << "v = " << v << std::endl << std::endl;

            Matrix tmp = u;
            tmp.add(v);
            std::cout << "u + v = " << tmp << std::endl << std::endl;

            tmp = u;
            tmp.sub(v);
            std::cout << "u - v = " << tmp << std::endl << std::endl;

            tmp = u;
            tmp.scl(2.);
            std::cout << "u * 2 = " << tmp << std::endl << std::endl;
        }
        {
            std::cout << GREEN << "LINEAR COMBINATION:" << END << std::endl;

            std::vector<K> vec_e1 = {{1., 0.}, {0., 0.}, {0., 1.}};
            std::vector<K> vec_e2 = {{0., 0.}, {1., 1.}, {0., 0.}};
            std::vector<K> vec_e3 = {{0., 1.}, {0., 0.}, {1., 0.}};

            Vector e1(vec_e1);
            Vector e2(vec_e2);
            Vector e3(vec_e3);

            std::vector<Vector> e_vecs = {e1, e2, e3};
            std::vector<K> coeff_1 = {{10., 0}, {-2., 1}, {0.5, 2}};

            print_linear_combination(e_vecs, coeff_1);
            std::cout << std::endl;
        }
        {
            std::cout << GREEN << "LINEAR INTERPOLATION:" << END << std::endl;

            std::vector<K> vec = {{2., 1.}, {1., 0.}};
            std::vector<K> vec2 = {{4., 2.}, {2., 10.}};
            Vector v1(vec);
            Vector v2(vec2);

            print_linear_interpolation(v1, v2, 0.3);
            std::cout << std::endl;
        }
        {
            std::cout << GREEN << "DOT PRODUCT:" << END << std::endl;

            std::vector<K> vec_u = {{-1., 4.}, {6., 3.}};
            std::vector<K> vec_v = {{3., 2.}, {2., 1.}};
            Vector u(vec_u);
            Vector v(vec_v);

            print_dot_product(u, v);
            std::cout << std::endl;
        }
        {
            std::cout << GREEN << "NORM:" << END << std::endl;

            std::vector<K> vec = {{1., 3.}, {2., 2.}, {3., 1.}};
            Vector v(vec);

            print_norms(v);
            std::cout << std::endl;
        }
        {
            std::cout << GREEN << "COSINE:" << END << std::endl;

            std::vector<K> vec1 = {{1., 3.}, {2., 2.}, {3., 1.}};
            std::vector<K> vec2 = {{2., 6.}, {3., 7.}, {4., 8.}};
            Vector v1(vec1);
            Vector v2(vec2);

            print_cosine(v1, v2);
            std::cout << std::endl;
        }
        {
            std::cout << GREEN << "CROSS PRODUCT:" << END << std::endl;

            std::vector<K> vec1 = {{1., 3.}, {2., 2.}, {3., 1.}};
            std::vector<K> vec2 = {{2., 6.}, {3., 7.}, {4., 8.}};
            Vector v1(vec1);
            Vector v2(vec2);

            print_cross_product(v1, v2);
            std::cout << std::endl;
        }
        {
            std::cout << GREEN << "MATRIX MULTIPLICATION:" << END << std::endl;

            std::vector<std::vector<K> > mat1 = {
            {{1., 0.}, {-2., 1.}},
            {{0., 3.}, {0., 0.}}};
            std::vector<std::vector<K> > mat2 = {
            {{2., 0.}, {4., 2.}},
            {{0., 6.}, {7., 0.}}};

            Matrix m1(mat1);
            Matrix m2(mat2);

            std::vector<K> vec = {{4., 2.}, {2., 1.}};
            Vector v(vec);

            print_mul_vec(m1, v);
            std::cout << std::endl;
            print_mul_mat(m1, m2);
            std::cout << std::endl;
        }
        {
            std::cout << GREEN << "TRACE:" << END << std::endl;

            std::vector<std::vector<K> > mat = {
            {{2., 1.}, {-5., 2.}, {0., 3.}},
            {{4., 4.}, {3., 5.}, {7., 6.}},
            {{-2., 7.}, {3., 8.}, {4., 9.}}};
            Matrix m(mat);

            print_trace(m);
            std::cout << std::endl;
        }
        {
            std::cout << GREEN << "TRANSPOSE:" << END << std::endl;

            std::vector<std::vector<K> > mat = {
            {{1., 6.}, {2., 5.}, {3., 4.}},
            {{4., 7.}, {5., 8.}, {6., 9.}}};
            Matrix m(mat);

            print_transpose(m);
            std::cout << std::endl;
        }
        {
            std::cout << GREEN << "ROW ECHELON FORM:" << END << std::endl;

            std::vector<std::vector<K> > mat = {
            {{1., 1.}, {2., 1.}, {3., 1.}},
            {{4., 1.}, {5., 1.}, {6., 1.}},
            {{7., 1.}, {5., 1.}, {7., 1.}}};
            Matrix m(mat);

            print_row_echelon(m);
            std::cout << std::endl;
        }
        {
            std::cout << GREEN << "DETERMINANT:" << END << std::endl;

            std::vector<std::vector<K> > mat = {
            {{2., 1.}, {-5., 2.}, {0., 3.}},
            {{4., 4.}, {3., 5.}, {7., 6.}},
            {{-2., 7.}, {3., 8.}, {4., 9.}}};
            Matrix m(mat);

            print_determinant(m);
            std::cout << std::endl;
        }
        {
            std::cout << GREEN << "INVERSE:" << END << std::endl;

            std::vector<std::vector<K> > mat = {
            {{2., 1.}, {-5., 2.}, {0., 3.}},
            {{4., 4.}, {3., 5.}, {7., 6.}},
            {{-2., 7.}, {3., 8.}, {4., 9.}}};
            Matrix m(mat);
            
            print_inverse(m);
            std::cout << std::endl;
        }
        {
            std::cout << GREEN << "RANK:" << END << std::endl;

            std::vector<std::vector<K> > mat = {
            {{2., 1.}, {-5., 2.}, {0., 3.}},
            {{4., 4.}, {3., 5.}, {7., 6.}},
            {{-2., 7.}, {3., 8.}, {4., 9.}}};
            Matrix m(mat);

            print_rank(m);
        }

    }
    catch (std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}