#include <iostream>
#include <queue>
#include <algorithm>
#include <climits>

#define MAX_N 100
#define DIR_NUM 4

using namespace std;

int n, k;
int grid[MAX_N+1][MAX_N+1];
vector<pair<int,int>> start_pos;

queue<pair<int,int>> q;
bool visited[MAX_N+1][MAX_N+1];
int spoil[MAX_N+1][MAX_N+1];

int dx[DIR_NUM] = {-1, 1, 0, 0};
int dy[DIR_NUM] = {0, 0, -1, 1};

bool InRange(int x, int y) {
    return 0 < x && x <= n && 0 < y && y <= n;
}

bool CanGo(int x, int y) {
    return InRange(x, y) && !visited[x][y] && grid[x][y]!=0;
}

void Push(int nx, int ny, int new_spoil) {
    q.push(make_pair(nx, ny));
    visited[nx][ny] = true;
    spoil[nx][ny] = new_spoil;
}

void BFS(){
    while(!q.empty()) {
        pair<int, int> curr_pos = q.front();
        int x = curr_pos.first, y = curr_pos.second;
        q.pop();

        int dx[DIR_NUM] = {-1, 1, 0, 0};
        int dy[DIR_NUM] = {0, 0, -1, 1};

        for(int dir = 0; dir < DIR_NUM; dir++) {
            int nx = x + dx[dir], ny = y + dy[dir];

            if(CanGo(nx, ny))
                Push(nx, ny, spoil[x][y] + 1);
        }
    }
}

int main() {
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> grid[i][j];
            if(grid[i][j]==2)
                start_pos.push_back(make_pair(i,j));
        }
    }

    for(int i=0;i<k;i++) {
        int x = start_pos[i].first, y = start_pos[i].second;
        Push(x,y,0);
    }
    BFS();

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if(visited[i][j])
                cout<<spoil[i][j]<<" ";
            else {
                if(grid[i][j]==0)
                    cout<<-1<<" ";
                else
                    cout<<-2<<" ";
            }
        }
        cout<<endl;
    }

    return 0;
}
