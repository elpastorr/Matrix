#include "../includes/Matrix.hpp"

//EX01
void    print_linear_combination(std::vector<Vector> &e_vectors, std::vector<K> coefs)
{
    std::cout << "Linear combination of" << std::endl;
    for (usize_t i = 0; i < e_vectors.size(); i++)
        std::cout << e_vectors[i] << std::endl;
    std::cout << "with coefficients " << coefs << " is:" << std::endl;
    std::cout << linear_combination(e_vectors, coefs) << std::endl;
}

//EX03
void    print_dot_product(Vector u, Vector v)
{
        std::cout << u << " = u" << std::endl;
        std::cout << v << " = v" << std::endl;

        std::cout << "u . v = " << u.dot(v) << std::endl;
}

//EX04
void   print_norms(Vector v)
{
    std::cout << v << " = v" << std::endl;

    std::cout << "||v||_1 = " << v.norm_1() << std::endl;
    std::cout << "||v||_2 = " << v.norm_2() << std::endl;
    std::cout << "||v||_inf = " << v.norm_inf() << std::endl;
}

//EX05
void    print_cosine(Vector u, Vector v)
{
        std::cout << u << " = u" << std::endl;
        std::cout << v << " = v" << std::endl;

        K cosine = angle_cos(u, v);

        std::cout << "cosine(u, v) = " << cosine << std::endl;
}

//EX06
void    print_cross_product(Vector u, Vector v)
{
        std::cout << u << " = u" << std::endl;
        std::cout << v << " = v" << std::endl;

        std::cout << cross_product(u, v) << " = cross_product(u, v)" << std::endl;
}

//EX07
void    print_mul_vec(Matrix m, Vector v) {
        std::cout << m << " = m" << std::endl << std::endl;
        std::cout << v << " = v" << std::endl << std::endl;
        
        std::cout << m.mul_vec(v) << " = m * v" << std::endl;
}

void    print_mul_mat(Matrix m1, Matrix m2) {
        std::cout << m1 << " = m1" << std::endl << std::endl;
        std::cout << m2 << " = m2" << std::endl << std::endl;

        std::cout << m1.mul_mat(m2) << " = m1 * m2" << std::endl;
}

//EX08
void    print_trace(Matrix m) {
        std::cout << m << " = m" << std::endl;

        std::cout << "trace(m) = " << m.trace() << std::endl;
}

//EX09
void    print_transpose(Matrix m) {
        std::cout << m << " = m" << std::endl << std::endl;

        std::cout << m.transpose() << " = transpose(m)" << std::endl;
}

//EX10
void    print_row_echelon(Matrix m) {
    std::cout << m << " = m" << std::endl << std::endl;

    std::cout << m.reduced_row_echelon() << " = m.reduced_row_echelon()" << std::endl;
}

//EX11
void    print_determinant(Matrix m) {
    std::cout << m << " = m" << std::endl;
    std::cout << "Determinant: " << m.determinant() << std::endl;
}

//EX12
void    print_inverse(Matrix m) {
    std::cout << m << " = m" << std::endl << std::endl;
    std::cout << m.inverse() << " = m.inverse()" << std::endl;
}

//EX13
void    print_rank(Matrix m) {
    std::cout << m << " = m" << std::endl;
    std::cout << "m.rank() = " << m.rank() << std::endl;
}
