#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_N 100

int n, x, y;
char grid[MAX_N+1][MAX_N+1];
int cur_dir, cur_x, cur_y;
int cnt;
bool success;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

void miro() {
    int nx=cur_x+dx[cur_dir];
    int ny=cur_y+dy[cur_dir];
    if(nx<1||nx>n||ny<1||ny>n) {
        cur_x=nx;
        cur_y=ny;
        cnt++;
        success=true;
    }
    else if(grid[nx][ny]=='#') {
        cur_dir=(cur_dir+3)%4;
    }
    else {
        cur_x=nx;
        cur_y=ny;
        cnt++;
        int wall_nx=nx+dx[(cur_dir+1)%4];
        int wall_ny=ny+dy[(cur_dir+1)%4];
        if(grid[wall_nx][wall_ny]!='#') {
            cur_dir=(cur_dir+1)%4;
            cur_x+=dx[cur_dir];
            cur_y+=dy[cur_dir];
            cnt++;
        }
    }
}

int main() {
    cin>>n>>x>>y;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>grid[i][j];
    cur_dir=0;
    cur_x=x;
    cur_y=y;
    cnt=0;
    success=false;
    while(!success) {
        miro();
        if(cur_x==x&&cur_y==y&&cur_dir==0) {
            break;
        }
    }
    if(success)
        cout<<cnt;
    else
        cout<<-1;
}