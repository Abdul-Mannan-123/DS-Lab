#include <iostream>
using namespace std;

int main() {
    int students;
    cout << "Enter number of students: ";
    cin >> students;
    int** marks = new int*[students];
    int* courses = new int[students];

    for (int i = 0; i < students; i++) {
        cout << "Enter courses for student " << i+1 << ": ";
        cin >> courses[i];
        marks[i] = new int[courses[i]];
        int sum = 0;
        for (int j = 0; j < courses[i]; j++) {
            cout << "Enter mark " << j+1 << ": ";
            cin >> marks[i][j];
            sum += marks[i][j];
        }
        cout << "Average: " << (float)sum / courses[i] << endl;
    }
    for (int i = 0; i < students; i++) delete[] marks[i];
    delete[] marks;
    delete[] courses;
}
