#include <iostream>
using namespace std;

void bubble_sort(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - 1; j++){
			if (arr[j] >= arr[j + 1]){
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	
	cout << "Printing sorted array!" << endl;
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	
}

int main () {
	int num;
	cout << "How many no in array: ";
	cin >> num;
	int arr[num];
	cout << "Enter " << num << " no in the array: ";
	for (int i = 0; i < num; i++) {
		cin >> arr[i];
	}
	cout << "Printing array!" << endl;
	for (int i = 0; i < num; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	bubble_sort(arr, num);
	
	return 0;
}
