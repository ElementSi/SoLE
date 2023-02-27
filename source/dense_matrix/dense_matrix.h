#ifndef SOLE_DENSE_MATRIX_H
#define SOLE_DENSE_MATRIX_H

#include <vector>

namespace dns {
    // Class allowing to store sparse matrix compactly
    class DenseMatrix {
    private:
        // Vectors of elements
        std::vector<double> data_;

        // Matrix dimensions
        unsigned int height_ = 0;
        unsigned int width_ = 0;

    public:
        // Constructor
        DenseMatrix(unsigned int height,
                    unsigned int width,
                    std::vector<double> input_v);

        // Element getter
        [[nodiscard]] double GetElement(unsigned int i, unsigned int j) const;

        // Column getter
        [[nodiscard]] std::vector<double> GetColumn(unsigned int j) const;

        // Row getter
        [[nodiscard]] std::vector<double> GetRow(unsigned int i) const;

        // Height getter
        [[nodiscard]] unsigned int GetHeight() const;

        // Width getter
        [[nodiscard]] unsigned int GetWidth() const;

        // Data vector getter
        [[nodiscard]] const std::vector<double> &GetValues() const;

        // Element setter
        void SetElement(unsigned int i, unsigned int j, double new_element);

        // Multiplication operator* for matrices
        DenseMatrix operator*(const DenseMatrix &input_m) const;

        // Multiplication operator* for matrix & vector
        std::vector<double> operator*(const std::vector<double> &input_v) const;

        // Multiplication operator* for matrix & scalar
        DenseMatrix operator*(double s) const;

        // Division operator/ for matrix & scalar
        DenseMatrix operator/(double s) const;

        // Addition operator+ for matrices
        DenseMatrix operator+(const DenseMatrix &input_m) const;

        // Subtraction operator- for matrices
        DenseMatrix operator-(const DenseMatrix &input_m) const;

        // Comparison operator== for matrices
        bool operator==(const DenseMatrix &input_m) const;
    };

    // Square matrix with ones on the main diagonal and zeros elsewhere
    DenseMatrix IdentityMatrix(unsigned int order);
}

#endif //SOLE_DENSE_MATRIX_H