#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_N 100

int n;
int grid[MAX_N][MAX_N];
long dp[MAX_N][MAX_N];

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    dp[0][0]=grid[0][0];
    for(int i=1;i<n;i++){
        dp[0][i]=grid[0][i]+dp[0][i-1];
        dp[i][0]=grid[i][0]+dp[i-1][0];
    }

    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
            dp[i][j]=grid[i][j]+max(dp[i-1][j],dp[i][j-1]);
        }
    }

    long ans=dp[n-1][n-1];
    for(int i=0;i<n-1;i++){
        ans=max(ans,dp[n-1][i]);
        ans=max(ans,dp[i][n-1]);
    }
    cout<<ans;

    return 0;
}
