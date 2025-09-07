#include <iostream>
using namespace std;

class SafePointer {
    int* ptr;
public:
    SafePointer() { ptr = new int; }
    void setValue(int v) { *ptr = v; }
    int getValue() { return *ptr; }
    void release() { delete ptr; ptr = NULL; }
};

int main() {
    SafePointer sp[5];
    for (int i = 0; i < 5; i++) {
        int val; cout << "Enter mark: "; cin >> val;
        sp[i].setValue(val);
    }
    cout << "Marks: ";
    for (int i = 0; i < 5; i++) cout << sp[i].getValue() << " ";
    for (int i = 0; i < 5; i++) sp[i].release();
}
