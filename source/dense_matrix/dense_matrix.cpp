#include "dense_matrix.h"

#include <utility>

namespace dns
{
    // Constructor
    DenseMatrix::DenseMatrix(size_t height,
                             size_t width,
                             std::vector<double> input_v)
            :
            height_(height),
            width_(width),
            data_(std::move(input_v))
    {}

    // Element getter
    double DenseMatrix::GetElement(size_t i, size_t j) const
    {
        return this->data_[i * this->width_ + j];
    }

    // Column getter
    [[nodiscard]] std::vector<double> DenseMatrix::GetColumn(size_t j) const
    {
        std::vector<double> col;
        col.reserve(this->height_);

        for (size_t i = 0; i < this->height_; ++i) {
            col.push_back(data_[i * this->width_ + j]);
        }

        return col;
    }

    // Row getter
    [[nodiscard]] std::vector<double> DenseMatrix::GetRow(size_t i) const
    {
        std::vector<double> row;
        row.reserve(this->width_);

        for (size_t j = i * this->width_; j < (i + 1) * this->width_; ++j) {
            row.push_back(data_[j]);
        }

        return row;
    }

    // Height getter
    [[nodiscard]] size_t DenseMatrix::GetHeight() const
    {
        return this->height_;
    }

    // Width getter
    [[nodiscard]] size_t DenseMatrix::GetWidth() const
    {
        return this->width_;
    }

    // Data vector getter
    const std::vector<double>& DenseMatrix::GetValues() const
    {
        return this->data_;
    }

    // Element setter
    void DenseMatrix::SetElement(size_t i, size_t j, double new_element)
    {
        this->data_[i * this->width_ + j] = new_element;
    }

    // Element getter & setter through () operator
    [[nodiscard]] double& DenseMatrix::operator()(size_t i, size_t j) {
        return this->data_[i * this->width_ + j];
    }

    // Multiplication operator* for matrices
    DenseMatrix DenseMatrix::operator*(const DenseMatrix& input_m) const
    {
        std::vector<double> answer_v;
        answer_v.reserve(this->height_ * input_m.GetWidth());

        for (size_t i = 0; i < this->height_; ++i) {
            for (size_t j = 0; j < input_m.GetWidth(); ++j) {
                double element = 0;

                for (size_t r = 0; r < this->width_; r++) {
                    element += this->GetElement(i, r) * input_m.GetElement(r, j);
                }

                answer_v.push_back(element);
            }
        }

        return {this->height_, input_m.GetWidth(), answer_v};
    }

    // Multiplication operator* for matrix & vector
    std::vector<double> DenseMatrix::operator*(const std::vector<double>& input_v) const
    {
        std::vector<double> answer_v;
        answer_v.reserve(this->height_);

        for (size_t i = 0; i < this->height_; ++i) {
            double answer_element = 0;

            for (size_t j = 0; j < this->width_; ++j) {
                answer_element += input_v[j] * this->data_[i * this->width_ + j];
            }

            answer_v.push_back(answer_element);
        }

        return answer_v;
    }

    // Multiplication operator* for matrix & scalar
    DenseMatrix DenseMatrix::operator*(double s) const
    {
        std::vector<double> answer_v;
        answer_v.reserve(this->height_ * this->width_);

        for (size_t i = 0; i < this->height_; ++i) {
            for (size_t j = 0; j < this->width_; ++j) {
                answer_v.push_back(this->GetElement(i, j) * s);
            }
        }

        return {this->height_, this->width_, answer_v};
    }

    // Division operator/ for matrix & scalar
    DenseMatrix DenseMatrix::operator/(double s) const
    {
        return *this * (1 / s);
    }

    // Addition operator+ for matrices
    DenseMatrix DenseMatrix::operator+(const DenseMatrix& input_m) const
    {
        std::vector<double> answer_v;
        answer_v.reserve(this->height_ * this->width_);

        for (size_t i = 0; i < this->height_; ++i) {
            for (size_t j = 0; j < this->width_; ++j) {
                answer_v.push_back(this->GetElement(i, j) + input_m.GetElement(i, j));
            }
        }

        return {this->height_, this->width_, answer_v};
    }

    // Subtraction operator- for matrices
    DenseMatrix DenseMatrix::operator-(const DenseMatrix& input_m) const
    {
        std::vector<double> answer_v;
        answer_v.reserve(this->height_ * this->width_);

        for (size_t i = 0; i < this->height_; ++i) {
            for (size_t j = 0; j < this->width_; ++j) {
                answer_v.push_back(this->GetElement(i, j) - input_m.GetElement(i, j));
            }
        }

        return {this->height_, this->width_, answer_v};
    }

    // Comparison operator== for matrices
    bool DenseMatrix::operator==(const DenseMatrix& input_m) const
    {
        for (size_t i = 0; i < this->height_; ++i) {
            for (size_t j = 0; j < this->width_; ++j) {
                if (input_m.GetElement(i, j) != this->GetElement(i, j)) {
                    return false;
                }
            }
        }

        return true;
    }

    // Square matrix with ones on the main diagonal and zeros elsewhere
    DenseMatrix IdentityMatrix(size_t order)
    {
        std::vector<double> temp_vector(order * order, 0.0);

        for (size_t i = 0; i < order; ++i) {
            temp_vector[i * order + i] = 1.0;
        }

        return {order, order, temp_vector};
    }
}