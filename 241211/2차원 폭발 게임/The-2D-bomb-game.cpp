#include <iostream>
#include <algorithm>

#define MAX_N 100

using namespace std;

int n,m,k;
int grid[MAX_N][MAX_N];

// 중력
void drop() {
    int temp[MAX_N][MAX_N];
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            temp[i][j] = 0;

    for (int j=0;j<n;j++) {
        int idx = n-1;
        for(int i=n-1;i>=0;i--) {
            if(grid[i][j]==0)
                continue;
            temp[idx--][j]=grid[i][j];
        }
    }

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            grid[i][j] = temp[i][j];
}

// 폭발
void bomb() {
    // 폭발 확인
    bool isBomb=false;

    for(int j=0;j<n;j++) {
        // 연속되는 개수
        int cnt=1;
        for(int i=1;i<n;i++) {
            // 빈칸 패스
            if(grid[i][j]==0)
                continue;
            // 연속 카운팅
            if(grid[i-1][j]==grid[i][j])
                cnt++;
            else {
                // 연속이 끊겼고, m 이상의 연속이었을 경우
                if(cnt>=m) {
                    // 카운트만큼 폭발
                    for(int l=1;l<=cnt;l++)
                        grid[i-l][j]=0;
                    isBomb=true;
                }
                // 카운트 리셋
                cnt=1;
            }
        }
        // 마지막까지 연속이 끊기지 않았을 경우 고려
        if(cnt>=m) {
            for(int l=1;l<=cnt;l++)
                grid[n-l][j]=0;
            isBomb=true;
        }
    }
    // 터졌을 경우 중력작용 후 다시 폭발 시도
    if(isBomb) {
        drop();
        bomb();
    }
}

// 회전
void rotate() {
    int temp[MAX_N][MAX_N];
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            temp[i][j] = 0;

    for (int i=n-1;i>=0;i--) {
        int idx = n-1;
        for(int j=n-1;j>=0;j--) {
            if(grid[i][j]==0)
                continue;
            temp[idx--][n-1-i]=grid[i][j];
        }
    }

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            grid[i][j] = temp[i][j];
}

int main() {
    // 입력
    cin>>n>>m>>k;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>grid[i][j];

    // 폭발
    bomb();
    for(int i=0;i<k;i++) {
        rotate();
        bomb();
    }

    // 남은 폭탄 수 카운팅
    int bomb_cnt=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(grid[i][j]!=0)
                bomb_cnt++;
    cout<<bomb_cnt;
}