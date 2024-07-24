#include <iostream>
#include <vector>
#include <string>
#include <iomanip> // for std::setw

using namespace std;//using namespace std is not recommended


void update_subjects(vector<string>& subjects) {
    cout << "Enter the number of subjects: ";
    int n;
    cin >> n;

    subjects.resize(n); // Resize the vector to fit the number of subjects
    for(int i = 0; i < n; i++) {
        cout << "Enter the name of subject " << i + 1 << ": ";
        cin >> subjects[i];
    }

    cout << "Subjects entered:\n";
    int i = 1; 
    for(const auto& subject : subjects) {
        cout << i << ". " << subject << "\n";
        i++; 
    }
}

double grade_to_gpa(std::string grade) {
    if (grade == "A" || grade == "A+") {
        return 4.0;
    } else if (grade == "A-") {
        return 3.7;
    } else if (grade == "B+") {
        return 3.3;
    } else if (grade == "B") {
        return 3.0;
    } else if (grade == "B-") {
        return 2.7;
    } else if (grade == "C+") {
        return 2.3;
    } else if (grade == "C") {
        return 2.0;
    } else if (grade == "C-") {
        return 1.7;
    } else if (grade == "D+") {
        return 1.3;
    } else if (grade == "D") {
        return 1.0;
    } else if (grade == "D-") {
        return 0.7;
    } else if (grade == "F") {
        return 0.0;
    } else {
        std::cerr << "Invalid grade entered." << std::endl;
        return -1.0; 
    }
}



void store_marks(const vector<string>& subjects, vector<double>& marks, vector<string>& grades) {//const vector<string>& subjects is passed by reference, but it is not modified
    marks.resize(subjects.size()); // Resize the marks vector to match subjects size
    grades.resize(subjects.size()); // Resize the grades vector to match subjects size
    for(size_t i = 0; i < subjects.size(); i++) {
        cout << "Enter the marks for " << subjects[i] << ": ";
        cin >> marks[i];
    }

    cout << "Marks entered:\n";
    for(size_t i = 0; i < subjects.size(); i++) {
        string grade;
        if(marks[i] >= 90) {
            grade = "A+";
        } else if(marks[i] >= 80) {
            grade = "A";
        } else if(marks[i] >= 70) {
            grade = "A-";
        } else if(marks[i] >= 65) {
            grade = "B+";
        } else if(marks[i] >= 60) {
            grade = "B";
        } else if(marks[i] >= 55) {
            grade = "B-";
        } else if(marks[i] >= 50) {
            grade = "C+";
        } else if(marks[i] >= 45) {
            grade = "C";
        } else if(marks[i] >= 40) {
            grade = "C-";
        } else if(marks[i] >= 35) {
            grade = "D+";
        } else if(marks[i] >= 30) {
            grade = "D";
        } else {
            grade = "F";
        }

        grades[i] = grade;
        double gpa = grade_to_gpa(grade);
        cout << subjects[i] << ": " << marks[i] << " -> Grade: " << grade << " -> GPA: " << gpa << "\n";
    }
}





int main() {
    vector<string> subjects;
    vector<double> marks;
    vector<string> grades; 

    update_subjects(subjects);
    store_marks(subjects, marks, grades);

    double cgpa = 0;
    int valid_gpa_count = 0;
    for (size_t i = 0; i < grades.size(); i++) {
        double gpa = grade_to_gpa(grades[i]);
        if (gpa != -1.0) {
            cgpa += gpa;
            valid_gpa_count++;
        }
    }
    if (valid_gpa_count > 0) {
        cgpa /= valid_gpa_count;
    }

    // Print the table
    cout << left << setw(15) << "Subject"  // setw is used to set the width of the column
         << setw(10) << "Marks" 
         << setw(10) << "Grade" 
         << setw(10) << "GPA" << endl;
    cout << "--------------------------------------------" << endl;
    for (size_t i = 0; i < subjects.size(); i++) {
        double gpa = grade_to_gpa(grades[i]);
        cout << left << setw(15) << subjects[i] 
             << setw(10) << marks[i] 
             << setw(10) << grades[i] 
             << setw(10) << gpa << endl;
    }
    cout << "--------------------------------------------" << endl;
    cout << left << setw(35) << "CGPA: " << cgpa << endl;

    return 0;
}
