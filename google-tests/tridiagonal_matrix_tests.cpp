#include "gtest/gtest.h"
#include "../source/tridiagonal_matrix/tridiagonal_matrix.h"
#include "../source/tridiagonal_matrix/tridiagonal_matrix_solver.h"

using namespace trd;

TEST(TridiagonalTest, SolverTestM5) {
    TridiagonalMatrix A {5,
                         {14.0, 2.0, 5.0, 7.0},
                         {5.0, 6.0, 3.0, 2.0, 7.0},
                         {1.0, 3.0, 2.0, 1.0}};
    std::vector<double> f {2.0, 8.0, 43.0, 11.0, 2.0};

    auto x = SolveTridiagonalMatrix(5, A, f);

    EXPECT_FLOAT_EQ(x[0], - 173.0 / 994.0);
    EXPECT_FLOAT_EQ(x[1], 2853.0 / 994.0);
    EXPECT_FLOAT_EQ(x[2], - 1124.0 / 497.0);
    EXPECT_FLOAT_EQ(x[3], 10945.0 / 497.0);
    EXPECT_FLOAT_EQ(x[4], - 10803.0 / 497.0);
}

TEST(TridiagonalTest, SolverTestM7) {
    TridiagonalMatrix A {7,
                         {3.0, 54.0, 2.0, 2.0, 1.0, 9.0},
                         {4.0, 5.0, 1.0, 8.0, 23.0, 1.0, 5.0},
                         {2.0, 3.0, 8.0, 12.0, 4.0, 14.0}};
    std::vector<double> f {1.0, 2.0, 19.0, 8.0, 4.0, 5.0, 3.0};

    auto x = SolveTridiagonalMatrix(7, A, f);

    EXPECT_FLOAT_EQ(x[0], 112439.0 / 812722.0);
    EXPECT_FLOAT_EQ(x[1], 181483.0 / 812722.0);
    EXPECT_FLOAT_EQ(x[2], 63452.0 / 406361.0);
    EXPECT_FLOAT_EQ(x[3], 1378683.0 / 1625444.0);
    EXPECT_FLOAT_EQ(x[4], 61103.0 / 812722.0);
    EXPECT_FLOAT_EQ(x[5], 116709.0 / 812722.0);
    EXPECT_FLOAT_EQ(x[6], 277557 / 812722.0);
}

TEST(TridiagonalTest, SolverTestM9) {
    TridiagonalMatrix A {9,
                         {3.0, 54.0, 2.0, 2.0, 1.0, 9.0, 17.0, 8.0},
                         {4.0, 5.0, 1.0, 8.0, 23.0, 1.0, 5.0, 4.0, 5.0},
                         {2.0, 3.0, 8.0, 12.0, 4.0, 14.0, 3.0, 7.0}};
    std::vector<double> f {5.0, 3.0, 2.0, 6.0, 4.0, 3.0, 2.0, 1.0, 1.0};

    auto x = SolveTridiagonalMatrix(9, A, f);

    EXPECT_FLOAT_EQ(x[0], 11844481.0 / 9298934.0);
    EXPECT_FLOAT_EQ(x[1], - 441627.0 / 9298934.0);
    EXPECT_FLOAT_EQ(x[2], - 904751.0 / 4649467.0);
    EXPECT_FLOAT_EQ(x[3], 11063807.0 / 18597868.0);
    EXPECT_FLOAT_EQ(x[4], 1263115.0 / 9298934.0);
    EXPECT_FLOAT_EQ(x[5], - 729929.0 / 9298934.0);
    EXPECT_FLOAT_EQ(x[6], 977272.0 / 4649467.0);
    EXPECT_FLOAT_EQ(x[7], 5131503.0 / 9298934.0);
    EXPECT_FLOAT_EQ(x[8], - 3175309.0 / 4649467.0);
}