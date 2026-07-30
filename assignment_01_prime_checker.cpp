#include <iostream>
using namespace std;

// Function to check if a number is prime
bool isPrime(int n) {
    // Numbers less than 2 are NOT prime
    if (n < 2) {
        return false;
    }
    
    // Check divisors from 2 up to n / 2
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false; // Found a factor, so it's not prime
        }
    }
    
    return true; // No factors found, so it is prime
}

int main() {
    int num;
    
    // Prompt the user for input
    cout << "Enter a number: ";
    cin >> num;
    
    // Call isPrime and output the result
    if (isPrime(num)) {
        cout << num << " is a prime number." << endl;
    } else {
        cout << num << " is NOT a prime number." << endl;
    }
    
    return 0;
}