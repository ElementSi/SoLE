#include "householder_transformation.h"

std::pair<dns::DenseMatrix, dns::DenseMatrix> HouseholderTransform(const dns::DenseMatrix& A)
{
    size_t height = A.GetHeight();
    size_t width = A.GetWidth();
    size_t order = height;

    // Creating a vector corresponding to the first column of A matrix
    std::vector<double> a = A.GetColumn(0);

    // Creating first v vector
    double sign;
    a[0] > 0 ? sign = 1.0 : sign = -1.0;
    std::vector<double> v = a + BasisVector(height, 0, sign * abs(a));

    // Creating P_1 matrix as a base for Q matrix
    dns::DenseMatrix Q = dns::IdentityMatrix(order) - (dyad(v, v) / (v * v)) * 2;
    std::vector<double> q(order);

    // Creating R matrix from A matrix
    dns::DenseMatrix R = A;

    double temp_ratio = 2 / (v * v);
    double temp_composition = (v * a);

    R.SetElement(0, 0, R(0, 0) - temp_ratio * temp_composition * v[0]);

    for (size_t i = 1; i < height; ++i) {
        R.SetElement(i, 0, 0);
    }

    for (size_t j = 1; j < width; ++j) {
        temp_composition = 0;

        // Scalar multiplication of v and a_i vectors
        for (size_t i = 0; i < height; ++i) {
            temp_composition += R(i, j) * v[i];
        }

        for (size_t i = 0; i < height; ++i) {
            R.SetElement(i, j, R(i, j) - temp_ratio * temp_composition * v[i]);
        }
    }

    // Iteration until process is finished
    for (size_t k = 1; k < width; ++k) {
        // Creating a & v vectors corresponding to the i column of A matrix
        a = R.GetColumn(k);

        for (size_t i = 0; i < k; ++i) {
            a[i] = 0;
        }

        a[k] > 0 ? sign = 1.0 : sign = -1.0;
        v = a + BasisVector(height, k, sign * abs(a));

        // Updating R matrix
        temp_ratio = 2 / (v * v);
        temp_composition = (v * a);

        R.SetElement(k, k, R(k, k) - temp_ratio * temp_composition * v[k]);

        for (size_t i = k + 1; i < height; ++i) {
            R.SetElement(i, k, 0);
        }

        for (size_t j = k + 1; j < width; ++j) {
            temp_composition = 0;

            // Scalar multiplication of v and a_i vectors
            for (size_t i = k; i < height; ++i) {
                temp_composition += R(i, j) * v[i];
            }

            for (size_t i = k; i < height; ++i) {
                R.SetElement(i, j, R(i, j) - temp_ratio * temp_composition * v[i]);
            }
        }

        // Updating Q matrix
        for (size_t j = 0; j < order; ++j) {
            temp_composition = 0;

            // Scalar multiplication of v and q_i vectors
            for (size_t i = k; i < order; ++i) {
                temp_composition += Q(j, i) * v[i];
            }

            for (size_t i = k; i < order; ++i) {
                Q.SetElement(j, i, Q(j, i) - temp_ratio * temp_composition * v[i]);
            }
        }
    }

    return {Q, R};
}