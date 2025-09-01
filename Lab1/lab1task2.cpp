#include <iostream>
#include <cstring>
using namespace std;

class Exam {
    char* name;
    char* date;
    int score;
public:
    Exam(const char* n, const char* d, int s) {
        name = new char[strlen(n)+1];
        strcpy(name, n);
        date = new char[strlen(d)+1];
        strcpy(date, d);
        score = s;
    }
    void display() {
        cout << name << " " << date << " " << score << endl;
    }
    ~Exam() {
        delete[] name;
        delete[] date;
    }
};

int main() {
    Exam e1("Abdul Mannan","01-09-2025",95);
    Exam e2 = e1;
    e1.display();
    e2.display();
    return 0;
}
