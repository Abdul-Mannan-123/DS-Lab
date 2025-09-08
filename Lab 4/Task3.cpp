#include <iostream>
using namespace std;

void selection_sort(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		int min_index = i;
		
		for (int j =  i + 1; j < n; j++) {
			if (arr[j] < arr[min_index]) {
				min_index = j;
			}
		}
		
		int temp = arr[i];
		arr[i] = arr[min_index];
		arr[min_index] = temp;
	}
	cout << "Printing sorted array!" << endl;
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	
}
int main() {
	int num;
	cout << "How many no in array: ";
	cin >> num;
	int arr[num];
	cout << "Enter " << num << " no in the array: ";
	for (int i = 0; i < num; i++) {
		cin >> arr[i];
	}
	selection_sort(arr, num);
	
	return 0;
}
