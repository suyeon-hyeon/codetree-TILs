#include <iostream>
#include <algorithm>

#define MAX_N 20
#define MAX_M 400

using namespace std;

int n, m, t;
int bead[MAX_N+1][MAX_N+1];
int cnt[MAX_N+1][MAX_N+1], cnt_next[MAX_N+1][MAX_N+1];
int r[MAX_M], c[MAX_M];

int bead_num;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,-1,1};

void move(){
    for(int time=0;time<t;time++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cnt_next[i][j]=0;
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if(cnt[i][j]==0)
                    continue;
                int max_dir=0;
                for(int dir=1;dir<4;dir++) {
                    if(bead[i+dx[dir]][j+dy[dir]]>bead[i+dx[max_dir]][j+dy[max_dir]])
                        max_dir=dir;
                }
                cnt_next[i+dx[max_dir]][j+dy[max_dir]]++;
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if(cnt_next[i][j]==1)
                    cnt[i][j]=cnt_next[i][j];
                else
                    cnt[i][j]=0;
            }
        }
    }
}

int main() {
    cin >> n >> m >> t;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> bead[i][j];
            cnt[i][j]=0;
        }
    }

    for (int i = 0; i < m; i++) {
        cin >> r[i] >> c[i];
        cnt[r[i]][c[i]]=1;
    }

    bead_num=0;
    move();
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            bead_num+=cnt[i][j];
        }
    }
    cout<<bead_num;
}
