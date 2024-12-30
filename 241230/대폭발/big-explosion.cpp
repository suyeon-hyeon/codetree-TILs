#include <iostream>
#include <algorithm>
#include <cmath>

#define MAX_N 100

using namespace std;

int n,m,r,c;
int grid[MAX_N+1][MAX_N+1];
int temp[MAX_N+1][MAX_N+1];

int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

int main() {
    cin>>n>>m>>r>>c;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            grid[i][j]=0;
            temp[i][j]=0;
        }
    }
        
    grid[r][c]=1;

    for(int t=1;t<=m;t++) {
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                if(grid[i][j]==0)
                    continue;
                temp[i][j]=1;
                int nx;
                int ny;
                for(int dir=0;dir<4;dir++) {
                    nx=i+dx[dir]*pow(2,t-1);
                    ny=j+dy[dir]*pow(2,t-1);
                    if(nx<1||nx>n||ny<1||ny>n)
                        continue;
                    temp[nx][ny]=1;
                }
            }
        }
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                grid[i][j]=temp[i][j];
            }
        }
    }

    int ans=0;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            ans+=grid[i][j];
        }
    }

    cout<<ans;
}