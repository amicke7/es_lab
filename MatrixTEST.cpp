#include "gtest/gtest.h"
#include "../MatrixFactory.h"
#include "../MatrixTemplate.h"
#include <iostream>
#include <random>

TEST(MatrixTemplate, testConstructor) {
    MatrixTemplate<int> testMatrix(3, 3);
    srand((unsigned) time(nullptr));
    for (int i = 0; i < testMatrix.getRows(); i++) {
        for (int j = 0; j < testMatrix.getColumns(); j++) {
            testMatrix.insert((rand() % 10) + 1,i,j);
        }
    }
    testMatrix.print();
    bool anwser=true;
    for (int i = 0; i < testMatrix.getRows(); i++) {
        for (int j = 0; j < testMatrix.getColumns(); j++) {
            if (testMatrix.selection(i,j) != 0)
                anwser = false;
            else
                anwser=true;
            ASSERT_EQ(anwser, false);
        }
    }
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

TEST(MatrixTemplate, testSelectFail) {
    MatrixTemplate<int> testMatrix(2, 2);
    ASSERT_THROW(testMatrix.selection(3, 0), std::out_of_range);
    EXPECT_THROW(testMatrix.selection(0, 3), std::out_of_range);
}

TEST(MatrixTemplate, testSelect){
    MatrixTemplate<int> testMatrix(2, 2);
    testMatrix.insert(1,0,0);
    testMatrix.insert(2,0,1);
    testMatrix.insert(3,1,0);
    testMatrix.insert(4,1,1);
    ASSERT_EQ(testMatrix.selection(0,0),1);
    ASSERT_EQ(testMatrix.selection(0,1),2);
    ASSERT_EQ(testMatrix.selection(1,0),3);
    ASSERT_EQ(testMatrix.selection(1,1),4);
}
TEST(MatrixTemplate, testInsertFail) {
    MatrixTemplate<int> testMatrix(2, 2);
    ASSERT_THROW(testMatrix.insert(4,7,9), std::out_of_range);
}

TEST(MatrixTemplate, testInsert){
    MatrixTemplate<int> testMatrix(2, 2);
    testMatrix.insert(1,0,0);
    testMatrix.insert(2,0,1);
    testMatrix.insert(3,1,0);
    testMatrix.insert(4,1,1);
    ASSERT_EQ(testMatrix.selection(0,0),1);
    ASSERT_EQ(testMatrix.selection(0,1),2);
    ASSERT_EQ(testMatrix.selection(1,0),3);
    ASSERT_EQ(testMatrix.selection(1,1),4);
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

TEST(MatrixTemplate, testProduct){
    MatrixTemplate<int>secondMatrix(2,3);
    MatrixTemplate<int>treMatrix(3,2);
    srand((unsigned) time(nullptr));
    for (int i = 0; i < secondMatrix.getRows(); i++) {
        for (int j = 0; j < secondMatrix.getColumns(); j++) {
            secondMatrix.insert((rand() % 10) + 1,i,j);
        }
    }
    srand((unsigned) time(nullptr));
    for (int i = 0; i < treMatrix.getRows(); i++) {
        for (int j = 0; j < treMatrix.getColumns(); j++) {
            treMatrix.insert((rand() % 10) + 1,i,j);
        }
    }
    MatrixTemplate<int> productMatrix = secondMatrix * (treMatrix);
    ASSERT_EQ(productMatrix.selection(0,0), ( secondMatrix.selection(0,0)*treMatrix.selection(0,0) ) + ( secondMatrix.selection(0,1)*treMatrix.selection(1,0) ) + ( secondMatrix.selection(0,2)*treMatrix.selection(2,0) ) );
    ASSERT_EQ(productMatrix.selection(0,1), ( secondMatrix.selection(0,0)*treMatrix.selection(0,1) ) + ( secondMatrix.selection(0,1)*treMatrix.selection(1,1) ) + ( secondMatrix.selection(0,2)*treMatrix.selection(2,1) ) );
    ASSERT_EQ(productMatrix.selection(1,0), ( secondMatrix.selection(1,0)*treMatrix.selection(0,0) ) + ( secondMatrix.selection(1,1)*treMatrix.selection(1,0) ) + ( secondMatrix.selection(1,2)*treMatrix.selection(2,0) ) );
    ASSERT_EQ(productMatrix.selection(1,1), ( secondMatrix.selection(1,0)*treMatrix.selection(0,1) ) + ( secondMatrix.selection(1,1)*treMatrix.selection(1,1) ) + ( secondMatrix.selection(1,2)*treMatrix.selection(2,1) ) );

}

TEST(MatrixTemplate, testProductScalare){
    MatrixTemplate<int>Matrix(2,2);
    srand((unsigned) time(nullptr));
    for (int i = 0; i < Matrix.getRows(); i++) {
        for (int j = 0; j < Matrix.getColumns(); j++) {
            Matrix.insert((rand() % 10) + 1,i,j);
        }
    }
    MatrixTemplate<int> product1Matrix = Matrix * (3);
    ASSERT_EQ(product1Matrix.selection(0,0), Matrix.selection(0,0)*3 );
    ASSERT_EQ(product1Matrix.selection(0,1), Matrix.selection(0,1)*3 );
    ASSERT_EQ(product1Matrix.selection(1,0), Matrix.selection(1,0)*3 );
    ASSERT_EQ(product1Matrix.selection(1,1), Matrix.selection(1,1)*3 );
}

TEST(MatrixTemplate,testProductFail){
    MatrixTemplate<int>Matrix1(2,2);
    MatrixTemplate<int>Matrix2(3,3);
    srand((unsigned) time(nullptr));
    for (int i = 0; i < Matrix1.getRows(); i++) {
        for (int j = 0; j < Matrix1.getColumns(); j++) {
            Matrix1.insert((rand() % 10) + 1,i,j);
        }
    }
    srand((unsigned) time(nullptr));
    for (int i = 0; i < Matrix2.getRows(); i++) {
        for (int j = 0; j < Matrix2.getColumns(); j++) {
            Matrix2.insert((rand() % 10) + 1,i,j);
        }
    }
    ASSERT_THROW(Matrix1 * (Matrix2), std::out_of_range);
}

TEST(MatrixTemplate, testSomma){
    MatrixTemplate<int>secondMatrix(2,2);
    MatrixTemplate<int>treMatrix(2,2);
    srand((unsigned) time(nullptr));
    for (int i = 0; i < secondMatrix.getRows(); i++) {
        for (int j = 0; j < secondMatrix.getColumns(); j++) {
            secondMatrix.insert((rand() % 10) + 1,i,j);
        }
    }
    srand((unsigned) time(nullptr));
    for (int i = 0; i < treMatrix.getRows(); i++) {
        for (int j = 0; j < treMatrix.getColumns(); j++) {
            treMatrix.insert((rand() % 10) + 1,i,j);
        }
    }
    MatrixTemplate<int> sommaMatrix = secondMatrix + (treMatrix);
    ASSERT_EQ(sommaMatrix.selection(0,0), ( secondMatrix.selection(0,0) + treMatrix.selection(0,0) ) );
    ASSERT_EQ(sommaMatrix.selection(0,1), ( secondMatrix.selection(0,1) + treMatrix.selection(0,1) ) );
    ASSERT_EQ(sommaMatrix.selection(1,0), ( secondMatrix.selection(1,0) + treMatrix.selection(1,0) ) );
    ASSERT_EQ(sommaMatrix.selection(1,1), ( secondMatrix.selection(1,1) + treMatrix.selection(1,1) ) );

}

TEST(MatrixTemplate,testSommaFail){
    MatrixTemplate<int>Matrix1(2,2);
    MatrixTemplate<int>Matrix2(3,3);
    srand((unsigned) time(nullptr));
    for (int i = 0; i < Matrix1.getRows(); i++) {
        for (int j = 0; j < Matrix1.getColumns(); j++) {
            Matrix1.insert((rand() % 10) + 1,i,j);
        }
    }
    srand((unsigned) time(nullptr));
    for (int i = 0; i < Matrix2.getRows(); i++) {
        for (int j = 0; j < Matrix2.getColumns(); j++) {
            Matrix2.insert((rand() % 10) + 1,i,j);
        }
    }
    ASSERT_THROW(Matrix1 + (Matrix2), std::out_of_range);
}