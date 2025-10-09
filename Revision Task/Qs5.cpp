// Rabbit and Cat both use Backtracking to reach food. Intersection points shown if same cell visited.

#include <iostream>
using namespace std;
#define N 5

int maze[N][N] = {
 {1,1,1,0,1},
 {0,1,0,1,1},
 {1,1,1,1,0},
 {0,1,0,1,1},
 {1,1,1,0,1}
};
int rabbitPath[N][N], catPath[N][N];

bool isSafe(int x, int y) {
    return (x>=0 && y>=0 && x<N && y<N && maze[x][y]==1);
}

bool solve(int x, int y, int endX, int endY, int path[N][N]) {
    if (x==endX && y==endY) { path[x][y]=1; return true; }

    if (isSafe(x,y) && path[x][y]==0) {
        path[x][y]=1;

        if (solve(x+1,y,endX,endY,path)) return true;
        if (solve(x,y+1,endX,endY,path)) return true;
        if (solve(x-1,y,endX,endY,path)) return true;
        if (solve(x,y-1,endX,endY,path)) return true;

        path[x][y]=0; // backtrack
    }
    return false;
}

void printPath(int path[N][N]) {
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++) cout << path[i][j] << " ";
        cout << endl;
    }
}

int main() {
    cout << "Rabbit path (0,0) -> (2,2):\n";
    solve(0,0,2,2,rabbitPath);
    printPath(rabbitPath);

    cout << "\nCat path (4,4) -> (2,2):\n";
    solve(4,4,2,2,catPath);
    printPath(catPath);

    cout << "\nIntersection Points (if any):\n";
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(rabbitPath[i][j]==1 && catPath[i][j]==1)
                cout << "("<<i<<","<<j<<") ";
        }
    }
}
