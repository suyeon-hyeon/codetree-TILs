#include <iostream>

using namespace std;

int main() {
    string a, b;
    cin >> a >> b;

    int n = a.length(), m = b.length();
    int dp[1005][1005] = {0};
    
    // dp 배열을 초기화합니다.
    for(int i = 1; i <= n; i++) dp[i][0] = i;
    for(int j = 1; j <= m; j++) dp[0][j] = j;

    // 두 문자열의 각 문자를 비교하며 동적 프로그래밍을 완성합니다.
    // dp[i][j] :: a문자열의 처음 i개 문자열을, b문자열의 처음 j개로 바꾸는데 필요한 최소 연산 횟수
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(a[i - 1] == b[j - 1]) {
                // 문자가 같으면 이전 편집 거리를 가져옵니다.
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                // 문자가 다르면 문자를 삽입하거나 삭제해야 합니다.
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
            }
        }
    }

    // 결과를 출력합니다.
    cout << dp[n][m];

    return 0;
}
