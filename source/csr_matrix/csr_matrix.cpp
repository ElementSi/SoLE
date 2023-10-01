#include "csr_matrix.h"

namespace csr
{
    // Constructors
    // It is assumed that elements in DOK are sorted
    CSRMatrix::CSRMatrix(size_t height,
                         size_t width,
                         const std::vector<Triplet>& DOK)
    {
        this->height_ = height;
        this->width_ = width;

        // Reserving place for data vectors to avoid unnecessary movements
        this->val_.reserve(DOK.size());
        this->col_.reserve(DOK.size());
        this->row_.reserve(this->height_ + 1);

        // Assigning a value of 0 to the 1st element of row_ vector
        this->row_.push_back(0);

        // Initialising of the counter of the elements up to the current row
        size_t nonzero_elements_in_rows = 0;

        for (auto it = DOK.begin(); it != DOK.end(); ++it) {
            // Addition new elements to val_ & col_ vectors
            this->val_.push_back(it->v);
            this->col_.push_back(it->j);

            // Addition new elements to row_ vector
            if (it != DOK.begin()) {
                for (size_t i = prev(it)->i; i < it->i; ++i) {
                    this->row_.push_back(nonzero_elements_in_rows);
                }
            }

            // Incrementing number of elements in previous rows
            ++nonzero_elements_in_rows;
        }

        // Assigning number of elements for the last rows to row_ vector
        size_t last_nonzero_row = 0;

        // Figuring out the row number of the last non-zero element
        if (!DOK.empty()) {
            last_nonzero_row = (std::prev(DOK.end()))->i;
        }

        // Filling last positions in row_ vector
        for (size_t i = last_nonzero_row; i < this->height_; ++i) {
            this->row_.push_back(nonzero_elements_in_rows);
        }
    }

    // Element getter
    double CSRMatrix::GetElement(size_t i, size_t j) const
    {
        // Return non-zero element
        for (size_t k = this->row_[i]; k != this->row_[i + 1]; ++k) {
            if (this->col_[k] == j) {
                return this->val_[k];
            }
        }

        // Return zero element
        return 0;
    }

    // Element getter through () operator
    [[nodiscard]] double CSRMatrix::operator()(size_t i, size_t j) const
    {
        // Return non-zero element
        for (size_t k = this->row_[i]; k != this->row_[i + 1]; ++k) {
            if (this->col_[k] == j) {
                return this->val_[k];
            }
        }

        // Return zero element
        return 0;
    }

    // Height getter
    [[nodiscard]] size_t CSRMatrix::GetHeight() const
    {
        return this->height_;
    }

    // Width getter
    [[nodiscard]] size_t CSRMatrix::GetWidth() const
    {
        return this->width_;
    }

    // Vectors getters
    const std::vector<double>& CSRMatrix::GetValues() const
    {
        return this->val_;
    }

    const std::vector<size_t>& CSRMatrix::GetColumns() const
    {
        return this->col_;
    }

    const std::vector<size_t>& CSRMatrix::GetRows() const
    {
        return this->row_;
    }

    // Multiplication operator (*) for matrix & vector
    std::vector<double> CSRMatrix::operator*(const std::vector<double>& input_v) const
    {
        std::vector<double> answer_v;
        answer_v.reserve(this->height_);

        for (size_t i = 0; i < this->height_; ++i) {
            double answer_element = 0;

            for (size_t j = this->row_[i]; j < this->row_[i + 1]; ++j) {
                answer_element += input_v[this->col_[j]] * this->val_[j];
            }

            answer_v.push_back(answer_element);
        }

        return answer_v;
    }
}