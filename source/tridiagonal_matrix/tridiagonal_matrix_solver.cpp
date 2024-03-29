#include "tridiagonal_matrix_solver.h"

namespace trd
{
    // Function to solve SoLE
    std::vector<double> SolveTridiagonalMatrix(size_t n,
                                               const TridiagonalMatrix& A,
                                               const std::vector<double>& f)
    {
        // Creating temporary vectors for coefs p_i, q_i & x_i
        std::vector<double> p(n);
        std::vector<double> q(n);
        std::vector<double> x(n);

        // Calculation of p_0 & q_0
        p[0] = -A.GetTriplet(0).c / A.GetTriplet(0).b;
        q[0] = f[0] / A.GetTriplet(0).b;

        // Calculation of p_j & q_j (j = 1, 2,..., n - 1)
        for (size_t i = 1; i < n; ++i) {
            p[i] = -A.GetTriplet(i - 1).c / (A.GetTriplet(i - 1).a * p[i - 1] + A.GetTriplet(i - 1).b);
            q[i] = (f[i - 1] - A.GetTriplet(i - 1).a * q[i - 1]) /
                   (A.GetTriplet(i - 1).a * p[i - 1] + A.GetTriplet(i - 1).b);
        }

        // Calculation of x_(n - 1)
        x[n - 1] = (f[n - 1] - A.GetTriplet(n - 1).a * q[n - 1]) /
                   (A.GetTriplet(n - 1).a * p[n - 1] + A.GetTriplet(n - 1).b);

        // Calculation of x_j (j = n - 2, n - 3,..., 0)
        for (size_t i = n - 1; i-- != 0;) {
            x[i] = p[i + 1] * x[i + 1] + q[i + 1];
        }

        return x;
    }
}