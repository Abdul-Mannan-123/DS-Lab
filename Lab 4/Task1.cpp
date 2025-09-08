#include <iostream> 
using namespace std;

void linear_search (int arr[], int key) {
	int size = sizeof(arr);
	for (int i = 0; i < size; i++) {
		if (arr[i] == key) {
			cout << "Index: " << arr[i] << endl;
			return;
		}
	}
		cout << "Key was not found!" << endl;
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
	int key;
	cout << "Enter the value for the index: ";
	cin >> key;
	linear_search(arr, key);
	return 0;
}
