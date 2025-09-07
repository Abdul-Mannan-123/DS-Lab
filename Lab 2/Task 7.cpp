#include <iostream>
using namespace std;

int main() {
    int dept;
    cout << "Enter departments: ";
    cin >> dept;

    int** salary = new int*[dept];
    int* emp = new int[dept];
    float* avg = new float[dept];

    for (int i = 0; i < dept; i++) {
        cout << "Employees in dept " << i+1 << ": ";
        cin >> emp[i];
        salary[i] = new int[emp[i]];
        int sum = 0, max = 0;
        for (int j = 0; j < emp[i]; j++) {
            cin >> salary[i][j];
            sum += salary[i][j];
            if (salary[i][j] > max) max = salary[i][j];
        }
        avg[i] = (float)sum / emp[i];
        cout << "Highest salary in dept " << i+1 << ": " << max << endl;
    }

    int best = 0;
    for (int i = 1; i < dept; i++)
        if (avg[i] > avg[best]) best = i;

    cout << "Department " << best+1 << " has highest average salary\n";

    for (int i = 0; i < dept; i++) delete[] salary[i];
    delete[] salary; delete[] emp; delete[] avg;
}
