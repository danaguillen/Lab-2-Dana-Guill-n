#include "SolutionB.h"
#include <iostream>

using namespace std;

int findProduct(string* productNames, int productCount, string name) {
    for (int i = 0; i < productCount; i++) {
        if (*(productNames + i) == name) {
            return i;
        }
    }
    return -1;
}

void addProduct(string*& productNames, double*& productPrices, int*& productStock, int& productCount, string name, double price, int qty) {
    int newCount = productCount + 1;
    string* newNames = new string[newCount];
    double* newPrices = new double[newCount];
    int* newStock = new int[newCount];

    for (int i = 0; i < productCount; i++) {
        *(newNames + i) = *(productNames + i);
        *(newPrices + i) = *(productPrices + i);
        *(newStock + i) = *(productStock + i);
    }

    *(newNames + productCount) = name;
    *(newPrices + productCount) = price;
    *(newStock + productCount) = qty;

    delete[] productNames;
    delete[] productPrices;
    delete[] productStock;

    productNames = newNames;
    productPrices = newPrices;
    productStock = newStock;
    productCount = newCount;
}

void removeProduct(string*& productNames, double*& productPrices, int*& productStock, int& productCount, string name) {
    int index = findProduct(productNames, productCount, name);
    if (index == -1) {
        cout << "Producto no encontrado." << endl;
        return;
    }

    if (productCount == 1) {
        delete[] productNames;
        delete[] productPrices;
        delete[] productStock;
        productNames = nullptr;
        productPrices = nullptr;
        productStock = nullptr;
        productCount = 0;
        cout << "Producto eliminado. Inventario vacio." << endl;
        return;
    }

    int newCount = productCount - 1;
    string* newNames = new string[newCount];
    double* newPrices = new double[newCount];
    int* newStock = new int[newCount];

    int j = 0;
    for (int i = 0; i < productCount; i++) {
        if (i != index) {
            *(newNames + j) = *(productNames + i);
            *(newPrices + j) = *(productPrices + i);
            *(newStock + j) = *(productStock + i);
            j++;
        }
    }

    delete[] productNames;
    delete[] productPrices;
    delete[] productStock;

    productNames = newNames;
    productPrices = newPrices;
    productStock = newStock;
    productCount = newCount;

    cout << "Producto eliminado correctamente." << endl;
}

void updateStock(int* productStock, int index, int newQty) {
    if (productStock != nullptr && index >= 0) {
        *(productStock + index) = newQty;
    }
}

void priceMinMax(double* productPrices, int productCount, double* minPrice, double* maxPrice) {
    if (productCount <= 0 || minPrice == nullptr || maxPrice == nullptr) return;

    *minPrice = *productPrices;
    *maxPrice = *productPrices;

    for (int i = 1; i < productCount; i++) {
        if (*(productPrices + i) < *minPrice) *minPrice = *(productPrices + i);
        if (*(productPrices + i) > *maxPrice) *maxPrice = *(productPrices + i);
    }
}

void salesMatrix(int** sales, int productCount) {
    if (sales == nullptr || productCount <= 0) return;

    cout << "\nVentas totales por dia" << endl;
    for (int i = 0; i < 7; i++) {
        int dayTotal = 0;
        for (int j = 0; j < productCount; j++) {
            dayTotal += *(*(sales + i) + j);
        }
        cout << "Dia " << (i + 1) << ": " << dayTotal << " unidades" << endl;
    }

    cout << "\nVentas totales por producto" << endl;
    for (int j = 0; j < productCount; j++) {
        int prodTotal = 0;
        for (int i = 0; i < 7; i++) {
            prodTotal += *(*(sales + i) + j);
        }
        cout << "Producto #" << (j + 1) << ": " << prodTotal << " unidades" << endl;
    }
}

void showInventory(string* productNames, double* productPrices, int* productStock, int productCount) {
    cout << "\nInventario actual" << endl;
    for (int i = 0; i < productCount; i++) {
        cout << *(productNames + i)
            << " | $" << *(productPrices + i)
            << " | Stock: " << *(productStock + i) << endl;
    }
}

void freeAll(string* productNames, double* productPrices, int* productStock) {
    delete[] productNames;
    delete[] productPrices;
    delete[] productStock;
}