#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <climits>

using namespace std;

int n;
char grid[20][20];
int x[11];
int y[11];
bool isPossible[10];
int seq[3];
int num_cnt;
int ans;

void FindMin(int cnt, int cur) {
    if(cnt==3) {
        int dis=0;
        dis+=abs(x[0]-x[seq[0]])+abs(y[0]-y[seq[0]]);
        dis+=abs(x[seq[0]]-x[seq[1]])+abs(y[seq[0]]-y[seq[1]]);
        dis+=abs(x[seq[1]]-x[seq[2]])+abs(y[seq[1]]-y[seq[2]]);
        dis+=abs(x[seq[2]]-x[10])+abs(y[seq[2]]-y[10]);
        
        ans=min(dis,ans);
        return;
    }
    
    for(int i=cur;i<=9;i++){
        if(isPossible[i]) {
            seq[cnt]=i;
            FindMin(cnt+1,i+1);
        }
    }
}

int main() {
    cin >> n;

    for (int i = 1; i <= 9; i++) {
        isPossible[i]=false;
    }

    num_cnt = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            if(grid[i][j]!='.'){
                if(grid[i][j]=='S'){
                    x[0]=i;
                    y[0]=j;
                }
                else if(grid[i][j]=='E'){
                    x[10]=i;
                    y[10]=j;
                }
                else {
                    int val = grid[i][j]-'0';
                    x[val]=i;
                    y[val]=j;
                    isPossible[val]=true;
                    num_cnt++;
                }
            }
        }
    }

    ans = INT_MAX;
    if(num_cnt<3){
        cout<<-1;
    }
    else {
        FindMin(0,1);
        cout<<ans;
    }
    
    return 0;
}
