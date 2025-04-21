#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int grid[25][25];
bool visited[25][25];
vector<int> num;
int sum;

int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

bool CanGo(int x, int y){
    return x>=0&&x<n&&y>=0&&y<n&&grid[x][y]==1&&!visited[x][y];
}

void DFS(int x, int y) {
    sum++;
    visited[x][y]=true;
    for(int i=0;i<4;i++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(CanGo(nx,ny)){
            DFS(nx,ny);
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

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==1&&!visited[i][j]) {
                sum=0;
                DFS(i,j);
                num.push_back(sum);
            }
        }
    }

    sort(num.begin(), num.end());

    cout<<num.size()<<endl;
    for (int i : num) cout << i << endl;

    return 0;
}
