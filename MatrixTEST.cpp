#include "gtest/gtest.h"
#include "../MatrixFactory.h"
#include "../MatrixTemplate.h"
#include <iostream>
#include <random>
TEST(MatrixTemplate, testConstructor) {
    MatrixTemplate<int> testMatrix(3, 3);
    testMatrix.print();
    bool anwser=true;
    for (int i = 0; i < testMatrix.getRows(); i++) {
        for (int j = 0; j < testMatrix.getColumns(); j++) {
            if (testMatrix.selection(i,j) != 0)
                anwser = false;
            else
                anwser=true;
        }
    }
    ASSERT_EQ(anwser, true);
}

TEST(MatrixTemplate, testRecMatrix) {
    MatrixFactory *factory_3 = new MatrixFactory();
    MatrixTemplate<int> *recMatrix = factory_3->creatematrix(2, 3);
    bool anwser = false;

    if (recMatrix->getColumns() != recMatrix->getRows() && recMatrix->getRows() > 1 && recMatrix->getColumns() > 1)
        anwser = true;
    ASSERT_EQ(anwser, true);
}

TEST(MatrixTemplate, testSquareMatrix) {
    MatrixFactory *factory_4 = new MatrixFactory();
    MatrixTemplate<int> *squareMatrix = factory_4->creatematrix(2, 2);
    bool anwser = false;
    if (squareMatrix->getColumns() == squareMatrix->getRows() && squareMatrix->getRows() > 1 && squareMatrix->getColumns() > 1)
        anwser = true;
    ASSERT_EQ(anwser, true);
}

TEST(MatrixTemplate, testSelectRow) {
    MatrixTemplate<int> testMatrix(2, 2);
    ASSERT_THROW(testMatrix.selection(3, 0), std::out_of_range);
    EXPECT_THROW(testMatrix.selection(0, 3), std::out_of_range);
}

TEST(MatrixTemplate, testTranspose) {
    MatrixTemplate<int> firstMatrix(2, 2);
    srand((unsigned) time(nullptr));
    for (int i = 0; i < firstMatrix.getRows(); i++) {
        for (int j = 0; j < firstMatrix.getColumns(); j++) {
            firstMatrix.insert((rand() % 10) + 1,i,j);
        }
    }
    MatrixTemplate<int> transposeMatrix = firstMatrix.trasposta();
    ASSERT_EQ(firstMatrix.selection(0,0), transposeMatrix.selection(0,0));
    ASSERT_EQ(firstMatrix.selection(0,1), transposeMatrix.selection(1,0));
    ASSERT_EQ(firstMatrix.selection(1,0), transposeMatrix.selection(0,1));
    ASSERT_EQ(firstMatrix.selection(1,1), transposeMatrix.selection(1,1));
}



