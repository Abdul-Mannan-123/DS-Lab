#include <iostream>
using namespace std;

int n;
int col[20];

bool is_safe(int row, int c) {
    for (int r = 0; r < row; r++) {
        if (col[r] == c || abs(col[r] - c) == abs(r - row))
            return false;
    }
    return true;
}

void print_board() {
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            if (col[r] == c) cout << "Q ";
            else cout << ". ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void solve_nq(int row, int &count) {
    if (row == n) {
        count++;
        print_board();
        return;
    }
    for (int c = 0; c < n; c++) {
        if (is_safe(row, c)) {
            col[row] = c;
            solve_nq(row + 1, count);
        }
    }
}

int main() {
    n = 4;
    int count = 0;
    solve_nq(0, count);
    cout << "total solutions: " << count << "\n";
    return 0;
}
