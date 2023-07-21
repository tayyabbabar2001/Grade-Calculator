#include <iostream>
using namespace std;

char calculateGrade(int std_marks[], int out_of[], int marks_weightage[], int size) {
    int total_marks = 0;
    double total_weightage = 0;

    for (int i = 0; i < size; i++) {
        if (marks_weightage[i] <= 0) {
            return 'X';
        }
        
        total_weightage += marks_weightage[i];
        total_marks += (std_marks[i] * marks_weightage[i]) / out_of[i];
    }


    if (total_weightage != 100.0) {
        return 'X';
    }

    double percentage = (total_marks * 100.0) / total_weightage;
    if (percentage < 0 || percentage > 100) {
        return 'X';
    } else if (percentage >= 85) {
        return 'A';
    } else if (percentage >= 70) {
        return 'B';
    } else if (percentage >= 60) {
        return 'C';
    } else if (percentage >= 50) {
        return 'D';
    } else {
        return 'F';
    }
}


int main() {
    int n;
    cout <<"Welcome to Grade Calculation code made by Tayyab Babar \n" 	;
 
    cout << "Enter the number of subjects: ";
    cin >> n;

    int std_marks[n], out_of[n], marks_weightage[n];
    cout << "Enter the std marks, out of, and marks weightage for " << n << " subjects:" << endl;

    for (int i = 0; i < n; i++) {
        cin >> std_marks[i] >> out_of[i] >> marks_weightage[i];
    }

    char grade = calculateGrade(std_marks, out_of, marks_weightage, n);
    if (grade == 'X') {
        cout << "Invalid Data" << endl;
    } else {
        cout << "Grade: " << grade << endl;
    }

    return 0;
}
