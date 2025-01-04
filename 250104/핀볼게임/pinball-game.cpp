#include <iostream>
#include <algorithm>

#define MAX_N 100

using namespace std;

int n;
int grid[MAX_N+2][MAX_N+2];

int max_t;

int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

bool InRange(int x, int y) {
    return x>=1&&x<=n&&y>=1&&y<=n;
}

void bead(int start_dir, int start_x, int start_y){
    int dir=start_dir;
    int nx=start_x+dx[dir];
    int ny=start_y+dy[dir];
    int t=1;
    while(InRange(nx,ny)){
        t++;
        if(grid[nx][ny]==1) {
            dir=3-dir;
        } else if(grid[nx][ny]==2) {
            if(dir%2==0) {
                dir+=1;
            } else if(dir%2==1) {
                dir-=0;
            }
        }
        nx+=dx[dir];
        ny+=dy[dir];   
    }
    max_t=max(max_t,t);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> grid[i][j];
    
    max_t=0;
    for(int dir=0;dir<4;dir++) {
        if(dir==0) {
            for(int i=1;i<=n;i++)
                bead(dir,i,0);
        } else if(dir==1) {
            for(int j=1;j<=n;j++)
                bead(dir,0,j);
        } else if(dir==2) {
            for(int i=1;i<=n;i++)
                bead(dir,i,n+1);
        } else if(dir==3) {
            for(int j=1;j<=n;j++)
                bead(dir,n+1,j);
        }
    }

    cout<<max_t;
}
