#ifndef SOLE_CSR_MATRIX_H
#define SOLE_CSR_MATRIX_H

#include <vector>

namespace csr {
    // Struct of triplet for DOK realization
    struct Triplet {
        unsigned int i;
        unsigned int j;
        double v;
    };

    // Class allowing to store sparse matrix compactly
    class CSRMatrix {
    private:
        // Vectors of values and indexing of columns and rows
        std::vector<double> val_;
        std::vector<unsigned int> col_;
        std::vector<unsigned int> row_;

        // Zero value for clear logic
        double zero_ = 0;

        // Matrix dimensions
        unsigned int height_ = 0;
        unsigned int width_ = 0;

    public:
        // Constructor
        CSRMatrix(unsigned int height,
                  unsigned int width,
                  const std::vector<Triplet> &DOK);

        // Element getter
        [[nodiscard]] const double &GetElement(unsigned int i, unsigned int j) const;

        // Vectors getters
        [[nodiscard]] const std::vector<double> &GetValues() const;

        [[nodiscard]] const std::vector<unsigned int> &GetColumns() const;

        [[nodiscard]] const std::vector<unsigned int> &GetRows() const;

        // Multiplication operator (*) for matrix & vector
        std::vector<double> operator*(const std::vector<double> &input_v);
    };
}

#endif //SOLE_CSR_MATRIX_H
