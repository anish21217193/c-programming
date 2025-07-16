#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

// Function to convert letter grades to grade points
float getGradePoint(string grade) {
    if (grade == "A" || grade == "a") return 4.0;
    if (grade == "B" || grade == "b") return 3.0;
    if (grade == "C" || grade == "c") return 2.0;
    if (grade == "D" || grade == "d") return 1.0;
    if (grade == "F" || grade == "f") return 0.0;
    return -1; // Invalid grade
}

int main() {
    int numCourses;
    cout << "Enter the number of courses: ";
    cin >> numCourses;

    vector<string> grades(numCourses);
    vector<int> creditHours(numCourses);
    float totalCredits = 0, totalGradePoints = 0;

    for (int i = 0; i < numCourses; ++i) {
        cout << "\nCourse " << i + 1 << ":\n";
        cout << "Enter grade (A/B/C/D/F): ";
        cin >> grades[i];

        float gradePoint = getGradePoint(grades[i]);
        while (gradePoint == -1) {
            cout << "Invalid grade entered. Please enter again (A/B/C/D/F): ";
            cin >> grades[i];
            gradePoint = getGradePoint(grades[i]);
        }

        cout << "Enter credit hours: ";
        cin >> creditHours[i];
        while (creditHours[i] <= 0) {
            cout << "Credit hours must be positive. Re-enter: ";
            cin >> creditHours[i];
        }

        totalCredits += creditHours[i];
        totalGradePoints += gradePoint * creditHours[i];
    }

    float GPA = (totalCredits == 0) ? 0 : totalGradePoints / totalCredits;

    // Display each course
    cout << "\n--- Course Summary ---\n";
    cout << left << setw(10) << "Course" << setw(10) << "Grade" << setw(15) << "Credit Hours" << "\n";
    for (int i = 0; i < numCourses; ++i) {
        cout << left << setw(10) << (i + 1)
             << setw(10) << grades[i]
             << setw(15) << creditHours[i] << "\n";
    }

    cout << fixed << setprecision(2);
    cout << "\nTotal Credits: " << totalCredits << endl;
    cout << "Total Grade Points: " << totalGradePoints << endl;
    cout << "Semester GPA / CGPA: " << GPA << endl;

    return 0;
}
