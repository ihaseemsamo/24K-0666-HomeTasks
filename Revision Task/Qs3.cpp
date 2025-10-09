// Using Backtracking to find a path for robot in grid avoiding obstacles.

#include <iostream>
using namespace std;
#define N 4

int maze[N][N] = {
    {1,0,1,1},
    {1,1,0,1},
    {0,1,1,1},
    {1,0,1,1}
};
int sol[N][N];

bool isSafe(int x, int y) {
    return (x>=0 && y>=0 && x<N && y<N && maze[x][y]==1 && sol[x][y]==0);
}

bool solve(int x, int y) {
    if (x==N-1 && y==N-1) { sol[x][y]=1; return true; }

    if (isSafe(x,y)) {
        sol[x][y]=1;

        if (solve(x+1,y)) return true;  // Down
        if (solve(x,y+1)) return true;  // Right
        if (solve(x-1,y)) return true;  // Up
        if (solve(x,y-1)) return true;  // Left

        sol[x][y]=0; // backtrack
    }
    return false;
}

int main() {
    if (solve(0,0)) {
        cout << "Path found for robot:\n";
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++) cout << sol[i][j] << " ";
            cout << endl;
        }
    } else cout << "No Path Found";
}
