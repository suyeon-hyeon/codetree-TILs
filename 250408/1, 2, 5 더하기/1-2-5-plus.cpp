#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int n;
int num[3] = {1,2,5};
int dp[1001];

int main() {
    cin >> n;

    for(int i=1;i<=n;i++)
        dp[i]=0;
    dp[0]=1;

    for(int i=1;i<=n;i++){
        for(int j=0;j<3;j++){
            if(i>=num[j]){
                dp[i] = (dp[i] + dp[i - num[j]]) % 10007;
            }
        }
    }

    cout<<dp[n];

    return 0;
}
