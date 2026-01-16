#include "includes/Complex.hpp"

Complex::Complex() : _real(0), _imag(0) {}

Complex::Complex(float real, float imag) : _real(real), _imag(imag) {}

Complex::Complex(float real) : _real(real), _imag(0) {}

Complex::~Complex() {}

Complex::Complex(const Complex &copy) {
    _real = copy.getReal();
    _imag = copy.getImag();
}

float  Complex::getReal() const {
    return _real;
}

float  Complex::getImag() const {
    return _imag;
}

std::ostream &operator<<(std::ostream &os, const Complex &complex) {
    os << complex.getReal();
    if (complex.getImag() >= 0)
        os << " + " << complex.getImag() << "i";
    else
        os << " - " << -complex.getImag() << "i";
    return os;
}

Complex &Complex::operator = (const Complex &other) {
    if (this != &other) {
        _real = other.getReal();
        _imag = other.getImag();
    }
    return *this;
}

bool    Complex::operator == (const Complex &other) {
    return (_real == other.getReal() && _imag == other.getImag());
}

bool    Complex::operator == (float other) {
    return (_real == other && _imag == 0);
}

bool    Complex::operator != (const Complex &other) {
    return !(*this == other);
}

bool    Complex::operator < (const Complex &other) {
    if (_real < other.getReal())
        return true;
    if (_real == other.getReal() && _imag < other.getImag())
        return true;
    return false;
}

bool    Complex::operator > (const Complex &other) {
    if (_real > other.getReal())
        return true;
    if (_real == other.getReal() && _imag > other.getImag())
        return true;
    return false;
}

bool    Complex::operator <= (const Complex &other) {
    return (*this < other || *this == other);
}

bool    Complex::operator >= (const Complex &other) {
    return (*this > other || *this == other);
}

bool    Complex::operator ! (void) {
    return (_real == 0 && _imag == 0);
}

Complex Complex::operator + (const Complex &other) const {
    return Complex(_real + other.getReal(), _imag + other.getImag());
}

Complex Complex::operator + (int other) const {
    return Complex(_real + static_cast<float>(other), _imag);
}

Complex Complex::operator - (const Complex &other) const {
    return Complex(_real - other.getReal(), _imag - other.getImag());
}

Complex Complex::operator - (void) const {
    return Complex(-_real, -_imag);
}

Complex Complex::operator * (const Complex &other) const {
    float real_part = _real * other.getReal() - _imag * other.getImag();
    float imag_part = _real * other.getImag() + _imag * other.getReal();
    return Complex(real_part, imag_part);
}

Complex Complex::operator / (const Complex &other) const {
    if (other.getReal() == 0 && other.getImag() == 0)
        throw std::invalid_argument("Division by zero in complex division.");

    float denominator = other.getReal() * other.getReal() + other.getImag() * other.getImag();
    if (denominator == 0)
        throw std::invalid_argument("Division by zero in complex division.");
    float real_part = (_real * other.getReal() + _imag * other.getImag()) / denominator;
    float imag_part = (_imag * other.getReal() - _real * other.getImag()) / denominator;

    return Complex(real_part, imag_part);
}

Complex Complex::operator ++ (int) {
    Complex ret = *this;
    _real++;
    _imag++;
    return ret;
}

Complex Complex::operator ++ (void) {
    _real ++;
    _imag ++;
    return *this;
}

Complex Complex::operator -- (int) {
    Complex ret = *this;
    _real--;
    _imag--;
    return ret;
}

Complex Complex::operator -- (void) {
    _real--;
    _imag--;
    return *this;
}

Complex Complex::operator += (const Complex &other) {
    _real += other.getReal();
    _imag += other.getImag();
    return *this;
}

Complex Complex::operator -= (const Complex &other) {
    _real -= other.getReal();
    _imag -= other.getImag();
    return *this;
}

Complex Complex::operator *= (const Complex &other) {
    auto tmp = _real;
    _real = _real * other.getReal() - _imag * other.getImag();
    _imag = tmp * other.getImag() + _imag * other.getReal();
    return *this;
}

Complex Complex::operator /= (const Complex &other) {
    if (other.getReal() == 0 && other.getImag() == 0)
        throw std::invalid_argument("Division by zero in complex division.");

    float denominator = other.getReal() * other.getReal() + other.getImag() * other.getImag();
    if (denominator == 0)
        throw std::invalid_argument("Division by zero in complex division.");

    float real_part = (_real * other.getReal() + _imag * other.getImag()) / denominator;
    float imag_part = (_imag * other.getReal() - _real * other.getImag()) / denominator;

    _real = real_part;
    _imag = imag_part;
    return *this;
}
