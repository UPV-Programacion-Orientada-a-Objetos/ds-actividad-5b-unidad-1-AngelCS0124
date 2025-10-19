#ifndef MATRIZDINAMICA_H
#define MATRIZDINAMICA_H

#include "MatrizBase.h"
#include <iostream>
#include <stdexcept>

template <typename T, int M, int N>
class MatrizDinamica : public MatrizBase<T> {
    private:
        T** _datos;
    public:
        MatrizDinamica() : MatrizBase<T>(M, N) {
            _datos = new T*[M];
            for(int i = 0; i < M; i++) {
                _datos[i] = new T[N];
                for(int j = 0; j < N; j++) {
                    _datos[i][j] = T();
                }
            }
        }

        ~MatrizDinamica() {
            for(int i = 0; i < M; i++) {
                delete[] _datos[i];
            }
            delete[] _datos;
        }
};

#endif