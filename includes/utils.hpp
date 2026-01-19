#ifndef UTILS_HPP
#define UTILS_HPP

#include "Matrix.hpp"

#define GREEN "\e[32m"
#define END "\e[0m"

void    print_linear_combination(std::vector<Vector> &e_vectors, std::vector<K> coefs);
void    print_dot_product(Vector u, Vector v);
void    print_norms(Vector v);
void    print_cosine(Vector u, Vector v);
void    print_cross_product(Vector u, Vector v);
void    print_mul_vec(Matrix m, Vector v);
void    print_mul_mat(Matrix m1, Matrix m2);
void    print_trace(Matrix m);
void    print_transpose(Matrix m);
void    print_row_echelon(Matrix m);
void    print_determinant(Matrix m);
void    print_inverse(Matrix m);
void    print_rank(Matrix m);

#endif