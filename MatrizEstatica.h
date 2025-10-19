#ifndef MATRIZESTATICA_H
#define MATRIZESTATICA_H

#include "MatrizBase.h"
#include <iostream>
#include <stdexcept>

template <typename T, int M, int N>
class MatrizEstatica : public MatrizBase<T> {
    private:
        T _datos[M][N];

    public:
        MatrizEstatica() : MatrizBase<T>(M, N) {
            for (int i = 0; i < M; ++i) {
                for (int j = 0; j < N; ++j) {
                    _datos[i][j] = T();
                }
            }
        }

        void cargarValores() override {
            std::cout << "Ingrese " << M << "x" << N << " valores:" << std::endl;
            for (int i = 0; i < M; ++i) {
                for (int j = 0; j < N; ++j) {
                    std::cout << "[" << i << "][" << j << "]: ";
                    std::cin >> _datos[i][j];
                }
            }
        }

        MatrizBase<T>* sumar(const MatrizBase<T>& otra) const override {
            if (this->_filas != otra.getFilas() || this->_columnas != otra.getColumnas()) {
                throw std::invalid_argument("Dimensiones incompatibles para suma");
            }

            const MatrizEstatica<T, M, N>* otraEstatica = dynamic_cast<const MatrizEstatica<T, M, N>*>(&otra);
            if (!otraEstatica) {
                throw std::invalid_argument("Tipos de matriz incompatibles");
            }

            MatrizEstatica<T, M, N>* resultado = new MatrizEstatica<T, M, N>();
            for (int i = 0; i < M; ++i) {
                for (int j = 0; j < N; ++j) {
                    resultado->_datos[i][j] = this->_datos[i][j] + otraEstatica->_datos[i][j];
                }
            }
            return resultado;
        }

        void imprimir() const override {
            for (int i = 0; i < M; ++i) {
                std::cout << "| ";
                for (int j = 0; j < N; ++j) {
                    std::cout << _datos[i][j] << " ";
                }
                std::cout << "|" << std::endl;
            }
        }
};

#endif