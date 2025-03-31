#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_N 4

int n;
int num[MAX_N+1][MAX_N+1];
int move_dir[MAX_N+1][MAX_N+1];
int r, c;
int dx[9]={0,-1,-1,0,1,1,1,0,-1};
int dy[9]={0,0,1,1,1,0,-1,-1,-1};

int max_val=0;

void FindMax(int x, int y, int cnt) {
    int val = num[x][y];
    int dir = move_dir[x][y];
    int cur_x=x+dx[dir];
    int cur_y=y+dy[dir];
    while(cur_x>=1&&cur_x<=n&&cur_y>=1&&cur_y<=n) {
        if(num[cur_x][cur_y]>val)
            FindMax(cur_x,cur_y,cnt+1);
        cur_x=cur_x+dx[dir];
        cur_y=cur_y+dy[dir];
    }

    max_val=max(max_val,cnt);
}

int main() {
    cin >> n;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) cin >> num[i][j];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) cin >> move_dir[i][j];

    cin >> r >> c;

    max_val=0;

    FindMax(r,c,0);

    cout<<max_val;
    return 0;
}
