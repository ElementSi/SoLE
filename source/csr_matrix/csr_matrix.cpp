#include "csr_matrix.h"

namespace csr {
    // Constructors
    // It is assumed that elements in DOK are sorted
    CSRMatrix::CSRMatrix(unsigned int height,
                         unsigned int width,
                         const std::vector<Triplet> &DOK) {
        this->height_ = height;
        this->width_ = width;

        // Reserving place for data vectors to avoid unnecessary movements
        this->val_.reserve(DOK.size());
        this->col_.reserve(DOK.size());
        this->row_.reserve(this->height_ + 1);

        // Assigning a value of 0 to the 1st element of row_ vector
        this->row_.push_back(0);

        // Initialising of the counter of the elements up to the current row
        unsigned int nonzero_elements_in_rows = 0;

        for (auto it = DOK.begin(); it != DOK.end(); it++) {
            // Addition new elements to val_ & col_ vectors
            this->val_.push_back(it->v);
            this->col_.push_back(it->j);

            // Addition new elements to row_ vector
            if (it != DOK.begin()) {
                for (unsigned int i = prev(it)->i; i < it->i; i++)
                    this->row_.push_back(nonzero_elements_in_rows);
            }

            // Incrementing number of elements in previous rows
            nonzero_elements_in_rows++;
        }

        // Assigning number of elements for the last rows to row_ vector
        unsigned int last_nonzero_row = 0;

        // Figuring out the row number of the last non-zero element
        if (!DOK.empty())
            last_nonzero_row = (DOK.end() - 1)->i;

        // Filling last positions in row_ vector
        for (unsigned int i = last_nonzero_row; i < this->height_; i++)
            this->row_.push_back(nonzero_elements_in_rows);
    };

    // Element getter
    double CSRMatrix::GetElement(unsigned int i, unsigned int j) const {
        // Return non-zero element
        for (unsigned int k = this->row_[i]; k != this->row_[i + 1]; k++) {
            if (this->col_[k] == j)
                return this->val_[k];
        }

        // Return zero element
        return this->zero_;
    }

    // Height getter
    [[nodiscard]] unsigned int CSRMatrix::GetHeight() const {
        return this->height_;
    }

    // Width getter
    [[nodiscard]] unsigned int CSRMatrix::GetWidth() const {
        return this->width_;
    }

    // Vectors getters
    const std::vector<double> &CSRMatrix::GetValues() const {
        return this->val_;
    }

    const std::vector<unsigned int> &CSRMatrix::GetColumns() const {
        return this->col_;
    }

    const std::vector<unsigned int> &CSRMatrix::GetRows() const {
        return this->row_;
    }

    // Multiplication operator (*) for matrix & vector
    std::vector<double> CSRMatrix::operator*(const std::vector<double> &input_v) const {
        std::vector<double> answer_v;
        answer_v.reserve(this->height_);
        double answer_element = 0;

        for (unsigned int i = 0; i < this->height_; i++) {
            answer_element = 0;

            for (unsigned int j = this->row_[i]; j < this->row_[i + 1]; j++) {
                answer_element += input_v[this->col_[j]] * this->val_[j];
            }

            answer_v.push_back(answer_element);
        }

        return answer_v;
    }
}