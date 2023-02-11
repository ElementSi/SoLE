#ifndef SOLE_TRIDIAGONAL_MATRIX_SOLVER_H
#define SOLE_TRIDIAGONAL_MATRIX_SOLVER_H

#include <vector>
#include "tridiagonal_matrix.h"

std::vector<double> SolveTridiagonalMatrix(unsigned int n,
                                           const TridiagonalMatrix& A,
                                           const std::vector<double>& f);

std::ostream& operator<<(std::ostream& os, const std::vector<double>& v);

#endif //SOLE_TRIDIAGONAL_MATRIX_SOLVER_H
