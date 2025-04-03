#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int n, m;
int grid[50][50];
int dp[50][50];

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dp[i][j]=-1;
        }
    }
    dp[0][0]=1;

    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            for(int k=0;k<i;k++){
                for(int l=0;l<j;l++){
                    if(dp[k][l]==-1)
                        continue;
                    
                    if(grid[k][l]<grid[i][j])
                        dp[i][j]=max(dp[i][j],dp[k][l]+1);
                }
            }
        }
    }

    int ans=0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans=max(dp[i][j],ans);
        }
    }
    cout<<ans;
    return 0;
}
