#include "vector"

#include "gtest/gtest.h"
#include "../source/dense_matrix/dense_matrix.h"

using namespace dns;

TEST(DenseTest, ConstructorTestM3)
{
    DenseMatrix A {3,
                   3,
                   {1, 2, 3, 4, 5, 6, 7, 8, 9}};
    std::vector<double> values {1, 2, 3, 4, 5, 6, 7, 8, 9};

    EXPECT_EQ(A.GetValues(), values);
}

TEST(DenseTest, GetterTestM3)
{
    DenseMatrix A {3,
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

TEST(DenseTest, ColGetterTestM3)
{
    DenseMatrix A {3,
                   3,
                   {1, 2, 3, 4, 5, 6, 7, 8, 9}};
    std::vector<double> a_0 {1, 4, 7};
    std::vector<double> a_1 {2, 5, 8};
    std::vector<double> a_2 {3, 6, 9};

    EXPECT_EQ(A.GetColumn(0), a_0);
    EXPECT_EQ(A.GetColumn(1), a_1);
    EXPECT_EQ(A.GetColumn(2), a_2);
}

TEST(DenseTest, RowGetterTestM3)
{
    DenseMatrix A {3,
                   3,
                   {1, 2, 3, 4, 5, 6, 7, 8, 9}};
    std::vector<double> a_0 {1, 2, 3};
    std::vector<double> a_1 {4, 5, 6};
    std::vector<double> a_2 {7, 8, 9};

    EXPECT_EQ(A.GetRow(0), a_0);
    EXPECT_EQ(A.GetRow(1), a_1);
    EXPECT_EQ(A.GetRow(2), a_2);
}

TEST(DenseTest, HeightGetterTestM3)
{
    DenseMatrix A {3,
                   3,
                   {1, 2, 3, 4, 5, 6, 7, 8, 9}};

    EXPECT_EQ(A.GetHeight(), 3);
}

TEST(DenseTest, WidthGetterTestM3)
{
    DenseMatrix A {3,
                   3,
                   {1, 2, 3, 4, 5, 6, 7, 8, 9}};

    EXPECT_EQ(A.GetHeight(), 3);
}

TEST(DenseTest, ValueGetterTestM3)
{
    DenseMatrix A {3,
                   3,
                   {1, 2, 3, 4, 5, 6, 7, 8, 9}};
    std::vector<double> v {1, 2, 3, 4, 5, 6, 7, 8, 9};

    EXPECT_EQ(A.GetValues(), v);
}

TEST(DenseTest, SetterTestM3)
{
    DenseMatrix A {3,
                   3,
                   {1, 2, 3, 4, 5, 6, 7, 8, 9}};

    A.SetElement(0, 0, 8.9);
    A.SetElement(0, 2, 0.0);

    EXPECT_EQ(A.GetElement(0, 0), 8.9);
    EXPECT_EQ(A.GetElement(0, 1), 2);
    EXPECT_EQ(A.GetElement(0, 2), 0.0);
    EXPECT_EQ(A.GetElement(1, 0), 4);
    EXPECT_EQ(A.GetElement(1, 1), 5);
    EXPECT_EQ(A.GetElement(1, 2), 6);
    EXPECT_EQ(A.GetElement(2, 0), 7);
    EXPECT_EQ(A.GetElement(2, 1), 8);
    EXPECT_EQ(A.GetElement(2, 2), 9);
}

TEST(DenseTest, BreceTestM3)
{
    DenseMatrix A {3,
                   3,
                   {1, 2, 3, 4, 5, 6, 7, 8, 9}};

    A(0, 0) = 8.9;
    A(0, 2) = 0.0;

    EXPECT_EQ(A(0, 0), 8.9);
    EXPECT_EQ(A(0, 1), 2);
    EXPECT_EQ(A(0, 2), 0.0);
    EXPECT_EQ(A(1, 0), 4);
    EXPECT_EQ(A(1, 1), 5);
    EXPECT_EQ(A(1, 2), 6);
    EXPECT_EQ(A(2, 0), 7);
    EXPECT_EQ(A(2, 1), 8);
    EXPECT_EQ(A(2, 2), 9);
}

TEST(DenseTest, onMatrixMultiplicationTestM3xM3)
{
    DenseMatrix A {3,
                   3,
                   {1, 2, 3, 4, 5, 6, 7, 8, 9}};
    DenseMatrix B {3,
                   3,
                   {3, 0, 2, 4, 12, 10, 2, 6, 0}};

    auto C = A * B;

    EXPECT_FLOAT_EQ(C.GetElement(0, 0), 17);
    EXPECT_FLOAT_EQ(C.GetElement(0, 1), 42);
    EXPECT_FLOAT_EQ(C.GetElement(0, 2), 22);
    EXPECT_FLOAT_EQ(C.GetElement(1, 0), 44);
    EXPECT_FLOAT_EQ(C.GetElement(1, 1), 96);
    EXPECT_FLOAT_EQ(C.GetElement(1, 2), 58);
    EXPECT_FLOAT_EQ(C.GetElement(2, 0), 71);
    EXPECT_FLOAT_EQ(C.GetElement(2, 1), 150);
    EXPECT_FLOAT_EQ(C.GetElement(2, 2), 94);
}

TEST(DenseTest, onMatrixMultiplicationTestM3x2xM2x4)
{
    DenseMatrix A {3,
                   2,
                   {1, 2, 3, 4, 5, 6}};
    DenseMatrix B {2,
                   4,
                   {3, 0, 2, 4, 12, 10, 2, 6}};

    auto C = A * B;

    EXPECT_FLOAT_EQ(C.GetElement(0, 0), 27);
    EXPECT_FLOAT_EQ(C.GetElement(0, 1), 20);
    EXPECT_FLOAT_EQ(C.GetElement(0, 2), 6);
    EXPECT_FLOAT_EQ(C.GetElement(0, 3), 16);
    EXPECT_FLOAT_EQ(C.GetElement(1, 0), 57);
    EXPECT_FLOAT_EQ(C.GetElement(1, 1), 40);
    EXPECT_FLOAT_EQ(C.GetElement(1, 2), 14);
    EXPECT_FLOAT_EQ(C.GetElement(1, 3), 36);
    EXPECT_FLOAT_EQ(C.GetElement(2, 0), 87);
    EXPECT_FLOAT_EQ(C.GetElement(2, 1), 60);
    EXPECT_FLOAT_EQ(C.GetElement(2, 2), 22);
    EXPECT_FLOAT_EQ(C.GetElement(2, 3), 56);
}

TEST(DenseTest, onVectorMultiplicationTestM5x3)
{
    DenseMatrix A {5,
                   3,
                   {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15}};
    std::vector<double> v {1, 0, 2};

    auto b = A * v;

    EXPECT_FLOAT_EQ(b[0], 7);
    EXPECT_FLOAT_EQ(b[1], 16);
    EXPECT_FLOAT_EQ(b[2], 25);
    EXPECT_FLOAT_EQ(b[3], 34);
    EXPECT_FLOAT_EQ(b[4], 43);
}

TEST(DenseTest, onScalarMultiplicationTestM3)
{
    DenseMatrix A {3,
                   3,
                   {1, 2, 3, 4, 5, 6, 7, 8, 9}};

    auto B = A * 2;

    EXPECT_FLOAT_EQ(B.GetElement(0, 0), 2);
    EXPECT_FLOAT_EQ(B.GetElement(0, 1), 4);
    EXPECT_FLOAT_EQ(B.GetElement(0, 2), 6);
    EXPECT_FLOAT_EQ(B.GetElement(1, 0), 8);
    EXPECT_FLOAT_EQ(B.GetElement(1, 1), 10);
    EXPECT_FLOAT_EQ(B.GetElement(1, 2), 12);
    EXPECT_FLOAT_EQ(B.GetElement(2, 0), 14);
    EXPECT_FLOAT_EQ(B.GetElement(2, 1), 16);
    EXPECT_FLOAT_EQ(B.GetElement(2, 2), 18);
}

TEST(DenseTest, DivisionTestM3)
{
    DenseMatrix A {3,
                   3,
                   {1, 2, 3, 4, 5, 6, 7, 8, 9}};

    auto B = A / 2;

    EXPECT_FLOAT_EQ(B.GetElement(0, 0), 0.5);
    EXPECT_FLOAT_EQ(B.GetElement(0, 1), 1.0);
    EXPECT_FLOAT_EQ(B.GetElement(0, 2), 1.5);
    EXPECT_FLOAT_EQ(B.GetElement(1, 0), 2.0);
    EXPECT_FLOAT_EQ(B.GetElement(1, 1), 2.5);
    EXPECT_FLOAT_EQ(B.GetElement(1, 2), 3.0);
    EXPECT_FLOAT_EQ(B.GetElement(2, 0), 3.5);
    EXPECT_FLOAT_EQ(B.GetElement(2, 1), 4.0);
    EXPECT_FLOAT_EQ(B.GetElement(2, 2), 4.5);
}

TEST(DenseTest, AdditionTestM3)
{
    DenseMatrix A {3,
                   3,
                   {1, 2, 3, 4, 5, 6, 7, 8, 9}};
    DenseMatrix B {3,
                   3,
                   {2, 3, 4, 5, 6, 7, 8, 9, 10}};

    auto C = A + B;

    EXPECT_FLOAT_EQ(C.GetElement(0, 0), 3);
    EXPECT_FLOAT_EQ(C.GetElement(0, 1), 5);
    EXPECT_FLOAT_EQ(C.GetElement(0, 2), 7);
    EXPECT_FLOAT_EQ(C.GetElement(1, 0), 9);
    EXPECT_FLOAT_EQ(C.GetElement(1, 1), 11);
    EXPECT_FLOAT_EQ(C.GetElement(1, 2), 13);
    EXPECT_FLOAT_EQ(C.GetElement(2, 0), 15);
    EXPECT_FLOAT_EQ(C.GetElement(2, 1), 17);
    EXPECT_FLOAT_EQ(C.GetElement(2, 2), 19);
}

TEST(DenseTest, SubtractionTestM3)
{
    DenseMatrix A {3,
                   3,
                   {1, 2, 3, 4, 5, 6, 7, 8, 9}};
    DenseMatrix B {3,
                   3,
                   {2, 3, 4, 5, 6, 7, 8, 9, 10}};

    auto C = A - B;

    EXPECT_FLOAT_EQ(C.GetElement(0, 0), -1);
    EXPECT_FLOAT_EQ(C.GetElement(0, 1), -1);
    EXPECT_FLOAT_EQ(C.GetElement(0, 2), -1);
    EXPECT_FLOAT_EQ(C.GetElement(1, 0), -1);
    EXPECT_FLOAT_EQ(C.GetElement(1, 1), -1);
    EXPECT_FLOAT_EQ(C.GetElement(1, 2), -1);
    EXPECT_FLOAT_EQ(C.GetElement(2, 0), -1);
    EXPECT_FLOAT_EQ(C.GetElement(2, 1), -1);
    EXPECT_FLOAT_EQ(C.GetElement(2, 2), -1);
}

TEST(DenseTest, ComparisonTestM3)
{
    DenseMatrix A {3,
                   3,
                   {1, 2, 3, 4, 5, 6, 7, 8, 9}};
    DenseMatrix B {3,
                   3,
                   {1, 2, 3, 4, 5, 6, 7, 8, 9}};

    EXPECT_TRUE(A == B);
}

TEST(DenseTest, IdentityMatrixTestM3)
{
    auto A = IdentityMatrix(3);

    EXPECT_EQ(A.GetElement(0, 0), 1);
    EXPECT_EQ(A.GetElement(1, 1), 1);
    EXPECT_EQ(A.GetElement(2, 2), 1);
}