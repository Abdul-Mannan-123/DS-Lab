#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int* arr = new int[n];
    for (int i = 0; i < n; i++) arr[i] = 0;

    int pos, val;
    cout << "Enter position and value (-1 to stop): ";
    while (true) {
        cin >> pos;
        if (pos == -1) break;
        cin >> val;
        if (pos >= 0 && pos < n) arr[pos] = val;
    }

    cout << "Array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";

    delete[] arr;
}
