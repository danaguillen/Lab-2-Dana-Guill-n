#include <iostream>
#include <string>
#include "SolutionA.h"
#include "SolutionB.h"

using namespace std;

int main() {
    string* productNames = nullptr;
    double* productPrices = nullptr;
    int* productStock = nullptr;
    int productCount = 0;

    int option = 0;

    do {
        cout << "\nGestor de Inventario" << endl;
        cout << "1. Agregar producto" << endl;
        cout << "2. Buscar producto" << endl;
        cout << "3. Eliminar producto" << endl;
        cout << "4. Actualizar stock" << endl;
        cout << "5. Ver precio minimo y maximo" << endl;
        cout << "6. Matriz de ventas" << endl;
        cout << "7. Mostrar inventario" << endl;
        cout << "8. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> option;

        if (option == 1) {
            string name;
            double price;
            int qty;

            cout << "Nombre del producto: ";
            cin >> name;
            cout << "Precio del producto: ";
            cin >> price;
            cout << "Cantidad de stock: ";
            cin >> qty;

            addProduct(productNames, productPrices, productStock, productCount, name, price, qty);
            cout << "Producto registrado con exito." << endl;
        }
        else if (option == 2) {
            if (productCount == 0) {
                cout << "El inventario esta vacio." << endl;
            }
            else {
                string name;
                cout << "Nombre del producto a buscar: ";
                cin >> name;

                int idx = findProduct(productNames, productCount, name);
                if (idx != -1) {
                    cout << "Encontrado en indice [" << idx << "]"
                        << " | Precio: $" << *(productPrices + idx)
                        << " | Stock: " << *(productStock + idx) << endl;
                }
                else {
                    cout << "Producto no encontrado." << endl;
                }
            }
        }
        else if (option == 3) {
            if (productCount == 0) {
                cout << "El inventario esta vacio." << endl;
            }
            else {
                string name;
                cout << "Nombre del producto a eliminar: ";
                cin >> name;
                removeProduct(productNames, productPrices, productStock, productCount, name);
            }
        }
        else if (option == 4) {
            if (productCount == 0) {
                cout << "El inventario esta vacio." << endl;
            }
            else {
                string name;
                cout << "Nombre del producto a actualizar: ";
                cin >> name;

                int idx = findProduct(productNames, productCount, name);
                if (idx != -1) {
                    int newQty;
                    cout << "Nuevo stock: ";
                    cin >> newQty;
                    updateStock(productStock, idx, newQty);
                    cout << "Stock actualizado correctamente." << endl;
                }
                else {
                    cout << "Producto no encontrado." << endl;
                }
            }
        }
        else if (option == 5) {
            if (productCount == 0) {
                cout << "El inventario esta vacio." << endl;
            }
            else {
                double minP = 0.0, maxP = 0.0;
                priceMinMax(productPrices, productCount, &minP, &maxP);
                cout << "Precio Minimo: $" << minP << " | Precio Maximo: $" << maxP << endl;
            }
        }
        else if (option == 6) {
            if (productCount == 0) {
                cout << "Registre productos primero para generar la matriz de ventas." << endl;
            }
            else {
                int** sales = new int* [7];
                for (int i = 0; i < 7; i++) {
                    *(sales + i) = new int[productCount];
                    for (int j = 0; j < productCount; j++) {
                        *(*(sales + i) + j) = (i + 1) * 2;
                    }
                }

                salesMatrix(sales, productCount);

                for (int i = 0; i < 7; i++) {
                    delete[] * (sales + i);
                }
                delete[] sales;
            }
        }
        else if (option == 7) {
            if (productCount == 0) {
                cout << "El inventario esta vacio." << endl;
            }
            else {
                showInventory(productNames, productPrices, productStock, productCount);
            }
        }

    } while (option != 8);

    freeAll(productNames, productPrices, productStock);
    cout << "Memoria liberada correctamente. Programa finalizado." << endl;
    return 0;
}