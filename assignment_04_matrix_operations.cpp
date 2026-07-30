// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
// TASK: Matrix Operations
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int MAX_SIZE = 10;

// Helper function to print a matrix neatly using setw()
void printMatrix(const int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
}

// Function to read matrix elements from user input
void readMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols, string name = "matrix") {
    cout << "Enter elements for " << name << " (" << rows << "x" << cols << "):" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

// PART A: Transpose a Matrix
void transposeMatrix(const int input[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = input[i][j];
        }
    }
}

// PART B: Add Two Matrices
void addMatrices(const int A[MAX_SIZE][MAX_SIZE], const int B[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}

// PART C: Multiply Two Matrices
void multiplyMatrices(const int A[MAX_SIZE][MAX_SIZE], const int B[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rowsA, int colsA, int colsB) {
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            result[i][j] = 0;
            for (int k = 0; k < colsA; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    int choice;
    cout << "--- Matrix Operations Menu ---" << endl;
    cout << "1. Transpose Matrix" << endl;
    cout << "2. Add Two Matrices" << endl;
    cout << "3. Multiply Two Matrices" << endl;
    cout << "Enter choice (1-3): ";
    cin >> choice;

    if (choice == 1) {
        int rows, cols;
        cout << "Enter number of rows: ";
        cin >> rows;
        cout << "Enter number of columns: ";
        cin >> cols;

        int mat[MAX_SIZE][MAX_SIZE];
        int trans[MAX_SIZE][MAX_SIZE];

        readMatrix(mat, rows, cols);
        transposeMatrix(mat, trans, rows, cols);

        cout << "\nOriginal Matrix:" << endl;
        printMatrix(mat, rows, cols);

        cout << "\nTransposed Matrix:" << endl;
        printMatrix(trans, cols, rows);

    } else if (choice == 2) {
        int rows, cols;
        cout << "Enter number of rows: ";
        cin >> rows;
        cout << "Enter number of columns: ";
        cin >> cols;

        int A[MAX_SIZE][MAX_SIZE], B[MAX_SIZE][MAX_SIZE], sum[MAX_SIZE][MAX_SIZE];

        readMatrix(A, rows, cols, "Matrix A");
        readMatrix(B, rows, cols, "Matrix B");

        addMatrices(A, B, sum, rows, cols);

        cout << "\nMatrix A + Matrix B:" << endl;
        printMatrix(sum, rows, cols);

    } else if (choice == 3) {
        int rowsA, colsA, rowsB, colsB;
        cout << "Enter rows for Matrix A: ";
        cin >> rowsA;
        cout << "Enter columns for Matrix A: ";
        cin >> colsA;

        cout << "Enter rows for Matrix B: ";
        cin >> rowsB;
        cout << "Enter columns for Matrix B: ";
        cin >> colsB;

        if (colsA != rowsB) {
            cout << "Error: Matrix multiplication impossible! (Columns of A must equal Rows of B)" << endl;
            return 1;
        }

        int A[MAX_SIZE][MAX_SIZE], B[MAX_SIZE][MAX_SIZE], product[MAX_SIZE][MAX_SIZE];

        readMatrix(A, rowsA, colsA, "Matrix A");
        readMatrix(B, rowsB, colsB, "Matrix B");

        multiplyMatrices(A, B, product, rowsA, colsA, colsB);

        cout << "\nMatrix A x Matrix B:" << endl;
        printMatrix(product, rowsA, colsB);

    } else {
        cout << "Invalid choice." << endl;
    }

    return 0;
}