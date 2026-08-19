#include "SolutionB.h"
#include <iostream>

void agregarProducto(std::string*& productos, int*& stock, int& tam, const std::string& nuevoProd, int nuevoStock) {
    int nuevoTam = tam + 1;

    std::string* tempProductos = new std::string[nuevoTam];
    int* tempStock = new int[nuevoTam];

    for (int i = 0; i < tam; ++i) {
        *(tempProductos + i) = *(productos + i);
        *(tempStock + i) = *(stock + i);
    }

    *(tempProductos + tam) = nuevoProd;
    *(tempStock + tam) = nuevoStock;

    delete[] productos;
    delete[] stock;

    productos = tempProductos;
    stock = tempStock;
    tam = nuevoTam;
}

int buscarProducto(const std::string* productos, int tam, const std::string& nombre) {
    for (int i = 0; i < tam; ++i) {
        if (*(productos + i) == nombre) {
            return i;
        }
    }
    return -1;
}

int** crearMatrizVentas(int filas, int columnas) {
    int** ventas = new int* [filas];
    for (int i = 0; i < filas; ++i) {
        ventas[i] = new int[columnas]();
    }
    return ventas;
}

void liberarMatrizVentas(int** ventas, int filas) {
    for (int i = 0; i < filas; ++i) {
        delete[] ventas[i];
    }
    delete[] ventas;
}

void mostrarInventario(const std::string* productos, const int* stock, int tam) {
    std::cout << "\nINVENTARIO ACTUAL" << std::endl;
    for (int i = 0; i < tam; ++i) {
        std::cout << i + 1 << ". " << *(productos + i) << " | Stock: " << *(stock + i) << std::endl;
    }
}