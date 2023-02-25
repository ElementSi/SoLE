#include "gtest/gtest.h"
#include "../source/csr_matrix/csr_matrix.h"

using namespace csr;

TEST(CSRTest, ConstructorTestM3x3) {
    CSRMatrix A{3,
                3,
                {
                        {0, 0, 1},
                        {0, 1, 2},
                        {1, 1, 4},
                        {2, 1, 2},
                        {2, 2, 6}}};
    std::vector<double> values{1, 2, 4, 2, 6};
    std::vector<unsigned int> columns{0, 1, 1, 1, 2};
    std::vector<unsigned int> rows{0, 2, 3, 5};

    EXPECT_EQ(A.GetValues(), values);
    EXPECT_EQ(A.GetColumns(), columns);
    EXPECT_EQ(A.GetRows(), rows);
}

TEST(CSRTest, GetterTestM3x3) {
    CSRMatrix A{3,
                3,
                {
                        {0, 0, 1},
                        {0, 1, 2},
                        {1, 1, 4},
                        {2, 1, 2},
                        {2, 2, 6}}};

    EXPECT_EQ(A.GetElement(0, 0), 1);
    EXPECT_EQ(A.GetElement(0, 1), 2);
    EXPECT_EQ(A.GetElement(0, 2), 0);
    EXPECT_EQ(A.GetElement(1, 0), 0);
    EXPECT_EQ(A.GetElement(1, 1), 4);
    EXPECT_EQ(A.GetElement(1, 2), 0);
    EXPECT_EQ(A.GetElement(2, 0), 0);
    EXPECT_EQ(A.GetElement(2, 1), 2);
    EXPECT_EQ(A.GetElement(2, 2), 6);
}

TEST(CSRTest, ZeroRowConstructorTestM3x3) {
    CSRMatrix A{3,
                3,
                {
                        {0, 0, 1},
                        {0, 1, 2},
                        {2, 1, 2},
                        {2, 2, 6}}};
    std::vector<double> values{1, 2, 2, 6};
    std::vector<unsigned int> columns{0, 1, 1, 2};
    std::vector<unsigned int> rows{0, 2, 2, 4};

    EXPECT_EQ(A.GetValues(), values);
    EXPECT_EQ(A.GetColumns(), columns);
    EXPECT_EQ(A.GetRows(), rows);
}

TEST(CSRTest, ZeroRowGetterTestM3x3) {
    CSRMatrix A{3,
                3,
                {
                        {0, 0, 1},
                        {0, 1, 2},
                        {2, 1, 2},
                        {2, 2, 6}}};

    EXPECT_EQ(A.GetElement(0, 0), 1);
    EXPECT_EQ(A.GetElement(0, 1), 2);
    EXPECT_EQ(A.GetElement(0, 2), 0);
    EXPECT_EQ(A.GetElement(1, 0), 0);
    EXPECT_EQ(A.GetElement(1, 1), 0);
    EXPECT_EQ(A.GetElement(1, 2), 0);
    EXPECT_EQ(A.GetElement(2, 0), 0);
    EXPECT_EQ(A.GetElement(2, 1), 2);
    EXPECT_EQ(A.GetElement(2, 2), 6);
}

TEST(CSRTest, ZeroRowConstructorTestM5x3) {
    CSRMatrix A{5,
                3,
                {
                        {0, 0, 1},
                        {0, 1, 2},
                        {1, 1, 4},
                        {3, 1, 2},
                        {3, 2, 6}}};
    std::vector<double> values{1, 2, 4, 2, 6};
    std::vector<unsigned int> columns{0, 1, 1, 1, 2};
    std::vector<unsigned int> rows{0, 2, 3, 3, 5, 5};

    EXPECT_EQ(A.GetValues(), values);
    EXPECT_EQ(A.GetColumns(), columns);
    EXPECT_EQ(A.GetRows(), rows);
}

TEST(CSRTest, ZeroRowGetterTestM5x3) {
    CSRMatrix A{5,
                3,
                {
                        {0, 0, 1},
                        {0, 1, 2},
                        {1, 1, 4},
                        {3, 1, 2},
                        {3, 2, 6}}};

    EXPECT_EQ(A.GetElement(0, 0), 1);
    EXPECT_EQ(A.GetElement(0, 1), 2);
    EXPECT_EQ(A.GetElement(0, 2), 0);
    EXPECT_EQ(A.GetElement(1, 0), 0);
    EXPECT_EQ(A.GetElement(1, 1), 4);
    EXPECT_EQ(A.GetElement(1, 2), 0);
    EXPECT_EQ(A.GetElement(2, 0), 0);
    EXPECT_EQ(A.GetElement(2, 1), 0);
    EXPECT_EQ(A.GetElement(2, 2), 0);
    EXPECT_EQ(A.GetElement(3, 0), 0);
    EXPECT_EQ(A.GetElement(3, 1), 2);
    EXPECT_EQ(A.GetElement(3, 2), 6);
    EXPECT_EQ(A.GetElement(4, 0), 0);
    EXPECT_EQ(A.GetElement(4, 1), 0);
    EXPECT_EQ(A.GetElement(4, 2), 0);
}

TEST(CSRTest, ZeroMatrixConstructorTestM3x3) {
    CSRMatrix A{3,
                3,
                {}};
    std::vector<double> values{};
    std::vector<unsigned int> columns{};
    std::vector<unsigned int> rows{0, 0, 0, 0};

    EXPECT_EQ(A.GetValues(), values);
    EXPECT_EQ(A.GetColumns(), columns);
    EXPECT_EQ(A.GetRows(), rows);
}

TEST(CSRTest, ZeroMatrixGetterTestM3x3) {
    CSRMatrix A{3,
                3,
                {}};

    EXPECT_EQ(A.GetElement(0, 0), 0);
    EXPECT_EQ(A.GetElement(0, 1), 0);
    EXPECT_EQ(A.GetElement(0, 2), 0);
    EXPECT_EQ(A.GetElement(1, 0), 0);
    EXPECT_EQ(A.GetElement(1, 1), 0);
    EXPECT_EQ(A.GetElement(1, 2), 0);
    EXPECT_EQ(A.GetElement(2, 0), 0);
    EXPECT_EQ(A.GetElement(2, 1), 0);
    EXPECT_EQ(A.GetElement(2, 2), 0);
}

TEST(CSRTest, MultiplicationTestM3x3) {
    CSRMatrix A{3,
                3,
                {
                        {0, 0, 1},
                        {0, 1, 2},
                        {1, 1, 4},
                        {2, 1, 2},
                        {2, 2, 6}}};

    std::vector<double> v {1, 0, 2};

    auto b = A * v;

    EXPECT_FLOAT_EQ(b[0], 1);
    EXPECT_FLOAT_EQ(b[1], 0);
    EXPECT_FLOAT_EQ(b[2], 12);
}

TEST(CSRTest, MultiplicationTestM5x3) {
    CSRMatrix A{5,
                3,
                {
                        {0, 0, 1},
                        {0, 1, 2},
                        {1, 1, 4},
                        {2, 1, 2},
                        {2, 2, 6},
                        {3, 0, 7},
                        {3, 1, 8},
                        {3, 2, 9}}};

    std::vector<double> v {1, 0, -2};

    auto b = A * v;

    EXPECT_FLOAT_EQ(b[0], 1);
    EXPECT_FLOAT_EQ(b[1], 0);
    EXPECT_FLOAT_EQ(b[2], -12);
    EXPECT_FLOAT_EQ(b[3], -11);
    EXPECT_FLOAT_EQ(b[4], 0);
}

TEST(CSRTest, ZeroMatrixMultiplicationTestM3x3) {
    CSRMatrix A{3,
                3,
                {}};

    std::vector<double> v {1, 0, 2};

    auto b = A * v;

    EXPECT_FLOAT_EQ(b[0], 0);
    EXPECT_FLOAT_EQ(b[1], 0);
    EXPECT_FLOAT_EQ(b[2], 0);
}