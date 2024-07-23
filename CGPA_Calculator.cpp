#include <iostream>
#include <vector>
#include <string>
using namespace std;


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
    int i = 1; // Declare 'i' before using it
    for(const auto& subject : subjects) {
        cout << i << ". " << subject << "\n";
        i++; // Increment 'i' after each iteration
    }
}


void store_marks(const vector<string>& subjects, vector<double>& marks) {
    marks.resize(subjects.size()); // Resize the marks vector to match subjects size
    for(size_t i = 0; i < subjects.size(); i++) {
        cout << "Enter the marks for " << subjects[i] << ": ";
        cin >> marks[i];
    }

    cout << "Marks entered:\n";
    for(size_t i = 0; i < subjects.size(); i++) {
        cout << subjects[i] << ": " << marks[i] << "\n";
    }
}


int main() {
    vector<string> subjects;
    vector<double> marks;

    update_subjects(subjects);
    store_marks(subjects, marks);

    return 0;
}
