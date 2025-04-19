#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int n;
int grid[10][10];
bool visited[10];
int ans;

void FindMax(int cnt, int val){
    if(cnt==n){
        ans=max(ans,val);
        return;
    }

    for(int i=0;i<n;i++){
        if(visited[i])
            continue;

        visited[i]=true;
        FindMax(cnt+1,min(val,grid[cnt][i]));
        visited[i]=false;
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    ans=0;
    
    FindMax(0,INT_MAX);

    cout<<ans;

    return 0;
}
