#include "tridiagonal_matrix.h"

// Constructors realization
TridiagonalMatrix::TridiagonalMatrix(unsigned int n,
                                     std::vector<double>& l_diag,
                                     std::vector<double>& m_diag,
                                     std::vector<double>& r_diag) {
    // Setting the data vector size equal to order of initial matrix
    this->data_.resize(n);

    // Setting elements b_0 & c_0 in first line
    this->data_[0].b = m_diag[0];
    this->data_[0].c = r_diag[0];

    // Setting elements a_j, b_j, c_j (j = 1, 2,..., n - 1) in middle lines
    for (int i = 1; i < n - 1; i++) {
        this->data_[i].a = l_diag[i - 1];
        this->data_[i].b = m_diag[i];
        this->data_[i].c = r_diag[i];
    }
    // Setting elements a_n & b_n in last line
    this->data_[n - 1].a = l_diag[n - 2];
    this->data_[n - 1].b = m_diag[n - 1];
}

TridiagonalMatrix::TridiagonalMatrix(unsigned int n,
                                     std::vector<double>&& l_diag,
                                     std::vector<double>&& m_diag,
                                     std::vector<double>&& r_diag) {
    // Setting the data vector size equal to order of initial matrix
    this->data_.resize(n);

    // Setting elements b_0 & c_0 in first line
    this->data_[0].b = m_diag[0];
    this->data_[0].c = r_diag[0];

    // Setting elements a_j, b_j, c_j (j = 1, 2,..., n - 1) in middle lines
    for (int i = 1; i < n - 1; i++) {
        this->data_[i].a = l_diag[i - 1];
        this->data_[i].b = m_diag[i];
        this->data_[i].c = r_diag[i];
    }
    // Setting elements a_n & b_n in last line
    this->data_[n - 1].a = l_diag[n - 2];
    this->data_[n - 1].b = m_diag[n - 1];
}

TridiagonalMatrix::TridiagonalMatrix(std::vector<Triplet> &v): data_(v) {}

TridiagonalMatrix::TridiagonalMatrix(std::vector<Triplet> &&v): data_(v) {}

std::ostream& operator<<(std::ostream& os, const TridiagonalMatrix& mtx) {
    unsigned int n = mtx.data_.size();
    unsigned int cell_w = 8;

    // Formatting
    os <<std::setprecision((int)cell_w - 4);

    // Printing first line
    os << std::setw((int)cell_w) << std::left << mtx.data_[0].b;
    os << std::setw((int)cell_w) << std::left << mtx.data_[0].c;

    for (int i = 2; i < n; i++) {
        os << std::setw((int)cell_w) << std::left << 0;
    }

    os << std::endl;

    // Printing middle lines
    for (int i = 1; i < n - 1; i++) {
        for (int j = 0; j < i - 1; j++) {
            os << std::setw((int)cell_w) << std::left << 0;
        }

        os << std::setw((int)cell_w) << std::left << mtx.data_[i].a;
        os << std::setw((int)cell_w) << std::left << mtx.data_[i].b;
        os << std::setw((int)cell_w) << std::left << mtx.data_[i].c;

        for (int j = i + 2; j < n; j++) {
            os << std::setw((int)cell_w) << std::left << 0;
        }

        os << std::endl;
    }

    // Printing last line
    for (int i = 0; i < n - 2; i++) {
        os << std::setw((int)cell_w) << std::left << 0;
    }

    os << std::setw((int)cell_w) << std::left << mtx.data_[n - 1].a;
    os << std::setw((int)cell_w) << std::left << mtx.data_[n - 1].b;
    os << std::endl;

    return os;
}

Triplet TridiagonalMatrix::GetTriplet(unsigned int i) const {
    return data_[i];
}
