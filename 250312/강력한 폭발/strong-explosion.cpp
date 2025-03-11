#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_N 20

int n,bomb_num;
int grid[MAX_N+1][MAX_N+1];
vector<int> x;
vector<int> y;
int dx[10]={2,-2,1,-1,0,0,1,1,-1,-1};
int dy[10]={0,0,0,0,1,-1,1,-1,1,-1};
int ans;

bool InRange(int pos_x, int pos_y) {
    return pos_x>=1&&pos_x<=n&&pos_y>=1&&pos_y<=n;
}

void Bomb(int pos_x, int pos_y, int select, int val) {
    grid[pos_x][pos_y]+=val;
    int from_i, to_i;
    if(select==1) {
        from_i=0;
        to_i=4;
    }
    else if(select==2) {
        from_i=2;
        to_i=6;
    }
    else {
        from_i=6;
        to_i=10;
    }
    for(int i=from_i;i<to_i;i++){
        int nx=pos_x+dx[i];
        int ny=pos_y+dy[i];
        if(!InRange(nx,ny))
            continue;
        grid[nx][ny]+=val;
    }
}

void Choose(int cur_num) {
    if(cur_num == bomb_num) {
        int sum=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(grid[i][j]!=0)
                    sum++;
            }
        }
        ans=max(ans,sum);
        return;
    }

    int cur_x = x[cur_num];
    int cur_y = y[cur_num];

    for(int select=1;select<=3;select++){
        Bomb(cur_x,cur_y,select,1);
        Choose(cur_num+1);
        Bomb(cur_x,cur_y,select,-1);
    }

}

int main() {
    cin >> n;
    bomb_num=0;
    ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>grid[i][j];
            if(grid[i][j]==1) {
                x.push_back(i);
                y.push_back(j);
                bomb_num++;
            }
        }
    }
    Choose(0);
    cout<<ans;
    return 0;
}
