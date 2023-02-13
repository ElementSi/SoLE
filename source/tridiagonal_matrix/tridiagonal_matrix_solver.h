#ifndef SOLE_TRIDIAGONAL_MATRIX_SOLVER_H
#define SOLE_TRIDIAGONAL_MATRIX_SOLVER_H

#include <vector>
#include "tridiagonal_matrix.h"

// Function to solve SoLE
std::vector<double> SolveTridiagonalMatrix(unsigned int n,
                                           const TridiagonalMatrix& A,
                                           const std::vector<double>& f);

std::vector<double> SolveTridiagonalMatrix(unsigned int n,
                                           const TridiagonalMatrix& A,
                                           const std::vector<double>&& f);

#endif //SOLE_TRIDIAGONAL_MATRIX_SOLVER_H
