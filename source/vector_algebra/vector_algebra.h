#ifndef SOLE_VECTOR_ALGEBRA_H
#define SOLE_VECTOR_ALGEBRA_H

#include <vector>
#include "../dense_matrix/dense_matrix.h"

// Addition of vectors
std::vector<double> operator+(const std::vector<double>& v1, const std::vector<double>& v2);

// Subtraction of vectors
std::vector<double> operator-(const std::vector<double>& v1, const std::vector<double>& v2);

// Multiplication of a vector by a scalar
std::vector<double> operator*(double s, const std::vector<double>& v);

std::vector<double> operator*(const std::vector<double>& v, double s);

// Division a vector by a scalar
std::vector<double> operator/(const std::vector<double>& v, double s);

// Scalar multiplication of vectors
double operator*(const std::vector<double>& v1, const std::vector<double>& v2);

// Absolute value (euclidean norm) of vector
double abs(const std::vector<double>& v);

// Dyad (as a product of vectors)
dns::DenseMatrix dyad(const std::vector<double>& v1, const std::vector<double>& v2);

// Standard basis unit vector
std::vector<double> BasisVector(size_t size, size_t direction);

// Vector directed strictly along one of the coordinates
std::vector<double> BasisVector(size_t size, size_t direction, double length);

#endif //SOLE_VECTOR_ALGEBRA_H