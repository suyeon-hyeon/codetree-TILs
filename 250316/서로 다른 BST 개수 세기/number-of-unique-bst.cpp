#include <iostream>

#define MAX_NUM 19

using namespace std;

int dp[MAX_NUM + 1];

int NumOfUniqueBST(int n) {
    int number_of_unique_bst = 0;

    for(int i = 0; i < n; i++)
        number_of_unique_bst += dp[i] * dp[n - i - 1];

    return number_of_unique_bst;
}

int main() {
    int n;
    cin >> n;

    dp[0] = 1;
    dp[1] = 1;

    for(int i = 2; i <= n; i++)
        dp[i] = NumOfUniqueBST(i);

    cout << dp[n];
}
