#pragma once

#ifndef MATRIX_HPP
#define MATRIX_HPP

# include "Complex.hpp"
# include <iostream>
# include <ostream>
# include <vector>
# include "Vector.hpp"

typedef long unsigned int usize_t;

# ifdef COMPLEX
typedef Complex K;
# else
typedef double K;
# endif


class Matrix {
    public:
        Matrix(std::vector<std::vector<K> > values);
        Matrix(size_t rows, size_t cols);
        Matrix(const Matrix& matrix);
        Matrix operator = (const Matrix& matrix);

        std::vector<std::vector<K> > get_values() const;
        K get_value(size_t row, size_t col) const;
        void set_value(size_t row, size_t col, K value);
        std::vector<K> get_row(size_t row) const;
        size_t  get_rows() const;
        size_t  get_cols() const;
        size_t  get_nb_values() const ;
        void    swap_rows(usize_t row1, usize_t row2);
        void    swap_cols(usize_t col1, usize_t col2);
        void    reset();

        K       recursive_determinant(Matrix matrix) const;
        K       determinant() const;
        Matrix  identity() const;
        Matrix  row_echelon_w_identity(Matrix& identity) const;
        Matrix  row_echelon() const;
        Matrix  reduced_row_echelon() const;
        Matrix  inverse() const;
        usize_t rank() const;


        void    add(Matrix mat);
        void    sub(Matrix mat);
        void    scl(K scalar);
        Vector  mul_vec(const Vector& vec);
        Matrix  mul_mat(const Matrix& mat);
        K       trace();
        Matrix  transpose();

        Matrix operator + (const Matrix& other);
        Matrix operator - (const Matrix& other);
        Matrix operator * (const Matrix& other);
        Matrix operator * (const K& scalar);

        private:
            std::vector<std::vector<K> > _values;

};

std::vector<std::vector<K> > createSmallerMatrix(usize_t row, Matrix matrix);
std::ostream& operator<<(std::ostream& os, const Matrix& values);

#endif