#include <iostream>
using namespace std;

int N;
int solutionCount = 0;
int board[20];

void printBoard() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (board[i] == j)
                cout << "Q ";
            else
                cout << ". ";
        }
        cout << '\n';
    }
    cout << '\n';
}

bool isSafe(int row, int col) {
    for (int i = 0; i < row; ++i) {
        int prevCol = board[i];
        if (prevCol == col)
            return false;
        int colDiff = prevCol - col;
        if (colDiff < 0) colDiff = -colDiff;
        int rowDiff = row - i;
        if (colDiff == rowDiff)
            return false;
    }
    return true;
}

void solveNQueens(int row, bool printFirst) {
    if (row == N) {
        ++solutionCount;
        if (printFirst && solutionCount == 1) {
            cout << "One Valid Solution for N = " << N << ":\n";
            printBoard();
        }
        return;
    }
    for (int col = 0; col < N; ++col) {
        if (isSafe(row, col)) {
            board[row] = col;
            solveNQueens(row + 1, printFirst);
        }
    }
}

int main() {
    cout << "Enter value of N (1..20): ";
    cin >> N;
    if (N < 1 || N > 20) {
        cout << "N must be between 1 and 20\n";
        return 0;
    }
    for (int i = 0; i < N; ++i) board[i] = -1;
    solveNQueens(0, true);
    cout << "Total number of distinct solutions for N = " << N << " is: " << solutionCount << '\n';
    return 0;
}
