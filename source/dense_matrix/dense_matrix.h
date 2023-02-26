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
        [[nodiscard]] const double &GetElement(unsigned int i, unsigned int j) const;

        // Data vector getter
        [[nodiscard]] const std::vector<double> &GetValues() const;

        // Multiplication operator (*) for matrix & vector
        std::vector<double> operator*(const std::vector<double> &input_v);
    };
}

#endif //SOLE_DENSE_MATRIX_H