#include <iostream>
#include <algorithm>

#define MAX_N 101

using namespace std;

int n, r, c;
int grid[MAX_N][MAX_N];

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

bool canMove;

void move() {
    for(int i=0;i<4;i++) {
        int next_r = r+dx[i];
        int next_c = c+dy[i];
        if(next_r<1||next_r>n||next_c<1||next_c>n)
            continue;
        if(grid[next_r][next_c]>grid[r][c]) {
            cout << grid[r][c] << " ";
            r=next_r;
            c=next_c;
            canMove=true;
            return;
        }
    }
    canMove=false;
}

int main() {
    // 입력
    cin >> n >> r >> c;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin >> grid[i][j];

    canMove = true;
    while(canMove) {
        move();
    }
    cout << grid[r][c];
}