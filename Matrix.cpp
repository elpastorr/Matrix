#include "Matrix.hpp"

Matrix::Matrix(std::vector<std::vector<T>> values){
    usize_t rows = values.size();
    if (rows < 2){
        throw std::invalid_argument("Matrix must have at least 2 rows.");
    }
    usize_t cols = values[0].size();
    if (cols < 2){
        throw std::invalid_argument("Matrix must have at least 2 columns.");
    }
    for (usize_t i = 0; i < rows; i++){
        if (values[i].size() != cols){
            throw std::invalid_argument("All rows must have the same number of columns.");
        }
    }        
    _values = values;
}

Matrix::Matrix(size_t size_rows, size_t size_cols){
    if (size_rows <= 0 || size_cols <= 0){
        throw std::invalid_argument("Wrong Matrix dimensions.");
    }
    std::vector<T> rows(size_rows, 0);
    _values = std::vector<std::vector<T>>(size_cols, rows);
    this->reset();
}

Matrix::Matrix(const Matrix& matrix){
    _values = matrix.get_values();
}

Matrix Matrix::operator = (const Matrix& matrix) {
    if (this != &matrix) {
        _values = matrix.get_values();
    }
    return *this;
}

std::vector<std::vector<T>> Matrix::get_values() const {
    return _values;
}

T Matrix::get_value(size_t row, size_t col) const {
    if (row < 0 || row >= this->get_rows() || col < 0 || col >= this->get_cols()) {
        throw std::out_of_range("Impossible to get value out of the matrix.");
    }
    return _values[row][col];
}

void Matrix::set_value(size_t row, size_t col, T value) {
    if (row < 0 || row >= this->get_rows() || col < 0 || col >= this->get_cols()) {
        throw std::out_of_range("Impossible to set value out of the matrix.");
    }
    _values[row][col] = value;
}

std::vector<T> Matrix::get_row(size_t row) const {
    return this->_values[row];
}

size_t Matrix::get_rows() const {
    this->return _values.size();
}

size_t Matrix::get_cols() const {
    if (_values.size() == 0)
        return 0;
    return this->_values.begin().size();
}

size_t Matrix::get_nb_values() const {
    return this->get_rows() * this->get_cols();
}

void Matrix::swap_rows(usize_t row1, usize_t row2) {
    for (usize_t i = 0; i < get_cols(); i++) {
        T tmp = this->get_value(row1, i);
        this->set_value(row1, i, this->get_value(row2, i));
        this->set_value(row2, i, tmp);
    }
}

void Matrix::swap_cols(usize_t col1, usize_t col2) {
    for (usize_t i = 0; i < get_rows(); i++) {
        T tmp = this->get_value(i, col1);
        this->set_value(i, col1, this->get_value(i, col2));
        this->set_value(i, col2, tmp);
    }
}

void Matrix::reset(){
    size_t rows = this->get_rows();
    size_t cols = this->get_cols();
    
    for (usize_t i = 0; i < rows; i++){
        for (usize_t j = 0; j < cols; j++){
            this->set_value(i, j, 0.);
        }
    }
}

std::vector<std::vector<T>> createSmallerMatrix(usize_t row, Matrix matrix){
    std::vector<std::vector<T>> res;
    std::vector<std::vector<T>> curr = matrix.get_values();
    usize_t size = matrix.get_columns();

    for (usize_t i = 1; i < size; i++){
        std::vector<T> tmp;
        for (usize_t j = 0; j < size; j++){
            if (j == row)
                continue;
            tmp.push_back(curr[i][j]);
        }
        res.push_back(tmp);
    }
    return res;
}

T Matrix::recursive_determinant(Matrix matrix) const {
    std::vector<std::vector<T>> matrix_values = matrix.get_values();
    
    usize_t size = matrix.get_rows();
    if (size == 2)
        return (matrix_values[0][0] * matrix_values[1][1]) - (matrix_values[0][1] * matrix_values[1][0]);

    T   det = 0;
    T   tmp;
    T   cofactor;
    for (usize_t i = 0; i < size; i++) {
        Matrix smaller_matrix(createSmallerMatrix(i, matrix));
        tmp = recursive_determinant(smaller_matrix);
        
        cofactor = T((i % 2 == 0) ? 1 : -1) * matrix_values[0][i];
        det += tmp * cofactor;
    }
    return det;
}

T Matrix::determinant() const {
    if (this->get_rows() != this->get_cols()) {
        throw std::invalid_argument("Determinant can only be calculated for square matrices.");
    }
    return (recursive_determinant(*this));
}

Matrix Matrix::identity() const {
    usize_t rows = this->get_rows();

    if (rows != this->get_cols()) {
        throw std::invalid_argument("Identity matrix can only be created for square matrices.");
    }

    std::vector<std::vector<T>> values(rows, std::vector<T>(rows, 0));
    for (usize_t i = 0; i < rows; i++) {
        values[i][i] = 1;
    }
    return (Matrix(values));
}

Matrix  Matrix::row_echelon_form(Matrix &mirror) const {
    Matrix result(*this);

    if (result.get_rows() == 0 || result.get_cols() == 0)
        throw std::invalid_argument("Can't compute row echelon form of an empty matrix.");

    if (result.get_rows() != mirror.get_rows() || result.get_columns() != mirror.get_columns())
        throw std::invalid_argument("Mirror matrix must have same size as the original matrix.");

    for (size_t i = 0; i < result.get_rows(); i++){
        // find the first non-zero column
        size_t column_non_empty = found_non_zero_col(i, result)

        // if there is just zero column, stop
        if (column_non_empty == -1)
            return result;
    
        // if the non-zero column is not in the diagonal change the index row
        if (column_non_empty != i)
            i = column_non_empty - 1;

        T pivot = result.get_value(i, column_non_empty);
        // if the pivot is null and there is a non-zero element in the same column, swap the rows
        if (pivot == 0.){
            size_t j = i + 1;
            while (j < result.get_rows()){
                if (!result.get_value(j, column_non_empty) != false){
                    result.swap_rows(i, j);
                    mirror.swap_rows(i, j);
                    break;
                }
                j++;
            }
            if (j == result.get_rows())
                continue;
        }

        // normalize the row
        T factor = T(1) / pivot;
        for (size_t j = 0; j < result.get_cols(); j++){
            result.set_value(i, j, result.get_value(i, j) * factor);
            mirror.set_value(i, j, mirror.get_value(i, j) * factor);
        }

        // zero the other rows
        for (size_t j = i + 1; j < result.get_rows(); j++){
            T factor_to_zero = (result.get_value(j, column_non_empty)) * -1;
            for (size_t k = 0; k < result.get_cols(); k++){
                result.set_value(j, k, result.get_value(j, k) + factor_to_zero * result.get_value(i, k));
                mirror.set_value(j, k, mirror.get_value(j, k) + factor_to_zero * mirror.get_value(i, k));
            }
        }
    }
    return result;
}

size_t  Matrix::found_non_zero_col(size_t start_row, const Matrix &matrix) const {
    for (size_t i = matrix.get_cols() - 1; i >= 0; i--){
        for (size_t j = start_row; j >= 0; j--){
            if (matrix.get_value(j, i) != 0.)
                return i;
        }
    }
    return -1;
}

Matrix Matrix::inverse() const {
    Matrix identity_matrix = this->identity();

    T determinant = this->determinant();
    if (determinant == 0)
        throw std::invalid_argument("Matrix is singular, it doesn't have an inverse.");

    std::vector<std::vector<T>> identity_values = identity_matrix.get_values();

    Matrix row_echelon = this->row_echelon_form(identity_matrix);

    usize_t columns = row_echelon.get_cols();
    for (usize_t i = row_echelon.get_rows() - 1; i > 0; i--){
        size_t column_non_empty = found_non_zero_col(i, row_echelon);
        if (column_non_empty == -1)
            return identity_matrix;
        for (usize_t j = 0; j < i; j++){
            T factor_to_zero = (row_echelon.get_value(j, column_non_empty)) * -1;
            for (usize_t k = 0; k < columns; k++){
                row_echelon.set_value(j, k, row_echelon.get_value(j, k) + factor_to_zero * row_echelon.get_value(i, k));
                identity_matrix.set_value(j, k, identity_matrix.get_value(j, k) + factor_to_zero * identity_matrix.get_value(i, k));
            }
        }
    }
    return identity_matrix;
}


Matrix& Matrix::operator + (const Matrix& other) {
    if (this->get_rows() != other.get_rows() || this->get_cols() != other.get_cols())
        throw std::invalid_argument("Matrices must have the same dimensions for addition.");

    Matrix result(this->get_rows(), this->get_cols());
    for (usize_t i = 0; i < this->get_rows(); i++) {
        for (usize_t j = 0; j < this->get_cols(); j++)
            result.set_value(i, j, this->get_value(i, j) + other.get_value(i, j));
    }
}

Matrix& Matrix::operator - (const Matrix& other) {
    if (this->get_rows() != other.get_rows() || this->get_cols() != other.get_cols())
        throw std::invalid_argument("Matrices must have the same dimensions for substraction.");

    Matrix result(this->get_rows(), this->get_cols());
    for (usize_t i = 0; i < this->get_rows(); i++) {
        for (usize_t j = 0; j < this->get_cols(); j++)
            result.set_value(i, j, this->get_value(i, j) - other.get_value(i, j));
    }
}

Matrix& Matrix::operator * (const Matrix& other) {
    if (this->get_cols() != other.get_rows())
        throw std::invalid_argument("Size incompatible for multiplication.");

    Matrix result(this->get_rows(), other.get_cols());
    for (usize_t i = 0; i < this->get_rows(); i++) {
        for (usize_t j = 0; j < other.get_cols(); j++) {
            T sum = 0;
            for (usize_t k = 0; k < this->get_cols(); k++) {
                sum += this->get_value(i, k) * other.get_value(k, j);
            }
            result.set_value(i, j, sum);
        }
    }
    return result;
}

Matrix& Matrix::operator*(const T& scalar) {
    for (usize_t i = 0; i < this->get_rows(); i++)
        for (usize_t j = 0; j < other.get_cols(); j++)
            v_values[i][j] *= scalar;
}