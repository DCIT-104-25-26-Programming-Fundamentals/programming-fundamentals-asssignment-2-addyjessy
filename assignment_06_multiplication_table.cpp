// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 6
// =============================================================================
// TASK: Multiplication Table Generator
// =============================================================================

#include <iostream>
using namespace std;

// PART A: Function to print the multiplication table for a single number (1 to 12)
void printTable(int num) {
    cout << "Multiplication Table for " << num << ":" << endl;
    for (int i = 1; i <= 12; i++) {
        cout << num << "  x  " << i << "  =  " << (num * i) << endl;
    }
}

// PART B: Function to print multiplication tables from 1 to N
void printTablesUpToN(int n) {
    for (int i = 1; i <= n; i++) {
        printTable(i);
        if (i < n) {
            cout << "---------------------------" << endl;
        }
    }
}

int main() {
    int choice;
    cout << "--- Multiplication Table Generator ---" << endl;
    cout << "1. Print table for a single number" << endl;
    cout << "2. Print tables from 1 to N" << endl;
    cout << "Enter choice (1 or 2): ";
    cin >> choice;

    if (choice == 1) {
        int num;
        cout << "Enter a number: ";
        cin >> num;

        if (num <= 0) {
            cout << "Error: Number must be a positive integer." << endl;
            return 1;
        }

        cout << endl;
        printTable(num);

    } else if (choice == 2) {
        int n;
        cout << "Enter a number N: ";
        cin >> n;

        if (n <= 0) {
            cout << "Error: Number must be a positive integer." << endl;
            return 1;
        }

        cout << endl;
        printTablesUpToN(n);

    } else {
        cout << "Invalid choice." << endl;
    }

    return 0;
}
