#include <iostream>
using namespace std;

int sumTail(int n, int total) {
    if (n == 0) return total;
    return sumTail(n - 1, total + n); 
}

int sumNonTail(int n) {
    if (n == 0) return 0;
    return n + sumNonTail(n - 1);
}

int main() {
    int n = 10;
    cout << "sumTail(10) = " << sumTail(n, 0) << '\n';
    cout << "sumNonTail(10) = " << sumNonTail(n) << '\n';
    return 0;
}
