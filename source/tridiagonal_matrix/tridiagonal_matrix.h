#ifndef SOLE_TRIDIAGONAL_MATRIX_H
#define SOLE_TRIDIAGONAL_MATRIX_H

#include <vector>
#include <stdexcept>


namespace trd
{
    // Struct of triplet for DOK realization
    struct Triplet
    {
        double a;
        double b;
        double c;
    };

    // Class allowing to store square tridiagonal matrix compactly
    class TridiagonalMatrix
    {
    private:
        // Vector of elements of main and adjacent diagonals of matrix
        std::vector<Triplet> data_;

        // Order of original square matrix
        size_t order_;

    public:
        // Constructors
        TridiagonalMatrix(size_t order,
                          const std::vector<double>& l_diag,
                          const std::vector<double>& m_diag,
                          const std::vector<double>& r_diag);

        TridiagonalMatrix(size_t order,
                          const std::vector<Triplet>& input_v);

        // Element getter
        [[nodiscard]] double GetElement(size_t i, size_t j) const;

        // Element getter through () operator
        [[nodiscard]] double operator()(size_t i, size_t j) const;

        // Triplet getter
        [[nodiscard]] const Triplet& GetTriplet(size_t i) const;

        // Order getter
        [[nodiscard]] size_t GetOrder() const;
    };

}

#endif //SOLE_TRIDIAGONAL_MATRIX_H