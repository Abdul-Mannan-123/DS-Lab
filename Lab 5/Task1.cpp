#include <iostream>
using namespace std;

int calculate_factorial(int n) {
	if (n == 1 || n == 0) {
		return n;
	}
	
	return n * calculate_factorial(n-1);
}

int main () {
	int n = 5;
	cout << "Factorial: " << calculate_factorial(n) << endl;
	return 0;
}
