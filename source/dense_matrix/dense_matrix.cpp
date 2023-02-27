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
    double DenseMatrix::GetElement(unsigned int i, unsigned int j) const {
        return this->data_[i * this->width_ + j];
    }

    // Column getter
    [[nodiscard]] std::vector<double> DenseMatrix::GetColumn(unsigned int j) const {
        std::vector<double> col;
        col.reserve(this->height_);

        for (unsigned int i = 0; i < this->height_; i++) {
            col.push_back(data_[i * this->width_ + j]);
        }

        return col;
    }

    // Row getter
    [[nodiscard]] std::vector<double> DenseMatrix::GetRow(unsigned int i) const {
        std::vector<double> row;
        row.reserve(this->width_);

        for (unsigned int j = i * this->width_; j < (i + 1) * this->width_; j++) {
            row.push_back(data_[j]);
        }

        return row;
    }

    // Height getter realization
    [[nodiscard]] unsigned int DenseMatrix::GetHeight() const {
        return this->height_;
    }

    // Width getter realization
    [[nodiscard]] unsigned int DenseMatrix::GetWidth() const {
        return this->width_;
    }

    // Data vector getter realization
    const std::vector<double> &DenseMatrix::GetValues() const {
        return this->data_;
    }

    // Element setter realization
    void DenseMatrix::SetElement(unsigned int i, unsigned int j, double new_element) {
        this->data_[i * this->width_ + j] = new_element;
    }

    // Multiplication operator* for matrices
    DenseMatrix DenseMatrix::operator*(const DenseMatrix &input_m) const {
        std::vector<double> answer_v;
        answer_v.reserve(this->height_ * input_m.GetWidth());

        for (unsigned int i = 0; i < this->height_; i++) {
            for (unsigned int j = 0; j < input_m.GetWidth(); j++) {
                double element = 0;

                for (unsigned int r = 0; r < this->width_; r++)
                    element += this->GetElement(i, r) * input_m.GetElement(r, j);

                answer_v.push_back(element);
            }
        }

        return {this->height_, input_m.GetWidth(), answer_v};
    }

    // Multiplication operator* for matrix & vector realization
    std::vector<double> DenseMatrix::operator*(const std::vector<double> &input_v) const {
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

    // Multiplication operator* for matrix & scalar realization
    DenseMatrix DenseMatrix::operator*(double s) const {
        std::vector<double> answer_v;
        answer_v.reserve(this->height_ * this->width_);

        for (unsigned int i = 0; i < this->height_; i++) {
            for (unsigned int j = 0; j < this->width_; j++) {
                answer_v.push_back(this->GetElement(i, j) * s);
            }
        }

        return {this->height_, this->width_, answer_v};
    }

    // Division operator/ for matrix & scalar realization
    DenseMatrix DenseMatrix::operator/(double s) const {
        return *this * (1 / s);
    }

    // Addition operator+ for matrices realization
    DenseMatrix DenseMatrix::operator+(const DenseMatrix &input_m) const {
        std::vector<double> answer_v;
        answer_v.reserve(this->height_ * this->width_);

        for (unsigned int i = 0; i < this->height_; i++) {
            for (unsigned int j = 0; j < this->width_; j++) {
                answer_v.push_back(this->GetElement(i, j) + input_m.GetElement(i, j));
            }
        }

        return {this->height_, this->width_, answer_v};
    }

    // Subtraction operator- for matrices realization
    DenseMatrix DenseMatrix::operator-(const DenseMatrix &input_m) const {
        std::vector<double> answer_v;
        answer_v.reserve(this->height_ * this->width_);

        for (unsigned int i = 0; i < this->height_; i++) {
            for (unsigned int j = 0; j < this->width_; j++) {
                answer_v.push_back(this->GetElement(i, j) - input_m.GetElement(i, j));
            }
        }

        return {this->height_, this->width_, answer_v};
    }

    // Comparison operator== for matrices
    bool DenseMatrix::operator==(const DenseMatrix &input_m) const {
        for (unsigned int i = 0; i < this->height_; i++) {
            for (unsigned int j = 0; j < this->width_; j++) {
                if (input_m.GetElement(i, j) != this->GetElement(i, j))
                    return false;
            }
        }

        return true;
    }

    // Square matrix with ones on the main diagonal and zeros elsewhere realization
    DenseMatrix IdentityMatrix(unsigned int order) {
        std::vector<double> temp_vector(order * order, 0.0);

        for (unsigned int i = 0; i < order; i++)
            temp_vector[i * order + i] = 1.0;

        return {order, order, temp_vector};
    }
}