// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 3
// =============================================================================
// TASK: Array Statistics Calculator
// =============================================================================

#include <iostream>
using namespace std;

// Function to compute the sum of array elements
double calculateSum(const double arr[], int size) {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

// Function to compute average
double calculateAverage(const double arr[], int size) {
    if (size == 0) return 0;
    return calculateSum(arr, size) / size;
}

// Function to find maximum value
double findMax(const double arr[], int size) {
    double maxVal = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

// Function to find minimum value
double findMin(const double arr[], int size) {
    double minVal = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < minVal) {
            minVal = arr[i];
        }
    }
    return minVal;
}

int main() {
    int n;
    cout << "How many numbers? ";
    cin >> n;

    // Validate positive integer input
    if (n <= 0) {
        cout << "Error: Number of elements must be greater than 0." << endl;
        return 1;
    }

    double arr[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter number " << (i + 1) << ": ";
        cin >> arr[i];
    }

    cout << "\nResults:" << endl;
    cout << "Sum:     " << calculateSum(arr, n) << endl;
    cout << "Average: " << calculateAverage(arr, n) << endl;
    cout << "Maximum: " << findMax(arr, n) << endl;
    cout << "Minimum: " << findMin(arr, n) << endl;

    return 0;
}