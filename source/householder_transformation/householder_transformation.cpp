#include "householder_transformation.h"

std::pair<dns::DenseMatrix, dns::DenseMatrix> HouseholderTransform(const dns::DenseMatrix &A) {
    unsigned int height = A.GetHeight();
    unsigned int width = A.GetWidth();
    unsigned int order = height;

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

    R.SetElement(0, 0, R.GetElement(0, 0) - temp_ratio * temp_composition * v[0]);

    for (unsigned int i = 1; i < height; i++)
        R.SetElement(i, 0, 0);

    for (unsigned int j = 1; j < width; j++) {
        temp_composition = 0;

        // Scalar multiplication of v and a_i vectors
        for (unsigned int i = 0; i < height; i++)
            temp_composition += R.GetElement(i, j) * v[i];

        for (unsigned int i = 0; i < height; i++)
            R.SetElement(i, j, R.GetElement(i, j) - temp_ratio * temp_composition * v[i]);
    }

    // Iteration until process is finished
    for (unsigned int k = 1; k < width; k++) {
        // Creating a & v vectors corresponding to the i column of A matrix
        a = R.GetColumn(k);

        for (unsigned int i = 0; i < k; i++)
            a[i] = 0;

        a[k] > 0 ? sign = 1.0 : sign = -1.0;
        v = a + BasisVector(height, k, sign * abs(a));

        // Updating R matrix
        temp_ratio = 2 / (v * v);
        temp_composition = (v * a);

        R.SetElement(k, k, R.GetElement(k, k) - temp_ratio * temp_composition * v[k]);

        for (unsigned int i = k + 1; i < height; i++) {
            R.SetElement(i, k, 0);
        }

        for (unsigned int j = k + 1; j < width; j++) {
            temp_composition = 0;

            // Scalar multiplication of v and a_i vectors
            for (unsigned int i = k; i < height; i++)
                temp_composition += R.GetElement(i, j) * v[i];

            for (unsigned int i = k; i < height; i++)
                R.SetElement(i, j, R.GetElement(i, j) - temp_ratio * temp_composition * v[i]);
        }

        // Updating Q matrix
        for (unsigned int j = 0; j < order; j++) {
            temp_composition = 0;

            // Scalar multiplication of v and q_i vectors
            for (unsigned int i = k; i < order; i++)
                temp_composition += Q.GetElement(j, i) * v[i];

            for (unsigned int i = k; i < order; i++)
                Q.SetElement(j, i, Q.GetElement(j, i) - temp_ratio * temp_composition * v[i]);
        }
    }

    return {Q, R};
}