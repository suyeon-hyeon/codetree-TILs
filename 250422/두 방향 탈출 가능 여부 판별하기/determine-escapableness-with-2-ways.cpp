#include <iostream>
#include <vector>

#define MAX_NUM 100

using namespace std;

int n, m;
int ans;

int graph[MAX_NUM + 1][MAX_NUM + 1];
bool visited[MAX_NUM + 1][MAX_NUM + 1];

bool CanGo(int x, int y) {
    return x>=0&&x<n&&y>=0&&y<m&&graph[x][y]==1&&!visited[x][y];
}

void DFS(int x, int y) {
    if(x==n-1&&y==m-1){
        ans=1;
        return;
    }
    int dx[2] = {0,1};
    int dy[2] = {1,0};

    visited[x][y] = true;

    for(int i = 0; i < 2; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(CanGo(nx,ny)){
            DFS(nx,ny);
        }
    }
}

int main() { 
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin>>graph[i][j];
        }
    }

    ans=0;

    DFS(0,0);

    cout<<ans;
}
