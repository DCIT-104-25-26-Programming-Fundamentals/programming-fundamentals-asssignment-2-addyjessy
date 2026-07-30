// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 9
// =============================================================================
// TASK: Console-Based Simple Calculator
// =============================================================================

#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>

using namespace std;

void clearBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

double add(double a, double b) { return a + b; }
double subtract(double a, double b) { return a - b; }
double multiply(double a, double b) { return a * b; }

bool divide(double a, double b, double& result) {
    if (b == 0) return false;
    result = a / b;
    return true;
}

bool calculateModulus(double a, double b, double& result) {
    if (b == 0) return false;
    result = fmod(a, b);
    return true;
}

double power(double base, double exp) { return pow(base, exp); }

double getNumberInput(const string& prompt) {
    double num;
    cout << prompt;
    while (!(cin >> num)) {
        cout << "Invalid input. Please enter a valid number: ";
        clearBuffer();
    }
    return num;
}

int main() {
    int choice = 0;

    while (choice != 7) {
        cout << "\n============================" << endl;
        cout << "      SIMPLE CALCULATOR     " << endl;
        cout << "============================" << endl;
        cout << "1. Addition" << endl;
        cout << "2. Subtraction" << endl;
        cout << "3. Multiplication" << endl;
        cout << "4. Division" << endl;
        cout << "5. Modulus" << endl;
        cout << "6. Exponentiation" << endl;
        cout << "7. Quit" << endl;
        cout << "Select an operation (1-7): ";

        if (!(cin >> choice)) {
            cout << "Invalid choice! Please enter a number from 1 to 7." << endl;
            clearBuffer();
            continue;
        }

        if (choice == 7) {
            cout << "Goodbye!" << endl;
            break;
        }

        if (choice < 1 || choice > 7) {
            cout << "Invalid choice! Please select an operation from 1 to 7." << endl;
            continue;
        }
if(choice >= 1 && choice <= 6) {
        double num1 = getNumberInput("Enter first number : ");
        double num2 = getNumberInput("Enter second number: ");
        double result = 0.0;

        cout << fixed << setprecision(2);

        switch (choice) {
            case 1:
                cout << "Result: " << num1 << " + " << num2 << " = " << add(num1, num2) << endl;
                break;
            case 2:
                cout << "Result: " << num1 << " - " << num2 << " = " << subtract(num1, num2) << endl;
                break;
            case 3:
                cout << "Result: " << num1 << " * " << num2 << " = " << multiply(num1, num2) << endl;
                break;
            case 4:
                if (divide(num1, num2, result)) {
                    cout << "Result: " << num1 << " / " << num2 << " = " << result << endl;
                } else {
                    cout << "Error: Cannot divide by zero." << endl;
                }
                break;
            case 5:
                if (calculateModulus(num1, num2, result)) {
                    cout << "Result: " << num1 << " % " << num2 << " = " << result << endl;
                } else {
                    cout << "Error: Cannot perform modulus by zero." << endl;
                }
                break;
            case 6:
                cout << "Result: " << num1 << " ^ " << num2 << " = " << power(num1, num2) << endl;
                break;
        }
    }
}

    return 0;
}