#pragma once

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
# include <ostream>
#include <vector>

typedef long unsigned int usize_t;

class Matrix;

# ifdef COMPLEX
typedef Complex K;
# else
typedef double K;
# endif

class Vector {
    public:
        Vector(std::vector<K> values);
        Vector(size_t size);

        std::vector<K> get_values() const ;
        K get_value(size_t i) const ;
        usize_t get_size() const ;
        void set_values(std::vector<K>& vec);
        void set_value(size_t i, K value);

        void    add(Vector mat);
        void    sub(Vector mat);
        void    scl(K scalar);

        Vector operator + (const Vector& other);
        Vector operator - (const Vector& other);
        Vector operator * (const K& scalar);



        private:
            std::vector<K> _values;
};

std::ostream& operator<<(std::ostream& os, const Vector& values);
Vector linear_combination(std::vector<Vector> &e_vectors, std::vector<K> coefs);

#endif