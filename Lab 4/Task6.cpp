#include <iostream>
using namespace std;

void combSort(int arr[], int n) {
    int gap = n;
    bool swapped = true;
    int comparisons = 0, swaps = 0;
    while (gap > 1 || swapped) {
        gap = (gap * 10) / 13;
        if (gap < 1) gap = 1;

        swapped = false;
        for (int i = 0; i + gap < n; i++) {
            comparisons++;
            if (arr[i] > arr[i + gap]) {
                swap(arr[i], arr[i + gap]);
                swaps++;
                swapped = true;
            }
        }
    }
    cout << "Total comparisons: " << comparisons << endl;
    cout << "Total swaps: " << swaps << endl;
}

int main() {
    int arr[] = {9, 7, 5, 3, 1, 2, 4, 6, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    combSort(arr, n);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
    return 0;
}
