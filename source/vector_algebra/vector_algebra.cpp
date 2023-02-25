#include "vector_algebra.h"

// Addition of vectors realization
std::vector<double> operator+(const std::vector<double>& v1, const std::vector<double>& v2) {
    std::vector<double> answer_v;

    for (int i = 0; i < std::size(v1); i++)
        answer_v.push_back(v1[i] + v2[i]);

    return answer_v;
}

// Subtraction of vectors realization
std::vector<double> operator-(const std::vector<double>& v1, const std::vector<double>& v2) {
    std::vector<double> answer_v;

    for (int i = 0; i < std::size(v1); i++)
        answer_v.push_back(v1[i] - v2[i]);

    return answer_v;
}

// Multiplication of a vector by a scalar realization
std::vector<double> operator*(double& x, const std::vector<double>& v) {
    std::vector<double> answer_v;

    for (int i = 0; i < std::size(v); i++)
        answer_v.push_back(x * v[i]);

    return answer_v;
}

// Division a vector by a scalar
std::vector<double> operator/(const std::vector<double>& v, double& x) {
    std::vector<double> answer_v;

    for (int i = 0; i < std::size(v); i++)
        answer_v.push_back(v[i] / x);

    return answer_v;
}

// Scalar multiplication of vectors
std::vector<double> operator*(const std::vector<double>& v1, const std::vector<double>& v2) {
    std::vector<double> answer_v;

    for (int i = 0; i < std::size(v1); i++)
        answer_v.push_back(v1[i] * v2[i]);

    return answer_v;
}