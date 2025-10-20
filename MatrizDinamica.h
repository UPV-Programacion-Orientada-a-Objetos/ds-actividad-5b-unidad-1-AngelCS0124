#ifndef MATRIZDINAMICA_H
#define MATRIZDINAMICA_H

#include "MatrizBase.h"
#include <iostream>
#include <stdexcept>

template <typename T>
class MatrizDinamica : public MatrizBase<T> {
private:
    T** _datos;
public:
    // Constructor de matriz dinámica
    MatrizDinamica(int filas, int columnas) : MatrizBase<T>(filas, columnas) {
        _datos = new T*[filas];
        for(int i = 0; i < filas; i++) {
            _datos[i] = new T[columnas];
            for(int j = 0; j < columnas; j++) {
                _datos[i][j] = T();
            }
        }
    }
    // Constructor de copia
    MatrizDinamica(const MatrizDinamica& otra) : MatrizBase<T>(otra._filas, otra._columnas) {
        _datos = new T*[this->_filas];
        for(int i = 0; i < this->_filas; i++) {
            _datos[i] = new T[this->_columnas];
            for(int j = 0; j < this->_columnas; j++) {
                _datos[i][j] = otra._datos[i][j];
            }
        }
    }
    // Operador de asignación
    MatrizDinamica& operator=(const MatrizDinamica& otra) {
        if (this != &otra) {
            for(int i = 0; i < this->_filas; i++) {
                delete[] _datos[i];
            }
            delete[] _datos;

            this->_filas = otra._filas;
            this->_columnas = otra._columnas;

            _datos = new T*[this->_filas];
            for(int i = 0; i < this->_filas; i++) {
                _datos[i] = new T[this->_columnas];
                for(int j = 0; j < this->_columnas; j++) {
                    _datos[i][j] = otra._datos[i][j];
                }
            }
        }
        return *this;
    }
    // Destructor de matriz dinámica
    ~MatrizDinamica() {
        for(int i = 0; i < this->_filas; i++) {
            delete[] _datos[i];
        }
        delete[] _datos;
    }
    // Método para cargar valores en la matriz
    void cargarValores() override {
        std::cout << "Ingrese " << this->_filas << "x" << this->_columnas << " valores:" << std::endl;
        for(int i = 0; i < this->_filas; i++) {
            for(int j = 0; j < this->_columnas; j++) {
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

        const MatrizDinamica<T>* otraDinamica = dynamic_cast<const MatrizDinamica<T>*>(&otra);
        if (!otraDinamica) {
            throw std::invalid_argument("Tipos de matriz incompatibles");
        }

        MatrizDinamica<T>* resultado = new MatrizDinamica<T>(this->_filas, this->_columnas);
        for(int i = 0; i < this->_filas; i++) {
            for(int j = 0; j < this->_columnas; j++) {
                resultado->_datos[i][j] = this->_datos[i][j] + otraDinamica->_datos[i][j];
            }
        }
        return resultado;
    }
    // Método para imprimir la matriz
    void imprimir() const override {
        for(int i = 0; i < this->_filas; i++) {
            std::cout << "| ";
            for(int j = 0; j < this->_columnas; j++) {
                std::cout << _datos[i][j] << " ";
            }
            std::cout << "|" << std::endl;
        }
    }
};

#endif