#include "csr_matrix.h"

namespace csr {
    // Constructors realization
    // It is assumed that elements in DOK are sorted
    CSRMatrix::CSRMatrix(unsigned int height,
                         unsigned int width,
                         const std::vector<Triplet> &DOK_matrix) {
        this->height_ = height;
        this->width_ = width;

        // Assigning a value of 0 to the 1st of row_ vector
        this->row_.push_back(0);

        // Initialising of the counter of the elements in the current row
        unsigned int elements_in_rows = 0;

        for (auto it = DOK_matrix.begin(); it != DOK_matrix.end(); it++) {
            // Addition new elements to val_ & col_ vectors
            this->val_.push_back(it->v);
            this->col_.push_back(it->j);

            // Addition new elements to row_ vector
            if (it != DOK_matrix.begin()) {
                for (unsigned int i = prev(it)->i; i < it->i; i++)
                    this->row_.push_back(elements_in_rows);
            }

            // Incrementing number of elements in previous rows
            elements_in_rows++;
        }

        // Assigning number of elements for the last rows to row_ vector
        unsigned int last_nonzero_row = 0;

        if (!DOK_matrix.empty())
            last_nonzero_row = (DOK_matrix.end() - 1)->i;

        for (unsigned int i = last_nonzero_row; i < height; i++)
            this->row_.push_back(elements_in_rows);
    };

    // Matrix element getter realization
    const double& CSRMatrix::GetElement(unsigned int i, unsigned int j) const {
        // Return non-zero element
        for (unsigned int k = this->row_[i]; k != this->row_[i + 1]; k++) {
            if (this->col_[k] == j)
                return this->val_[k];
        }

        // Return zero element
        return this->zero_;
    }

    // Matrix vectors getters realization
    const std::vector<double>& CSRMatrix::GetValues() const {
        return this->val_;
    }

    const std::vector<unsigned int>& CSRMatrix::GetColumns() const {
        return this->col_;
    }

    const std::vector<unsigned int>& CSRMatrix::GetRows() const {
        return this->row_;
    }
}