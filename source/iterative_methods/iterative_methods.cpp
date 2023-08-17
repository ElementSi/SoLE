#include <algorithm>

#include "iterative_methods.h"

// Simple iteration method realization
std::vector<double> SolveSimpleIteration(const csr::CSRMatrix &A,
                                         const std::vector<double> &b,
                                         const std::vector<double> &x_0,
                                         double target_r_norm,
                                         double tau) {
    // Solutions column
    std::vector<double> x = x_0;

    // Iteration
    while (abs(b - A * x) > target_r_norm) {
        x = x - tau * (A * x - b);
    }

    return x;
}

// Counting the number of operations required by the simple iteration method realization
unsigned int CountSimpleIteration(const csr::CSRMatrix &A,
                                  const std::vector<double> &b,
                                  const std::vector<double> &x_0,
                                  double target_r_norm,
                                  double tau) {
    // Solutions column
    std::vector<double> x = x_0;

    unsigned int counter = 0;

    // Iteration
    while (abs(b - A * x) > target_r_norm) {
        x = x - tau * (A * x - b);
        counter++;
    }

    return counter;
}

// Writing to the file residual norm when solving by the simple iteration method realization
void RecordSimpleIteration(const csr::CSRMatrix &A,
                           const std::vector<double> &b,
                           const std::vector<double> &x_0,
                           unsigned int iterations_number,
                           double tau,
                           const std::string &address) {
    // Opening an external file to record the residual
    std::fstream fs;
    fs.open(address, std::fstream::out);

    // Solutions column
    std::vector<double> x = x_0;

    // Iteration
    for (unsigned int k = 0; k < iterations_number; k++) {
        fs << abs(b - A * x) << std::endl;
        x = x - tau * (A * x - b);
    }

    fs.close();
}

// Jacobi's method realization
std::vector<double> SolveJacoby(const csr::CSRMatrix &A,
                                const std::vector<double> &b,
                                const std::vector<double> &x_0,
                                double target_r_norm) {
    unsigned int dim = x_0.size();

    // Solutions columns
    std::vector<double> x_prev = x_0;
    std::vector<double> x_next(dim);

    // Getting A matrix structure vectors for more efficient calculation
    const std::vector<double> &val = A.GetValues();
    const std::vector<unsigned int> &row = A.GetRows();
    const std::vector<unsigned int> &col = A.GetColumns();

    // Iteration
    double sub_product;
    double main_diag_element;
    while (abs(b - A * x_prev) > target_r_norm) {
        for (unsigned int i = 0; i < dim; i++) {
            sub_product = 0;

            for (unsigned int j = row[i]; j < row[i + 1]; j++) {
                if (i == col[j])
                    main_diag_element = val[j];

                else
                    sub_product += x_prev[col[j]] * val[j];
            }

            x_next[i] = (1.0 / main_diag_element) * (b[i] - sub_product);
        }

        x_prev = x_next;
    }

    return x_next;
}

// Writing to the file residual norm when solving by the Jacoby method realization
void RecordJacoby(const csr::CSRMatrix &A,
                  const std::vector<double> &b,
                  const std::vector<double> &x_0,
                  unsigned int iterations_number,
                  const std::string &address) {
    // Opening an external file to record the residual
    std::fstream fs;
    fs.open(address, std::fstream::out);

    unsigned int dim = x_0.size();

    // Solutions columns
    std::vector<double> x_prev = x_0;
    std::vector<double> x_next(dim);

    // Getting A matrix structure vectors for more efficient calculation
    const std::vector<double> &val = A.GetValues();
    const std::vector<unsigned int> &row = A.GetRows();
    const std::vector<unsigned int> &col = A.GetColumns();

    // Iteration
    double sub_product;
    double main_diag_element;
    for (unsigned int k = 0; k < iterations_number; k++) {
        for (unsigned int i = 0; i < dim; i++) {
            sub_product = 0;

            for (unsigned int j = row[i]; j < row[i + 1]; j++) {
                if (i == col[j])
                    main_diag_element = val[j];

                else
                    sub_product += x_prev[col[j]] * val[j];
            }

            x_next[i] = (1.0 / main_diag_element) * (b[i] - sub_product);
        }

        fs << abs(b - A * x_prev) << std::endl;

        x_prev = x_next;
    }

    fs.close();
}

// Gauss-Seidel method realization
std::vector<double> SolveGaussSeidel(const csr::CSRMatrix &A,
                                     const std::vector<double> &b,
                                     const std::vector<double> &x_0,
                                     double target_r_norm) {
    unsigned int dim = x_0.size();

    // Solutions column
    std::vector<double> x = x_0;

    // Getting A matrix structure vectors for more efficient calculation
    const std::vector<double> &val = A.GetValues();
    const std::vector<unsigned int> &row = A.GetRows();
    const std::vector<unsigned int> &col = A.GetColumns();

    // Iteration
    double upper_sub_product;
    double lower_sub_product;
    double main_diag_element;
    while (abs(b - A * x) > target_r_norm) {
        for (unsigned int i = 0; i < dim; i++) {
            upper_sub_product = 0;
            lower_sub_product = 0;

            for (unsigned int j = row[i]; j < row[i + 1]; j++) {
                if (col[j] < i)
                    upper_sub_product += x[col[j]] * val[j];

                else if (col[j] > i)
                    lower_sub_product += x[col[j]] * val[j];

                else
                    main_diag_element = val[j];
            }

            x[i] = (1.0 / main_diag_element) * (b[i] - upper_sub_product - lower_sub_product);
        }
    }

    return x;
}

// Writing to the file residual norm when solving by the Gauss-Seidel method realization
void RecordGaussSeidel(const csr::CSRMatrix &A,
                       const std::vector<double> &b,
                       const std::vector<double> &x_0,
                       unsigned int iterations_number,
                       const std::string &address) {
    // Opening an external file to record the residual
    std::fstream fs;
    fs.open(address, std::fstream::out);

    unsigned int dim = x_0.size();

    // Solutions column
    std::vector<double> x = x_0;

    // Getting A matrix structure vectors for more efficient calculation
    const std::vector<double> &val = A.GetValues();
    const std::vector<unsigned int> &row = A.GetRows();
    const std::vector<unsigned int> &col = A.GetColumns();

    // Iteration
    double upper_sub_product;
    double lower_sub_product;
    double main_diag_element;
    for (unsigned int k = 0; k < iterations_number; k++) {
        fs << abs(b - A * x) << std::endl;

        for (unsigned int i = 0; i < dim; i++) {
            upper_sub_product = 0;
            lower_sub_product = 0;

            for (unsigned int j = row[i]; j < row[i + 1]; j++) {
                if (col[j] < i)
                    upper_sub_product += x[col[j]] * val[j];

                else if (col[j] > i)
                    lower_sub_product += x[col[j]] * val[j];

                else
                    main_diag_element = val[j];
            }

            x[i] = (1.0 / main_diag_element) * (b[i] - upper_sub_product - lower_sub_product);
        }
    }

    fs.close();
}
