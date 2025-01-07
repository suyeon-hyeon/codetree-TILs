#include <iostream>
#include <algorithm>

#define MAX_N 20

using namespace std;

int n, m;
int grid[MAX_N+1][MAX_N+1];
int seq_x[MAX_N*MAX_N+1];
int seq_y[MAX_N*MAX_N+1];

int dx[8]={0,1,1,1,0,-1,-1,-1};
int dy[8]={1,1,0,-1,-1,-1,0,1};

bool InRange(int x, int y) {
    return x>=1&&x<=n&&y>=1&&y<=n;
}

void turn() {
    for(int num=1;num<=n*n;num++) {
        int max=0;
        for(int dir=0;dir<8;dir++) {
            int nx=seq_x[num]+dx[dir];
            int ny=seq_y[num]+dy[dir];
            if(!InRange(nx,ny))
                continue;
            if(max<grid[nx][ny]) {
                max=grid[nx][ny];
            }
        }
        grid[seq_x[max]][seq_y[max]]=num;
            grid[seq_x[num]][seq_y[num]]=max;
            
            int temp_x=seq_x[num];
            int temp_y=seq_y[num];

            seq_x[num]=seq_x[max];
            seq_y[num]=seq_y[max];
            
            seq_x[max]=temp_x;
            seq_y[max]=temp_y;
    }
}

int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> grid[i][j];
            seq_x[grid[i][j]]=i;
            seq_y[grid[i][j]]=j;
        }
    }

    for(int i=0;i<m;i++) {
        turn();
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
}
