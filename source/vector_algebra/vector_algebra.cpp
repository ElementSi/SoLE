#include "cmath"
#include <numeric>

#include "vector_algebra.h"

// Addition of vectors
std::vector<double> operator+(const std::vector<double>& v1, const std::vector<double>& v2)
{
    std::vector<double> answer_v;
    answer_v.reserve(v1.size());

    for (int i = 0; i < std::size(v1); ++i) {
        answer_v.push_back(v1[i] + v2[i]);
    }

    return answer_v;
}

// Subtraction of vectors
std::vector<double> operator-(const std::vector<double>& v1, const std::vector<double>& v2)
{
    std::vector<double> answer_v;
    answer_v.reserve(v1.size());

    for (int i = 0; i < std::size(v1); ++i) {
        answer_v.push_back(v1[i] - v2[i]);
    }

    return answer_v;
}

// Multiplication of a vector by a scalar
std::vector<double> operator*(double s, const std::vector<double>& v)
{
    std::vector<double> answer_v;
    answer_v.reserve(v.size());

    for (int i = 0; i < std::size(v); ++i) {
        answer_v.push_back(s * v[i]);
    }

    return answer_v;
}

std::vector<double> operator*(const std::vector<double>& v, double s)
{
    std::vector<double> answer_v;
    answer_v.reserve(v.size());

    for (int i = 0; i < std::size(v); ++i) {
        answer_v.push_back(s * v[i]);
    }

    return answer_v;
}

// Division a vector by a scalar
std::vector<double> operator/(const std::vector<double>& v, double s)
{
    std::vector<double> answer_v;
    answer_v.reserve(v.size());

    for (int i = 0; i < std::size(v); ++i) {
        answer_v.push_back(v[i] / s);
    }

    return answer_v;
}

// Scalar multiplication of vectors
double operator*(const std::vector<double>& v1, const std::vector<double>& v2)
{
    double answer = 0;

    for (int i = 0; i < std::size(v1); ++i) {
        answer += v1[i] * v2[i];
    }

    return answer;
}

// Absolute value (euclidean norm) of vector
double abs(const std::vector<double>& v)
{
    return sqrt(v * v);
}

// Dyad (as a product of vectors)
dns::DenseMatrix dyad(const std::vector<double>& v1, const std::vector<double>& v2)
{
    std::vector<double> temp_vector;
    temp_vector.reserve(std::size(v1) * std::size(v2));

    for (size_t i = 0; i < std::size(v1); ++i) {
        for (size_t j = 0; j < std::size(v2); ++j) {
            temp_vector.push_back(v1[i] * v2[j]);
        }
    }

    return {std::size(v1),
            std::size(v2),
            temp_vector};
}

// Standard basis unit vector
std::vector<double> BasisVector(size_t size, size_t direction)
{
    std::vector<double> temp_vector(size, 0.0);
    temp_vector[direction] = 1.0;

    return temp_vector;
}

// Vector directed strictly along one of the coordinates
std::vector<double> BasisVector(size_t size, size_t direction, double length)
{
    std::vector<double> temp_vector(size, 0.0);
    temp_vector[direction] = length;

    return temp_vector;
}