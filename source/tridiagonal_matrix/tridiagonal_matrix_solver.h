#ifndef SOLE_TRIDIAGONAL_MATRIX_SOLVER_H
#define SOLE_TRIDIAGONAL_MATRIX_SOLVER_H

#include <vector>

#include "tridiagonal_matrix.h"

namespace trd {
// Function to solve SoLE
    std::vector<double> SolveTridiagonalMatrix(unsigned int order,
                                               const TridiagonalMatrix &matrix,
                                               const std::vector<double> &vector);
}

#endif //SOLE_TRIDIAGONAL_MATRIX_SOLVER_H
