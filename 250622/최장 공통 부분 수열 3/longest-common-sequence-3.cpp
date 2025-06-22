#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

#define INF 1987654321

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1), b(m + 1);
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    vector<vector<pair<int, int>>> path(n + 1, vector<pair<int, int>>(m + 1));
    vector<vector<int>> cur_best(n + 1, vector<int>(m + 1, INF));

    // 두 배열의 요소를 입력받습니다.
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= m; i++) cin >> b[i];
    
    // 배열을 뒤집습니다.
    reverse(a.begin() + 1, a.end());
    reverse(b.begin() + 1, b.end());

    // 최장 공통 부분 수열을 찾기 위한 동적 프로그래밍을 수행합니다.
    // dp[i][j] :: 문자열 a는 i번째까지, 문자열 b는 j번째까지 보았을 때 최장 공통 부분 수열의 길이
    // cur_best[i][j] :: 문자열 a는 i번째까지, 문자열 b는 j번째까지 보았을 때 최장 공통 부분 수열 중
    // 가장 마지막으로 선택된 값을 최소화시킨 수열의 그 최솟값
    // path[i][j] : 그러한 최장 공통 부분 수열이 어느 이전 정보에서 왔는지의 정보
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            // 각 단계에서 최적의 해를 찾습니다.
            if(dp[i - 1][j] > dp[i][j] || (dp[i - 1][j] == dp[i][j] && cur_best[i - 1][j] < cur_best[i][j])) {
                dp[i][j] = dp[i - 1][j];
                path[i][j] = {i - 1, j};
                cur_best[i][j] = cur_best[i - 1][j];
            }
            
            if(dp[i][j - 1] > dp[i][j] || (dp[i][j - 1] == dp[i][j] && cur_best[i][j - 1] < cur_best[i][j])) {
                dp[i][j] = dp[i][j - 1];
                path[i][j] = {i, j - 1};
                cur_best[i][j] = cur_best[i][j - 1];
            }

            if(a[i] == b[j] && (dp[i - 1][j - 1] + 1 > dp[i][j] || (dp[i - 1][j - 1] + 1 == dp[i][j] && a[i] < cur_best[i][j]))) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                path[i][j] = {i - 1, j - 1};
                cur_best[i][j] = a[i];
            }
        }
    }

    // 최장 공통 부분 수열을 추적합니다.
    vector<int> lcs;
    for(int i = n, j = m; i > 0 && j > 0;) {
        if(path[i][j] == make_pair(i - 1, j - 1) && a[i] == b[j]) {
            lcs.push_back(a[i]);
            i--; j--;
        } else {
            tie(i, j) = path[i][j];
        }
    }

    // 최장 공통 부분 수열을 출력합니다.
    for(int i = 0; i < lcs.size(); i++) {
        cout << lcs[i] << " ";
    }

    return 0;
}
