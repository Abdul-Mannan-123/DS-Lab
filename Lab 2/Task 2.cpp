#include <iostream>
using namespace std;

int main() {
    int rows, cols;
    cout << "Enter benches and seats: ";
    cin >> rows >> cols;
    int** seats = new int*[rows];
    for (int i = 0; i < rows; i++) {
        seats[i] = new int[cols];
        for (int j = 0; j < cols; j++) seats[i][j] = 0;
    }
    int r, c;
    cout << "Enter seat to fill (row col), -1 to stop: ";
    while (true) {
        cin >> r;
        if (r == -1) break;
        cin >> c;
        if (r >= 0 && r < rows && c >= 0 && c < cols) seats[r][c] = 1;
    }
    cout << "seating Chart:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) cout << seats[i][j] << " ";
        cout << endl;
    }
    for (int i = 0; i < rows; i++) delete[] seats[i];
    delete[] seats;
}
