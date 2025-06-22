#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

// 입력받은 두 문자열의 최장 공통 부분 수열(LCS)을 찾는 프로그램입니다.
int main() {
    string a, b;
    cin >> a >> b;

    int n = a.size(), m = b.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    vector<vector<pair<int, int>>> path(n + 1, vector<pair<int, int>>(m + 1));

    // dp 배열을 계산하고 각 단계에서의 경로를 추적합니다.
    // dp[i][j] : 문자열 a를 i번째까지 확인하고, 문자열 b를 j번째까지 확인했을 때
    // 최장 공통 부분 수열의 길이
    // path[i][j] : 그러한 최장 공통 부분 수열이 어느 이전 정보에서 왔는지의 정보
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(dp[i][j] < dp[i - 1][j]) {
                dp[i][j] = dp[i - 1][j];
                path[i][j] = {i - 1, j};
            }

            if(dp[i][j] < dp[i][j - 1]) {
                dp[i][j] = dp[i][j - 1];
                path[i][j] = {i, j - 1};
            }

            if(a[i - 1] == b[j - 1] and dp[i][j] < dp[i - 1][j - 1] + 1) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                path[i][j] = {i - 1, j - 1};
            }
        }
    }

    // 최장 공통 부분 수열을 추적하여 결과를 구성합니다.
    vector<char> lcs;
    for(int i = n, j = m; i > 0 && j > 0;) {
        if(path[i][j] == make_pair(i - 1, j - 1) && a[i - 1] == b[j - 1]) {
            lcs.push_back(a[i - 1]);
            i--; j--;
        } else {
            tie(i, j) = path[i][j];
        }
    }

    // 최장 공통 부분 수열을 출력합니다.
    for(auto it = lcs.rbegin(); it != lcs.rend(); ++it) {
        cout << *it;
    }

    return 0;
}
