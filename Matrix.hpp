#pragma once

#ifndef MATRIX_HPP
#define MATRIX_HPP

# include <vector>

# ifndef COMPLEX
typedef Complex T;
# else
typedef double T;
# endif


class Matrix {
    public:
        Matrix(<std::vector<std::vector<T>> values);
        Matrix(size_t rows, size_t cols);*
        Matrix(const Matrix& matrix);
        Matrix operator = (const Matrix& matrix);

        std::vector<std::vector<T>> get_values() const ;
        T get_value(size_t row, size_t col) const ;
        void set_value(size_t row, size_t col, T value);
        std::vector<T> get_row(size_t row) const ;
        size_t  get_rows() const ;
        size_t  get_cols() const ;
        size_t  get_nb_values() const ;
        void    swap_rows(usize_t row1, usize_t row2);
        void    swap_cols(usize_t col1, usize_t col2);
        void    reset();

        T       determinant() const ;
        Matrix  identity() const ;
        Matrix  inverse() const ;


        Matrix& operator + (const Matrix&);
        Matrix& operator - (const Matrix&);
        Matrix& operator * (const Matrix&);
        Matrix& operator * (const T&);

        private:
            std::vector<std::vector<T>> _values;

};

#endif