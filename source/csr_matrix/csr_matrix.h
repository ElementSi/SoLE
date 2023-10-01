#ifndef SOLE_CSR_MATRIX_H
#define SOLE_CSR_MATRIX_H

#include <vector>

namespace csr
{
    // Struct of triplet for DOK realization
    struct Triplet
    {
        size_t i;
        size_t j;
        double v;
    };

    // Class allowing to store sparse matrix compactly
    class CSRMatrix
    {
    private:
        // Vectors of values and indexing of columns and rows
        std::vector<double> val_;
        std::vector<size_t> col_;
        std::vector<size_t> row_;

        // Matrix dimensions
        size_t height_ = 0;
        size_t width_ = 0;

    public:
        // Constructor
        CSRMatrix(size_t height,
                  size_t width,
                  const std::vector<Triplet>& DOK);

        // Element getter
        [[nodiscard]] double GetElement(size_t i, size_t j) const;

        // Height getter
        [[nodiscard]] size_t GetHeight() const;

        // Width getter
        [[nodiscard]] size_t GetWidth() const;

        // Vectors getters
        [[nodiscard]] const std::vector<double>& GetValues() const;

        [[nodiscard]] const std::vector<size_t>& GetColumns() const;

        [[nodiscard]] const std::vector<size_t>& GetRows() const;

        // Multiplication operator (*) for matrix & vector
        std::vector<double> operator*(const std::vector<double>& input_v) const;
    };
}

#endif //SOLE_CSR_MATRIX_H
