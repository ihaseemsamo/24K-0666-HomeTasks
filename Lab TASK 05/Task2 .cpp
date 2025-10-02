#include <iostream>
using namespace std;

#define N 5

int maze[N][N] = {
    {1, 0, 0, 0, 0},
    {1, 1, 1, 1, 0},
    {0, 0, 0, 1, 0},
    {1, 1, 0, 1, 1},
    {0, 1, 1, 1, 1}
};

int solution[N][N];

void printSolution() {
    cout << "Solution Path (1 = path, 0 = not visited):\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << solution[i][j] << " ";
        }
        cout << endl;
    }
}

bool isSafe(int x, int y) {
    if (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1) {
        return true;
    }
    return false;
}

bool solveMazeUtil(int x, int y) {
    if (x == N - 1 && y == N - 1) {
        solution[x][y] = 1;
        return true;
    }

    if (isSafe(x, y)) {
        if (solution[x][y] == 1)
            return false;

        solution[x][y] = 1;

        if (solveMazeUtil(x + 1, y))
            return true;

        if (solveMazeUtil(x, y + 1))
            return true;

        if (solveMazeUtil(x - 1, y))
            return true;

        if (solveMazeUtil(x, y - 1))
            return true;

        solution[x][y] = 0;
        return false;
    }
    return false;
}

bool solveMaze() {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            solution[i][j] = 0;

    if (!solveMazeUtil(0, 0)) {
        cout << "No solution exists!" << endl;
        return false;
    }

    printSolution();
    return true;
}

int main() {
    solveMaze();
    return 0;
}
