
#ifndef MATRIZBASE_H
#define MATRIZBASE_H

template <typename T>
class MatrizBase {
    protected:
        int _filas;
        int _columnas;
    public:
        // Constructor de matriz base
        MatrizBase(int filas, int columnas) : _filas(filas), _columnas(columnas) {}
        // Destructor de matriz base (el ~ indica que es un destructor)
        virtual ~MatrizBase() = default;
        // Getter de filas
        int getFilas() const { 
            return _filas; 
        }
        // Getter de columnas
        int getColumnas() const { 
            return _columnas; 
        }
        // Métodos virtuales
        virtual void cargarValores() = 0;
        virtual MatrizBase<T>* sumar(const MatrizBase<T>& otra) const = 0;
        virtual void imprimir() const = 0;
        // Métodos para suma
        virtual T obtenerCelda(int i, int j) const = 0;
        virtual void establecerCelda(int i, int j, T valor) = 0;
};

#endif