#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int n;
int a[11][11];
bool visited[11];
int ans;

void FindMin(int cnt,int pre,int sum) {
    if(cnt==n){
        if(a[pre][1]==0)
            return;
        ans=min(ans,sum+a[pre][1]);
        return;
    }

    for(int i=2;i<=n;i++){
        if(visited[i]||a[pre][i]==0)
            continue;
        
        visited[i]=true;
        FindMin(cnt+1, i, sum+a[pre][i]);
        visited[i]=false;
    }
}

int main() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    ans = INT_MAX;

    FindMin(1,1,0);

    cout<<ans;

    return 0;
}
