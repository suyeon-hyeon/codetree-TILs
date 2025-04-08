#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int a[100];
int dp[10001];

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for(int i=1;i<=m;i++)
        dp[i]=-1;
    dp[0]=0;
    
    for(int i=0;i<=n;i++){
        for(int j=m;j>=0;j--){
            if(j>=a[i]){
                if(dp[j-a[i]]==-1)
                    continue;
                
                dp[j]=dp[j-a[i]]+1;
            }
        }
    }

    if(dp[m]==-1)
        cout<<"No";
    else
        cout<<"Yes";

    return 0;
}
