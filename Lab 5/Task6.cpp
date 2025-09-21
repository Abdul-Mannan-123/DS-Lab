#include <iostream>
using namespace std;

int n = 4;
int sol[10][10];

bool is_safe(int maze[10][10], int x, int y, bool visited[10][10]) {
    return (x >= 0 && x < n && y >= 0 && y < n && maze[x][y] == 1 && !visited[x][y]);
}

bool solve_maze_util(int maze[10][10], int x, int y, bool visited[10][10]) {
    if (x == n - 1 && y == n - 1) {
        sol[x][y] = 1;
        return true;
    }

    if (is_safe(maze, x, y, visited)) {
        visited[x][y] = true;
        sol[x][y] = 1;

        int dx[4] = {1, 0, -1, 0};
        int dy[4] = {0, 1, 0, -1};

        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k], ny = y + dy[k];
            if (solve_maze_util(maze, nx, ny, visited)) return true;
        }

        sol[x][y] = 0;
        visited[x][y] = false;
    }
    return false;
}

void print_sol() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << sol[i][j] << " ";
        cout << "\n";
    }
}

int main() {
    int maze[10][10] = {
        {1,0,0,0},
        {1,1,0,1},
        {0,1,0,0},
        {1,1,1,1}
    };
    bool visited[10][10] = {false};

    if (solve_maze_util(maze, 0, 0, visited)) {
        print_sol();
    } else {
        cout << "no path\n";
    }
    return 0;
}
