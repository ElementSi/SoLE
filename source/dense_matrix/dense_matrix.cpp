#include "dense_matrix.h"

#include <utility>

namespace dns {
    // Constructor realization
    DenseMatrix::DenseMatrix(unsigned int height,
                             unsigned int width,
                             std::vector<double> input_v) :
            height_(height),
            width_(width),
            data_(std::move(input_v)) {}

    // Element getter realization
    const double &DenseMatrix::GetElement(unsigned int i, unsigned int j) const {
        return this->data_[i * this->width_ + j];
    }

    // Data vector getter realization
    const std::vector<double> &DenseMatrix::GetValues() const {
        return this->data_;
    }

    // Multiplication operator (*) for matrix & vector realization
    std::vector<double> DenseMatrix::operator*(const std::vector<double> &input_v) {
        std::vector<double> answer_v;
        answer_v.reserve(this->height_);

        for (unsigned int i = 0; i < this->height_; i++) {
            double answer_element = 0;

            for (unsigned int j = 0; j < this->width_; j++) {
                answer_element += input_v[j] * this->data_[i * this->width_ + j];
            }

            answer_v.push_back(answer_element);
        }

        return answer_v;
    }
}