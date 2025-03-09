#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX_N 50

struct Marble {
    int id, weight, dir;
};

int n, m, t, k;
vector<Marble> grid[MAX_N+1][MAX_N+1];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};
char direction_map[128];

void move() {
    vector<Marble> next_grid[MAX_N+1][MAX_N+1];

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            if(!grid[i][j].empty()) {
                Marble m = grid[i][j][0];
                int nx= i+dx[m.dir];
                int ny= j+dy[m.dir];

                if(nx<1||nx>n||ny<1||ny>n) {
                    m.dir^=1;
                    next_grid[i][j].push_back(m);
                } else {
                    next_grid[nx][ny].push_back(m);
                }
            }
        }
    }

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++){
            if(next_grid[i][j].size()>1){
                sort(next_grid[i][j].begin(),next_grid[i][j].end(),
                [](const Marble &a, const Marble &b){
                    return a.id>b.id;
                });
                int sum_weight=0;
                for(Marble m:next_grid[i][j])
                    sum_weight+=m.weight;
                next_grid[i][j].resize(1);
                next_grid[i][j][0].weight=sum_weight;
            }
        }
    }

    swap(grid,next_grid);
}

int main() {
    cin >> n >> m >> t;
    direction_map['U']=0;
    direction_map['D']=1;
    direction_map['R']=2;
    direction_map['L']=3;

    for (int i = 0; i < m; i++) {
        int r, c, w;
        char d;
        cin >> r >> c >> d >> w;
        grid[r][c].push_back({i,w,direction_map[d]});
    }

    for(int i=0;i<t;i++) {
        move();
    }

    int sum=0;
    int max_weight=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(!grid[i][j].empty()) {
                sum++;
                max_weight=max(max_weight, grid[i][j][0].weight);
            }
        }
    }

    cout<<sum<<" "<<max_weight;
}
