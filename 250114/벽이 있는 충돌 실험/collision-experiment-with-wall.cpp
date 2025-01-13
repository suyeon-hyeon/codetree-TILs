#include <iostream>
#include <algorithm>

#define MAX_N 50

using namespace std;

int T;
int N, M;
int grid[MAX_N+1][MAX_N+1];
int x[MAX_N*MAX_N];
int y[MAX_N*MAX_N];
int d[MAX_N*MAX_N];

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

bool InRange(int x, int y){return x>=0&&x<=N&&y>=0&&y<=N;}

int CharToInt(char d) {
    int dir=-1;
    switch(d){
        case 'R':
            dir=0;
            break;
        case 'D':
            dir=1;
            break;
        case 'L':
            dir=2;
            break;
        case 'U':
            dir=3;
            break;
    }
    return dir;
}

void move() {
    int temp[MAX_N+1][MAX_N+1];
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) {
            temp[i][j]=0;
        }
    }
    for(int m=0;m<M;m++) {
        int nx=x[m]+d[m];
        int ny=y[m]+d[m];

        if(!InRange(nx,ny)) {
            d[m]=(d[m]+2)%4;
            continue;
        }

        temp[nx][ny]++;
    }

    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) {
            if(temp[i][j]==1)
                grid[i][j]=1;
            else
                grid[i][j]=0;
        }
    }
}

int main() {
    cin >> T;

    for (int t = 0; t < T; t++) {
        cin >> N >> M;

        for(int i=1;i<=N;i++) {
            for(int j=1;j<=N;j++) {
                grid[i][j]=0;
            }
        }

        for (int i = 0; i < M; i++) {
            char dir;
            cin >> x[i] >> y[i] >> dir;
            grid[x[i]][y[i]]=1;
            d[i]=CharToInt(dir);
        }

        for (int i=0;i<M*M;i++) {
            move();
        }

        int sum=0;

        for(int i=1;i<=N;i++) {
            for(int j=1;j<=N;j++) {
                if(grid[i][j]==1)
                    sum++;
            }
        }
        cout<<sum<<endl;

    }

}
