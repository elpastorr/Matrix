#pragma once

# include <iostream>

class Complex {
    public:
        Complex();
        ~Complex();
        Complex(float real, float imag);
        Complex(float real);
        Complex(const Complex &copy);

        Complex &operator = (const Complex &other);
        bool    operator == (const Complex &other);
        bool    operator == (float other);
        bool    operator != (const Complex &other);
        bool    operator < (const Complex &other);
        bool    operator > (const Complex &other);
        bool    operator <= (const Complex &other);
        bool    operator >= (const Complex &other);
        bool    operator ! (void);

        Complex operator + (const Complex &other) const;
        Complex operator + (int other) const;
        Complex operator - (const Complex &other) const;
        Complex operator - (void) const;
        Complex operator * (const Complex &other) const;
        Complex operator / (const Complex &other) const;
        Complex operator ++ (int);
        Complex operator ++ (void);
        Complex operator -- (int);
        Complex operator -- (void);

        Complex operator += (const Complex &other);
        Complex operator -= (const Complex &other);
        Complex operator *= (const Complex &other);
        Complex operator /= (const Complex &other);

        float   getReal() const;
        float   getImag() const;

    private:
        float _real;
        float _imag;
};

std::ostream &operator<<(std::ostream &os, const Complex &complex);
