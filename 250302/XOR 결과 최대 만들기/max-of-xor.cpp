#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_N 20

int n, m;
vector<int> answer;
int input[MAX_N+1];
int max_result;

void Choose(int start, int cnt, int result) {
    if(cnt == m) {
        max_result=max(max_result,result);
        return;
    }

    for(int i=start;i<=n;i++){
        Choose(i+1, cnt+1, result^input[i]);
    }

}

int main() {
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin>>input[i];
    }
    max_result=-1;
    Choose(1,0,0);
    cout<<max_result;
    return 0;
}
