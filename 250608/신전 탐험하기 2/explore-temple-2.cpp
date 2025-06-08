#include <iostream>

using namespace std;

int n;
int l[1001], m[1001], r[1001];

int main() {#include <iostream>
using namespace std;

int n;
int a[1005][5];
int dp[1005][5][5];

int main() {
    // n과 각 활동의 점수를 입력받습니다.
    cin >> n;
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= 3; j++)
            cin >> a[i][j];
    }

    // 첫 번째 날의 각 활동 점수를 초기화합니다.
    for(int j = 1; j <= 3; j++) {
        dp[1][j][j] = a[1][j];
    }

    // 동적 프로그래밍을 사용하여 최대 점수를 계산합니다.
    // dp[i][j][k] : i번째 층까지 올라왔을 때,
    // 첫 번째 층에서 j번 방(j = 1일 때 : 왼쪽, j = 2일 때 : 가운데, j = 3일 때 : 오른쪽) 을 고르고,
    // i 번째 층에서 k번 방(k = 1일 때 : 왼쪽, k = 2일 때 : 가운데, k = 3일 때 : 오른쪽)
    // 을 골랐을 때 가져갈 수 있는 보물의 최대 개수
    for(int i = 1; i < n; i++) {
        for(int j = 1; j <= 3; j++) {
            for(int k = 1; k <= 3; k++) {
                for(int l = 1; l <= 3; l++) {
                    // 이전 층과 같은 방을 고르지 않는 경우에 대해 계산합니다.
                    if(k != l) {
                        dp[i + 1][j][l] = max(dp[i + 1][j][l], dp[i][j][k] + a[i + 1][l]);
                    }
                }
            }
        }
    }

    // 가능한 모든 조합을 고려하여 최대 점수를 찾습니다.
    int ans = 0;
    for(int j = 1; j <= 3; j++) {
        for(int k = 1; k <= 3; k++) {
            if(j != k) {
                ans = max(ans, dp[n][j][k]);
            }
        }
    }

    // 계산된 최대 점수를 출력합니다.
    cout << ans;
    return 0;
}

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> l[i] >> m[i] >> r[i];
    }

    // Please write your code here.

    return 0;
}
