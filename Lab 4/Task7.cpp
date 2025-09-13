#include <iostream>
using namespace std;

class Result {
public:
    long long comparisons;
    long long swaps;
    Result() {
        comparisons = 0;
        swaps = 0;
    }
    void reset() {
        comparisons = 0;
        swaps = 0;
    }
};

class Sorter {
public:
    void bubbleSort(int arr[], int n, Result &res) {
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                res.comparisons++;
                if (arr[j] > arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                    res.swaps++;
                }
            }
        }
    }

    void insertionSort(int arr[], int n, Result &res) {
        for (int i = 1; i < n; i++) {
            int key = arr[i];
            int j = i - 1;
            while (j >= 0) {
                res.comparisons++;
                if (arr[j] > key) {
                    arr[j + 1] = arr[j];
                    res.swaps++;
                    j--;
                } else break;
            }
            arr[j + 1] = key;
        }
    }

    void shellSort(int arr[], int n, Result &res) {
        for (int gap = n / 2; gap > 0; gap /= 2) {
            for (int i = gap; i < n; i++) {
                int temp = arr[i];
                int j = i;
                while (j >= gap) {
                    res.comparisons++;
                    if (arr[j - gap] > temp) {
                        arr[j] = arr[j - gap];
                        res.swaps++;
                        j -= gap;
                    } else break;
                }
                arr[j] = temp;
            }
        }
    }
};

int main() {
    const int n = 20;
    int data[n] = {34, 7, 23, 32, 5, 62, 78, 9, 12, 45, 87, 65, 1, 90, 17, 56, 29, 73, 4,38};
    int arr1[n], arr2[n], arr3[n];
    for (int i = 0; i < n; i++) {
        arr1[i] = data[i];
        arr2[i] = data[i];
        arr3[i] = data[i];
    }
    Result r1, r2, r3;
    Sorter s;
    s.bubbleSort(arr1, n, r1);
    s.insertionSort(arr2, n, r2);
    s.shellSort(arr3, n, r3);
    cout << "Bubble Sort -> Comparisons:" << r1.comparisons << ",Swaps: " << r1.swaps << endl;
    cout << "Insertion Sort -> Comparisons: " << r2.comparisons << ",Swaps: " << r2.swaps << endl;
    cout << "Shell Sort -> Comparisons: " << r3.comparisons << ",Swaps: " << r3.swaps << endl;
}
