#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_N 100

int n;
int grid[MAX_N+1][MAX_N+1];
long dp[MAX_N+1][MAX_N+1];

int main() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> grid[i][j];
        }
    }

    dp[1][n]=grid[1][n];
    for(int i=n-1;i>=1;i--){
        dp[1][i]=grid[1][i]+dp[1][i+1];
    }
    for(int i=2;i<=n;i++){
        dp[i][n]=grid[i][n]+dp[i-1][n];
    }

    for(int i=2;i<=n;i++){
        for(int j=n-1;j>=1;j--){
            dp[i][j]=grid[i][j]+min(dp[i-1][j],dp[i][j+1]);
        }
    }

    long ans=dp[n][1];
    cout<<ans;

    return 0;
}
