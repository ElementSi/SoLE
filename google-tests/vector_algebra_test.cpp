#include "gtest/gtest.h"
#include "../source/vector_algebra/vector_algebra.h"

TEST(VectorTest, AdditionV3) {
    std::vector<double> v1{1, 2, 3};
    std::vector<double> v2{4, 3, 2};

    auto answer = v1 + v2;

    EXPECT_FLOAT_EQ(answer[0], 5);
    EXPECT_FLOAT_EQ(answer[1], 5);
    EXPECT_FLOAT_EQ(answer[2], 5);
}

TEST(VectorTest, SubtractionV3) {
    std::vector<double> v1{1, 2, 3};
    std::vector<double> v2{4, 3, 2};

    auto answer = v1 - v2;

    EXPECT_FLOAT_EQ(answer[0], -3);
    EXPECT_FLOAT_EQ(answer[1], -1);
    EXPECT_FLOAT_EQ(answer[2], 1);
}

TEST(VectorTest, MultiplicationV3) {
    std::vector<double> v{1, 2, 3};
    double s = 1.5;

    auto answer = s * v;

    EXPECT_FLOAT_EQ(answer[0], 1.5);
    EXPECT_FLOAT_EQ(answer[1], 3);
    EXPECT_FLOAT_EQ(answer[2], 4.5);
}

TEST(VectorTest, DivisionV3) {
    std::vector<double> v{1, 2, 3};
    double s = 2;

    auto answer = v / s;

    EXPECT_FLOAT_EQ(answer[0], 0.5);
    EXPECT_FLOAT_EQ(answer[1], 1);
    EXPECT_FLOAT_EQ(answer[2], 1.5);
}

TEST(VectorTest, ScalarMultiplicationV3) {
    std::vector<double> v1{1, 2, 3};
    std::vector<double> v2{4, 3, 2};

    auto answer = v1 * v2;

    EXPECT_FLOAT_EQ(answer, 16);
}

TEST(VectorTest, AbsoluteValueV3) {
    std::vector<double> v{1, 2, 2};

    auto answer = abs(v);

    EXPECT_FLOAT_EQ(answer, 3);

    v = {1.5, 0, 0};

    answer = abs(v);

    EXPECT_FLOAT_EQ(answer, 1.5);
}

TEST(VectorTest, DyadV3) {
    std::vector<double> v1{1, 2, 3};
    std::vector<double> v2{4, 3, 2};

    auto answer = dyad(v1, v2);

    EXPECT_FLOAT_EQ(answer.GetElement(0, 0), 4);
    EXPECT_FLOAT_EQ(answer.GetElement(0, 1), 3);
    EXPECT_FLOAT_EQ(answer.GetElement(0, 2), 2);
    EXPECT_FLOAT_EQ(answer.GetElement(1, 0), 8);
    EXPECT_FLOAT_EQ(answer.GetElement(1, 1), 6);
    EXPECT_FLOAT_EQ(answer.GetElement(1, 2), 4);
    EXPECT_FLOAT_EQ(answer.GetElement(2, 0), 12);
    EXPECT_FLOAT_EQ(answer.GetElement(2, 1), 9);
    EXPECT_FLOAT_EQ(answer.GetElement(2, 2), 6);
}

TEST(VectorTest, DyadV3x2) {
    std::vector<double> v1{1, 2, 3};
    std::vector<double> v2{4, 5};

    auto answer = dyad(v1, v2);

    EXPECT_FLOAT_EQ(answer.GetElement(0, 0), 4);
    EXPECT_FLOAT_EQ(answer.GetElement(0, 1), 5);
    EXPECT_FLOAT_EQ(answer.GetElement(1, 0), 8);
    EXPECT_FLOAT_EQ(answer.GetElement(1, 1), 10);
    EXPECT_FLOAT_EQ(answer.GetElement(2, 0), 12);
    EXPECT_FLOAT_EQ(answer.GetElement(2, 1), 15);
}