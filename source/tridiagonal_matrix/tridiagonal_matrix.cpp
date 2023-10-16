#include "tridiagonal_matrix.h"

namespace trd
{
    // Constructors
    TridiagonalMatrix::TridiagonalMatrix(size_t order,
                                         const std::vector<double>& l_diag,
                                         const std::vector<double>& m_diag,
                                         const std::vector<double>& r_diag)
            : order_ {order}
    {
        // Setting the data vector size equal to order of initial matrix
        this->data_.resize(this->order_);

        if (this->order_ != 0) {
            // Setting element b_0 in first line
            this->data_[0].b = m_diag[0];
        }

        if (this->order_ != 1) {
            // Setting element c_0 in first line
            this->data_[0].c = r_diag[0];

            // Setting elements a_j, b_j, c_j (j = 1, 2,..., order - 2) in middle lines
            for (size_t i = 1; i < this->order_ - 1; ++i) {
                this->data_[i].a = l_diag[i - 1];
                this->data_[i].b = m_diag[i];
                this->data_[i].c = r_diag[i];
            }
            // Setting elements a_(order-1) & b_(order-1) in last line
            this->data_[this->order_ - 1].a = l_diag[this->order_ - 2];
            this->data_[this->order_ - 1].b = m_diag[this->order_ - 1];
        }
    }

    TridiagonalMatrix::TridiagonalMatrix(size_t order,
                                         const std::vector<Triplet>& input_v)
            : data_ {input_v},
              order_ {order}
    {}

    // Element getter
    [[nodiscard]] double TridiagonalMatrix::GetElement(size_t i, size_t j) const
    {
        if (i > this->order_ || j > this->order_) {
            throw std::out_of_range("TridiagonalMatrix::GetElement(i, j)");
        }

        if (i > j && i - j == 1) {
            return this->data_[i].a;
        } else if (i == j) {
            return this->data_[i].b;
        } else if (j > i && j - i == 1) {
            return this->data_[i].c;
        } else {
            return 0.0;
        }
    }

    // Element getter through () operator
    [[nodiscard]] double TridiagonalMatrix::operator()(size_t i, size_t j) const
    {
        return this->GetElement(i, j);
    }

    // Triplet getter
    const Triplet& TridiagonalMatrix::GetTriplet(size_t i) const
    {
        if (i > this->order_) {
            throw std::out_of_range("TridiagonalMatrix::GetTriplet(i)");
        }

        return this->data_[i];
    }

    // Order getter
    size_t TridiagonalMatrix::GetOrder() const
    {
        return this->order_;
    }
}