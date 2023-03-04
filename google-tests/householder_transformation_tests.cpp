#include <cmath>
#include <random>

#include "gtest/gtest.h"
#include "../source/householder_transformation/householder_transformation.h"

TEST(HouseholderTest, TestM2) {
    unsigned int m = 2;
    unsigned int n = 2;
    dns::DenseMatrix A{m,
                       n,
                       {1.0, 4.0,
                        3.0, 2.0}};
    dns::DenseMatrix Q{m,
                       m,
                       {-1 / sqrt(10), 3 / sqrt(10),
                        -3 / sqrt(10), -1 / sqrt(10)}};
    dns::DenseMatrix R{m,
                       n,
                       {-sqrt(10), -sqrt(10),
                        0, sqrt(10)}};

    auto QR_pair = HouseholderTransform(A);
    auto QR = QR_pair.first * QR_pair.second;

    for (unsigned int i = 0; i < m; i++) {
        for (unsigned int j = 0; j < m; j++)
            EXPECT_FLOAT_EQ(Q.GetElement(i, j), QR_pair.first.GetElement(i, j));
    }

    for (unsigned int i = 0; i < m; i++) {
        for (unsigned int j = 0; j < n; j++)
            EXPECT_FLOAT_EQ(R.GetElement(i, j), QR_pair.second.GetElement(i, j));
    }

    for (unsigned int i = 0; i < m; i++) {
        for (unsigned int j = 0; j < n; j++)
            EXPECT_FLOAT_EQ(A.GetElement(i, j), QR.GetElement(i, j));
    }
}

TEST(HouseholderTest, TestM3) {
    unsigned int m = 3;
    unsigned int n = 3;
    dns::DenseMatrix A{m,
                       n,
                       {12.0, -52.0, 4.0,
                        6.0, 167.0, -68.0,
                        -4.0, 24.0, -41.0}};


    auto QR_pair = HouseholderTransform(A);
    auto QR = QR_pair.first * QR_pair.second;

    // Orthogonality test for Q matrix
    // Criterion: the sum of the squares of all the elements of any row is equal to 1
    double sum;
    for (unsigned int i = 0; i < m; i++) {
        sum = 0;
        for (unsigned int j = 0; j < m; j++)
            sum += pow(QR_pair.first.GetElement(i, j), 2);

        EXPECT_FLOAT_EQ(sum, 1);
    }

    // Triangularity test for R matrix
    for (unsigned int i = 1; i < m; i++) {
        for (unsigned int j = 0; j < std::min(i, n); j++)
            EXPECT_EQ(QR_pair.second.GetElement(i, j), 0);
    }

    for (unsigned int i = 0; i < m; i++) {
        for (unsigned int j = 0; j < n; j++)
            EXPECT_FLOAT_EQ(A.GetElement(i, j), QR.GetElement(i, j));
    }
}

TEST(HouseholderTest, TestM4x3) {
    unsigned int m = 4;
    unsigned int n = 3;
    dns::DenseMatrix A{m,
                       n,
                       {12.0, -52.0, 4.0,
                        6.0, 167.0, -68.0,
                        -4.0, 24.0, -41.0,
                        2.0, 1.0, 61.0}};


    auto QR_pair = HouseholderTransform(A);
    auto QR = QR_pair.first * QR_pair.second;

    // Orthogonality test for Q matrix
    // Criterion: the sum of the squares of all the elements of any row is equal to 1
    double sum;
    for (unsigned int i = 0; i < m; i++) {
        sum = 0;
        for (unsigned int j = 0; j < m; j++)
            sum += pow(QR_pair.first.GetElement(i, j), 2);

        EXPECT_FLOAT_EQ(sum, 1);
    }

    // Triangularity test for R matrix
    for (unsigned int i = 1; i < m; i++) {
        for (unsigned int j = 0; j < std::min(i, n); j++)
            EXPECT_EQ(QR_pair.second.GetElement(i, j), 0);
    }

    for (unsigned int i = 0; i < m; i++) {
        for (unsigned int j = 0; j < n; j++)
            EXPECT_FLOAT_EQ(A.GetElement(i, j), QR.GetElement(i, j));
    }
}

TEST(HouseholderTest, TestM1000) {
    unsigned int m = 1000;
    unsigned int n = 1000;

    std::vector<double> init_vector;
    init_vector.reserve(m * n);

    double lower_bound = -100;
    double upper_bound = 100;

    std::uniform_real_distribution<double> random_double(lower_bound,
                                                         upper_bound);

    std::default_random_engine engine;

    for (unsigned int k = 0; k < m * n; k++)
        init_vector.push_back(random_double(engine));

    dns::DenseMatrix A{m,
                       n,
                       init_vector};

    auto QR_pair = HouseholderTransform(A);
    auto QR = QR_pair.first * QR_pair.second;

    // Orthogonality test for Q matrix
    // Criterion: the sum of the squares of all the elements of any row is equal to 1
    double sum;
    for (unsigned int i = 0; i < m; i++) {
        sum = 0;
        for (unsigned int j = 0; j < m; j++)
            sum += pow(QR_pair.first.GetElement(i, j), 2);

        EXPECT_FLOAT_EQ(sum, 1);
    }

    // Triangularity test for R matrix
    for (unsigned int i = 1; i < m; i++) {
        for (unsigned int j = 0; j < std::min(i, n); j++)
            EXPECT_EQ(QR_pair.second.GetElement(i, j), 0);
    }

    for (unsigned int i = 0; i < m; i++) {
        for (unsigned int j = 0; j < n; j++)
            EXPECT_FLOAT_EQ(A.GetElement(i, j), QR.GetElement(i, j));
    }
}

