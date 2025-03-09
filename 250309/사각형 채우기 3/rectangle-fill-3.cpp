#include <iostream>

using namespace std;

#define MAX_N 1000

int n;
long dp[MAX_N+1];

int main() {
    cin >> n;

    dp[0]=1;
    dp[1]=2;

    for(int i=2;i<=n;i++) {
        dp[i]=dp[i-1]*2+dp[i-2]*3;
        for(int j=3;j<=i;j++)
            dp[i]+=dp[i-j]*2;
        dp[i]%=1000000007;
    }

    cout<<dp[n];

    return 0;
}
