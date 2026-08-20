#ifndef SOLUTIONB_H
#define SOLUTIONB_H

#include <string>

int findProduct(std::string* productNames, int productCount, std::string name);
void addProduct(std::string*& productNames, double*& productPrices, int*& productStock, int& productCount, std::string name, double price, int qty);
void removeProduct(std::string*& productNames, double*& productPrices, int*& productStock, int& productCount, std::string name);
void updateStock(int* productStock, int index, int newQty);
void priceMinMax(double* productPrices, int productCount, double* minPrice, double* maxPrice);
void salesMatrix(int** sales, int productCount);
void showInventory(std::string* productNames, double* productPrices, int* productStock, int productCount);
void freeAll(std::string* productNames, double* productPrices, int* productStock);

#endif