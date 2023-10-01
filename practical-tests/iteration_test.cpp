#include "../source/iterative_methods/iterative_methods.h"

// Counting the number of operations required by the simple iteration method
size_t CountSimpleIteration(const csr::CSRMatrix& A,
                            const std::vector<double>& b,
                            const std::vector<double>& x_0,
                            double target_r_norm,
                            double tau)
{
    // Solutions column
    std::vector<double> x = x_0;

    size_t counter = 0;

    // Iteration
    while (abs(b - A * x) > target_r_norm) {
        x = x - tau * (A * x - b);
        ++counter;
    }

    return counter;
}

// Writing to the file residual norm when solving by the simple iteration method
void RecordSimpleIteration(const csr::CSRMatrix& A,
                           const std::vector<double>& b,
                           const std::vector<double>& x_0,
                           size_t iterations_number,
                           double tau,
                           const std::string& address)
{
    // Opening an external file to record the residual
    std::fstream fs;
    fs.open(address, std::fstream::out);

    // Solutions column
    std::vector<double> x = x_0;

    // Iteration
    for (size_t k = 0; k < iterations_number; ++k) {
        fs << abs(b - A * x) << std::endl;
        x = x - tau * (A * x - b);
    }

    fs.close();
}

// Writing to the file residual norm when solving by the Jacoby method realization
void RecordJacoby(const csr::CSRMatrix& A,
                  const std::vector<double>& b,
                  const std::vector<double>& x_0,
                  size_t iterations_number,
                  const std::string& address)
{
    // Opening an external file to record the residual
    std::fstream fs;
    fs.open(address, std::fstream::out);

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
    for (size_t k = 0; k < iterations_number; ++k) {
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

        fs << abs(b - A * x_prev) << std::endl;

        x_prev = x_next;
    }

    fs.close();
}

// Writing to the file residual norm when solving by the Gauss-Seidel method realization
void RecordGaussSeidel(const csr::CSRMatrix& A,
                       const std::vector<double>& b,
                       const std::vector<double>& x_0,
                       size_t iterations_number,
                       const std::string& address)
{
    // Opening an external file to record the residual
    std::fstream fs;
    fs.open(address, std::fstream::out);

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
    for (size_t k = 0; k < iterations_number; ++k) {
        fs << abs(b - A * x) << std::endl;

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

    fs.close();
}

int main()
{
    csr::CSRMatrix A_3 {3,
                        3,
                        {{0, 0, 10},
                         {0, 1, 1},
                         {1, 0, 1},
                         {1, 1, 7},
                         {2, 1, 0.1},
                         {2, 2, 1}}};
    std::vector<double> x_0_3 {0, 0, 0};
    std::vector<double> b_3 {20, 30, 1};
    double target_r_norm = 10e-12;

    std::fstream fs;
    fs.open(R"(..\..\practical-tests\data\data_task3.txt)", std::fstream::out);

    for (double tau = 0.0001; tau < 0.1940; tau += 0.0001) {
        fs << CountSimpleIteration(A_3, b_3, x_0_3, target_r_norm, tau) << std::endl;
    }

    fs.close();

    csr::CSRMatrix A_4 {3,
                        3,
                        {{0, 0, 12},
                         {0, 1, 17},
                         {0, 2, 3},
                         {1, 0, 17},
                         {1, 1, 15825},
                         {1, 2, 28},
                         {2, 0, 3},
                         {2, 1, 28},
                         {2, 2, 238}}};
    std::vector<double> x_0_4 {1, 1, 1};
    std::vector<double> b_4 {1, 2, 3};
    size_t iterations_number = 50000;

    RecordSimpleIteration(A_4, b_4, x_0_4, iterations_number, 0.000126,
                          R"(..\..\practical-tests\data\data_task4_Simple.txt)");
    RecordJacoby(A_4, b_4, x_0_4, iterations_number,
                 R"(..\..\practical-tests\data\data_task4_Jacoby.txt)");
    RecordGaussSeidel(A_4, b_4, x_0_4, iterations_number,
                      R"(..\..\practical-tests\data\data_task4_Gauss-Seidel.txt)");
}
