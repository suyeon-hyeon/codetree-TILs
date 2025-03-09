#include <iostream>

using namespace std;

#define MAX_N 1000

int n;
int dp[MAX_N+1];

int main() {
    cin >> n;
    
    dp[0]=1;
    dp[1]=1;
    dp[2]=2;

    for(int i=3;i<=n;i++){
        dp[i]=(dp[i-1]+dp[i-2])%10007;
    }

    cout<<dp[n];

    return 0;
}
