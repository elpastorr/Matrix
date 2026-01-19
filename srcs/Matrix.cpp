#include "../includes/Matrix.hpp"

Matrix::Matrix(std::vector<std::vector<K> > values){
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
    std::vector<K> rows(size_rows, 0);
    _values = std::vector<std::vector<K> >(size_cols, rows);
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

std::vector<std::vector<K> > Matrix::get_values() const {
    return _values;
}

K Matrix::get_value(size_t row, size_t col) const {
    if (row >= this->get_rows() || col >= this->get_cols()) {
        throw std::out_of_range("Impossible to get value out of the matrix.");
    }
    return _values[row][col];
}

void Matrix::set_value(size_t row, size_t col, K value) {
    if (row >= this->get_rows() || col >= this->get_cols()) {
        throw std::out_of_range("Impossible to set value out of the matrix.");
    }
    _values[row][col] = value;
}

std::vector<K> Matrix::get_row(size_t row) const {
    return this->_values[row];
}

size_t Matrix::get_rows() const {
    return this->_values.size();
}

size_t Matrix::get_cols() const {
    if (this->_values.size() == 0)
        return 0;
    return this->_values[0].size();
}

size_t Matrix::get_nb_values() const {
    return this->get_rows() * this->get_cols();
}

void Matrix::swap_rows(usize_t row1, usize_t row2) {
    for (usize_t i = 0; i < get_cols(); i++) {
        K tmp = this->get_value(row1, i);
        this->set_value(row1, i, this->get_value(row2, i));
        this->set_value(row2, i, tmp);
    }
}

void Matrix::swap_cols(usize_t col1, usize_t col2) {
    for (usize_t i = 0; i < get_rows(); i++) {
        K tmp = this->get_value(i, col1);
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

std::vector<std::vector<K> > createSmallerMatrix(usize_t row, Matrix matrix){
    std::vector<std::vector<K> > res;
    std::vector<std::vector<K> > curr = matrix.get_values();
    usize_t size = matrix.get_cols();

    for (usize_t i = 1; i < size; i++){
        std::vector<K> tmp;
        for (usize_t j = 0; j < size; j++){
            if (j == row)
                continue;
            tmp.push_back(curr[i][j]);
        }
        res.push_back(tmp);
    }
    return res;
}

K Matrix::recursive_determinant(Matrix matrix) const {
    std::vector<std::vector<K> > matrix_values = matrix.get_values();
    
    usize_t size = matrix.get_rows();
    if (size == 2)
        return (matrix_values[0][0] * matrix_values[1][1]) - (matrix_values[0][1] * matrix_values[1][0]);

    K   det = 0;
    K   tmp;
    K   cofactor;
    for (usize_t i = 0; i < size; i++) {
        Matrix smaller_matrix(createSmallerMatrix(i, matrix));
        tmp = recursive_determinant(smaller_matrix);
        
        cofactor = K((i % 2 == 0) ? 1 : -1) * matrix_values[0][i];
        det += tmp * cofactor;
    }
    return det;
}

K Matrix::determinant() const {
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

    std::vector<std::vector<K> > values(rows, std::vector<K>(rows, 0));
    for (usize_t i = 0; i < rows; i++) {
        values[i][i] = 1;
    }
    return (Matrix(values));
}

size_t  find_non_zero_col(usize_t start, const Matrix& mat) {
    for (usize_t j = 0; j < mat.get_cols(); j++){
        for (usize_t i = start; i < mat.get_rows(); i++){
            if (mat.get_value(i, j) != 0.)
                return j;
        }
    }
    return -1;
}

Matrix  Matrix::row_echelon_w_identity(Matrix& identity) const {
    Matrix result(*this);

    if (result.get_rows() == 0 || result.get_cols() == 0)
        throw std::invalid_argument("Can't compute row echelon form of an empty matrix.");
    if (identity.get_rows() != result.get_rows() || identity.get_cols() != result.get_cols())
        throw std::invalid_argument("Identity matrix must have the same dimensions as the original matrix.");

    for (usize_t i = 0; i < result.get_rows(); i++){
        int non_zero_col = find_non_zero_col(i, result);
        // if there is just zero column, stop
        if (non_zero_col == -1)
            return result;

        K pivot = result.get_value(i, non_zero_col);

        if (pivot == 0.) {
            usize_t j = i + 1;
            while (j < result.get_rows()){
                if (result.get_value(j, non_zero_col) != 0.){
                    result.swap_rows(i, j);
                    identity.swap_rows(i, j);
                    break;
                }
                j++;
            }
            if (j == result.get_rows())
                continue;
        }

        // normalize the row
        K factor = K(1) / pivot;
        for (usize_t j = 0; j < result.get_cols(); j++) {
            result.set_value(i, j, result.get_value(i, j) * factor);
            identity.set_value(i, j, identity.get_value(i, j) * factor);
        }
        // get the other rows to zero
        for (usize_t j = i + 1; j < result.get_rows(); j++){
            K factor_to_zero = (result.get_value(j, non_zero_col)) * -1;
            for (usize_t k = 0; k < result.get_cols(); k++) {
                result.set_value(j, k, result.get_value(j, k) + factor_to_zero * result.get_value(i, k));
                identity.set_value(j, k, identity.get_value(j, k) + factor_to_zero * identity.get_value(i, k));
            }
        }
    }
    return result;
}

Matrix Matrix::inverse() const {
    if (this->get_rows() != this->get_cols())
        throw std::invalid_argument("Inverse can only be calculated for square matrices.");
    Matrix identity_matrix = this->identity();

    K determinant = this->determinant();
    if (determinant == 0)
        throw std::invalid_argument("Matrix is singular, it doesn't have an inverse.");

    Matrix row_echelon = this->row_echelon_w_identity(identity_matrix);

    usize_t columns = row_echelon.get_cols();
    for (usize_t i = row_echelon.get_rows() - 1; i > 0; i--){
        size_t column_non_empty = find_non_zero_col(i, row_echelon);
        if (static_cast<int>(column_non_empty) == -1)
            return identity_matrix;
        for (usize_t j = 0; j < i; j++){
            K factor_to_zero = (row_echelon.get_value(j, column_non_empty)) * -1;
            for (usize_t k = 0; k < columns; k++){
                row_echelon.set_value(j, k, row_echelon.get_value(j, k) + factor_to_zero * row_echelon.get_value(i, k));
                identity_matrix.set_value(j, k, identity_matrix.get_value(j, k) + factor_to_zero * identity_matrix.get_value(i, k));
            }
        }
    }
    return identity_matrix;
}

void    Matrix::add(Matrix mat) {
    if (this->get_rows() != mat.get_rows() || this->get_cols() != mat.get_cols())
        throw std::invalid_argument("Matrices must have the same dimensions for addition.");

    for (usize_t i = 0; i < this->get_rows(); i++) {
        for (usize_t j = 0; j < this->get_cols(); j++)
            _values[i][j] = this->get_value(i, j) + mat.get_value(i, j);
    }
}

void    Matrix::sub(Matrix mat) {
    if (this->get_rows() != mat.get_rows() || this->get_cols() != mat.get_cols())
        throw std::invalid_argument("Matrices must have the same dimensions for substraction.");

    for (usize_t i = 0; i < this->get_rows(); i++) {
        for (usize_t j = 0; j < this->get_cols(); j++)
            _values[i][j] = this->get_value(i, j) - mat.get_value(i, j);
    }
}

void    Matrix::scl(K scalar) {
    for (usize_t i = 0; i < this->get_rows(); i++)
        for (usize_t j = 0; j < this->get_cols(); j++)
            this->set_value(i, j,  this->get_value(i, j) * scalar);
}

Vector  Matrix::mul_vec(const Vector& vec) {
    if (this->get_cols() != vec.get_size())
        throw std::invalid_argument("Size incompatible for multiplication.");

    Vector res(this->get_rows());
    for (usize_t i = 0; i < this->get_rows(); i++) {
        K sum = 0;
        for (usize_t j = 0; j < this->get_cols(); j++) {
            sum += this->get_value(i, j) * vec.get_value(j);
        }
        res.set_value(i, sum);
    }
    return res;
}

Matrix  Matrix::mul_mat(const Matrix& mat) {
    if (this->get_cols() != mat.get_rows())
        throw std::invalid_argument("Size incompatible for multiplication.");

    Matrix res(this->get_rows(), mat.get_cols());
    for (usize_t i = 0; i < this->get_rows(); i++) {
        for (usize_t j = 0; j < mat.get_cols(); j++) {
            K sum = 0;
            for (usize_t k = 0; k < this->get_cols(); k++) {
                sum += this->get_value(i, k) * mat.get_value(k, j);
            }
            res.set_value(i, j, sum);
        }
    }
    return res;
}

K   Matrix::trace() {
    if (this->get_rows() != this->get_cols())
        throw std::invalid_argument("Trace can only be calculated for square matrices.");

    K trace = 0;
    for (usize_t i = 0; i < this->get_rows(); i++) {
        trace += this->get_value(i, i);
    }
    return trace;
}

Matrix  Matrix::transpose() {
    Matrix transposed(this->get_rows(), this->get_cols());

    for (usize_t i = 0; i < this->get_rows(); i++) {
        for (usize_t j = 0; j < this->get_cols(); j++) {
            transposed.set_value(j, i, this->get_value(i, j));
        }
    }
    return transposed;
}

Matrix  Matrix::row_echelon() const {
    Matrix result(*this);

    if (result.get_rows() == 0 || result.get_cols() == 0)
        throw std::invalid_argument("Can't compute row echelon form of an empty matrix.");

    for (usize_t i = 0; i < result.get_rows(); i++){
        int non_zero_col = find_non_zero_col(i, result);
        // if there is just zero column, stop
        if (non_zero_col == -1)
            return result;

        K pivot = result.get_value(i, non_zero_col);

        if (pivot == 0.) {
            usize_t j = i + 1;
            while (j < result.get_rows()){
                if (result.get_value(j, non_zero_col) != 0.){
                    result.swap_rows(i, j);
                    break;
                }
                j++;
            }
            if (j == result.get_rows())
                continue;
            pivot = result.get_value(i, non_zero_col);
        }

        // normalize the row
        K factor = K(1) / pivot;
        for (usize_t j = 0; j < result.get_cols(); j++)
            result.set_value(i, j, result.get_value(i, j) * factor);
    
        // get the other rows to zero
        for (usize_t j = i + 1; j < result.get_rows(); j++){
            K factor_to_zero = (result.get_value(j, non_zero_col)) * -1;
            for (usize_t k = 0; k < result.get_cols(); k++) {
                result.set_value(j, k, result.get_value(j, k) + factor_to_zero * result.get_value(i, k));
            }
        }
    }
    return result;
}

Matrix  Matrix::reduced_row_echelon() const {
    Matrix result(this->row_echelon());

    for (usize_t i = result.get_rows() - 1; i > 0; i--){
        size_t column_non_empty = find_non_zero_col(i, result);
        if (static_cast<int>(column_non_empty) == -1)
            return result;
        for (usize_t j = 0; j < i; j++){
            K factor_to_zero = (result.get_value(j, column_non_empty)) * -1;
            for (usize_t k = 0; k < result.get_cols(); k++){
                result.set_value(j, k, result.get_value(j, k) + factor_to_zero * result.get_value(i, k));
            }
        }
    }
    return result;
}

usize_t Matrix::rank() const {
    Matrix row_echelon = this->row_echelon();
    usize_t rank = 0;

    for (usize_t i = 0; i < row_echelon.get_rows(); i++){
        for (usize_t j = 0; j < row_echelon.get_cols(); j++){
            if (row_echelon.get_value(i, j) != 0.){
                rank++;
                break;
            }
        }
    }
    return rank;
}

Matrix  Matrix::operator + (const Matrix& other) {
    this->add(other);
    return *this;
}

Matrix  Matrix::operator - (const Matrix& other) {
    this->sub(other);
    return *this;
}

Matrix  Matrix::operator * (const Matrix& other) {
    this->mul_mat(other);
    return *this;
}

Matrix  Matrix::operator*(const K& scalar) {
    this->scl(scalar);
    return *this;
}

 std::ostream& operator<<(std::ostream& os, const  Matrix& values) {
    std::vector<std::vector<K> > matrix = values.get_values();
    usize_t rows = values.get_rows();
    usize_t columns = values.get_cols();
    for (usize_t i = 0; i < rows; i++){
        os << "[";
        for (usize_t j = 0; j < columns; j++){
            os << matrix[i][j];
            if (j + 1 < columns)
                os << ", ";
        }
        if (i + 1 < rows)
            os <<"]\n";
        else
            os <<"]";

    }
	return (os);
}
