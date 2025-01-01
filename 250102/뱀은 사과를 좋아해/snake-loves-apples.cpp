#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_N 100
#define MAX_S 10000

int n,m,k;
int grid[MAX_N+1][MAX_N+1];
int head_x,head_y;
int snake_length;
char past_x[MAX_S], past_y[MAX_S];
int t;
bool stop;

int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

int ASCIItoInt(char d){
    int ans=-1;
    if(d=='R') {ans=0;}
    else if(d=='D') {ans=1;}
    else if(d=='L') {ans=2;}
    else if(d=='U') {ans=3;}
    return ans;
}

bool InRange(int x, int y){
    return x>=1&&x<=n&&y>=1&&y<=n;
}

void move(char d) {
    int dir=ASCIItoInt(d);
    int nx=head_x+dx[dir];
    int ny=head_y+dy[dir];
    past_x[t]=head_x;
    past_y[t]=head_y;
    t++;
    if(!InRange(nx,ny)) {
        stop=true;
        return;
    }
    if(grid[nx][ny]==2)
        snake_length++;
    else {
        grid[past_x[t-snake_length]][past_y[t-snake_length]]=0;
        if(grid[nx][ny]==1) {
            stop=true;
            return;
        }
    }
    grid[nx][ny]=1;

    head_x=nx;
    head_y=ny;
}

int main() {
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            grid[i][j]=0; // 빈칸 = 0
        }
    }
    head_x=1;head_y=1;
    snake_length=1;
    t=0;
    grid[1][1]=1; // 뱀 = 1
    for(int i=0;i<m;i++) {
        int x,y;
        cin>>x>>y;
        grid[x][y]=2; // 사과 = 2
    }
    stop=false;
    for(int i=0;i<k;i++) {
        char d;
        int p;
        cin>>d>>p;
        if(stop)
            break;
        for(int j=0;j<p;j++) {
            if(stop)
                break;
            move(d);
        }
    }

    cout<<t;
}