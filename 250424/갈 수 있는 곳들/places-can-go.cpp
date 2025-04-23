#include <iostream>
#include <queue>

using namespace std;

int n, k;
int grid[101][101];
bool visited[101][101];
queue<pair<int,int>> q;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool InRange(int x, int y) {
    return 0 < x && x <= n && 0 < y && y <= n;
}

bool CanGo(int x, int y) {
    return InRange(x, y) && grid[x][y]==0 && !visited[x][y];
}

void BFS() {
    while(!q.empty()) {
        // queue에서 가장 먼저 들어온 원소를 뺍니다.
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

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) cin >> grid[i][j];

    for (int i = 0; i < k; i++) {
        int r, c;
        cin>>r>>c;

        if(!visited[r][c]) {
            q.push(make_pair(r,c));
            visited[r][c]=true;

            BFS();
        }
    }

    int ans = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(visited[i][j])
                ans++;
        }
    }
    cout<<ans;

    return 0;
}
