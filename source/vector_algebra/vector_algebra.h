#ifndef SOLE_VECTOR_ALGEBRA_H
#define SOLE_VECTOR_ALGEBRA_H

#include <vector>

// Addition of vectors
std::vector<double> operator+(const std::vector<double>&, const std::vector<double>&);

// Subtraction of vectors
std::vector<double> operator-(const std::vector<double>&, const std::vector<double>&);

// Multiplication of a vector by a scalar
std::vector<double> operator*(double&, const std::vector<double>&);

// Division a vector by a scalar
std::vector<double> operator/(const std::vector<double>&, double&);

// Scalar multiplication of vectors
std::vector<double> operator*(const std::vector<double>&, const std::vector<double>& v);

#endif //SOLE_VECTOR_ALGEBRA_H