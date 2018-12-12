

#ifndef ES_LAB_PROGRAMMAZIONE_MATRIXTEMPLATE_H
#define ES_LAB_PROGRAMMAZIONE_MATRIXTEMPLATE_H

#include <iostream>
#include<stdexcept>

template<class T> class MatrixTemplate {
public:
    MatrixTemplate(int r,int c):rows(r),columns(c){
        T** matrix= new T*[columns];
        for (int i=0;i<rows;i=i+1){
            matrix[i] = new T[columns];
        }
        this->matrix=matrix;
    }

    virtual ~MatrixTemplate();

    int getColumns() const;

    int getRows() const;

    MatrixTemplate<T> product(MatrixTemplate<T>& b);

    MatrixTemplate<T> somma(MatrixTemplate<T>& a);

    MatrixTemplate<T> productscalare(T scalare);

    MatrixTemplate<T> sommascalare(T scalare);

    MatrixTemplate<T> trasposta();

    T selection(int m,int n);

    void insert(T v,int x,int y);

    void print();


private:
     int columns;
     int rows;
     T** matrix;
};

template<typename T>
void MatrixTemplate<T>::print(){
    for(int i=0;i<(rows);i++) {
        for (int j = 0; j < (columns); j++) {
            std::cout << "" << matrix[i][j];
        }
        std::cout<<std::endl;
    }
}

template<typename T>
MatrixTemplate<T>::~MatrixTemplate() {
    for (int i=0;i<rows;i=i+1){
        delete[] matrix[i];
    }
}

template <typename T>
MatrixTemplate<T> MatrixTemplate<T>::product(MatrixTemplate<T>& b) {
    if (columns != b.rows) {
        throw std::out_of_range("disaccordo tra le due matrici");
    }
    else {
        MatrixTemplate<T> *d = new MatrixTemplate<T>(rows,rows);
        for (int i = 0; i < (rows); i = i + 1) {
            for (int j = 0; j < (b.columns); j = j + 1) {
                d->matrix[i][j] = 0;
                for (int l = 0; l < (columns); l = l + 1) {
                    d->matrix[i][j] = d->matrix[i][j] + matrix[i][l] * b.matrix[l][j];
                }
                std::cout << "" << d->matrix[i][j];
            }
            std::cout<<std::endl;
        }
        return (*d);
    }
}

template <typename T>
MatrixTemplate<T> MatrixTemplate<T>::productscalare(T scalare) {
    MatrixTemplate<T> *d = new MatrixTemplate<T>(rows,columns);
    for (int i = 0; i < (rows); i = i + 1) {
        for (int j = 0; j < (columns); j = j + 1) {
            d->matrix[i][j] = 1;
            d->matrix[i][j] = d->matrix[i][j] *( matrix[i][j] * scalare );
            std::cout << "" << d->matrix[i][j];
        }
        std::cout<<std::endl;
    }
    return (*d);
}

template <typename T>
MatrixTemplate<T> MatrixTemplate<T>::somma(MatrixTemplate<T>& a) {
    if (columns != a.columns && rows!=a.rows) {
        throw std::out_of_range("disaccordo tra le due matrici");
    }
    else {
        MatrixTemplate<T> *d = new MatrixTemplate<T>(rows, columns);
        for (int i = 0; i < (rows); i = i + 1) {
            for (int j = 0; j < (columns); j = j + 1) {
                d->matrix[i][j] = 0;
                d->matrix[i][j] = d->matrix[i][j] + ( matrix[i][j] + a.matrix[i][j] );
                std::cout << "" << d->matrix[i][j];
            }
            std::cout << std::endl;
        }
        return (*d);
    }
}

template <typename T>
MatrixTemplate<T> MatrixTemplate<T>::sommascalare(T scalare) {
    MatrixTemplate<T> *d = new MatrixTemplate<T>(rows,columns);
    for (int i = 0; i < (rows); i = i + 1) {
        for (int j = 0; j < (columns); j = j + 1) {
            d->matrix[i][j] = 0;
            d->matrix[i][j] = d->matrix[i][j] + ( matrix[i][j] + scalare );
            std::cout << "" << d->matrix[i][j];
        }
        std::cout<<std::endl;
    }
    return (*d);
}


template <typename T>
MatrixTemplate<T> MatrixTemplate<T>::trasposta() {
    MatrixTemplate<T>* f=new MatrixTemplate<T>(columns,rows);
    for (int i = 0; i<(columns);i++) {
        for (int j = 0; j<(rows);j++) {
            f->matrix[i][j] = matrix[j][i];
            std::cout<<""<<f->matrix[i][j];
        }
        std::cout<<std::endl;
    }return (*f);
}

template <typename T>
T MatrixTemplate<T>::selection(int m,int n){
    if(m>=(rows)){
        throw std::out_of_range( "riga oltre dimensione");

    }
    if(n>=(columns)){
        throw std::out_of_range( "colonna oltre dimensione");
    }
    std::cout<<matrix[m][n]<<std::endl;
    return matrix[m][n];
}

template <typename T>
void MatrixTemplate<T>::insert(T v,int x,int y){

    matrix[x][y]=v;
}

template <typename T>
int MatrixTemplate<T>::getColumns() const {
    return columns;
}

template <typename T>
int MatrixTemplate<T>::getRows() const {
    return rows;
}




#endif //ES_LAB_PROGRAMMAZIONE_MATRIXTEMPLATE_H
