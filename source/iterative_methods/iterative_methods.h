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

// Jacobi's method
std::vector<double> SolveJacoby(const csr::CSRMatrix &A,
                                const std::vector<double> &b,
                                const std::vector<double> &x_0,
                                double target_r_norm);

// Gauss-Seidel's method
std::vector<double> SolveGaussSeidel(const csr::CSRMatrix &A,
                                     const std::vector<double> &b,
                                     const std::vector<double> &x_0,
                                     double target_r_norm);

#endif //SOLE_ITERATIVE_METHODS_H
