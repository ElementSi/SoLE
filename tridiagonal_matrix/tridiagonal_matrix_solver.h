#ifndef SOLE_TRIDIAGONAL_MATRIX_SOLVER_H
#define SOLE_TRIDIAGONAL_MATRIX_SOLVER_H

#include <vector>
#include "tridiagonal_matrix.h"

// Function to solve SoLE
std::vector<double> SolveTridiagonalMatrix(unsigned int n,
                                           const TridiagonalMatrix& A,
                                           const std::vector<double>& f);

// Custom output operator for std::vector<double> class
std::ostream& operator<<(std::ostream& os, const std::vector<double>& v);

#endif //SOLE_TRIDIAGONAL_MATRIX_SOLVER_H
