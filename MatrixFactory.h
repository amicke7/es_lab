#include "MatrixTemplate.h"
#include <iostream>

#ifndef ES_LAB_PROGRAMMAZIONE_MATRIXFACTORY_H
#define ES_LAB_PROGRAMMAZIONE_MATRIXFACTORY_H


class MatrixFactory {
public:
    MatrixTemplate<int>* creatematrix(int righe,int colonne);
    MatrixTemplate<float>* creatematrix1(int righe,int colonne);

};



MatrixTemplate<int>* MatrixFactory::creatematrix(int righe,int colonne) {
    MatrixTemplate<int>* matrix1 = new MatrixTemplate<int>(righe, colonne);
    return matrix1;

}

MatrixTemplate<float>* MatrixFactory::creatematrix1(int righe,int colonne) {
    MatrixTemplate<float>* matrix2 = new MatrixTemplate<float>(righe, colonne);
    return matrix2;

}

#endif //ES_LAB_PROGRAMMAZIONE_MATRIXFACTORY_H
