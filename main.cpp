#include <iostream>
#include "tridiagonal_matrix/tridiagonal_matrix.h"
#include "tridiagonal_matrix/tridiagonal_matrix_solver.h"

int main() {
    TridiagonalMatrix A {5, {14, 2, 5, 7}, {5, 6, 3, 2, 7}, {1, 3, 2, 1}};
    std::vector<double> f {2, 8, 43, 11, 2};

    std::cout << A;

    std::cout <<std::endl;

    std::cout <<SolveTridiagonalMatrix(5, A, f);

    return 0;
}
