#include <iostream>
using namespace std;

bool is_safe(int grid[9][9], int row, int col, int num) {
    for (int x = 0; x < 9; x++)
        if (grid[row][x] == num || grid[x][col] == num)
            return false;

    int sr = row - row % 3, sc = col - col % 3;
    for (int r = 0; r < 3; r++)
        for (int c = 0; c < 3; c++)
            if (grid[sr + r][sc + c] == num)
                return false;

    return true;
}

bool solve_sudoku(int grid[9][9]) {
    int row = -1, col = -1;
    bool empty_found = false;
    for (int r = 0; r < 9 && !empty_found; r++) {
        for (int c = 0; c < 9; c++) {
            if (grid[r][c] == 0) {
                row = r;
                col = c;
                empty_found = true;
                break;
            }
        }
    }
    if (!empty_found) return true;

    for (int num = 1; num <= 9; num++) {
        if (is_safe(grid, row, col, num)) {
            grid[row][col] = num;
            if (solve_sudoku(grid)) return true;
            grid[row][col] = 0;
        }
    }
    return false;
}

void print_grid(int grid[9][9]) {
    for (int r = 0; r < 9; r++) {
        for (int c = 0; c < 9; c++) cout << grid[r][c] << " ";
        cout << "\n";
    }
}

int main() {
    int grid[9][9] = {
        {5,3,0, 0,7,0, 0,0,0},
        {6,0,0, 1,9,5, 0,0,0},
        {0,9,8, 0,0,0, 0,6,0},

        {8,0,0, 0,6,0, 0,0,3},
        {4,0,0, 8,0,3, 0,0,1},
        {7,0,0, 0,2,0, 0,0,6},

        {0,6,0, 0,0,0, 2,8,0},
        {0,0,0, 4,1,9, 0,0,5},
        {0,0,0, 0,8,0, 0,7,9}
    };

    if (solve_sudoku(grid)) {
        print_grid(grid);
    } else {
        cout << "no solution\n";
    }
    return 0;
}
