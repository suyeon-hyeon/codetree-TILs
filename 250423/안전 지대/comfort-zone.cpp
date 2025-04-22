#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int n, m;
int grid[50][50];
bool visited[50][50];

int dx[4] ={0,1,0,-1};
int dy[4] ={1,0,-1,0};

bool CanGo(int x, int y, int k){
    return x>=0&&x<n&&y>=0&&y<m&&grid[x][y]-k>0&&!visited[x][y];
}

void DFS(int x, int y, int k) {
    for(int i=0;i<4;i++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(CanGo(nx,ny,k)){
            visited[nx][ny]=true;
            DFS(nx,ny,k);
        }
    }
}

int main() {
    cin >> n >> m;

    int k_max=0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            k_max=max(k_max,grid[i][j]);    
        }
    }

    int safety_area[100];
    for(int k=1;k<k_max;k++){
        safety_area[k]=0;
    }

    for(int k=1;k<k_max;k++){
        int num;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                visited[i][j]=false;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(CanGo(i,j,k)) {
                    safety_area[k]++;
                    DFS(i,j,k);
                }
            }
        }
    }

    int ans=1;
    int ans_num=0;

    for(int k=1;k<k_max;k++){
        if(safety_area[k]>ans_num){
            ans_num=safety_area[k];
            ans=k;
        }
    }

    cout<<ans<<" "<<ans_num;

    return 0;
}
