#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of months: ";
    cin >> n;

    int* expenses = new int[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter expense for month " << i+1 << ": ";
        cin >> expenses[i];
    }

    char choice;
    cout << "Add more months? (y/n): ";
    cin >> choice;
    if (choice == 'y') {
        int extra;
        cout << "Enter extra months: ";
        cin >> extra;
        int* newArr = new int[n+extra];
        for (int i = 0; i < n; i++) newArr[i] = expenses[i];
        for (int i = n; i < n+extra; i++) {
            cout << "Enter expense for month " << i+1 << ": ";
            cin >> newArr[i];
        }
        delete[] expenses;
        expenses = newArr;
        n += extra;
    }

    int total = 0;
    for (int i = 0; i < n; i++) total += expenses[i];
    cout << "Total: " << total << " Average: " << (float)total/n;

    delete[] expenses;
}
