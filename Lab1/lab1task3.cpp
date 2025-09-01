#include <iostream>
using namespace std;

class Box {
    int* size;
public:
    Box(int s) {
        size = new int(s);
    }
    Box(const Box& other) {
        size = new int(*other.size);
    }
    Box& operator=(const Box& other) {
        if (this != &other) {
            delete size;
            size = new int(*other.size);
        }
        return *this;
    }
    ~Box() {
        delete size;
    }
    void set(int s) {
		 *size = s; 
	}
    int get() { 
		return *size; 
	}
};

int main() {
    Box b1(10);
    Box b2 = b1;
    b2.set(20);
    cout << b1.get() << " " << b2.get() << endl;

    Box b3(5);
    b3 = b1;
    b3.set(30);
    cout << b1.get() << " " << b3.get() << endl;

    return 0;
}
