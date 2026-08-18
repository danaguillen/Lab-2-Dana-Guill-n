#ifndef SOLUTION_A_H
#define SOLUTION_A_H

int countGreaterThan(int* array, int size, int limit);
int sumArray(int* array, int size);
double average(int* array, int size);

void sumByRow(int matrix[3][4], int result[3]);
int countValue(int matrix[3][4], int value);

void findMinMax(int* array, int size, int* minResult, int* maxResult);
void doubleValue(int& value);

void freeMatrix(int** matrix, int rows);
int* resizeArray(int* oldArray, int oldSize, int newSize);

void fillAndPrint(int count);

#endif