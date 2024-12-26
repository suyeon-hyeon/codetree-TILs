#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_N 100

int n, m, r, c;
int grid[MAX_N+1][MAX_N+1];

int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

int x, y, z;

bool inRange(int r, int c){ return r>=1&&r<=n&&c>=1&&c<=n; }

void roll(char cmd) {
    int pre_x=x;
    int pre_y=y;
    int pre_z=z;
    int nr, nc;
    if(cmd=='R') {
        nr=r+dx[0];
        nc=c+dy[0];
        if(!inRange(nr,nc))
            return;
        r=nr;c=nc;
        grid[r][c]=pre_y;
        x=pre_x;
        y=pre_z;
        z=7-pre_y;
    } else if(cmd=='D') {
        nr=r+dx[1];
        nc=c+dy[1];
        if(!inRange(nr,nc))
            return;
        r=nr;c=nc;
        grid[r][c]=pre_x;
        x=pre_z;
        y=pre_y;
        z=7-pre_x;
    } else if(cmd=='L') {
        nr=r+dx[2];
        nc=c+dy[2];
        if(!inRange(nr,nc))
            return;
        r=nr;c=nc;
        grid[r][c]=7-pre_y;
        x=pre_x;
        y=7-pre_z;
        z=pre_y;
    } else if(cmd=='U') {
        nr=r+dx[3];
        nc=c+dy[3];
        if(!inRange(nr,nc))
            return;
        r=nr;c=nc;
        grid[r][c]=7-pre_x;
        x=7-pre_z;
        y=pre_y;
        z=7-pre_y;
    }
}

int main() {
    cin>>n>>m>>r>>c;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            grid[i][j]=0;
    
    grid[r][c]=6;
    x=2;y=3;z=1;
    for(int i=0;i<m;i++) {
        char cmd;
        cin>>cmd;
        roll(cmd);
    }

    int sum=0;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            sum+=grid[i][j];
        }
    }

    cout<<sum;
}