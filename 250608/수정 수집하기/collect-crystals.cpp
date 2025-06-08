#include <iostream>
using namespace std;

const int INF = 1987654321;
const int MAX_N = 1005;
const int MAX_K = 25;
const int STATES = 5;

int n, k;
string str;
int dp[MAX_N][MAX_K][STATES];

int main() {
    // n과 k 값을 입력받습니다.
    cin >> n >> k;
    // 문자열 str을 입력받습니다.
    cin >> str;
    // 문자열 앞에 공백을 추가하여 인덱스를 1부터 시작하게 합니다.
    str = " " + str;
    
    // dp 배열을 초기화합니다.
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= k; j++) {
            dp[i][j][0] = dp[i][j][1] = -INF;
        }
    }
    
    // 초기 상태를 설정합니다.
    dp[0][0][0] = 0;
    dp[0][1][1] = 0;

    // 동적 프로그래밍을 이용하여 문제를 해결합니다.
    // dp[i][j][k] :: i번째 수정까지 떨어졌을 때, 총 j번 엘라가 움직였고,
    // 현재 위치가 k일 때 (k = 0일 때 왼쪽, k = 1일 때 오른쪽) 수집할 수 있는 수정의 최대 개수
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= k; j++) {
            // 현재 위치가 왼쪽일 때를 관리합니다.
            if(dp[i][j][0] != -INF) {
                if(str[i + 1] == 'L') {
                    dp[i + 1][j][0] = max(dp[i + 1][j][0], dp[i][j][0] + 1);
                    dp[i + 1][j + 1][1] = max(dp[i + 1][j + 1][1], dp[i][j][0]);
                } else {
                    dp[i + 1][j][0] = max(dp[i + 1][j][0], dp[i][j][0]);
                    dp[i + 1][j + 1][1] = max(dp[i + 1][j + 1][1], dp[i][j][0] + 1);
                }
            }

            // 현재 위치가 오른쪽일 때를 관리합니다.
            if(dp[i][j][1] != -INF) {
                if(str[i + 1] == 'L') {
                    dp[i + 1][j + 1][0] = max(dp[i + 1][j + 1][0], dp[i][j][1] + 1);
                    dp[i + 1][j][1] = max(dp[i + 1][j][1], dp[i][j][1]);
                }
                else {
                    dp[i + 1][j + 1][0] = max(dp[i + 1][j + 1][0], dp[i][j][1]);
                    dp[i + 1][j][1] = max(dp[i + 1][j][1], dp[i][j][1] + 1);
                }
            }
        }
    }

    // 최종 결과를 계산합니다.
    int ans = 0;
    for(int j = 0; j <= k; j++) {
        ans = max(ans, dp[n][j][0]);
        ans = max(ans, dp[n][j][1]);
    }

    // 결과를 출력합니다.
    cout << ans;
    return 0;
}
