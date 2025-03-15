#include <iostream>

using namespace std;

#define MAX_N 1000

int n;
long dp[MAX_N+1];

int main() {
    cin >> n;

    dp[0]=1;
    dp[1]=1;

    for(int i=2;i<=n;i++) {
        dp[i]=dp[i-1]+dp[i-2]*2;
        dp[i]%=10007;
    }

    cout<<dp[n];

    return 0;
}
