#include "Vector.hpp"

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

std::ostream& operator<<(std::ostream& os, const Vector& values)
{
    std::vector<K> vector = values.get_values();
    usize_t size = vector.size();
    for (usize_t i = 0; i < size; i++){
        os << "[" << vector[i] << "]\n";
    }
	return (os);
}