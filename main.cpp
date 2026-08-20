#include <iostream>
#include <string>
#include "SolutionA.h"
#include "SolutionB.h"

using namespace std;

void agregarProducto(string*& productos, int*& stock, int& tam, const string& nuevaProd, int nuevoStock);
int buscarProducto(const string* productos, int tam, const string& nombre);
void mostrarInventario(const string* productos, const int* stock, int tam);

int main() {
    int option = 0;

    int tam = 0;
    string* productos = nullptr;
    int* stock = nullptr;

    do {
        cout << "\nMENU DE OPCIONES" << endl;
        cout << "1. Probar Ejercicio 1 (Arreglo 1D)" << endl;
        cout << "2. Probar Ejercicio 2 (Matriz 2D)" << endl;
        cout << "3. Agregar producto al inventario" << endl;
        cout << "4. Buscar producto" << endl;
        cout << "5. Mostrar inventario" << endl;
        cout << "6. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> option;

        if (option == 1) {
            int size = 5;
            int* arr = new int[size] {2, 8, 4, 10, 6};
            int minVal = 0, maxVal = 0;

            findMinMax(arr, size, &minVal, &maxVal);
            cout << "Minimo: " << minVal << " | Maximo: " << maxVal << endl;

            delete[] arr;
        }
        else if (option == 2) {
            fillAndPrint(3);
        }
        else if (option == 3) {
            string nombre;
            int cantidad;

            cout << "Nombre del producto: ";
            cin >> nombre;
            cout << "Cantidad de stock: ";
            cin >> cantidad;

            agregarProducto(productos, stock, tam, nombre, cantidad);
            cout << "Producto agregado correctamente." << endl;
        }
        else if (option == 4) {
            if (tam == 0) {
                cout << "El inventario esta vacio." << endl;
            }
            else {
                string nombre;
                cout << "Ingrese el nombre a buscar: ";
                cin >> nombre;

                int pos = buscarProducto(productos, tam, nombre);
                if (pos != -1) {
                    cout << "Producto encontrado en el indice " << pos << " con stock de " << *(stock + pos) << endl;
                }
                else {
                    cout << "Producto no encontrado." << endl;
                }
            }
        }
        else if (option == 5) {
            if (tam == 0) {
                cout << "El inventario esta vacio." << endl;
            }
            else {
                mostrarInventario(productos, stock, tam);
            }
        }

    } while (option != 6);

    delete[] productos;
    delete[] stock;

    cout << "Programa finalizado." << endl;
    return 0;
}