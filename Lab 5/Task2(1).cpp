#include <iostream>
using namespace std;

void print_numbers(int n) {
	if (n == 1) {
		cout << 1;
	}
	else {
		print_numbers(n-1);
		cout << n;
	}
}
int main () {
	int n = 5;
	print_numbers(5);
}
