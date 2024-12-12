#include <iostream>
#include <algorithm>

# define MAX_N 50

using namespace std;

int n;

int grid[MAX_N][MAX_N];
int bomb_grid[MAX_N][MAX_N];

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

void drop() {
    int temp[MAX_N][MAX_N];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            temp[i][j]=0;

    for(int j=0;j<n;j++) {
        int idx = n-1;
        for(int i=n-1;i>=0;i--) {
            if(bomb_grid[i][j]==0)
                continue;
            temp[idx--][j]=bomb_grid[i][j];
        }
    }

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            bomb_grid[i][j]=temp[i][j];
}

int countPair() {
    int cnt = 0;
    for(int i=0;i<n;i++) {
        for(int j=1;j<n;j++) {
            if(bomb_grid[i][j]==0)
                continue;
            if(bomb_grid[i][j]==bomb_grid[i][j-1])
                cnt++;
        }
        for(int j=1;j<n;j++) {
            if(bomb_grid[j][i]==0)
                continue;
            if(bomb_grid[j][i]==bomb_grid[j-1][i])
                cnt++;
        }
    }
    return cnt;
}

int bomb(int x, int y) {
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            bomb_grid[i][j]=grid[i][j];

    int cnt = bomb_grid[x][y];
    bomb_grid[x][y]=0;

    for(int i=1;i<cnt;i++) {
        for(int j=0;j<4;j++) {
            int nx = x+dx[j]*i;
            int ny = y+dy[j]*i;
            if(nx<0||nx>=n||ny<0||ny>=n)
                continue;
            bomb_grid[nx][ny]=0;
        }
    }

    drop();
    return countPair();
}

int main() {
    cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>grid[i][j];

    int maxPair=0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            maxPair=max(maxPair,bomb(i,j));
        }
    }

    cout<<maxPair;
}