#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX_N 50

struct Marble {
    int id, speed, dir;
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
            for(Marble m:grid[i][j]) {
                int nx= i+dx[m.dir]*m.speed;
                int ny= j+dy[m.dir]*m.speed;

                while(nx<1||nx>n){
                    m.dir^=1;
                    nx=(nx<1)?2-nx:2*n-nx;
                }
                while(ny<1||ny>n){
                    m.dir^=1;
                    ny=(ny<1)?2-ny:2*n-ny;
                }

                next_grid[nx][ny].push_back(m);
            }
        }
    }

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++){
            if(next_grid[i][j].size()>k){
                sort(next_grid[i][j].begin(),next_grid[i][j].end(),
                [](const Marble &a, const Marble &b){
                    return (a.speed==b.speed)?(a.id>b.id):(a.speed>b.speed);
                });
                next_grid[i][j].resize(k);
            }
        }
    }

    swap(grid,next_grid);
}

int main() {
    cin >> n >> m >> t >> k;
    direction_map['U']=0;
    direction_map['D']=1;
    direction_map['R']=2;
    direction_map['L']=3;

    for (int i = 0; i < m; i++) {
        int r, c, v;
        char d;
        cin >> r >> c >> d >> v;
        grid[r][c].push_back({i,v,direction_map[d]});
    }

    for(int i=0;i<t;i++) {
        move();
    }

    int sum=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            sum+=grid[i][j].size();
        }
    }

    cout<<sum;
}
