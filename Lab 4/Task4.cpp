#include <iostream>
using namespace std;

void insertion_sort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int binarySearch(int arr[], int n, int key) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int main () {
    int num;
    cout << "How many numbers in array: ";
    cin >> num;

    int arr[num];
    cout << "Enter " << num << " numbers in the array: ";
    for (int i = 0; i < num; i++) {
        cin >> arr[i];
    }

    cout << "Original array: ";
    for (int i = 0; i < num; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    insertion_sort(arr, num); 

    cout << "Sorted array: ";
    for (int i = 0; i < num; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    int key;
    cout << "Enter key to find: ";
    cin >> key;
    int result = binarySearch(arr, num, key);

    if (result != -1)
        cout << "Key found at index: " << result << endl;
    else
        cout << "Key not found" << endl;

    return 0;
}
