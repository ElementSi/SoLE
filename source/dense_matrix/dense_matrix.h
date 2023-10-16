#ifndef SOLE_DENSE_MATRIX_H
#define SOLE_DENSE_MATRIX_H

#include <vector>

namespace dns
{
    // Class allowing to store sparse matrix compactly
    class DenseMatrix
    {
    private:
        // Vectors of elements
        std::vector<double> data_;

        // Matrix dimensions
        size_t height_ = 0;
        size_t width_ = 0;

    public:
        // Constructor
        DenseMatrix(size_t height,
                    size_t width,
                    std::vector<double> input_v);

        // Element getter
        [[nodiscard]] double GetElement(size_t i, size_t j) const;

        // Element getter through () operator
        double operator()(size_t i, size_t j) const;

        // Column getter
        [[nodiscard]] std::vector<double> GetColumn(size_t j) const;

        // Row getter
        [[nodiscard]] std::vector<double> GetRow(size_t i) const;

        // Height getter
        [[nodiscard]] size_t GetHeight() const;

        // Width getter
        [[nodiscard]] size_t GetWidth() const;

        // Data vector getter
        [[nodiscard]] const std::vector<double>& GetValues() const;

        // Element setter
        void SetElement(size_t i, size_t j, double new_element);

        // Element setter through () operator
        double& operator()(size_t i, size_t j);

        // Multiplication operator* for matrices
        DenseMatrix operator*(const DenseMatrix& input_m) const;

        // Multiplication operator* for matrix & vector
        std::vector<double> operator*(const std::vector<double>& input_v) const;

        // Multiplication operator* for matrix & scalar
        DenseMatrix operator*(double s) const;

        // Division operator/ for matrix & scalar
        DenseMatrix operator/(double s) const;

        // Addition operator+ for matrices
        DenseMatrix operator+(const DenseMatrix& input_m) const;

        // Subtraction operator- for matrices
        DenseMatrix operator-(const DenseMatrix& input_m) const;

        // Comparison operator== for matrices
        bool operator==(const DenseMatrix& input_m) const;
    };

    // Square matrix with ones on the main diagonal and zeros elsewhere
    DenseMatrix IdentityMatrix(size_t order);
}

#endif //SOLE_DENSE_MATRIX_H