#include <iostream>
#include "MatrizBase.h"
#include "MatrizEstatica.h"
#include "MatrizDinamica.h"

using namespace std;

int main() {
    cout << "=== SISTEMA DE ALGEBRA LINEAL ===" << endl;
    
    try {
        // Matriz Dinámica con matriz float
        cout << "\n--- MATRIZ DINAMICA FLOAT ---" << endl;
        MatrizBase<float>* matrizA = new MatrizDinamica<float>(2, 3);
        cout << "Matriz A (2x3):" << endl;
        matrizA->cargarValores();
        cout << "Matriz A:" << endl;
        matrizA->imprimir();
        // Matriz Estática con matriz float
        cout << "\n--- MATRIZ ESTATICA FLOAT ---" << endl;
        MatrizBase<float>* matrizB = new MatrizEstatica<float, 2, 3>();
        cout << "Matriz B (2x3):" << endl;
        matrizB->cargarValores();
        cout << "Matriz B:" << endl;
        matrizB->imprimir();
        // Suma
        cout << "\n--- SUMA ---" << endl;
        MatrizBase<float>* resultado = matrizA->sumar(*matrizB);
        cout << "Resultado A + B:" << endl;
        resultado->imprimir();
        // Matriz dinámica con matriz int
        cout << "\n--- MATRIZ DINAMICA INT ---" << endl;
        MatrizBase<int>* matrizC = new MatrizDinamica<int>(2, 2);
        MatrizBase<int>* matrizD = new MatrizEstatica<int, 2, 2>();
        // Carga de valores
        cout << "Matriz C (2x2):" << endl;
        matrizC->cargarValores();
        cout << "Matriz D (2x2):" << endl;  
        matrizD->cargarValores();
        // Impresión de matrices
        MatrizBase<int>* resultadoInt = matrizC->sumar(*matrizD);
        cout << "Resultado C + D:" << endl;
        resultadoInt->imprimir();
        // Limpieza de memoria
        delete matrizA;
        delete matrizB;
        delete resultado;
        delete matrizC;
        delete matrizD;
        delete resultadoInt;
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
        return 1;
    }
    // Fin de ejecución
    cout << "\n=== ADIOS ===" << endl;
    return 0;
}