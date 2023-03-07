#include "../source/iterative_methods/iterative_methods.h"

int main() {
    csr::CSRMatrix A_3{3,
                       3,
                       {
                               {0, 0, 10},
                               {0, 1, 1},
                               {1, 0, 1},
                               {1, 1, 7},
                               {2, 1, 0.1},
                               {2, 2, 1}}};
    std::vector<double> x_0_3{0, 0, 0};
    std::vector<double> b_3{20, 30, 1};
    double target_r_norm = 10e-12;

    std::fstream fs;
    fs.open(R"(..\..\practical-tests\data\data_task3.txt)", std::fstream::out);

    for (double tau = 0.0001; tau < 0.1940; tau += 0.0001) {
        fs << CountSimpleIteration(A_3, b_3, x_0_3, target_r_norm, tau) << std::endl;
    }

    fs.close();

    csr::CSRMatrix A_4{3,
                       3,
                       {
                               {0, 0, 12},
                               {0, 1, 17},
                               {0, 2, 3},
                               {1, 0, 17},
                               {1, 1, 15825},
                               {1, 2, 28},
                               {2, 0, 3},
                               {2, 1, 28},
                               {2, 2, 238}}};
    std::vector<double> x_0_4{1, 1, 1};
    std::vector<double> b_4{1, 2, 3};
    unsigned int iterations_number = 50000;

    RecordSimpleIteration(A_4, b_4, x_0_4, iterations_number, 0.000126,
                          R"(..\..\practical-tests\data\data_task4_Simple.txt)");
    RecordJacoby(A_4, b_4, x_0_4, iterations_number,
                 R"(..\..\practical-tests\data\data_task4_Jacoby.txt)");
    RecordGaussSeidel(A_4, b_4, x_0_4, iterations_number,
                      R"(..\..\practical-tests\data\data_task4_Gauss-Seidel.txt)");
}
