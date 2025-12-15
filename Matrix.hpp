#pragma once

#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <iostream>
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
        Matrix(std::vector<std::vector<K>> values);
        Matrix(size_t rows, size_t cols);
        Matrix(const Matrix& matrix);
        Matrix operator = (const Matrix& matrix);

        std::vector<std::vector<K>> get_values() const;
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
        Matrix  row_echelon_form(Matrix &mirror) const;
        size_t  found_non_zero_col(size_t start_row, const Matrix &matrix) const;

        Matrix  inverse() const;

        void    add(Matrix mat);
        void    sub(Matrix mat);
        void    scl(K scalar);
        void    mul_mat(const Matrix& mat);

        Matrix operator + (const Matrix& other);
        Matrix operator - (const Matrix& other);
        Matrix operator * (const Matrix& other);
        Matrix operator * (const K& scalar);

        private:
            std::vector<std::vector<K>> _values;

};

std::vector<std::vector<K>> createSmallerMatrix(usize_t row, Matrix matrix);
std::ostream& operator<<(std::ostream& os, const Matrix& values);

#endif