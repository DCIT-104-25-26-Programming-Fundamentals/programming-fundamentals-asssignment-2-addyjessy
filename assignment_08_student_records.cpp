// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 8
// =============================================================================
// TASK: Student Record Management System
// =============================================================================

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <limits>

using namespace std;

// Struct to represent a student record
struct Student {
    string name;
    int id;
    vector<double> scores;
};

// Clear remaining input buffer safely
void clearBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Helper function to calculate average score of a student
double computeAverage(const vector<double>& scores) {
    if (scores.empty()) return 0.0;
    double sum = 0;
    for (double score : scores) {
        sum += score;
    }
    return sum / scores.size();
}

// Function to add a student record
void addStudent(vector<Student>& students) {
    Student s;

    clearBuffer();
    cout << "Student name: ";
    getline(cin, s.name);

    cout << "Student ID: ";
    while (!(cin >> s.id)) {
        cout << "Invalid ID. Please enter an integer: ";
        clearBuffer();
    }

    int numScores;
    cout << "How many scores? ";
    while (!(cin >> numScores) || numScores < 0) {
        cout << "Please enter a valid positive number: ";
        clearBuffer();
    }

    for (int i = 0; i < numScores; i++) {
        double score;
        cout << "Enter score " << (i + 1) << ": ";
        while (!(cin >> score)) {
            cout << "Invalid score. Enter a numeric value: ";
            clearBuffer();
        }
        s.scores.push_back(score);
    }

    students.push_back(s);
    cout << "Student \"" << s.name << "\" added successfully." << endl;
}

// Function to display all student records
void displayAllStudents(const vector<Student>& students) {
    if (students.empty()) {
        cout << "\nNo student records found!" << endl;
        return;
    }

    cout << "\n------------------------------------------------------------------" << endl;
    cout << left << setw(20) << "Name" 
         << setw(12) << "ID" 
         << setw(20) << "Scores" 
         << setw(10) << "Average" << endl;
    cout << "------------------------------------------------------------------" << endl;

    for (const auto& s : students) {
        string scoresStr = "";
        for (size_t i = 0; i < s.scores.size(); i++) {
            // Displays exact scores without casting to int
            scoresStr += to_string(s.scores[i]);
            // Trim trailing zeros from to_string output
            scoresStr.erase(scoresStr.find_last_not_of('0') + 1, string::npos);
            if (scoresStr.back() == '.') scoresStr.pop_back();

            if (i < s.scores.size() - 1) scoresStr += ", ";
        }

        cout << left << setw(20) << s.name 
             << setw(12) << s.id 
             << setw(20) << scoresStr 
             << fixed << setprecision(2) << computeAverage(s.scores) << endl;
    }
    cout << "------------------------------------------------------------------" << endl;
}

// Function to calculate and print average for a specific student ID
void calculateStudentAverage(const vector<Student>& students) {
    if (students.empty()) {
        cout << "\nNo student records found!" << endl;
        return;
    }

    int targetId;
    cout << "Enter student ID: ";
    while (!(cin >> targetId)) {
        cout << "Invalid input. Enter a valid student ID: ";
        clearBuffer();
    }

    for (const auto& s : students) {
        if (s.id == targetId) {
            double avg = computeAverage(s.scores);
            cout << s.name << "'s average score: " << fixed << setprecision(2) << avg << endl;
            return;
        }
    }

    cout << "Error: Student with ID " << targetId << " not found." << endl;
}

int main() {
    vector<Student> students;
    int choice = 0;

    while (choice != 4) {
        cout << "\n================================" << endl;
        cout << "   STUDENT RECORD SYSTEM MENU   " << endl;
        cout << "================================" << endl;
        cout << "1. Add student" << endl;
        cout << "2. Display all students" << endl;
        cout << "3. Calculate average score" << endl;
        cout << "4. Quit" << endl;
        cout << "Enter your choice (1-4): ";

        if (!(cin >> choice)) {
            cout << "Invalid choice! Please enter a number." << endl;
            clearBuffer();
            continue;
        }

        if (choice == 1) {
            addStudent(students);
        } else if (choice == 2) {
            displayAllStudents(students);
        } else if (choice == 3) {
            calculateStudentAverage(students);
        } else if (choice == 4) {
            cout << "Goodbye!" << endl;
        } else {
            cout << "Invalid choice! Please enter a number from 1 to 4." << endl;
        }
    }

    return 0;
}
