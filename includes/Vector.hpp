#pragma once

#ifndef VECTOR_HPP
#define VECTOR_HPP

# include "Complex.hpp"
# include <iostream>
# include <ostream>
# include <vector>

typedef long unsigned int usize_t;

class Matrix;

# ifndef K
#  ifndef COMPLEX
typedef double K;
#  else
typedef Complex K;
#  endif
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
        K       dot(Vector v);
        K       norm_1();
        K       norm_2();
        K       norm_inf();


        Vector operator + (const Vector& other);
        Vector operator - (const Vector& other);
        Vector operator * (const K& scalar);



        private:
            std::vector<K> _values;
};

std::ostream& operator<<(std::ostream& os, const Vector& values);
Vector  linear_combination(std::vector<Vector> &e_vectors, std::vector<K> coefs);
K       angle_cos(Vector &u, Vector &v);
Vector  cross_product(Vector &vec_u, Vector &vec_v);

#endif
