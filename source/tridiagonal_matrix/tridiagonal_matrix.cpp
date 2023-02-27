#include "tridiagonal_matrix.h"

namespace trd {
    // Constructors realization
    TridiagonalMatrix::TridiagonalMatrix(unsigned int order,
                                         const std::vector<double> &l_diag,
                                         const std::vector<double> &m_diag,
                                         const std::vector<double> &r_diag) {
        // Setting the data vector size equal to order of initial matrix
        this->data_.resize(order);
        this->order_ = order;

        // Setting elements b_0 & c_0 in first line
        this->data_[0].b = m_diag[0];
        this->data_[0].c = r_diag[0];

        // Setting elements a_j, b_j, c_j (j = 1, 2,..., order - 2) in middle lines
        for (int i = 1; i < order - 1; i++) {
            this->data_[i].a = l_diag[i - 1];
            this->data_[i].b = m_diag[i];
            this->data_[i].c = r_diag[i];
        }
        // Setting elements a_(order-1) & b_(order-1) in last line
        this->data_[order - 1].a = l_diag[order - 2];
        this->data_[order - 1].b = m_diag[order - 1];
    }

    TridiagonalMatrix::TridiagonalMatrix(unsigned int order,
                                         std::vector<Triplet> &input_v) :
            data_(input_v),
            order_(order) {}

    // Element getter realization
    [[nodiscard]] double TridiagonalMatrix::GetElement(unsigned int i, unsigned int j) const {
        if (int(i) - int(j) == 1) return this->data_[i].a;

        else if (int(i) - int(j) == 0) return this->data_[i].b;

        else if (int(i) - int(j) == -1) return this->data_[i].c;

        else return this->zero_;
    }

    // Triplet getter realization
    const Triplet &TridiagonalMatrix::GetTriplet(unsigned int i) const {
        return this->data_[i];
    }

    // Order getter realization
    unsigned int TridiagonalMatrix::GetOrder() const {
        return this->order_;
    }
}