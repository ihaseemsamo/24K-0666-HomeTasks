// Backtracking used to find safe escape route in maze.
// If no safe route exists, function returns false (the "return false;" line handles it).

#include <iostream>
using namespace std;
#define N 4

int maze[N][N] = {
    {1,1,0,1},
    {0,1,1,0},
    {1,1,0,1},
    {0,1,1,1}
};
int sol[N][N];

bool isSafe(int x, int y) {
    return (x>=0 && y>=0 && x<N && y<N && maze[x][y]==1 && sol[x][y]==0);
}

bool solve(int x, int y) {
    if (x==N-1 && y==N-1) { sol[x][y]=1; return true; }

    if (isSafe(x,y)) {
        sol[x][y]=1;

        if (solve(x+1,y) || solve(x,y+1) || solve(x-1,y) || solve(x,y-1))
            return true;

        sol[x][y]=0; // backtrack
    }
    return false; // <-- handles "no path found"
}

int main() {
    if (solve(0,0)) {
        cout << "Safe escape path found:\n";
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++) cout << sol[i][j] << " ";
            cout << endl;
        }
    } else cout << "No Safe Escape Possible.";
}
