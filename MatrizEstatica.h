#ifndef MATRIZESTATICA_H
#define MATRIZESTATICA_H

#include "MatrizBase.h"
#include <iostream>
#include <stdexcept>

template <typename T, int M, int N>
class MatrizEstatica : public MatrizBase<T> {
    private:
        T _datos[M][N];
    protected:
        T obtenerCelda(int i, int j) const override {
            if (i < 0 || i >= M || j < 0 || j >= N) 
                throw std::out_of_range("Indices fuera de rango");
            return _datos[i][j];
        }
        
        void establecerCelda(int i, int j, T valor) override {
            if (i < 0 || i >= M || j < 0 || j >= N) 
                throw std::out_of_range("Indices fuera de rango");
            _datos[i][j] = valor;
        }
    public:
        // Constructor de matriz estática
        MatrizEstatica() : MatrizBase<T>(M, N) {
            for (int i = 0; i < M; ++i) {
                for (int j = 0; j < N; ++j) {
                    _datos[i][j] = T();
                }
            }
        }
        // Método para cargar valores en la matriz
        void cargarValores() override {
            std::cout << "Ingrese " << M << "x" << N << " valores:" << std::endl;
            for (int i = 0; i < M; ++i) {
                for (int j = 0; j < N; ++j) {
                    std::cout << "[" << i << "][" << j << "]: ";
                    std::cin >> _datos[i][j];
                }
            }
        }
        // Método para sumar dos matrices
        MatrizBase<T>* sumar(const MatrizBase<T>& otra) const override {
            if (this->_filas != otra.getFilas() || this->_columnas != otra.getColumnas()) {
                throw std::invalid_argument("Dimensiones incompatibles para suma");
            }

            MatrizEstatica<T, M, N>* resultado = new MatrizEstatica<T, M, N>();
            for (int i = 0; i < M; ++i) {
                for (int j = 0; j < N; ++j) {
                    T suma = this->obtenerCelda(i, j) + otra.obtenerCelda(i, j);
                    resultado->establecerCelda(i, j, suma);
                }
            }
            return resultado;
        }
        // Método para imprimir la matriz
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