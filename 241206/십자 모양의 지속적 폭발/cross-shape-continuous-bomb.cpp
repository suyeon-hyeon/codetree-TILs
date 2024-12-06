#include <iostream>
#include <algorithm>

#define MAX_N 200
#define MAX_M 10
#define NONE -1

using namespace std;

int n,m;

int grid[MAX_N][MAX_N];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

// 폭발 후 떨어지는 함수
void drop() {
    int temp[MAX_N][MAX_N];
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            temp[i][j] = 0;

    for(int j=0;j<n;j++) {
        int col_idx = n-1;
        for(int i=n-1;i>=0;i--) {
            if(grid[i][j]==0)
                continue;
            temp[col_idx--][j] = grid[i][j];
        }
    }

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            grid[i][j] = temp[i][j];
}

// 폭발 함수
void bomb(int c) {
    int pos = NONE;
    for(int i=0;i<n;i++) {
        if(grid[i][c]==0)
            continue;
        pos = i;
        break;
    }
    if(pos==NONE)
        return;

    int cnt = grid[pos][c];
    grid[pos][c] = 0;
    for(int i=1;i<cnt;i++) {
        for(int j=0;j<4;j++) {
            int nx = pos+dx[j]*i;
            int ny = c+dy[j]*i;
            if(nx<0||nx>=n||ny<0||ny>=n||grid[nx][ny]==0)
                continue;
            grid[nx][ny] = 0;
        }
    }

    drop();
}

int main() {
    // 입력
    // 격자 크기(n) 및 폭탄터지는 회수(m)
    cin >> n >> m;
    // 격자 (grid)
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> grid[i][j];

    // 터트릴 열 위치(c)에 터지는 함수 실행
    for(int i=0; i<m; i++) {
        int c;
        cin >> c;
        bomb(c-1);
    }

    // 출력
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++)
            cout << grid[i][j] << " ";
        cout << endl;
    }
}