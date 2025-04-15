#include <iostream>
#include <tuple>
#include <algorithm>

#define MAX_N 1000

using namespace std;

// 변수 선언
int n;
pair<int, int> segments[MAX_N];

// dp[i] : x1 기준으로 정렬되어 있다는 가정 하에서
//         i번째 선분을 끝으로
//         겹치지 않게 선택할 수 있는 최대 선분의 수
int dp[MAX_N];

int main() {
    // 입력:
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x1, x2;
        cin >> x1 >> x2;
        segments[i] = make_pair(x1, x2);
    }

    // x1 기준으로 오름차순 정렬을 진행합니다.
    sort(segments, segments + n);

    for(int i = 0; i < n; i++) {
        // 현재 선분이 시작 선분인 경우에는
        // dp값이 1이 되므로
        // 초기 셋팅은 1입니다.
        dp[i] = 1;

        // i번째 선분 선택 전에
        // 바로 선택한 선분을 j라 했을 때 
        // i, j 선분이 서로 겹치지 않는 경우 중 
        // 선택 할 수 있는 선분의 최대 개수를 계산합니다.
        for(int j = 0; j < i; j++) {
            int x1_i;
            tie(x1_i, ignore) = segments[i];

            int x2_j;
            tie(ignore, x2_j) = segments[j];
            
            // 이미 x1 순으로 정렬이 되어있기에
            // x2[j] < x1[i]이기만 하면 두 선분은 겹치지 않습니다.
            if(x2_j < x1_i)
                dp[i] = max(dp[i], dp[j] + 1);
        }
    }

    // 마지막으로 선택한 선분 위치가 i일 때의 경우 중
    // 고를 수 있는 선분의 수가 가장 큰 경우를 고릅니다.
    int ans = 0;
    for(int i = 0; i < n; i++)
        ans = max(ans, dp[i]);

    cout << ans;
    return 0;
}
