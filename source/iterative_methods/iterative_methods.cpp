#include <algorithm>

#include "iterative_methods.h"

// Simple iteration method
std::vector<double> SolveSimpleIteration(const csr::CSRMatrix& A,
                                         const std::vector<double>& b,
                                         const std::vector<double>& x_0,
                                         double target_r_norm,
                                         double tau)
{
    // Solutions column
    std::vector<double> x = x_0;

    // Iteration
    while (abs(b - A * x) > target_r_norm) {
        x = x - tau * (A * x - b);
    }

    return x;
}

// Jacobi's method
std::vector<double> SolveJacoby(const csr::CSRMatrix& A,
                                const std::vector<double>& b,
                                const std::vector<double>& x_0,
                                double target_r_norm)
{
    size_t dim = x_0.size();

    // Solutions columns
    std::vector<double> x_prev = x_0;
    std::vector<double> x_next(dim);

    // Getting A matrix structure vectors for more efficient calculation
    const std::vector<double>& val = A.GetValues();
    const std::vector<size_t>& row = A.GetRows();
    const std::vector<size_t>& col = A.GetColumns();

    // Iteration
    double sub_product;
    double main_diag_element;
    while (abs(b - A * x_prev) > target_r_norm) {
        for (size_t i = 0; i < dim; ++i) {
            sub_product = 0;

            for (size_t j = row[i]; j < row[i + 1]; ++j) {
                if (i == col[j]) {
                    main_diag_element = val[j];
                } else {
                    sub_product += x_prev[col[j]] * val[j];
                }
            }

            x_next[i] = (1.0 / main_diag_element) * (b[i] - sub_product);
        }

        x_prev = x_next;
    }

    return x_next;
}

// Gauss-Seidel's method
std::vector<double> SolveGaussSeidel(const csr::CSRMatrix& A,
                                     const std::vector<double>& b,
                                     const std::vector<double>& x_0,
                                     double target_r_norm)
{
    size_t dim = x_0.size();

    // Solutions column
    std::vector<double> x = x_0;

    // Getting A matrix structure vectors for more efficient calculation
    const std::vector<double>& val = A.GetValues();
    const std::vector<size_t>& row = A.GetRows();
    const std::vector<size_t>& col = A.GetColumns();

    // Iteration
    double upper_sub_product;
    double lower_sub_product;
    double main_diag_element;
    while (abs(b - A * x) > target_r_norm) {
        for (size_t i = 0; i < dim; ++i) {
            upper_sub_product = 0;
            lower_sub_product = 0;

            for (size_t j = row[i]; j < row[i + 1]; ++j) {
                if (col[j] < i) {
                    upper_sub_product += x[col[j]] * val[j];
                } else if (col[j] > i) {
                    lower_sub_product += x[col[j]] * val[j];
                } else {
                    main_diag_element = val[j];
                }
            }

            x[i] = (1.0 / main_diag_element) * (b[i] - upper_sub_product - lower_sub_product);
        }
    }

    return x;
}