#ifndef SOLE_ITERATIVE_METHODS_H
#define SOLE_ITERATIVE_METHODS_H

#include <vector>

#include "../csr_matrix/csr_matrix.h"

std::vector<double> SolveIterativeMethod(const csr::CSRMatrix A,
                                         const std::vector<double> &b);


#endif //SOLE_ITERATIVE_METHODS_H
