

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

    MatrixTemplate<T> productscalare(int scalare);

    MatrixTemplate<T> trasposta();

    T selection(int m,int n);

    void insert(T v,int x,int y);

    void print();

    MatrixTemplate<T>& operator=(const MatrixTemplate<T>& ugualianza);

    MatrixTemplate<T> operator+(const MatrixTemplate<T>& somma);

    MatrixTemplate<T> operator*(const MatrixTemplate<T>& prodotto);

private:
     int columns;
     int rows;
     T** matrix;
};
template<typename T>
MatrixTemplate<T>& MatrixTemplate<T>::operator=(const MatrixTemplate<T>& ugualianza){
   if(this != &ugualianza){
       delete[] matrix;
       rows=ugualianza.rows;
       columns=ugualianza.columns;
       T** matrix= new T*[columns];
       for (int i=0;i<columns;i=i+1){
           matrix[i] = new T[rows];
       }
       for(int i=0;i<rows;i++){
           for(int j=0;j<columns;j++){
               matrix[i][j]=ugualianza.matrix[i][j];
           }
       }
   }
}
template<typename T>
MatrixTemplate<T> MatrixTemplate<T>::operator+(const MatrixTemplate<T>& somma){
if(this->rows == somma.rows || this->columns == somma.columns){
    MatrixTemplate<T> summatrix(rows,columns);
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            summatrix.matrix[i][j]=matrix[i][j] + somma.matrix[i][j];
        }
    }
    return summatrix;
}
}
template<typename T>
MatrixTemplate<T> MatrixTemplate<T>::operator*(const MatrixTemplate<T>& prodotto) {
    if (this->columns == prodotto.rows) {
        MatrixTemplate<T> prodmatrix(rows, prodmatrix.columns);
        for (int i = 0; i < (rows); i = i + 1) {
            for (int j = 0; j < (prodotto.columns); j = j + 1) {
                prodmatrix.matrix[i][j] = 0;
                for (int l = 0; l < (columns); l = l + 1) {
                    prodmatrix.matrix[i][j] = prodmatrix.matrix[i][j] + matrix[i][l] * prodotto.matrix[l][j];
                }
            }
        }
        return prodmatrix;
    }
}
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
        if(rows==b.columns) {
            MatrixTemplate<T> *d = new MatrixTemplate<T>(rows,columns);
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
}
template <typename T>
MatrixTemplate<T> MatrixTemplate<T>::productscalare(int scalare) {
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
