#ifndef SOLE_TRIDIAGONAL_MATRIX_H
#define SOLE_TRIDIAGONAL_MATRIX_H

#include <iostream>
#include <iomanip>
#include <vector>

// Struct of three doubles
struct Triplet {
    double a;
    double b;
    double c;
};

class TridiagonalMatrix {
private:
    // Vector of elements of main and adjacent diagonals of matrix
    std::vector<Triplet> data_;

public:
    // Constructors
    TridiagonalMatrix() = default;

    TridiagonalMatrix(unsigned int n,
                      std::vector<double>& l_diag,
                      std::vector<double>& m_diag,
                      std::vector<double>& r_diag);

    TridiagonalMatrix(unsigned int n,
                      std::vector<double>&& l_diag,
                      std::vector<double>&& m_diag,
                      std::vector<double>&& r_diag);

    TridiagonalMatrix(std::vector<Triplet>& v);

    TridiagonalMatrix(std::vector<Triplet>&& v);

    // Destructors
    ~TridiagonalMatrix() = default;

    // Custom output operator for TridiagonalMatrix class
    friend std::ostream& operator<<(std::ostream& os, const TridiagonalMatrix& mtx);

    // Getter
    Triplet GetTriplet(unsigned int i) const;
};

#endif //SOLE_TRIDIAGONAL_MATRIX_H