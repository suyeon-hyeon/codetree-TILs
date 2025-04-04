#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int n, m;
int coin[100];
int dp[10001];

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> coin[i];
    }

    for (int i = 1; i <= m; i++) {
        dp[i]=INT_MAX;
    }
    dp[0]=0;

    for(int i=1;i<=m;i++){
        for(int j=0;j<n;j++){
            if(i>=coin[j]){
                if(dp[i-coin[j]]==INT_MAX)
                    continue;

                dp[i] = min(dp[i],dp[i-coin[j]]+1);
            }
        }
    }

    int ans = dp[m];

    if(ans==INT_MAX)
        cout<<-1;
    
    else
        cout<<ans;

    return 0;
}
