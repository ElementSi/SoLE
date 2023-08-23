#ifndef SOLE_TRIDIAGONAL_MATRIX_H
#define SOLE_TRIDIAGONAL_MATRIX_H

#include <vector>

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
        unsigned int order_;

    public:
        // Constructors
        TridiagonalMatrix(unsigned int order,
                          const std::vector<double> &l_diag,
                          const std::vector<double> &m_diag,
                          const std::vector<double> &r_diag);

        TridiagonalMatrix(unsigned int order,
                          const std::vector<Triplet> &input_v);

        // Element getter
        [[nodiscard]] double GetElement(unsigned int i, unsigned int j) const;

        // Triplet getter
        [[nodiscard]] const Triplet &GetTriplet(unsigned int i) const;

        // Order getter
        [[nodiscard]] unsigned int GetOrder() const;
    };

}

#endif //SOLE_TRIDIAGONAL_MATRIX_H