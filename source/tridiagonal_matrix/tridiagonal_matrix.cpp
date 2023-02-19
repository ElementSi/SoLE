#include "tridiagonal_matrix.h"

namespace trd {
    // Constructors realization
    TridiagonalMatrix::TridiagonalMatrix(unsigned int n,
                                         const std::vector<double> &l_diag,
                                         const std::vector<double> &m_diag,
                                         const std::vector<double> &r_diag) {
        // Setting the data vector size equal to order of initial matrix
        this->data_.resize(n);
        this->order_ = n;

        // Setting elements b_0 & c_0 in first line
        this->data_[0].b = m_diag[0];
        this->data_[0].c = r_diag[0];

        // Setting elements a_j, b_j, c_j (j = 1, 2,..., n - 2) in middle lines
        for (int i = 1; i < n - 1; i++) {
            this->data_[i].a = l_diag[i - 1];
            this->data_[i].b = m_diag[i];
            this->data_[i].c = r_diag[i];
        }
        // Setting elements a_(n-1) & b_(n-1) in last line
        this->data_[n - 1].a = l_diag[n - 2];
        this->data_[n - 1].b = m_diag[n - 1];
    }

    TridiagonalMatrix::TridiagonalMatrix(unsigned int n,
                                         std::vector<Triplet> &v) :
            data_(v), order_(n) {}

    // Triplet getter realization
    const Triplet &TridiagonalMatrix::GetTriplet(unsigned int i) const {
        return this->data_[i];
    }

    // Order getter realization
    unsigned int TridiagonalMatrix::GetOrder() const {
        return this->order_;
    }
}