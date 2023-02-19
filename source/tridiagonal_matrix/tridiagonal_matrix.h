#ifndef SOLE_TRIDIAGONAL_MATRIX_H
#define SOLE_TRIDIAGONAL_MATRIX_H

#include <vector>

namespace trd {
    // Struct of triplet for DOK realization
    struct Triplet {
        double a;
        double b;
        double c;
    };

    // Class allowing to store square tridiagonal matrix compactly
    class TridiagonalMatrix {
    private:
        // Vector of elements of main and adjacent diagonals of matrix
        std::vector<Triplet> data_;

        // Order of original square matrix
        unsigned int order_ = 0;

    public:
        // Constructors
        TridiagonalMatrix() = default;

        TridiagonalMatrix(unsigned int,
                          const std::vector<double>&,
                          const std::vector<double>&,
                          const std::vector<double>&);

        TridiagonalMatrix(unsigned int,
                          std::vector<Triplet>&);

        // Destructors
        ~TridiagonalMatrix() = default;

        // Triplet getter
        [[nodiscard]] const Triplet& GetTriplet(unsigned int) const;

        // Order getter
        [[nodiscard]] unsigned int GetOrder() const;
    };

}

#endif //SOLE_TRIDIAGONAL_MATRIX_H