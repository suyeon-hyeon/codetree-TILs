#include <iostream>
#include <queue>

using namespace std;

int n, k;
int grid[101][101];
int r,c;
bool visited[101][101];
queue<pair<int,int>> q;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool InRange(int x, int y) {
    return 0 < x && x <= n && 0 < y && y <= n;
}

bool CanGo(int x, int y) {
    return InRange(x, y) && grid[x][y]<grid[r][c] && !visited[x][y];
}

void BFS() {
    while(!q.empty()) {
        pair<int, int> curr_pos = q.front();
        int x = curr_pos.first, y = curr_pos.second;
        q.pop();

        for(int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir], ny = y + dy[dir];

            if(CanGo(nx, ny)){
                q.push(make_pair(nx, ny));
                visited[nx][ny] = true;
            }
        }
    }

}

int main() {
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> grid[i][j];
        }
    }

    cin>>r>>c;

    for (int t = 0; t < k; t++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                visited[i][j]=false;
            }
        }
        q.push(make_pair(r,c));
        visited[r][c]=true;

        BFS();

        visited[r][c]=false;
        int max_val=0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if(visited[i][j]&&grid[i][j]>max_val) {
                    max_val=grid[i][j];
                    r=i;
                    c=j;
                }
            }
        }
    }

    cout<<r<<" "<<c;
}
