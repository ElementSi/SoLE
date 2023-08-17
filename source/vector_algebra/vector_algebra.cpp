#include "cmath"
#include <numeric>

#include "vector_algebra.h"

// Addition of vectors realization
std::vector<double> operator+(const std::vector<double> &v1, const std::vector<double> &v2) {
    std::vector<double> answer_v;
    answer_v.reserve(v1.size());

    for (int i = 0; i < std::size(v1); i++)
        answer_v.push_back(v1[i] + v2[i]);

    return answer_v;
}

// Subtraction of vectors realization
std::vector<double> operator-(const std::vector<double> &v1, const std::vector<double> &v2) {
    std::vector<double> answer_v;
    answer_v.reserve(v1.size());

    for (int i = 0; i < std::size(v1); i++)
        answer_v.push_back(v1[i] - v2[i]);

    return answer_v;
}

// Multiplication of a vector by a scalar realization
std::vector<double> operator*(double s, const std::vector<double> &v) {
    std::vector<double> answer_v;
    answer_v.reserve(v.size());

    for (int i = 0; i < std::size(v); i++)
        answer_v.push_back(s * v[i]);

    return answer_v;
}

std::vector<double> operator*(const std::vector<double> &v, double s) {
    std::vector<double> answer_v;
    answer_v.reserve(v.size());

    for (int i = 0; i < std::size(v); i++)
        answer_v.push_back(s * v[i]);

    return answer_v;
}

// Division a vector by a scalar realization
std::vector<double> operator/(const std::vector<double> &v, double s) {
    std::vector<double> answer_v;
    answer_v.reserve(v.size());

    for (int i = 0; i < std::size(v); i++)
        answer_v.push_back(v[i] / s);

    return answer_v;
}

// Scalar multiplication of vectors realization
double operator*(const std::vector<double> &v1, const std::vector<double> &v2) {
    double answer = 0;

    for (int i = 0; i < std::size(v1); i++)
        answer += v1[i] * v2[i];

    return answer;
}

// Absolute value (euclidean norm) of vector realization
double abs(const std::vector<double> &v) {
    return sqrt(v * v);
}

// Dyad (as a product of vectors) realization
dns::DenseMatrix dyad(const std::vector<double> &v1, const std::vector<double> &v2) {
    std::vector<double> temp_vector;
    temp_vector.reserve(std::size(v1) * std::size(v2));

    for (unsigned int i = 0; i < std::size(v1); i++) {
        for (unsigned int j = 0; j < std::size(v2); j++) {
            temp_vector.push_back(v1[i] * v2[j]);
        }
    }

    return {static_cast<unsigned int>(std::size(v1)),
            static_cast<unsigned int>(std::size(v2)),
            temp_vector};
}

// Standard basis unit vector realization
std::vector<double> BasisVector(unsigned int size, unsigned int direction) {
    std::vector<double> temp_vector(size, 0.0);
    temp_vector[direction] = 1.0;

    return temp_vector;
}

// Vector directed strictly along one of the coordinates
std::vector<double> BasisVector(unsigned int size, unsigned int direction, double length) {
    std::vector<double> temp_vector(size, 0.0);
    temp_vector[direction] = length;

    return temp_vector;
}