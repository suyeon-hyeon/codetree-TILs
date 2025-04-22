#include <iostream>
#include <algorithm>

using namespace std;

int n;
int grid[100][100];
bool visited[100][100];

int block;

int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

bool CanGo(int x, int y, int val) {
    return x>=0&&x<n&&y>=0&&y<n&&grid[x][y]==val&&!visited[x][y];
}

void DFS(int x, int y, int val) {
    visited[x][y]=true;
    block++;
    for(int i=0;i<4;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(CanGo(nx,ny,val)){
            DFS(nx,ny,val);
        }
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    
    int bomb_num=0;
    int block_max=0;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            block=0;
            DFS(i,j,grid[i][j]);
            block_max=max(block_max,block);
            if(block>3)
                bomb_num++;
        }
    }

    cout<<bomb_num<<" "<<block_max;

    return 0;
}
