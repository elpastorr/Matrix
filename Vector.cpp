#include "includes/Vector.hpp"

Vector::Vector(std::vector<K> values){
    if (values.size() < 2){
        throw std::invalid_argument("Vector must have at least 2 elements.");
    }
    _values = values;
}

Vector::Vector(size_t size){
    if (size <= 0){
        throw std::invalid_argument("Wrong Vector size.");
    }
    _values = std::vector<K>(size, 0);
}

std::vector<K> Vector::get_values() const {
    return _values;
}

K Vector::get_value(size_t i) const {
    if (i < 0 || i >= this->get_size()) {
        throw std::out_of_range("Impossible to get value out of the vector.");
    }
    return _values[i];
}

usize_t Vector::get_size() const {
    return _values.size();
}

void Vector::set_values(std::vector<K>& vec) {
    this->_values = vec;
}

void Vector::set_value(size_t i, K value) {
    if (i < 0 || i >= _values.size()) {
        throw std::out_of_range("Impossible to set value out of the vector.");
    }
    _values[i] = value;
}

void    Vector::add(Vector mat) {
    if (this->get_size() != mat.get_size())
        throw std::invalid_argument("Vectors must have the same size for addition.");

    for (usize_t i = 0; i < this->get_size(); i++) {
        this->set_value(i, this->get_value(i) + mat.get_value(i));
    }
}

void    Vector::sub(Vector mat) {
    if (this->get_size() != mat.get_size())
        throw std::invalid_argument("Vectors must have the same size for substraction.");

    for (usize_t i = 0; i < this->get_size(); i++) {
        this->set_value(i, this->get_value(i) - mat.get_value(i));
    }
}

void    Vector::scl(K scalar) {
    for (usize_t i = 0; i < this->get_size(); i++) {
        this->set_value(i, this->get_value(i) * scalar);
    }
}

K   Vector::dot(Vector v) {
    if (this->get_size() != v.get_size())
        throw std::invalid_argument("Vectors must have the same size for dot product.");

    K result = 0;
    for (usize_t i = 0; i < this->get_size(); i++) {
        result += this->get_value(i) * v.get_value(i);
    }
    return result;
}

K   abs(K value) {
    return (value < 0) ? -value : value;
}

K   sqrt(K value) {
    if (value < 0)
        return -1;
    if (value == 0 || value == 1)
        return value;

    K previous = value;
    K res = (previous + value / previous) / 2;
    while (abs(res - previous) > 0.00001) {
        previous = res;
        res = (res + value / res) / 2;
    }
    return res;
}

// somme des valeurs absolues des coordonnées 
K   Vector::norm_1() {
    K res = abs(_values[0]);

    for (usize_t i = 1; i < this->get_size(); i++)
        res += abs(_values[i]);
    return res;
}

//racine carrée de la somme des carrés des coordonnées
K   Vector::norm_2() {
    K res = _values[0] * _values[0];

    for (usize_t i = 1; i < this->get_size(); i++)
        res += _values[i] * _values[i];
    return sqrt(res);
}

// valeur absolue de la coordonnée la plus grande
K   Vector::norm_inf() {
    K res = abs(_values[0]);

    for (usize_t i = 1; i < this->get_size(); i++)
        if (abs(_values[i]) > res)
            res = abs(_values[i]);
    return res;
}

Vector Vector::operator + (const Vector& other) {
    this->add(other);
    return *this;
}

Vector Vector::operator - (const Vector& other) {
    this->sub(other);
    return *this;
}

Vector Vector::operator * (const K& scalar) {
    this->scl(scalar);
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Vector& values) {
    std::vector<K> vector = values.get_values();
    usize_t size = vector.size();
    os << "[";
    for (usize_t i = 0; i < size; i++){
        os << vector[i];
        if (i != size - 1)
            os << ", ";
    }
    os << "]";
	return (os);
}

Vector linear_combination(std::vector<Vector> &e_vectors, std::vector<K> coefs) {
    if (e_vectors.empty())
        throw std::invalid_argument("Vectors array is empty.");

    usize_t nb_vector = e_vectors.size();
    usize_t vec_size = e_vectors[0].get_size();

    if (nb_vector != coefs.size())
        throw std::invalid_argument("Size of vectors and coefficients must be the same.");

    for (usize_t i = 0; i < nb_vector; i++)
    {
        if (vec_size != e_vectors[i].get_size())
            throw std::invalid_argument("All vectors must have the same size.");
        e_vectors[i].scl(coefs[i]);
        if (i > 0)
            e_vectors[0].add(e_vectors[i]);
    }

    return e_vectors[0];
}

K       angle_cos(Vector &u, Vector &v) {
    if (u.get_size() != v.get_size())
        throw std::invalid_argument("Vectors must have the same size.");

    K dot = u.dot(v);
    K norm_u = u.norm_2();
    K norm_v = v.norm_2();

    if (norm_u == 0 || norm_v == 0)
        throw std::invalid_argument("Cannot compute angle cosine with zero-length vector.");

    return dot / (norm_u * norm_v);
}

Vector  cross_product(Vector &vec_u, Vector &vec_v) {
    if (vec_u.get_size() != 3 || vec_v.get_size() != 3)
        throw std::invalid_argument("Cross product is only defined for 3-dimensional vectors.");

    std::vector<K> result;
    std::vector<K> u = vec_u.get_values();
    std::vector<K> v = vec_v.get_values();

    result.push_back(u[1] * v[2] - u[2] * v[1]);
    result.push_back(u[2] * v[0] - u[0] * v[2]);
    result.push_back(u[0] * v[1] - u[1] * v[0]);

    return Vector(result);
}