#ifndef SOLE_HOUSEHOLDER_TRANSFORMATION_H
#define SOLE_HOUSEHOLDER_TRANSFORMATION_H

#include "../dense_matrix/dense_matrix.h"
#include "../vector_algebra/vector_algebra.h"

std::pair<dns::DenseMatrix, dns::DenseMatrix> HouseholderTransform(const dns::DenseMatrix &matrix);

#endif //SOLE_HOUSEHOLDER_TRANSFORMATION_H
