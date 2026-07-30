// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 5
// =============================================================================
// TASK: Fibonacci Sequence Generator
// =============================================================================

#include <iostream>
using namespace std;

// PART A: Function to generate and print the first N Fibonacci terms
void printFibonacci(int n) {
    if (n <= 0) {
        cout << "Error: Number of terms must be a positive integer." << endl;
        return;
    }

    long long first = 0, second = 1;

    cout << "Fibonacci sequence: ";
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            cout << first << " ";
        } else if (i == 1) {
            cout << second << " ";
        } else {
            long long next = first + second;
            cout << next << " ";
            first = second;
            second = next;
        }
    }
    cout << endl;
}

// PART B: Function to check if a given number belongs to the Fibonacci sequence
bool isFibonacci(long long target) {
    if (target < 0) return false;
    if (target == 0 || target == 1) return true;

    long long first = 0, second = 1, next = first + second;

    while (next <= target) {
        if (next == target) {
            return true;
        }
        first = second;
        second = next;
        next = first + second;
    }

    return false;
}

int main() {
    // --- PART A ---
    int n;
    cout << "How many terms? ";
    cin >> n;
    printFibonacci(n);

    cout << endl;

    // --- PART B ---
    long long num;
    cout << "Enter a number to check: ";
    cin >> num;

    if (isFibonacci(num)) {
        cout << num << " is a Fibonacci number." << endl;
    } else {
        cout << num << " is NOT a Fibonacci number." << endl;
    }

    return 0;
}