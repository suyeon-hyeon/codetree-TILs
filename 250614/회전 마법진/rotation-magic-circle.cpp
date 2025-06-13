#include <iostream>
using namespace std;

#define INF 1987654321

int n;
string a, b;
int dp[10005][15];

int main() {
    // n, a, b를 입력받습니다.
    cin >> n >> a >> b;

    // 문자열의 인덱스를 1부터 시작하게 하기 위해 앞에 공백을 추가합니다.
    a = " " + a;
    b = " " + b;

    // dp 배열을 초기화합니다. 초기값은 INF로 설정합니다.
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= 9; j++) 
            dp[i][j] = INF;

    // 초기 상태를 설정합니다.
    dp[0][0] = 0;

    // 동적 프로그래밍을 통해 문제를 해결합니다.
    // dp[i][j] :: i번째 마법진까지 맞춰졌을 때, 현재 j번 반시계 방향으로 회전한 형태일 때 회전의 최소 횟수
    for(int i = 0; i < n; i++)
        for(int j = 0; j <= 9; j++) {
            if(dp[i][j] == INF) continue;
            
            int cur = (a[i + 1] - '0' + j) % 10;
            int target = (b[i + 1] - '0');

            // 반시계 방향 회전의 비용을 계산하고 dp 값을 갱신합니다.
            int cost = (target - cur + 10) % 10;
            int nj = (j + cost) % 10;
            dp[i + 1][nj] = min(dp[i + 1][nj], dp[i][j] + cost);

            // 시계 방향 회전의 비용을 계산하고 dp 값을 갱신합니다.
            cost = (cur - target + 10) % 10;
            nj = j;
            dp[i + 1][nj] = min(dp[i + 1][nj], dp[i][j] + cost);
        }

    // 최종 결과를 계산합니다.
    int ans = INF;
    for(int j = 0; j <= 9; j++) {
        ans = min(ans, dp[n][j]);
    }

    // 결과를 출력합니다.
    cout << ans;
    return 0;
}
