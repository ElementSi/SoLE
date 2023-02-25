#include "gtest/gtest.h"
#include "../source/dense_matrix/dense_matrix.h"

using namespace dns;

TEST(DenseTest, ConstructorTestM3) {
    DenseMatrix A{3,
                  3,
                  {1, 2, 3, 4, 5, 6, 7, 8, 9}};
    std::vector<double> values{1, 2, 3, 4, 5, 6, 7, 8, 9};

    EXPECT_EQ(A.GetValues(), values);
}

TEST(DenseTest, GetterTestM3) {
    DenseMatrix A{3,
                  3,
                  {1, 2, 3, 4, 5, 6, 7, 8, 9}};

    EXPECT_EQ(A.GetElement(0, 0), 1);
    EXPECT_EQ(A.GetElement(0, 1), 2);
    EXPECT_EQ(A.GetElement(0, 2), 3);
    EXPECT_EQ(A.GetElement(1, 0), 4);
    EXPECT_EQ(A.GetElement(1, 1), 5);
    EXPECT_EQ(A.GetElement(1, 2), 6);
    EXPECT_EQ(A.GetElement(2, 0), 7);
    EXPECT_EQ(A.GetElement(2, 1), 8);
    EXPECT_EQ(A.GetElement(2, 2), 9);
}

TEST(DenseTest, MultiplicationTestM3) {
    DenseMatrix A{3,
                  3,
                  {1, 2, 3, 4, 5, 6, 7, 8, 9}};
    std::vector<double> v{1, 0, 2};

    auto b = A * v;

    EXPECT_FLOAT_EQ(b[0], 7);
    EXPECT_FLOAT_EQ(b[1], 16);
    EXPECT_FLOAT_EQ(b[2], 25);
}

TEST(DenseTest, MultiplicationTestM5x3) {
    DenseMatrix A{5,
                  3,
                  {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15}};
    std::vector<double> v{1, 0, 2};

    auto b = A * v;

    EXPECT_FLOAT_EQ(b[0], 7);
    EXPECT_FLOAT_EQ(b[1], 16);
    EXPECT_FLOAT_EQ(b[2], 25);
    EXPECT_FLOAT_EQ(b[3], 34);
    EXPECT_FLOAT_EQ(b[4], 43);
}