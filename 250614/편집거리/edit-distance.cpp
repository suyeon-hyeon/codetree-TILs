#include <iostream>
#include <string>
#include <algorithm>

#define MAX_LEN 1000

using namespace std;

int dp[MAX_LEN + 1][MAX_LEN + 1];
string str1, str2;
int str1_len, str2_len;

void Initialize() {
    // 아무 것도 없는 상태와 각 문자열의 편집 거리를 초기화해줍니다.
    dp[0][0] = 0;

    for(int i = 1; i <= str1_len; i++)
        dp[i][0] = i;

    for(int j = 1; j <= str2_len; j++)
        dp[0][j] = j;
}

int main() {
    cin >> str1 >> str2;

    str1_len = (int) str1.size();
    str2_len = (int) str2.size();

    // string의 index가 0부터 시작하기 때문에
    // 이를 1부터 시작하기 위해서 앞에 #을 추가해줍니다.
    str1 = "#" + str1;
    str2 = "#" + str2;

    Initialize();

    for(int i = 1; i <= str1_len; i++){
        // 첫 번째 문자열의 i 번째까지 문자열을 고려했을 때
        // 두 번째 문자열의 j 번째까지 문자열을 고려했을 때
        // 가능한 최소 편집 거리를 구해줍니다.
        for(int j = 1; j <= str2_len; j++){
            // Case 1:
            // 첫 번째 문자열의 i번째 문자와,  두 번째 문자열 j번째 문자가 일치하는 경우
            // 해당 문자를 편집하지 않는 것이 항상 더 좋으므로
            // 첫 번째 문자열에서 i-1번째 문자까지 고려하고, 
            // 두 번째 문자열의 j-1번째 문자까지 고려했을 때인 dp[i-1][j-1]을 사용합니다. 
            if(str1[i] == str2[j])
                dp[i][j] = dp[i-1][j-1];

            // Case 2:
            // 각 문자를 바꾸거나, 삽입하거나 삭제하는 경우에 대하여
            // 최소 편집 거리를 구해준 뒤 1을 추가해줍니다.
            else
                dp[i][j] = min(min(dp[i-1][j-1], dp[i-1][j]), dp[i][j-1]) + 1;
        }
    }

    cout << dp[str1_len][str2_len];

    return 0;
}
