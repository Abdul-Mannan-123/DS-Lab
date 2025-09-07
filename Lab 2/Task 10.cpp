#include <iostream>
using namespace std;

int main() {
    int cat;
    cout << "Enter categories: ";
    cin >> cat;

    int** books = new int*[cat];
    int* count = new int[cat];

    for (int i = 0; i < cat; i++) {
        cout << "Books in category " << i+1 << ": ";
        cin >> count[i];
        books[i] = new int[count[i]];
        for (int j = 0; j < count[i]; j++) cin >> books[i][j];
    }

    int id; cout << "Enter book ID to search: "; cin >> id;
    bool found = false;
    for (int i = 0; i < cat; i++) {
        for (int j = 0; j < count[i]; j++) {
            if (books[i][j] == id) {
                cout << "Book found in category " << i+1 << endl;
                found = true;
            }
        }
    }
    if (!found) cout << "Book not found\n";

    for (int i = 0; i < cat; i++) delete[] books[i];
    delete[] books; delete[] count;
}
