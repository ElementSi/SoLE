#ifndef SOLE_ITERATIVE_METHODS_H
#define SOLE_ITERATIVE_METHODS_H

#include <vector>
#include <string>
#include <fstream>

#include "../csr_matrix/csr_matrix.h"
#include "../vector_algebra/vector_algebra.h"

// Simple iteration method
std::vector<double> SolveSimpleIteration(const csr::CSRMatrix &A,
                                         const std::vector<double> &b,
                                         const std::vector<double> &x_0,
                                         double target_r_norm,
                                         double tau);

// Counting the number of operations required by the simple iteration method
unsigned int CountSimpleIteration(const csr::CSRMatrix &A,
                                  const std::vector<double> &b,
                                  const std::vector<double> &x_0,
                                  double target_r_norm,
                                  double tau);

// Writing to the file residual norm when solving by the simple iteration method
void RecordSimpleIteration(const csr::CSRMatrix &A,
                           const std::vector<double> &b,
                           const std::vector<double> &x_0,
                           unsigned int iterations_number,
                           double tau,
                           const std::string &address);

// Jacobi method
std::vector<double> SolveJacoby(const csr::CSRMatrix &A,
                                const std::vector<double> &b,
                                const std::vector<double> &x_0,
                                double target_r_norm);

// Writing to the file residual norm when solving by the Jacoby method
void RecordJacoby(const csr::CSRMatrix &A,
                  const std::vector<double> &b,
                  const std::vector<double> &x_0,
                  unsigned int iterations_number,
                  const std::string &address);

// Gauss-Seidel method
std::vector<double> SolveGaussSeidel(const csr::CSRMatrix &A,
                                     const std::vector<double> &b,
                                     const std::vector<double> &x_0,
                                     double target_r_norm);

// Writing to the file residual norm when solving by the Gauss-Seidel method
void RecordGaussSeidel(const csr::CSRMatrix &A,
                       const std::vector<double> &b,
                       const std::vector<double> &x_0,
                       unsigned int iterations_number,
                       const std::string &address);

#endif //SOLE_ITERATIVE_METHODS_H
