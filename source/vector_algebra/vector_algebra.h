#ifndef SOLE_VECTOR_ALGEBRA_H
#define SOLE_VECTOR_ALGEBRA_H

#include <vector>

// Addition of vectors
std::vector<double> operator+(const std::vector<double> &v1, const std::vector<double> &v2);

// Subtraction of vectors
std::vector<double> operator-(const std::vector<double> &v1, const std::vector<double> &v2);

// Multiplication of a vector by a scalar
std::vector<double> operator*(double &s, const std::vector<double> &v);
std::vector<double> operator*(const std::vector<double> &v, double &s);

// Division a vector by a scalar
std::vector<double> operator/(const std::vector<double> &v, double &s);

// Scalar multiplication of vectors
double operator*(const std::vector<double> &v1, const std::vector<double> &v2);

#endif //SOLE_VECTOR_ALGEBRA_H